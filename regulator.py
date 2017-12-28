#!/usr/bin/env python

import argparse
from copy import deepcopy
from distutils.dir_util import mkpath
import os
import re
import string
import xml.etree.ElementTree as ET

peripheral_defaults = dict()
register_defaults = dict(width=32, 
                         access='read-write', 
                         size=32, 
                         resetValue=0,
                         resetMask=0xFFFFFFFF)

field_defaults = dict(bitOffset=0, bitWidth=32)

svd_defaults = dict(peripheral=peripheral_defaults,
                    register=register_defaults,
                    field=field_defaults,
                    device=dict())

access_mode_map = {'read-write':'RW',
                   'read-only':'RO',
                   'write-only':'WO'}
                        
INDENT = " " * 2

def indent(s, count=1):
    prefix = INDENT * count
    lines = s.split('\n')
    for i in range(len(lines)):
        if lines[i] != '':
            lines[i] = prefix + lines[i]
    return '\n'.join(lines)

def include_guard_token(*parts):
    middle = '_'.join([p.upper().replace('.','_') for p in parts])
    return "_" + middle + "_"

def clean_svd(s):
    return re.sub('\n\s*', ' ', s).replace('$', '\\$')
    
def svd_to_dict(element, defaults=None):
    if defaults is None:
        result = {}
    else:
        result = deepcopy(defaults[element.tag])
    for child in element:
        result[child.tag] = clean_svd(child.text)
    return result
    
def make_type_name(name):
    subnames = name.lower().split('_')
    return ''.join([sn.lower().capitalize() for sn in subnames])

def make_instance_name(name):
    return name.lower()

class Field(object):
    template_fname = 'templates/field.ht'
    
    def __init__(self, name, description, msb, lsb):
        self.name = name
        self.description = description
        self.msb = msb
        self.lsb = lsb
        if (msb == lsb):
            self.type = 'bool'
        else:
            self.type = 'unsigned'
        
    @classmethod
    def from_svd(cls, element, defaults=None):
        if element.tag != 'field':
            raise RuntimeError('Argument must be a field SVD element')
        params = svd_to_dict(element, defaults=defaults)
        width = int(params['bitWidth'], 0)
        lsb = int(params['bitOffset'], 0)
        msb = lsb + width - 1
        return Field(params['name'], params['description'], msb, lsb)
        
    def __repr__(self):
        return "<Field: %s [%i:%i]>" % (self.name, self.msb, self.lsb)
    
    def __cmp__(self, other):
        return self.msb.__cmp__(other.msb)
        
    def to_cpp(self):

        with open(self.template_fname, 'r') as f:
            template_string = f.read()
        
        replacements = dict(FIELD_NAME=make_instance_name(self.name),
        					MSB=self.msb, 
                            LSB=self.lsb,
                            FIELD_TYPE=self.type,
                            FIELD_DESCRIPTION=self.description,
                            INDENT=INDENT)
        template = string.Template(template_string)
        return template.safe_substitute(replacements)
        
class Padding(object):
    template_fname = 'templates/padding.ht'
    
    def __init__(self, offset_start, offset_end):
        self.offset_start = offset_start
        self.offset_end = offset_end
        if (((offset_end - offset_start) % 4) == 0):
            self.pad_type = 'uint32_t'
            self.pad_size = 4
        elif (((offset_end - offset_start) % 2) == 0):
            self.pad_type = 'uint16_t'
            self.pad_size = 2
        else:
            self.pad_type = 'uint8_t'
            self.pad_size = 1
        self.pad_count = (offset_end - offset_start)/self.pad_size
            
    
    def __repr__(self):
        return "<Padding: %s (x%d) [+0x%X - +0x%x]>" % \
            (self.pad_type, self.pad_count, self.offset_start, self.offset_end)
    
    def to_cpp(self):
        with open(self.template_fname, 'r') as f:
            template_string = f.read()
        
        replacements = dict(PAD_OFFSET_START="0x%X" % (self.offset_start),
                            PAD_OFFSET_END="0x%X" % (self.offset_end),
                            PAD_TYPE=self.pad_type,
                            PAD_COUNT=self.pad_count,
                            INDENT=INDENT)
        template = string.Template(template_string)
        return template.safe_substitute(replacements)
        
class Register(object):
    template_fname = 'templates/register.ht'
    
    def __init__(self, name, description, offset, size, 
                 access_mode, reset_value, fields):
        self.name = name
        self.description = description
        self.offset = offset
        self.size = size
        self.type = 'uint%u_t' % (size)
        self.access_mode = access_mode
        self.reset_value = reset_value
        self.fields = sorted(fields, reverse=True)
        
    @classmethod  
    def from_svd(cls, element, defaults=None):
        if element.tag != 'register':
            raise RuntimeError('Argument must be register SVD element')
        params = svd_to_dict(element, defaults)
        offset = int(params['addressOffset'], 0)
        size = int(params['size'], 0)
        reset_value = int(params['resetValue'], 0)
        access_mode = access_mode_map[params['access']]
        defaults['field']['reg_width'] = size
        fields = [Field.from_svd(f, defaults) for f in element.find('fields')]
        return Register(params['name'], params['description'],
                        offset, size, access_mode, reset_value, fields)
        
    def __repr__(self):
        return "<Register %s (+0x%X)>" % (self.name, self.offset)
        
    def to_cpp(self):
        replacements = dict(REGISTER_NAME=make_instance_name(self.name),
                            DESCRIPTION=self.description,
                            OFFSET="0x%X" % self.offset,
                            ACCESS_MODE=self.access_mode,
                            STORAGE_TYPE=self.type,
                            RESET_VALUE="0x%X" % self.reset_value,
                            INDENT=INDENT)

        if (len(self.fields) == 1):
            fields = indent('SBF_NO_FIELDS')
        else:
            fields = indent("\n".join([field.to_cpp() for field in self.fields]))
        replacements['FIELDS'] = fields

        with open(self.template_fname, 'r') as f:
            template_string = f.read()        
        template = string.Template(template_string)
        return template.safe_substitute(replacements)
        

class Peripheral(object):
    cache = {}
    template_fname='templates/peripheral.ht'
    
    def __init__(self, name, description, base_address, registers, group_name, parent):
        self.name = name
        self.description = description
        self.base_address = base_address
        self.registers = registers
        self.group_name = group_name
        self.parent = parent
    
    @classmethod
    def from_svd(cls, element, defaults=None):
        if element.tag != 'peripheral':
            raise RuntimeError('Argument must be a peripheral SVD element')
        params = svd_to_dict(element, defaults)
        params.pop('registers', None)
        # params['addressBlock'] = svd_to_dict(element.find('addressBlock'), defaults)

        if element.attrib.has_key('derivedFrom'):
            params['parent'] = element.attrib['derivedFrom']            
            template = deepcopy(cls.cache[params['parent']])
        else:
            regs = [Register.from_svd(r, defaults) for r in element.find('registers')]
            template = dict(registers=regs, parent='')
        template.update(params)
        cls.cache[template['name']] = template
        return Peripheral(template['name'], template['description'], \
                          int(template['baseAddress'], 0), template['registers'], \
                          template['groupName'], template['parent'])

    def __repr__(self):
        return "<Peripheral %s (%s) @ 0x%08X>" % (self.name, self.group_name, self.base_address)
    
    def to_cpp(self):
        with open(self.template_fname, 'r') as f:
            template_string = f.read()

        replacements = dict()
        replacements['INDENT'] = INDENT
        replacements['PERIPHERAL_GROUP'] = make_type_name(self.group_name)
        replacements['PERIPHERAL_TYPE'] = make_type_name(self.name)
        replacements['PERIPHERAL_NAME'] = make_instance_name(self.name)
        replacements['BASE_ADDRESS'] = "0x%08X" % (self.base_address)
        replacements['DESCRIPTION'] = self.description
         
        reg_map = dict([(r.offset, r) for r in self.registers])
        offsets = reg_map.keys()
        offsets.sort()
        current_offset = 0
        cpp_regs = ""
        for target_offset in offsets:
            if current_offset < target_offset:
                # Add padding
                padding = Padding(current_offset, target_offset)
                cpp_regs += indent(padding.to_cpp()) + "\n";
                current_offset = target_offset
            reg = reg_map[target_offset]
            cpp_regs += indent(reg.to_cpp()) + "\n"
            current_offset += (reg.size / 8)
        replacements['REGISTERS'] = cpp_regs        

        template = string.Template(template_string)
        return template.safe_substitute(replacements)      


class Device(object):
    device_file_template_fname = 'templates/device_file.ht'
    peripheral_file_template_fname = 'templates/peripheral_file.ht'
    
    def __init__(self, name, **kwargs):
        self.name = name
        self.__dict__.update(kwargs)
        
    @classmethod
    def from_svd(cls, element, defaults=None):
        if element.tag != 'device':
            raise RuntimeError('Argument must be a device SVD element')
        params = svd_to_dict(element, defaults)
        peripherals = [Peripheral.from_svd(p, svd_defaults) for p in element.iter('peripheral')]
        peripherals = sorted(peripherals, key=lambda p: p.name)
        params['peripherals'] = peripherals
        name = params.pop('name')
        return Device(name, **params)
        
    @classmethod
    def from_svdfile(cls, svd_fname, defaults=None):
        root = ET.parse(svd_fname).getroot()
        return Device.from_svd(root.iter('device').next(), defaults)
    
    def __repr__(self):
        return "<Device %s>" % self.name
    
    def _file_replacements(self, fname):
        replacements = dict()
        replacements['NAMESPACE'] = make_type_name(self.name)
        replacements['INCLUDE_GUARD_TOKEN'] = include_guard_token(self.name, fname)
        return replacements
        
    def _generate_device_file(self, peripheral_header_fnames, output_path=''):
        with open(self.device_file_template_fname, 'r') as f:
            template_string = f.read()
        
        output_fname = self.name.lower() + ".h"
        output_fpath = os.path.join(output_path, output_fname)
        replacements = self._file_replacements(output_fname)
        replacements['PERIPHERAL_INCLUDES'] = \
            '\n'.join(['#include "%s"' % (n) for n in peripheral_header_fnames])
    
        template = string.Template(template_string)
        with open(output_fpath, 'w') as f:
            print "Writing " + output_fpath + "...",
            f.write(template.safe_substitute(replacements))
            print "done"

    def _generate_peripheral_files(self, output_path=''):
        with open(self.peripheral_file_template_fname, 'r') as f:
            template_string = f.read()
        
        peripheral_header_fnames = []
        for p in self.peripherals:
            output_fname = self.name.lower() + "_" + p.name.lower() + ".h"
            output_fpath = os.path.join(output_path, output_fname)
            replacements = self._file_replacements(output_fname)
            replacements['PERIPHERAL'] = p.to_cpp();
        
            template = string.Template(template_string)
            with open(output_fpath, 'w') as f:
                print "Writing " + output_fpath + "...",
                f.write(template.safe_substitute(replacements))
                print "done"

            peripheral_header_fnames.append(output_fname)
        return peripheral_header_fnames
        
    def generate_header_files(self, output_path=''):
        fnames = self._generate_peripheral_files(output_path)
        return self._generate_device_file(fnames, output_path)



parser = argparse.ArgumentParser()
parser.add_argument("svd_file", help="SVD input file")
parser.add_argument("out_dir", help="Directory for generated files", default='')

args = parser.parse_args()

dev = Device.from_svdfile(args.svd_file, svd_defaults)

if (args.out_dir != ''):
    mkpath(args.out_dir)
dev.generate_header_files(args.out_dir)

