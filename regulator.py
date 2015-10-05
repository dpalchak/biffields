#!/usr/bin/env python

import xml.etree.ElementTree as ET
from copy import deepcopy
import string
import re

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
                        
INDENT = " " * 4

def indent(s, count=1):
    prefix = INDENT * count
    lines = s.split('\n')
    for i in range(len(lines)):
        if lines[i] != '':
            lines[i] = prefix + lines[i]
    return '\n'.join(lines)

def include_guard_token(filename):
    filename = filename.replace(".h", "")
    return "_%s_H_" % filename

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
    return name.lower().capitalize()

def make_instance_name(name):
    return name.lower()

class Field(object):
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
        
    def cpp_declaration(self):
        template_fname = 'field_declaration.ht'
        with open(template_fname, 'r') as f:
            template_string = f.read()
        
        replacements = dict(FIELD_NAME=make_instance_name(self.name),
        					MSB=self.msb, 
                            LSB=self.lsb,
                            FIELD_TYPE=self.type,
                            FIELD_DESCRIPTION=self.description)
        template = string.Template(template_string)
        return template.safe_substitute(replacements)
        

class Register(object):
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
        
    def cpp_declaration(self):
        replacements = dict(REGISTER_NAME=make_instance_name(self.name),
                            DESCRIPTION=self.description,
                            OFFSET="0x%X" % self.offset,
                            ACCESS_MODE=self.access_mode,
                            STORAGE_TYPE=self.type,
                            RESET_VALUE="0x%X" % self.reset_value)
                            
        template_fname = 'register_declaration.ht'

        if (len(self.fields) == 1):
            fields = indent('SBF_NO_FIELDS')
        else:
            fields = indent("\n".join([field.cpp_declaration() for field in self.fields]))
        replacements['FIELDS'] = fields

        with open(template_fname, 'r') as f:
            template_string = f.read()        
        template = string.Template(template_string)
        return template.safe_substitute(replacements)
        

class Peripheral(object):
    cache = {}
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
            template = deepcopy(cls.cache[element.attrib['derivedFrom']])
            params['parent'] = element.attrib['derivedFrom']            
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
    
    def cpp_class_declaration(self, template_fname='peripheral_class_declaration.ht'):
        with open(template_fname, 'r') as f:
            template_string = f.read()

        replacements = dict(PERIPHERAL_TYPE=make_type_name(self.group_name)) 
        reg_map = dict([(r.offset, r) for r in self.registers])
        offsets = reg_map.keys()
        offsets.sort()
        current_offset = 0
        reg_decls = ""
        for target_offset in offsets:
            if current_offset < target_offset:
                # Add padding
                pad_byte_count = target_offset - current_offset
                if (pad_byte_count % 4) != 0:
                    raise RuntimeError('Unaligned padding required')
                pad_word_count = pad_byte_count / 4
                if pad_word_count > 1:
                    reg_decls += indent("//  Alignment padding\nSBF_REGISTER_RSVD(__padding_0x%X_to_0x%X, uint32_t, %u)\n" % \
                        (current_offset, target_offset - 4, pad_word_count))
                else:
                    reg_decls += indent("//  Alignment padding\nSBF_REGISTER_RSVD(__padding_0x%X, uint32_t, 1)\n" % \
                        (current_offset))
                current_offset += pad_byte_count
            reg = reg_map[target_offset]
            reg_decls += indent(reg.cpp_declaration()) + "\n"
            current_offset += (reg.size / 8)
        replacements['REGISTER_DECLARATIONS'] = reg_decls        

        template = string.Template(template_string)
        return template.safe_substitute(replacements)
        
    def cpp_instance_declaration(self, template_fname='peripheral_instance_declaration.ht'):
        with open(template_fname, 'r') as f:
            template_string = f.read()

        replacements = dict(PERIPHERAL_TYPE=make_type_name(self.group_name))
        replacements['PERIPHERAL_NAME'] = make_instance_name(self.name)
        replacements['PERIPHERAL_NAME_CAPITALIZED'] = make_instance_name(self.name).capitalize()
        replacements['BASE_ADDRESS'] = "0x%08X" % (self.base_address)
        replacements['DESCRIPTION'] = self.description
        template = string.Template(template_string)
        return template.safe_substitute(replacements)
        



class Device(object):
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
        classes = {}
        for p in peripherals:
            if '' == getattr(p, 'parent', ''):
                classes[p.group_name] = p
        params['peripherals'] = peripherals
        params['peripheral_classes'] = classes
        name = params.pop('name')
        return Device(name, **params)
        
    @classmethod
    def from_svdfile(cls, svd_fname, defaults=None):
        root = ET.parse(svd_fname).getroot()
        return Device.from_svd(root.iter('device').next(), defaults)
    
    def __repr__(self):
        return "<Device %s>" % self.name
        
    def cpp_declaration(self, template_fname='device_declaration.ht'):
        with open(template_fname, 'r') as f:
            template_string = f.read()
        
        replacements = dict()
        replacements['NAMESPACE_START'] = "namespace %s {" % make_type_name(self.name)
        replacements['NAMESPACE_END'] = "} // namespace %s" % make_type_name(self.name)
   
        replacements['INCLUDE_GUARD_TOKEN'] = include_guard_token(self.name)  
        pc_dec = '\n'.join([p.cpp_class_declaration() for p in 
                            sorted(self.peripheral_classes.values(), key=lambda p: p.name)])
        replacements['PERIPHERAL_CLASS_DECLARATIONS'] = pc_dec            
        p_dec = '\n'.join([p.cpp_instance_declaration() for p in 
                           sorted(self.peripherals, key=lambda p: p.name)])
        replacements['PERIPHERAL_DECLARATIONS'] = p_dec
    
        template = string.Template(template_string)
        return template.safe_substitute(replacements)
            

    def cpp_definition(self, template_fname):
        pass

    def generate_header_file(self, fname=None):
        if fname is None:
            fname = self.name.lower() + ".h"
        with open(fname, 'w') as f:
            f.write(self.cpp_declaration())
        

dev = Device.from_svdfile('SVD/STM32L4x6.svd', svd_defaults)
dev.generate_header_file('generated/stm32l4x6.h')



