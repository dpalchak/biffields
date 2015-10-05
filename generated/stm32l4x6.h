#ifndef _STM32L4x6_H_
#define _STM32L4x6_H_

//#include "data/sbf/sbf_register.h"

namespace Stm32l4x6 {


// Adc registers
struct Adc {
    // ADC Common status register
    // Offset +0x0
    SBF_REGISTER_RO(csr, uint32_t, 0x0,
        SBF_FIELD(jqovf_slv, 26:26, bool) 		// Injected Context Queue Overflow flag of the slave ADC
        SBF_FIELD(awd3_slv, 25:25, bool) 		// Analog watchdog 3 flag of the slave ADC
        SBF_FIELD(awd2_slv, 24:24, bool) 		// Analog watchdog 2 flag of the slave ADC
        SBF_FIELD(awd1_slv, 23:23, bool) 		// Analog watchdog 1 flag of the slave ADC
        SBF_FIELD(jeos_slv, 22:22, bool) 		// End of injected sequence flag of the slave ADC
        SBF_FIELD(jeoc_slv, 21:21, bool) 		// End of injected conversion flag of the slave ADC
        SBF_FIELD(ovr_slv, 20:20, bool) 		// Overrun flag of the slave ADC
        SBF_FIELD(eos_slv, 19:19, bool) 		// End of regular sequence flag of the slave ADC
        SBF_FIELD(eoc_slv, 18:18, bool) 		// End of regular conversion of the slave ADC
        SBF_FIELD(eosmp_slv, 17:17, bool) 		// EOSMP_SLV
        SBF_FIELD(adrdy_slv, 16:16, bool) 		// ADRDY_SLV
        SBF_FIELD(jqovf_mst, 10:10, bool) 		// JQOVF_MST
        SBF_FIELD(awd3_mst, 9:9, bool) 		// AWD3_MST
        SBF_FIELD(awd2_mst, 8:8, bool) 		// AWD2_MST
        SBF_FIELD(awd1_mst, 7:7, bool) 		// AWD1_MST
        SBF_FIELD(jeos_mst, 6:6, bool) 		// JEOS_MST
        SBF_FIELD(jeoc_mst, 5:5, bool) 		// JEOC_MST
        SBF_FIELD(ovr_mst, 4:4, bool) 		// OVR_MST
        SBF_FIELD(eos_mst, 3:3, bool) 		// EOS_MST
        SBF_FIELD(eoc_mst, 2:2, bool) 		// EOC_MST
        SBF_FIELD(eosmp_mst, 1:1, bool) 		// EOSMP_MST
        SBF_FIELD(addrdy_mst, 0:0, bool) 		// ADDRDY_MST
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x4, uint32_t, 1)
    // ADC common control register
    // Offset +0x8
    SBF_REGISTER_RW(ccr, uint32_t, 0x0,
        SBF_FIELD(vbaten, 24:24, bool) 		// VBAT enable
        SBF_FIELD(tsen, 23:23, bool) 		// Temperature sensor enable
        SBF_FIELD(vrefen, 22:22, bool) 		// VREFINT enable
        SBF_FIELD(ckmode, 17:16, unsigned) 		// ADC clock mode
        SBF_FIELD(mdma, 15:14, unsigned) 		// Direct memory access mode for multi ADC mode
        SBF_FIELD(dmacfg, 13:13, bool) 		// DMA configuration (for multi-ADC mode)
        SBF_FIELD(delay, 11:8, unsigned) 		// Delay between 2 sampling phases
        SBF_FIELD(mult, 4:0, unsigned) 		// Multi ADC mode selection
    )
    // ADC common regular data register for dual and triple modes
    // Offset +0xC
    SBF_REGISTER_RO(cdr, uint32_t, 0x0,
        SBF_FIELD(rdata_slv, 31:16, unsigned) 		// Regular data of the slave ADC
        SBF_FIELD(rdata_mst, 15:0, unsigned) 		// Regular data of the master ADC
    )

}; // Adc registers


// Aes registers
struct Aes {
    // control register
    // Offset +0x0
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(dmaouten, 12:12, bool) 		// Enable DMA management of data output phase
        SBF_FIELD(dmainen, 11:11, bool) 		// Enable DMA management of data input phase
        SBF_FIELD(errie, 10:10, bool) 		// Error interrupt enable
        SBF_FIELD(ccfie, 9:9, bool) 		// CCF flag interrupt enable
        SBF_FIELD(errc, 8:8, bool) 		// Error clear
        SBF_FIELD(ccfc, 7:7, bool) 		// Computation Complete Flag Clear
        SBF_FIELD(chmod, 6:5, unsigned) 		// AES chaining mode
        SBF_FIELD(mode, 4:3, unsigned) 		// AES operating mode
        SBF_FIELD(datatype, 2:1, unsigned) 		// Data type selection (for data in and data out to/from the cryptographic block)
        SBF_FIELD(en, 0:0, bool) 		// AES enable
    )
    // status register
    // Offset +0x4
    SBF_REGISTER_RO(sr, uint32_t, 0x0,
        SBF_FIELD(wrerr, 2:2, bool) 		// Write error flag
        SBF_FIELD(rderr, 1:1, bool) 		// Read error flag
        SBF_FIELD(ccf, 0:0, bool) 		// Computation complete flag
    )
    // data input register
    // Offset +0x8
    SBF_REGISTER_RW(dinr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // data output register
    // Offset +0xC
    SBF_REGISTER_RO(doutr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // key register 0
    // Offset +0x10
    SBF_REGISTER_RW(keyr0, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // key register 1
    // Offset +0x14
    SBF_REGISTER_RW(keyr1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // key register 2
    // Offset +0x18
    SBF_REGISTER_RW(keyr2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // key register 3
    // Offset +0x1C
    SBF_REGISTER_RW(keyr3, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // initialization vector register 0
    // Offset +0x20
    SBF_REGISTER_RW(ivr0, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // initialization vector register 1
    // Offset +0x24
    SBF_REGISTER_RW(ivr1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // initialization vector register 2
    // Offset +0x28
    SBF_REGISTER_RW(ivr2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // initialization vector register 3
    // Offset +0x2C
    SBF_REGISTER_RW(ivr3, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Aes registers


// Can registers
struct Can {
    // master control register
    // Offset +0x0
    SBF_REGISTER_RW(mcr, uint32_t, 0x10002,
        SBF_FIELD(dbf, 16:16, bool) 		// DBF
        SBF_FIELD(reset, 15:15, bool) 		// RESET
        SBF_FIELD(ttcm, 7:7, bool) 		// TTCM
        SBF_FIELD(abom, 6:6, bool) 		// ABOM
        SBF_FIELD(awum, 5:5, bool) 		// AWUM
        SBF_FIELD(nart, 4:4, bool) 		// NART
        SBF_FIELD(rflm, 3:3, bool) 		// RFLM
        SBF_FIELD(txfp, 2:2, bool) 		// TXFP
        SBF_FIELD(sleep, 1:1, bool) 		// SLEEP
        SBF_FIELD(inrq, 0:0, bool) 		// INRQ
    )
    // master status register
    // Offset +0x4
    SBF_REGISTER_RW(msr, uint32_t, 0xC02,
        SBF_FIELD(rx, 11:11, bool) 		// RX
        SBF_FIELD(samp, 10:10, bool) 		// SAMP
        SBF_FIELD(rxm, 9:9, bool) 		// RXM
        SBF_FIELD(txm, 8:8, bool) 		// TXM
        SBF_FIELD(slaki, 4:4, bool) 		// SLAKI
        SBF_FIELD(wkui, 3:3, bool) 		// WKUI
        SBF_FIELD(erri, 2:2, bool) 		// ERRI
        SBF_FIELD(slak, 1:1, bool) 		// SLAK
        SBF_FIELD(inak, 0:0, bool) 		// INAK
    )
    // transmit status register
    // Offset +0x8
    SBF_REGISTER_RW(tsr, uint32_t, 0x1C000000,
        SBF_FIELD(low2, 31:31, bool) 		// Lowest priority flag for mailbox 2
        SBF_FIELD(low1, 30:30, bool) 		// Lowest priority flag for mailbox 1
        SBF_FIELD(low0, 29:29, bool) 		// Lowest priority flag for mailbox 0
        SBF_FIELD(tme2, 28:28, bool) 		// Lowest priority flag for mailbox 2
        SBF_FIELD(tme1, 27:27, bool) 		// Lowest priority flag for mailbox 1
        SBF_FIELD(tme0, 26:26, bool) 		// Lowest priority flag for mailbox 0
        SBF_FIELD(code, 25:24, unsigned) 		// CODE
        SBF_FIELD(abrq2, 23:23, bool) 		// ABRQ2
        SBF_FIELD(terr2, 19:19, bool) 		// TERR2
        SBF_FIELD(alst2, 18:18, bool) 		// ALST2
        SBF_FIELD(txok2, 17:17, bool) 		// TXOK2
        SBF_FIELD(rqcp2, 16:16, bool) 		// RQCP2
        SBF_FIELD(abrq1, 15:15, bool) 		// ABRQ1
        SBF_FIELD(terr1, 11:11, bool) 		// TERR1
        SBF_FIELD(alst1, 10:10, bool) 		// ALST1
        SBF_FIELD(txok1, 9:9, bool) 		// TXOK1
        SBF_FIELD(rqcp1, 8:8, bool) 		// RQCP1
        SBF_FIELD(abrq0, 7:7, bool) 		// ABRQ0
        SBF_FIELD(terr0, 3:3, bool) 		// TERR0
        SBF_FIELD(alst0, 2:2, bool) 		// ALST0
        SBF_FIELD(txok0, 1:1, bool) 		// TXOK0
        SBF_FIELD(rqcp0, 0:0, bool) 		// RQCP0
    )
    // receive FIFO 0 register
    // Offset +0xC
    SBF_REGISTER_RW(rf0r, uint32_t, 0x0,
        SBF_FIELD(rfom0, 5:5, bool) 		// RFOM0
        SBF_FIELD(fovr0, 4:4, bool) 		// FOVR0
        SBF_FIELD(full0, 3:3, bool) 		// FULL0
        SBF_FIELD(fmp0, 1:0, unsigned) 		// FMP0
    )
    // receive FIFO 1 register
    // Offset +0x10
    SBF_REGISTER_RW(rf1r, uint32_t, 0x0,
        SBF_FIELD(rfom1, 5:5, bool) 		// RFOM1
        SBF_FIELD(fovr1, 4:4, bool) 		// FOVR1
        SBF_FIELD(full1, 3:3, bool) 		// FULL1
        SBF_FIELD(fmp1, 1:0, unsigned) 		// FMP1
    )
    // interrupt enable register
    // Offset +0x14
    SBF_REGISTER_RW(ier, uint32_t, 0x0,
        SBF_FIELD(slkie, 17:17, bool) 		// SLKIE
        SBF_FIELD(wkuie, 16:16, bool) 		// WKUIE
        SBF_FIELD(errie, 15:15, bool) 		// ERRIE
        SBF_FIELD(lecie, 11:11, bool) 		// LECIE
        SBF_FIELD(bofie, 10:10, bool) 		// BOFIE
        SBF_FIELD(epvie, 9:9, bool) 		// EPVIE
        SBF_FIELD(ewgie, 8:8, bool) 		// EWGIE
        SBF_FIELD(fovie1, 6:6, bool) 		// FOVIE1
        SBF_FIELD(ffie1, 5:5, bool) 		// FFIE1
        SBF_FIELD(fmpie1, 4:4, bool) 		// FMPIE1
        SBF_FIELD(fovie0, 3:3, bool) 		// FOVIE0
        SBF_FIELD(ffie0, 2:2, bool) 		// FFIE0
        SBF_FIELD(fmpie0, 1:1, bool) 		// FMPIE0
        SBF_FIELD(tmeie, 0:0, bool) 		// TMEIE
    )
    // interrupt enable register
    // Offset +0x18
    SBF_REGISTER_RW(esr, uint32_t, 0x0,
        SBF_FIELD(rec, 31:24, unsigned) 		// REC
        SBF_FIELD(tec, 23:16, unsigned) 		// TEC
        SBF_FIELD(lec, 6:4, unsigned) 		// LEC
        SBF_FIELD(boff, 2:2, bool) 		// BOFF
        SBF_FIELD(epvf, 1:1, bool) 		// EPVF
        SBF_FIELD(ewgf, 0:0, bool) 		// EWGF
    )
    // bit timing register
    // Offset +0x1C
    SBF_REGISTER_RW(btr, uint32_t, 0x0,
        SBF_FIELD(silm, 31:31, bool) 		// SILM
        SBF_FIELD(lbkm, 30:30, bool) 		// LBKM
        SBF_FIELD(sjw, 25:24, unsigned) 		// SJW
        SBF_FIELD(ts2, 22:20, unsigned) 		// TS2
        SBF_FIELD(ts1, 19:16, unsigned) 		// TS1
        SBF_FIELD(brp, 9:0, unsigned) 		// BRP
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x20_to_0x17C, uint32_t, 88)
    // TX mailbox identifier register
    // Offset +0x180
    SBF_REGISTER_RW(ti0r, uint32_t, 0x0,
        SBF_FIELD(stid, 31:21, unsigned) 		// STID
        SBF_FIELD(exid, 20:3, unsigned) 		// EXID
        SBF_FIELD(ide, 2:2, bool) 		// IDE
        SBF_FIELD(rtr, 1:1, bool) 		// RTR
        SBF_FIELD(txrq, 0:0, bool) 		// TXRQ
    )
    // mailbox data length control and time stamp register
    // Offset +0x184
    SBF_REGISTER_RW(tdt0r, uint32_t, 0x0,
        SBF_FIELD(time, 31:16, unsigned) 		// TIME
        SBF_FIELD(tgt, 8:8, bool) 		// TGT
        SBF_FIELD(dlc, 3:0, unsigned) 		// DLC
    )
    // mailbox data low register
    // Offset +0x188
    SBF_REGISTER_RW(tdl0r, uint32_t, 0x0,
        SBF_FIELD(data3, 31:24, unsigned) 		// DATA3
        SBF_FIELD(data2, 23:16, unsigned) 		// DATA2
        SBF_FIELD(data1, 15:8, unsigned) 		// DATA1
        SBF_FIELD(data0, 7:0, unsigned) 		// DATA0
    )
    // mailbox data high register
    // Offset +0x18C
    SBF_REGISTER_RW(tdh0r, uint32_t, 0x0,
        SBF_FIELD(data7, 31:24, unsigned) 		// DATA7
        SBF_FIELD(data6, 23:16, unsigned) 		// DATA6
        SBF_FIELD(data5, 15:8, unsigned) 		// DATA5
        SBF_FIELD(data4, 7:0, unsigned) 		// DATA4
    )
    // mailbox identifier register
    // Offset +0x190
    SBF_REGISTER_RW(ti1r, uint32_t, 0x0,
        SBF_FIELD(stid, 31:21, unsigned) 		// STID
        SBF_FIELD(exid, 20:3, unsigned) 		// EXID
        SBF_FIELD(ide, 2:2, bool) 		// IDE
        SBF_FIELD(rtr, 1:1, bool) 		// RTR
        SBF_FIELD(txrq, 0:0, bool) 		// TXRQ
    )
    // mailbox data length control and time stamp register
    // Offset +0x194
    SBF_REGISTER_RW(tdt1r, uint32_t, 0x0,
        SBF_FIELD(time, 31:16, unsigned) 		// TIME
        SBF_FIELD(tgt, 8:8, bool) 		// TGT
        SBF_FIELD(dlc, 3:0, unsigned) 		// DLC
    )
    // mailbox data low register
    // Offset +0x198
    SBF_REGISTER_RW(tdl1r, uint32_t, 0x0,
        SBF_FIELD(data3, 31:24, unsigned) 		// DATA3
        SBF_FIELD(data2, 23:16, unsigned) 		// DATA2
        SBF_FIELD(data1, 15:8, unsigned) 		// DATA1
        SBF_FIELD(data0, 7:0, unsigned) 		// DATA0
    )
    // mailbox data high register
    // Offset +0x19C
    SBF_REGISTER_RW(tdh1r, uint32_t, 0x0,
        SBF_FIELD(data7, 31:24, unsigned) 		// DATA7
        SBF_FIELD(data6, 23:16, unsigned) 		// DATA6
        SBF_FIELD(data5, 15:8, unsigned) 		// DATA5
        SBF_FIELD(data4, 7:0, unsigned) 		// DATA4
    )
    // mailbox identifier register
    // Offset +0x1A0
    SBF_REGISTER_RW(ti2r, uint32_t, 0x0,
        SBF_FIELD(stid, 31:21, unsigned) 		// STID
        SBF_FIELD(exid, 20:3, unsigned) 		// EXID
        SBF_FIELD(ide, 2:2, bool) 		// IDE
        SBF_FIELD(rtr, 1:1, bool) 		// RTR
        SBF_FIELD(txrq, 0:0, bool) 		// TXRQ
    )
    // mailbox data length control and time stamp register
    // Offset +0x1A4
    SBF_REGISTER_RW(tdt2r, uint32_t, 0x0,
        SBF_FIELD(time, 31:16, unsigned) 		// TIME
        SBF_FIELD(tgt, 8:8, bool) 		// TGT
        SBF_FIELD(dlc, 3:0, unsigned) 		// DLC
    )
    // mailbox data low register
    // Offset +0x1A8
    SBF_REGISTER_RW(tdl2r, uint32_t, 0x0,
        SBF_FIELD(data3, 31:24, unsigned) 		// DATA3
        SBF_FIELD(data2, 23:16, unsigned) 		// DATA2
        SBF_FIELD(data1, 15:8, unsigned) 		// DATA1
        SBF_FIELD(data0, 7:0, unsigned) 		// DATA0
    )
    // mailbox data high register
    // Offset +0x1AC
    SBF_REGISTER_RW(tdh2r, uint32_t, 0x0,
        SBF_FIELD(data7, 31:24, unsigned) 		// DATA7
        SBF_FIELD(data6, 23:16, unsigned) 		// DATA6
        SBF_FIELD(data5, 15:8, unsigned) 		// DATA5
        SBF_FIELD(data4, 7:0, unsigned) 		// DATA4
    )
    // receive FIFO mailbox identifier register
    // Offset +0x1B0
    SBF_REGISTER_RO(ri0r, uint32_t, 0x0,
        SBF_FIELD(stid, 31:21, unsigned) 		// STID
        SBF_FIELD(exid, 20:3, unsigned) 		// EXID
        SBF_FIELD(ide, 2:2, bool) 		// IDE
        SBF_FIELD(rtr, 1:1, bool) 		// RTR
    )
    // mailbox data high register
    // Offset +0x1B4
    SBF_REGISTER_RO(rdt0r, uint32_t, 0x0,
        SBF_FIELD(time, 31:16, unsigned) 		// TIME
        SBF_FIELD(fmi, 15:8, unsigned) 		// FMI
        SBF_FIELD(dlc, 3:0, unsigned) 		// DLC
    )
    // mailbox data high register
    // Offset +0x1B8
    SBF_REGISTER_RO(rdl0r, uint32_t, 0x0,
        SBF_FIELD(data3, 31:24, unsigned) 		// DATA3
        SBF_FIELD(data2, 23:16, unsigned) 		// DATA2
        SBF_FIELD(data1, 15:8, unsigned) 		// DATA1
        SBF_FIELD(data0, 7:0, unsigned) 		// DATA0
    )
    // receive FIFO mailbox data high register
    // Offset +0x1BC
    SBF_REGISTER_RO(rdh0r, uint32_t, 0x0,
        SBF_FIELD(data7, 31:24, unsigned) 		// DATA7
        SBF_FIELD(data6, 23:16, unsigned) 		// DATA6
        SBF_FIELD(data5, 15:8, unsigned) 		// DATA5
        SBF_FIELD(data4, 7:0, unsigned) 		// DATA4
    )
    // mailbox data high register
    // Offset +0x1C0
    SBF_REGISTER_RO(ri1r, uint32_t, 0x0,
        SBF_FIELD(stid, 31:21, unsigned) 		// STID
        SBF_FIELD(exid, 20:3, unsigned) 		// EXID
        SBF_FIELD(ide, 2:2, bool) 		// IDE
        SBF_FIELD(rtr, 1:1, bool) 		// RTR
    )
    // mailbox data high register
    // Offset +0x1C4
    SBF_REGISTER_RO(rdt1r, uint32_t, 0x0,
        SBF_FIELD(time, 31:16, unsigned) 		// TIME
        SBF_FIELD(fmi, 15:8, unsigned) 		// FMI
        SBF_FIELD(dlc, 3:0, unsigned) 		// DLC
    )
    // mailbox data high register
    // Offset +0x1C8
    SBF_REGISTER_RO(rdl1r, uint32_t, 0x0,
        SBF_FIELD(data3, 31:24, unsigned) 		// DATA3
        SBF_FIELD(data2, 23:16, unsigned) 		// DATA2
        SBF_FIELD(data1, 15:8, unsigned) 		// DATA1
        SBF_FIELD(data0, 7:0, unsigned) 		// DATA0
    )
    // mailbox data high register
    // Offset +0x1CC
    SBF_REGISTER_RO(rdh1r, uint32_t, 0x0,
        SBF_FIELD(data7, 31:24, unsigned) 		// DATA7
        SBF_FIELD(data6, 23:16, unsigned) 		// DATA6
        SBF_FIELD(data5, 15:8, unsigned) 		// DATA5
        SBF_FIELD(data4, 7:0, unsigned) 		// DATA4
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x1D0_to_0x23C, uint32_t, 28)
    // Filter bank 0 register 1
    // Offset +0x240
    SBF_REGISTER_RW(f0r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 0 register 2
    // Offset +0x244
    SBF_REGISTER_RW(f0r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 1 register 1
    // Offset +0x248
    SBF_REGISTER_RW(f1r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 1 register 2
    // Offset +0x24C
    SBF_REGISTER_RW(f1r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 2 register 1
    // Offset +0x250
    SBF_REGISTER_RW(f2r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 2 register 2
    // Offset +0x254
    SBF_REGISTER_RW(f2r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 3 register 1
    // Offset +0x258
    SBF_REGISTER_RW(f3r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 3 register 2
    // Offset +0x25C
    SBF_REGISTER_RW(f3r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 4 register 1
    // Offset +0x260
    SBF_REGISTER_RW(f4r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 4 register 2
    // Offset +0x264
    SBF_REGISTER_RW(f4r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 5 register 1
    // Offset +0x268
    SBF_REGISTER_RW(f5r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 5 register 2
    // Offset +0x26C
    SBF_REGISTER_RW(f5r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 6 register 1
    // Offset +0x270
    SBF_REGISTER_RW(f6r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 6 register 2
    // Offset +0x274
    SBF_REGISTER_RW(f6r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 7 register 1
    // Offset +0x278
    SBF_REGISTER_RW(f7r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 7 register 2
    // Offset +0x27C
    SBF_REGISTER_RW(f7r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 8 register 1
    // Offset +0x280
    SBF_REGISTER_RW(f8r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 8 register 2
    // Offset +0x284
    SBF_REGISTER_RW(f8r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 9 register 1
    // Offset +0x288
    SBF_REGISTER_RW(f9r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 9 register 2
    // Offset +0x28C
    SBF_REGISTER_RW(f9r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 10 register 1
    // Offset +0x290
    SBF_REGISTER_RW(f10r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 10 register 2
    // Offset +0x294
    SBF_REGISTER_RW(f10r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 11 register 1
    // Offset +0x298
    SBF_REGISTER_RW(f11r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 11 register 2
    // Offset +0x29C
    SBF_REGISTER_RW(f11r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 4 register 1
    // Offset +0x2A0
    SBF_REGISTER_RW(f12r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 12 register 2
    // Offset +0x2A4
    SBF_REGISTER_RW(f12r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 13 register 1
    // Offset +0x2A8
    SBF_REGISTER_RW(f13r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 13 register 2
    // Offset +0x2AC
    SBF_REGISTER_RW(f13r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 14 register 1
    // Offset +0x2B0
    SBF_REGISTER_RW(f14r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 14 register 2
    // Offset +0x2B4
    SBF_REGISTER_RW(f14r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 15 register 1
    // Offset +0x2B8
    SBF_REGISTER_RW(f15r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 15 register 2
    // Offset +0x2BC
    SBF_REGISTER_RW(f15r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 16 register 1
    // Offset +0x2C0
    SBF_REGISTER_RW(f16r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 16 register 2
    // Offset +0x2C4
    SBF_REGISTER_RW(f16r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 17 register 1
    // Offset +0x2C8
    SBF_REGISTER_RW(f17r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 17 register 2
    // Offset +0x2CC
    SBF_REGISTER_RW(f17r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 18 register 1
    // Offset +0x2D0
    SBF_REGISTER_RW(f18r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 18 register 2
    // Offset +0x2D4
    SBF_REGISTER_RW(f18r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 19 register 1
    // Offset +0x2D8
    SBF_REGISTER_RW(f19r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 19 register 2
    // Offset +0x2DC
    SBF_REGISTER_RW(f19r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 20 register 1
    // Offset +0x2E0
    SBF_REGISTER_RW(f20r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 20 register 2
    // Offset +0x2E4
    SBF_REGISTER_RW(f20r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 21 register 1
    // Offset +0x2E8
    SBF_REGISTER_RW(f21r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 21 register 2
    // Offset +0x2EC
    SBF_REGISTER_RW(f21r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 22 register 1
    // Offset +0x2F0
    SBF_REGISTER_RW(f22r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 22 register 2
    // Offset +0x2F4
    SBF_REGISTER_RW(f22r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 23 register 1
    // Offset +0x2F8
    SBF_REGISTER_RW(f23r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 23 register 2
    // Offset +0x2FC
    SBF_REGISTER_RW(f23r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 24 register 1
    // Offset +0x300
    SBF_REGISTER_RW(f24r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 24 register 2
    // Offset +0x304
    SBF_REGISTER_RW(f24r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 25 register 1
    // Offset +0x308
    SBF_REGISTER_RW(f25r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 25 register 2
    // Offset +0x30C
    SBF_REGISTER_RW(f25r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 26 register 1
    // Offset +0x310
    SBF_REGISTER_RW(f26r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 26 register 2
    // Offset +0x314
    SBF_REGISTER_RW(f26r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 27 register 1
    // Offset +0x318
    SBF_REGISTER_RW(f27r1, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )
    // Filter bank 27 register 2
    // Offset +0x31C
    SBF_REGISTER_RW(f27r2, uint32_t, 0x0,
        SBF_FIELD(fb31, 31:31, bool) 		// Filter bits
        SBF_FIELD(fb30, 30:30, bool) 		// Filter bits
        SBF_FIELD(fb29, 29:29, bool) 		// Filter bits
        SBF_FIELD(fb28, 28:28, bool) 		// Filter bits
        SBF_FIELD(fb27, 27:27, bool) 		// Filter bits
        SBF_FIELD(fb26, 26:26, bool) 		// Filter bits
        SBF_FIELD(fb25, 25:25, bool) 		// Filter bits
        SBF_FIELD(fb24, 24:24, bool) 		// Filter bits
        SBF_FIELD(fb23, 23:23, bool) 		// Filter bits
        SBF_FIELD(fb22, 22:22, bool) 		// Filter bits
        SBF_FIELD(fb21, 21:21, bool) 		// Filter bits
        SBF_FIELD(fb20, 20:20, bool) 		// Filter bits
        SBF_FIELD(fb19, 19:19, bool) 		// Filter bits
        SBF_FIELD(fb18, 18:18, bool) 		// Filter bits
        SBF_FIELD(fb17, 17:17, bool) 		// Filter bits
        SBF_FIELD(fb16, 16:16, bool) 		// Filter bits
        SBF_FIELD(fb15, 15:15, bool) 		// Filter bits
        SBF_FIELD(fb14, 14:14, bool) 		// Filter bits
        SBF_FIELD(fb13, 13:13, bool) 		// Filter bits
        SBF_FIELD(fb12, 12:12, bool) 		// Filter bits
        SBF_FIELD(fb11, 11:11, bool) 		// Filter bits
        SBF_FIELD(fb10, 10:10, bool) 		// Filter bits
        SBF_FIELD(fb9, 9:9, bool) 		// Filter bits
        SBF_FIELD(fb8, 8:8, bool) 		// Filter bits
        SBF_FIELD(fb7, 7:7, bool) 		// Filter bits
        SBF_FIELD(fb6, 6:6, bool) 		// Filter bits
        SBF_FIELD(fb5, 5:5, bool) 		// Filter bits
        SBF_FIELD(fb4, 4:4, bool) 		// Filter bits
        SBF_FIELD(fb3, 3:3, bool) 		// Filter bits
        SBF_FIELD(fb2, 2:2, bool) 		// Filter bits
        SBF_FIELD(fb1, 1:1, bool) 		// Filter bits
        SBF_FIELD(fb0, 0:0, bool) 		// Filter bits
    )

}; // Can registers


// Comp registers
struct Comp {
    // Comparator 1 control and status register
    // Offset +0x0
    SBF_REGISTER_RW(comp1_csr, uint32_t, 0x0,
        SBF_FIELD(comp1_lock, 31:31, bool) 		// COMP1_CSR register lock bit
        SBF_FIELD(comp1_value, 30:30, bool) 		// Comparator 1 output status bit
        SBF_FIELD(comp1_scalen, 23:23, bool) 		// Voltage scaler enable bit
        SBF_FIELD(comp1_brgen, 22:22, bool) 		// Scaler bridge enable
        SBF_FIELD(comp1_blanking, 20:18, unsigned) 		// Comparator 1 blanking source selection bits
        SBF_FIELD(comp1_hyst, 17:16, unsigned) 		// Comparator 1 hysteresis selection bits
        SBF_FIELD(comp1_polarity, 15:15, bool) 		// Comparator 1 polarity selection bit
        SBF_FIELD(comp1_inpsel, 7:7, bool) 		// Comparator1 input plus selection bit
        SBF_FIELD(comp1_inmsel, 6:4, unsigned) 		// Comparator 1 Input Minus connection configuration bit
        SBF_FIELD(comp1_pwrmode, 3:2, unsigned) 		// Power Mode of the comparator 1
        SBF_FIELD(comp1_en, 0:0, bool) 		// Comparator 1 enable bit
    )
    // Comparator 2 control and status register
    // Offset +0x4
    SBF_REGISTER_RW(comp2_csr, uint32_t, 0x0,
        SBF_FIELD(comp2_lock, 31:31, bool) 		// COMP2_CSR register lock bit
        SBF_FIELD(comp2_value, 30:30, bool) 		// Comparator 2 output status bit
        SBF_FIELD(comp2_scalen, 23:23, bool) 		// Voltage scaler enable bit
        SBF_FIELD(comp2_brgen, 22:22, bool) 		// Scaler bridge enable
        SBF_FIELD(comp2_blanking, 20:18, unsigned) 		// Comparator 2 blanking source selection bits
        SBF_FIELD(comp2_hyst, 17:16, unsigned) 		// Comparator 2 hysteresis selection bits
        SBF_FIELD(comp2_polarity, 15:15, bool) 		// Comparator 2 polarity selection bit
        SBF_FIELD(comp2_winmode, 9:9, bool) 		// Windows mode selection bit
        SBF_FIELD(comp2_inpsel, 7:7, bool) 		// Comparator 2 Input Plus connection configuration bit
        SBF_FIELD(comp2_inmsel, 6:4, unsigned) 		// Comparator 2 Input Minus connection configuration bit
        SBF_FIELD(comp2_pwrmode, 3:2, unsigned) 		// Power Mode of the comparator 2
        SBF_FIELD(comp2_en, 0:0, bool) 		// Comparator 2 enable bit
    )

}; // Comp registers


// Crc registers
struct Crc {
    // Data register
    // Offset +0x0
    SBF_REGISTER_RW(dr, uint32_t, 0xFFFFFFFF,
        SBF_NO_FIELDS
    )
    // Independent data register
    // Offset +0x4
    SBF_REGISTER_RW(idr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Control register
    // Offset +0x8
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(rev_out, 7:7, bool) 		// Reverse output data
        SBF_FIELD(rev_in, 6:5, unsigned) 		// Reverse input data
        SBF_FIELD(polysize, 4:3, unsigned) 		// Polynomial size
        SBF_FIELD(reset, 0:0, bool) 		// RESET bit
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0xC, uint32_t, 1)
    // Initial CRC value
    // Offset +0x10
    SBF_REGISTER_RW(init, uint32_t, 0xFFFFFFFF,
        SBF_NO_FIELDS
    )
    // polynomial
    // Offset +0x14
    SBF_REGISTER_RW(pol, uint32_t, 0x4C11DB7,
        SBF_NO_FIELDS
    )

}; // Crc registers


// Dac registers
struct Dac {
    // control register
    // Offset +0x0
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(cen2, 30:30, bool) 		// DAC Channel 2 calibration enable
        SBF_FIELD(dmaudrie2, 29:29, bool) 		// DAC channel2 DMA underrun interrupt enable
        SBF_FIELD(dmaen2, 28:28, bool) 		// DAC channel2 DMA enable
        SBF_FIELD(mamp2, 27:24, unsigned) 		// DAC channel2 mask/amplitude selector
        SBF_FIELD(wave2, 23:22, unsigned) 		// DAC channel2 noise/triangle wave generation enable
        SBF_FIELD(tsel2, 21:19, unsigned) 		// DAC channel2 trigger selection
        SBF_FIELD(ten2, 18:18, bool) 		// DAC channel2 trigger enable
        SBF_FIELD(en2, 16:16, bool) 		// DAC channel2 enable
        SBF_FIELD(cen1, 14:14, bool) 		// DAC Channel 1 calibration enable
        SBF_FIELD(dmaudrie1, 13:13, bool) 		// DAC channel1 DMA Underrun Interrupt enable
        SBF_FIELD(dmaen1, 12:12, bool) 		// DAC channel1 DMA enable
        SBF_FIELD(mamp1, 11:8, unsigned) 		// DAC channel1 mask/amplitude selector
        SBF_FIELD(wave1, 7:6, unsigned) 		// DAC channel1 noise/triangle wave generation enable
        SBF_FIELD(tsel1, 5:3, unsigned) 		// DAC channel1 trigger selection
        SBF_FIELD(ten1, 2:2, bool) 		// DAC channel1 trigger enable
        SBF_FIELD(en1, 0:0, bool) 		// DAC channel1 enable
    )
    // software trigger register
    // Offset +0x4
    SBF_REGISTER_WO(swtrigr, uint32_t, 0x0,
        SBF_FIELD(swtrig2, 1:1, bool) 		// DAC channel2 software trigger
        SBF_FIELD(swtrig1, 0:0, bool) 		// DAC channel1 software trigger
    )
    // channel1 12-bit right-aligned data holding register
    // Offset +0x8
    SBF_REGISTER_RW(dhr12r1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel1 12-bit left-aligned data holding register
    // Offset +0xC
    SBF_REGISTER_RW(dhr12l1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel1 8-bit right-aligned data holding register
    // Offset +0x10
    SBF_REGISTER_RW(dhr8r1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel2 12-bit right aligned data holding register
    // Offset +0x14
    SBF_REGISTER_RW(dhr12r2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel2 12-bit left aligned data holding register
    // Offset +0x18
    SBF_REGISTER_RW(dhr12l2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel2 8-bit right-aligned data holding register
    // Offset +0x1C
    SBF_REGISTER_RW(dhr8r2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Dual DAC 12-bit right-aligned data holding register
    // Offset +0x20
    SBF_REGISTER_RW(dhr12rd, uint32_t, 0x0,
        SBF_FIELD(dacc2dhr, 27:16, unsigned) 		// DAC channel2 12-bit right-aligned data
        SBF_FIELD(dacc1dhr, 11:0, unsigned) 		// DAC channel1 12-bit right-aligned data
    )
    // DUAL DAC 12-bit left aligned data holding register
    // Offset +0x24
    SBF_REGISTER_RW(dhr12ld, uint32_t, 0x0,
        SBF_FIELD(dacc2dhr, 31:20, unsigned) 		// DAC channel2 12-bit left-aligned data
        SBF_FIELD(dacc1dhr, 15:4, unsigned) 		// DAC channel1 12-bit left-aligned data
    )
    // DUAL DAC 8-bit right aligned data holding register
    // Offset +0x28
    SBF_REGISTER_RW(dhr8rd, uint32_t, 0x0,
        SBF_FIELD(dacc2dhr, 15:8, unsigned) 		// DAC channel2 8-bit right-aligned data
        SBF_FIELD(dacc1dhr, 7:0, unsigned) 		// DAC channel1 8-bit right-aligned data
    )
    // channel1 data output register
    // Offset +0x2C
    SBF_REGISTER_RO(dor1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel2 data output register
    // Offset +0x30
    SBF_REGISTER_RO(dor2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // status register
    // Offset +0x34
    SBF_REGISTER_RW(sr, uint32_t, 0x0,
        SBF_FIELD(bwst2, 31:31, bool) 		// DAC Channel 2 busy writing sample time flag
        SBF_FIELD(cal_flag2, 30:30, bool) 		// DAC Channel 2 calibration offset status
        SBF_FIELD(dmaudr2, 29:29, bool) 		// DAC channel2 DMA underrun flag
        SBF_FIELD(bwst1, 15:15, bool) 		// DAC Channel 1 busy writing sample time flag
        SBF_FIELD(cal_flag1, 14:14, bool) 		// DAC Channel 1 calibration offset status
        SBF_FIELD(dmaudr1, 13:13, bool) 		// DAC channel1 DMA underrun flag
    )
    // calibration control register
    // Offset +0x38
    SBF_REGISTER_RW(ccr, uint32_t, 0x0,
        SBF_FIELD(otrim2, 20:16, unsigned) 		// DAC Channel 2 offset trimming value
        SBF_FIELD(otrim1, 4:0, unsigned) 		// DAC Channel 1 offset trimming value
    )
    // mode control register
    // Offset +0x3C
    SBF_REGISTER_RW(mcr, uint32_t, 0x0,
        SBF_FIELD(mode2, 18:16, unsigned) 		// DAC Channel 2 mode
        SBF_FIELD(mode1, 2:0, unsigned) 		// DAC Channel 1 mode
    )
    // Sample and Hold sample time register 1
    // Offset +0x40
    SBF_REGISTER_RW(shsr1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Sample and Hold sample time register 2
    // Offset +0x44
    SBF_REGISTER_RW(shsr2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Sample and Hold hold time register
    // Offset +0x48
    SBF_REGISTER_RW(shhr, uint32_t, 0x10001,
        SBF_FIELD(thold2, 25:16, unsigned) 		// DAC Channel 2 hold time
        SBF_FIELD(thold1, 9:0, unsigned) 		// DAC Channel 1 hold Time
    )
    // Sample and Hold refresh time register
    // Offset +0x4C
    SBF_REGISTER_RW(shrr, uint32_t, 0x1,
        SBF_FIELD(trefresh2, 23:16, unsigned) 		// DAC Channel 2 refresh Time
        SBF_FIELD(trefresh1, 7:0, unsigned) 		// DAC Channel 1 refresh Time
    )

}; // Dac registers


// Dbgmcu registers
struct Dbgmcu {
    // MCU Device ID Code Register
    // Offset +0x0
    SBF_REGISTER_RO(idcode, uint32_t, 0x0,
        SBF_FIELD(rev_id, 31:16, unsigned) 		// Revision Identifier
        SBF_FIELD(dev_id, 15:0, unsigned) 		// Device Identifier
    )
    // Debug MCU Configuration Register
    // Offset +0x4
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(trace_mode, 7:6, unsigned) 		// Trace pin assignment control
        SBF_FIELD(trace_ioen, 5:5, bool) 		// Trace pin assignment control
        SBF_FIELD(dbg_standby, 2:2, bool) 		// Debug Standby Mode
        SBF_FIELD(dbg_stop, 1:1, bool) 		// Debug Stop Mode
        SBF_FIELD(dbg_sleep, 0:0, bool) 		// Debug Sleep Mode
    )
    // APB Low Freeze Register 1
    // Offset +0x8
    SBF_REGISTER_RW(apb1_fzr1, uint32_t, 0x0,
        SBF_FIELD(dbg_lptimer_stop, 31:31, bool) 		// LPTIM1 counter stopped when core is halted
        SBF_FIELD(dbg_can_stop, 25:25, bool) 		// bxCAN stopped when core is halted
        SBF_FIELD(dbg_i2c3_stop, 23:23, bool) 		// I2C3 SMBUS timeout counter stopped when core is halted
        SBF_FIELD(dbg_i2c2_stop, 22:22, bool) 		// I2C2 SMBUS timeout mode stopped when core is halted
        SBF_FIELD(dbg_i2c1_stop, 21:21, bool) 		// I2C1 SMBUS timeout mode stopped when core is halted
        SBF_FIELD(dbg_iwdg_stop, 12:12, bool) 		// Debug Independent Wachdog stopped when Core is halted
        SBF_FIELD(dbg_wwdg_stop, 11:11, bool) 		// Debug Window Wachdog stopped when Core is halted
        SBF_FIELD(dbg_rtc_stop, 10:10, bool) 		// Debug RTC stopped when Core is halted
        SBF_FIELD(dbg_tim7_stop, 5:5, bool) 		// TIM7 counter stopped when core is halted
        SBF_FIELD(dbg_timer6_stop, 4:4, bool) 		// Debug Timer 6 stopped when Core is halted
        SBF_FIELD(dbg_tim5_stop, 3:3, bool) 		// TIM5 counter stopped when core is halted
        SBF_FIELD(dbg_tim4_stop, 2:2, bool) 		// TIM4 counter stopped when core is halted
        SBF_FIELD(dbg_tim3_stop, 1:1, bool) 		// TIM3 counter stopped when core is halted
        SBF_FIELD(dbg_timer2_stop, 0:0, bool) 		// Debug Timer 2 stopped when Core is halted
    )
    // APB Low Freeze Register 2
    // Offset +0xC
    SBF_REGISTER_RW(apb1_fzr2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // APB High Freeze Register
    // Offset +0x10
    SBF_REGISTER_RW(apb2_fzr, uint32_t, 0x0,
        SBF_FIELD(dbg_tim17_stop, 18:18, bool) 		// TIM17 counter stopped when core is halted
        SBF_FIELD(dbg_tim16_stop, 17:17, bool) 		// TIM16 counter stopped when core is halted
        SBF_FIELD(dbg_tim15_stop, 16:16, bool) 		// TIM15 counter stopped when core is halted
        SBF_FIELD(dbg_tim8_stop, 13:13, bool) 		// TIM8 counter stopped when core is halted
        SBF_FIELD(dbg_tim1_stop, 11:11, bool) 		// TIM1 counter stopped when core is halted
    )

}; // Dbgmcu registers


// Dfsdm registers
struct Dfsdm {
    // channel configuration y register
    // Offset +0x0
    SBF_REGISTER_RW(chcfg0r1, uint32_t, 0x0,
        SBF_FIELD(dfsdmen, 31:31, bool) 		// DFSDMEN
        SBF_FIELD(ckoutsrc, 30:30, bool) 		// CKOUTSRC
        SBF_FIELD(ckoutdiv, 23:16, unsigned) 		// CKOUTDIV
        SBF_FIELD(datpack, 15:14, unsigned) 		// DATPACK
        SBF_FIELD(datmpx, 13:12, unsigned) 		// DATMPX
        SBF_FIELD(chinsel, 8:8, bool) 		// CHINSEL
        SBF_FIELD(chen, 7:7, bool) 		// CHEN
        SBF_FIELD(ckaben, 6:6, bool) 		// CKABEN
        SBF_FIELD(scden, 5:5, bool) 		// SCDEN
        SBF_FIELD(spicksel, 3:2, unsigned) 		// SPICKSEL
        SBF_FIELD(sitp, 1:0, unsigned) 		// SITP
    )
    // channel configuration y register
    // Offset +0x4
    SBF_REGISTER_RW(chcfg0r2, uint32_t, 0x0,
        SBF_FIELD(offset, 31:8, unsigned) 		// OFFSET
        SBF_FIELD(dtrbs, 7:3, unsigned) 		// DTRBS
    )
    // analog watchdog and short-circuit detector register
    // Offset +0x8
    SBF_REGISTER_RW(awscd0r, uint32_t, 0x0,
        SBF_FIELD(awford, 23:22, unsigned) 		// AWFORD
        SBF_FIELD(awfosr, 20:16, unsigned) 		// AWFOSR
        SBF_FIELD(bkscd, 15:12, unsigned) 		// BKSCD
        SBF_FIELD(scdt, 7:0, unsigned) 		// SCDT
    )
    // channel watchdog filter data register
    // Offset +0xC
    SBF_REGISTER_RW(chwdat0r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel data input register
    // Offset +0x10
    SBF_REGISTER_RW(chdatin0r, uint32_t, 0x0,
        SBF_FIELD(indat1, 31:16, unsigned) 		// INDAT1
        SBF_FIELD(indat0, 15:0, unsigned) 		// INDAT0
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x14_to_0x1C, uint32_t, 3)
    // CHCFG1R1
    // Offset +0x20
    SBF_REGISTER_RW(chcfg1r1, uint32_t, 0x0,
        SBF_FIELD(datpack, 15:14, unsigned) 		// DATPACK
        SBF_FIELD(datmpx, 13:12, unsigned) 		// DATMPX
        SBF_FIELD(chinsel, 8:8, bool) 		// CHINSEL
        SBF_FIELD(chen, 7:7, bool) 		// CHEN
        SBF_FIELD(ckaben, 6:6, bool) 		// CKABEN
        SBF_FIELD(scden, 5:5, bool) 		// SCDEN
        SBF_FIELD(spicksel, 3:2, unsigned) 		// SPICKSEL
        SBF_FIELD(sitp, 1:0, unsigned) 		// SITP
    )
    // CHCFG1R2
    // Offset +0x24
    SBF_REGISTER_RW(chcfg1r2, uint32_t, 0x0,
        SBF_FIELD(offset, 31:8, unsigned) 		// OFFSET
        SBF_FIELD(dtrbs, 7:3, unsigned) 		// DTRBS
    )
    // AWSCD1R
    // Offset +0x28
    SBF_REGISTER_RW(awscd1r, uint32_t, 0x0,
        SBF_FIELD(awford, 23:22, unsigned) 		// AWFORD
        SBF_FIELD(awfosr, 20:16, unsigned) 		// AWFOSR
        SBF_FIELD(bkscd, 15:12, unsigned) 		// BKSCD
        SBF_FIELD(scdt, 7:0, unsigned) 		// SCDT
    )
    // CHWDAT1R
    // Offset +0x2C
    SBF_REGISTER_RW(chwdat1r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // CHDATIN1R
    // Offset +0x30
    SBF_REGISTER_RW(chdatin1r, uint32_t, 0x0,
        SBF_FIELD(indat1, 31:16, unsigned) 		// INDAT1
        SBF_FIELD(indat0, 15:0, unsigned) 		// INDAT0
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x34_to_0x3C, uint32_t, 3)
    // CHCFG2R1
    // Offset +0x40
    SBF_REGISTER_RW(chcfg2r1, uint32_t, 0x0,
        SBF_FIELD(datpack, 15:14, unsigned) 		// DATPACK
        SBF_FIELD(datmpx, 13:12, unsigned) 		// DATMPX
        SBF_FIELD(chinsel, 8:8, bool) 		// CHINSEL
        SBF_FIELD(chen, 7:7, bool) 		// CHEN
        SBF_FIELD(ckaben, 6:6, bool) 		// CKABEN
        SBF_FIELD(scden, 5:5, bool) 		// SCDEN
        SBF_FIELD(spicksel, 3:2, unsigned) 		// SPICKSEL
        SBF_FIELD(sitp, 1:0, unsigned) 		// SITP
    )
    // CHCFG2R2
    // Offset +0x44
    SBF_REGISTER_RW(chcfg2r2, uint32_t, 0x0,
        SBF_FIELD(offset, 31:8, unsigned) 		// OFFSET
        SBF_FIELD(dtrbs, 7:3, unsigned) 		// DTRBS
    )
    // AWSCD2R
    // Offset +0x48
    SBF_REGISTER_RW(awscd2r, uint32_t, 0x0,
        SBF_FIELD(awford, 23:22, unsigned) 		// AWFORD
        SBF_FIELD(awfosr, 20:16, unsigned) 		// AWFOSR
        SBF_FIELD(bkscd, 15:12, unsigned) 		// BKSCD
        SBF_FIELD(scdt, 7:0, unsigned) 		// SCDT
    )
    // CHWDAT2R
    // Offset +0x4C
    SBF_REGISTER_RW(chwdat2r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // CHDATIN2R
    // Offset +0x50
    SBF_REGISTER_RW(chdatin2r, uint32_t, 0x0,
        SBF_FIELD(indat1, 31:16, unsigned) 		// INDAT1
        SBF_FIELD(indat0, 15:0, unsigned) 		// INDAT0
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x54_to_0x5C, uint32_t, 3)
    // CHCFG3R1
    // Offset +0x60
    SBF_REGISTER_RW(chcfg3r1, uint32_t, 0x0,
        SBF_FIELD(datpack, 15:14, unsigned) 		// DATPACK
        SBF_FIELD(datmpx, 13:12, unsigned) 		// DATMPX
        SBF_FIELD(chinsel, 8:8, bool) 		// CHINSEL
        SBF_FIELD(chen, 7:7, bool) 		// CHEN
        SBF_FIELD(ckaben, 6:6, bool) 		// CKABEN
        SBF_FIELD(scden, 5:5, bool) 		// SCDEN
        SBF_FIELD(spicksel, 3:2, unsigned) 		// SPICKSEL
        SBF_FIELD(sitp, 1:0, unsigned) 		// SITP
    )
    // CHCFG3R2
    // Offset +0x64
    SBF_REGISTER_RW(chcfg3r2, uint32_t, 0x0,
        SBF_FIELD(offset, 31:8, unsigned) 		// OFFSET
        SBF_FIELD(dtrbs, 7:3, unsigned) 		// DTRBS
    )
    // AWSCD3R
    // Offset +0x68
    SBF_REGISTER_RW(awscd3r, uint32_t, 0x0,
        SBF_FIELD(awford, 23:22, unsigned) 		// AWFORD
        SBF_FIELD(awfosr, 20:16, unsigned) 		// AWFOSR
        SBF_FIELD(bkscd, 15:12, unsigned) 		// BKSCD
        SBF_FIELD(scdt, 7:0, unsigned) 		// SCDT
    )
    // CHWDAT3R
    // Offset +0x6C
    SBF_REGISTER_RW(chwdat3r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // CHDATIN3R
    // Offset +0x70
    SBF_REGISTER_RW(chdatin3r, uint32_t, 0x0,
        SBF_FIELD(indat1, 31:16, unsigned) 		// INDAT1
        SBF_FIELD(indat0, 15:0, unsigned) 		// INDAT0
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x74_to_0x7C, uint32_t, 3)
    // CHCFG4R1
    // Offset +0x80
    SBF_REGISTER_RW(chcfg4r1, uint32_t, 0x0,
        SBF_FIELD(datpack, 15:14, unsigned) 		// DATPACK
        SBF_FIELD(datmpx, 13:12, unsigned) 		// DATMPX
        SBF_FIELD(chinsel, 8:8, bool) 		// CHINSEL
        SBF_FIELD(chen, 7:7, bool) 		// CHEN
        SBF_FIELD(ckaben, 6:6, bool) 		// CKABEN
        SBF_FIELD(scden, 5:5, bool) 		// SCDEN
        SBF_FIELD(spicksel, 3:2, unsigned) 		// SPICKSEL
        SBF_FIELD(sitp, 1:0, unsigned) 		// SITP
    )
    // CHCFG4R2
    // Offset +0x84
    SBF_REGISTER_RW(chcfg4r2, uint32_t, 0x0,
        SBF_FIELD(offset, 31:8, unsigned) 		// OFFSET
        SBF_FIELD(dtrbs, 7:3, unsigned) 		// DTRBS
    )
    // AWSCD4R
    // Offset +0x88
    SBF_REGISTER_RW(awscd4r, uint32_t, 0x0,
        SBF_FIELD(awford, 23:22, unsigned) 		// AWFORD
        SBF_FIELD(awfosr, 20:16, unsigned) 		// AWFOSR
        SBF_FIELD(bkscd, 15:12, unsigned) 		// BKSCD
        SBF_FIELD(scdt, 7:0, unsigned) 		// SCDT
    )
    // CHWDAT4R
    // Offset +0x8C
    SBF_REGISTER_RW(chwdat4r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // CHDATIN4R
    // Offset +0x90
    SBF_REGISTER_RW(chdatin4r, uint32_t, 0x0,
        SBF_FIELD(indat1, 31:16, unsigned) 		// INDAT1
        SBF_FIELD(indat0, 15:0, unsigned) 		// INDAT0
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x94_to_0x9C, uint32_t, 3)
    // CHCFG5R1
    // Offset +0xA0
    SBF_REGISTER_RW(chcfg5r1, uint32_t, 0x0,
        SBF_FIELD(datpack, 15:14, unsigned) 		// DATPACK
        SBF_FIELD(datmpx, 13:12, unsigned) 		// DATMPX
        SBF_FIELD(chinsel, 8:8, bool) 		// CHINSEL
        SBF_FIELD(chen, 7:7, bool) 		// CHEN
        SBF_FIELD(ckaben, 6:6, bool) 		// CKABEN
        SBF_FIELD(scden, 5:5, bool) 		// SCDEN
        SBF_FIELD(spicksel, 3:2, unsigned) 		// SPICKSEL
        SBF_FIELD(sitp, 1:0, unsigned) 		// SITP
    )
    // CHCFG5R2
    // Offset +0xA4
    SBF_REGISTER_RW(chcfg5r2, uint32_t, 0x0,
        SBF_FIELD(offset, 31:8, unsigned) 		// OFFSET
        SBF_FIELD(dtrbs, 7:3, unsigned) 		// DTRBS
    )
    // AWSCD5R
    // Offset +0xA8
    SBF_REGISTER_RW(awscd5r, uint32_t, 0x0,
        SBF_FIELD(awford, 23:22, unsigned) 		// AWFORD
        SBF_FIELD(awfosr, 20:16, unsigned) 		// AWFOSR
        SBF_FIELD(bkscd, 15:12, unsigned) 		// BKSCD
        SBF_FIELD(scdt, 7:0, unsigned) 		// SCDT
    )
    // CHWDAT5R
    // Offset +0xAC
    SBF_REGISTER_RW(chwdat5r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // CHDATIN5R
    // Offset +0xB0
    SBF_REGISTER_RW(chdatin5r, uint32_t, 0x0,
        SBF_FIELD(indat1, 31:16, unsigned) 		// INDAT1
        SBF_FIELD(indat0, 15:0, unsigned) 		// INDAT0
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0xB4_to_0xBC, uint32_t, 3)
    // CHCFG6R1
    // Offset +0xC0
    SBF_REGISTER_RW(chcfg6r1, uint32_t, 0x0,
        SBF_FIELD(datpack, 15:14, unsigned) 		// DATPACK
        SBF_FIELD(datmpx, 13:12, unsigned) 		// DATMPX
        SBF_FIELD(chinsel, 8:8, bool) 		// CHINSEL
        SBF_FIELD(chen, 7:7, bool) 		// CHEN
        SBF_FIELD(ckaben, 6:6, bool) 		// CKABEN
        SBF_FIELD(scden, 5:5, bool) 		// SCDEN
        SBF_FIELD(spicksel, 3:2, unsigned) 		// SPICKSEL
        SBF_FIELD(sitp, 1:0, unsigned) 		// SITP
    )
    // CHCFG6R2
    // Offset +0xC4
    SBF_REGISTER_RW(chcfg6r2, uint32_t, 0x0,
        SBF_FIELD(offset, 31:8, unsigned) 		// OFFSET
        SBF_FIELD(dtrbs, 7:3, unsigned) 		// DTRBS
    )
    // AWSCD6R
    // Offset +0xC8
    SBF_REGISTER_RW(awscd6r, uint32_t, 0x0,
        SBF_FIELD(awford, 23:22, unsigned) 		// AWFORD
        SBF_FIELD(awfosr, 20:16, unsigned) 		// AWFOSR
        SBF_FIELD(bkscd, 15:12, unsigned) 		// BKSCD
        SBF_FIELD(scdt, 7:0, unsigned) 		// SCDT
    )
    // CHWDAT6R
    // Offset +0xCC
    SBF_REGISTER_RW(chwdat6r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // CHDATIN6R
    // Offset +0xD0
    SBF_REGISTER_RW(chdatin6r, uint32_t, 0x0,
        SBF_FIELD(indat1, 31:16, unsigned) 		// INDAT1
        SBF_FIELD(indat0, 15:0, unsigned) 		// INDAT0
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0xD4_to_0xDC, uint32_t, 3)
    // CHCFG7R1
    // Offset +0xE0
    SBF_REGISTER_RW(chcfg7r1, uint32_t, 0x0,
        SBF_FIELD(datpack, 15:14, unsigned) 		// DATPACK
        SBF_FIELD(datmpx, 13:12, unsigned) 		// DATMPX
        SBF_FIELD(chinsel, 8:8, bool) 		// CHINSEL
        SBF_FIELD(chen, 7:7, bool) 		// CHEN
        SBF_FIELD(ckaben, 6:6, bool) 		// CKABEN
        SBF_FIELD(scden, 5:5, bool) 		// SCDEN
        SBF_FIELD(spicksel, 3:2, unsigned) 		// SPICKSEL
        SBF_FIELD(sitp, 1:0, unsigned) 		// SITP
    )
    // CHCFG7R2
    // Offset +0xE4
    SBF_REGISTER_RW(chcfg7r2, uint32_t, 0x0,
        SBF_FIELD(offset, 31:8, unsigned) 		// OFFSET
        SBF_FIELD(dtrbs, 7:3, unsigned) 		// DTRBS
    )
    // AWSCD7R
    // Offset +0xE8
    SBF_REGISTER_RW(awscd7r, uint32_t, 0x0,
        SBF_FIELD(awford, 23:22, unsigned) 		// AWFORD
        SBF_FIELD(awfosr, 20:16, unsigned) 		// AWFOSR
        SBF_FIELD(bkscd, 15:12, unsigned) 		// BKSCD
        SBF_FIELD(scdt, 7:0, unsigned) 		// SCDT
    )
    // CHWDAT7R
    // Offset +0xEC
    SBF_REGISTER_RW(chwdat7r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // CHDATIN7R
    // Offset +0xF0
    SBF_REGISTER_RW(chdatin7r, uint32_t, 0x0,
        SBF_FIELD(indat1, 31:16, unsigned) 		// INDAT1
        SBF_FIELD(indat0, 15:0, unsigned) 		// INDAT0
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0xF4_to_0xFC, uint32_t, 3)
    // control register 1
    // Offset +0x100
    SBF_REGISTER_RW(dfsdm0_cr1, uint32_t, 0x0,
        SBF_FIELD(awfsel, 30:30, bool) 		// Analog watchdog fast mode select
        SBF_FIELD(fast, 29:29, bool) 		// Fast conversion mode selection for regular conversions
        SBF_FIELD(rch, 26:24, unsigned) 		// Regular channel selection
        SBF_FIELD(rdmaen, 21:21, bool) 		// DMA channel enabled to read data for the regular conversion
        SBF_FIELD(rsync, 19:19, bool) 		// Launch regular conversion synchronously with DFSDM0
        SBF_FIELD(rcont, 18:18, bool) 		// Continuous mode selection for regular conversions
        SBF_FIELD(rswstart, 17:17, bool) 		// Software start of a conversion on the regular channel
        SBF_FIELD(jexten, 14:13, unsigned) 		// Trigger enable and trigger edge selection for injected conversions
        SBF_FIELD(jextsel, 10:8, unsigned) 		// Trigger signal selection for launching injected conversions
        SBF_FIELD(jdmaen, 5:5, bool) 		// DMA channel enabled to read data for the injected channel group
        SBF_FIELD(jscan, 4:4, bool) 		// Scanning conversion mode for injected conversions
        SBF_FIELD(jsync, 3:3, bool) 		// Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger
        SBF_FIELD(jswstart, 1:1, bool) 		// Start a conversion of the injected group of channels
        SBF_FIELD(dfen, 0:0, bool) 		// DFSDM enable
    )
    // control register 2
    // Offset +0x104
    SBF_REGISTER_RW(dfsdm0_cr2, uint32_t, 0x0,
        SBF_FIELD(awdch, 23:16, unsigned) 		// Analog watchdog channel selection
        SBF_FIELD(exch, 15:8, unsigned) 		// Extremes detector channel selection
        SBF_FIELD(ckabie, 6:6, bool) 		// Clock absence interrupt enable
        SBF_FIELD(scdie, 5:5, bool) 		// Short-circuit detector interrupt enable
        SBF_FIELD(awdie, 4:4, bool) 		// Analog watchdog interrupt enable
        SBF_FIELD(rovrie, 3:3, bool) 		// Regular data overrun interrupt enable
        SBF_FIELD(jovrie, 2:2, bool) 		// Injected data overrun interrupt enable
        SBF_FIELD(reocie, 1:1, bool) 		// Regular end of conversion interrupt enable
        SBF_FIELD(jeocie, 0:0, bool) 		// Injected end of conversion interrupt enable
    )
    // interrupt and status register
    // Offset +0x108
    SBF_REGISTER_RO(dfsdm0_isr, uint32_t, 0xFF0000,
        SBF_FIELD(scdf, 31:24, unsigned) 		// short-circuit detector flag
        SBF_FIELD(ckabf, 23:16, unsigned) 		// Clock absence flag
        SBF_FIELD(rcip, 14:14, bool) 		// Regular conversion in progress status
        SBF_FIELD(jcip, 13:13, bool) 		// Injected conversion in progress status
        SBF_FIELD(awdf, 4:4, bool) 		// Analog watchdog
        SBF_FIELD(rovrf, 3:3, bool) 		// Regular conversion overrun flag
        SBF_FIELD(jovrf, 2:2, bool) 		// Injected conversion overrun flag
        SBF_FIELD(reocf, 1:1, bool) 		// End of regular conversion flag
        SBF_FIELD(jeocf, 0:0, bool) 		// End of injected conversion flag
    )
    // interrupt flag clear register
    // Offset +0x10C
    SBF_REGISTER_RW(dfsdm0_icr, uint32_t, 0x0,
        SBF_FIELD(clrscdf, 31:24, unsigned) 		// Clear the short-circuit detector flag
        SBF_FIELD(clrckabf, 23:16, unsigned) 		// Clear the clock absence flag
        SBF_FIELD(clrrovrf, 3:3, bool) 		// Clear the regular conversion overrun flag
        SBF_FIELD(clrjovrf, 2:2, bool) 		// Clear the injected conversion overrun flag
    )
    // injected channel group selection register
    // Offset +0x110
    SBF_REGISTER_RW(dfsdm0_jchgr, uint32_t, 0x1,
        SBF_NO_FIELDS
    )
    // filter control register
    // Offset +0x114
    SBF_REGISTER_RW(dfsdm0_fcr, uint32_t, 0x0,
        SBF_FIELD(ford, 31:29, unsigned) 		// Sinc filter order
        SBF_FIELD(fosr, 25:16, unsigned) 		// Sinc filter oversampling ratio (decimation rate)
        SBF_FIELD(iosr, 7:0, unsigned) 		// Integrator oversampling ratio (averaging length)
    )
    // data register for injected group
    // Offset +0x118
    SBF_REGISTER_RO(dfsdm0_jdatar, uint32_t, 0x0,
        SBF_FIELD(jdata, 31:8, unsigned) 		// Injected group conversion data
        SBF_FIELD(jdatach, 2:0, unsigned) 		// Injected channel most recently converted
    )
    // data register for the regular channel
    // Offset +0x11C
    SBF_REGISTER_RO(dfsdm0_rdatar, uint32_t, 0x0,
        SBF_FIELD(rdata, 31:8, unsigned) 		// Regular channel conversion data
        SBF_FIELD(rpend, 4:4, bool) 		// Regular channel pending data
        SBF_FIELD(rdatach, 2:0, unsigned) 		// Regular channel most recently converted
    )
    // analog watchdog high threshold register
    // Offset +0x120
    SBF_REGISTER_RW(dfsdm0_awhtr, uint32_t, 0x0,
        SBF_FIELD(awht, 31:8, unsigned) 		// Analog watchdog high threshold
        SBF_FIELD(bkawh, 3:0, unsigned) 		// Break signal assignment to analog watchdog high threshold event
    )
    // analog watchdog low threshold register
    // Offset +0x124
    SBF_REGISTER_RW(dfsdm0_awltr, uint32_t, 0x0,
        SBF_FIELD(awlt, 31:8, unsigned) 		// Analog watchdog low threshold
        SBF_FIELD(bkawl, 3:0, unsigned) 		// Break signal assignment to analog watchdog low threshold event
    )
    // analog watchdog status register
    // Offset +0x128
    SBF_REGISTER_RO(dfsdm0_awsr, uint32_t, 0x0,
        SBF_FIELD(awhtf, 15:8, unsigned) 		// Analog watchdog high threshold flag
        SBF_FIELD(awltf, 7:0, unsigned) 		// Analog watchdog low threshold flag
    )
    // analog watchdog clear flag register
    // Offset +0x12C
    SBF_REGISTER_RW(dfsdm0_awcfr, uint32_t, 0x0,
        SBF_FIELD(clrawhtf, 15:8, unsigned) 		// Clear the analog watchdog high threshold flag
        SBF_FIELD(clrawltf, 7:0, unsigned) 		// Clear the analog watchdog low threshold flag
    )
    // Extremes detector maximum register
    // Offset +0x130
    SBF_REGISTER_RO(dfsdm0_exmax, uint32_t, 0x80000000,
        SBF_FIELD(exmax, 31:8, unsigned) 		// Extremes detector maximum value
        SBF_FIELD(exmaxch, 2:0, unsigned) 		// Extremes detector maximum data channel
    )
    // Extremes detector minimum register
    // Offset +0x134
    SBF_REGISTER_RO(dfsdm0_exmin, uint32_t, 0x7FFFFF00,
        SBF_FIELD(exmin, 31:8, unsigned) 		// EXMIN
        SBF_FIELD(exminch, 2:0, unsigned) 		// Extremes detector minimum data channel
    )
    // conversion timer register
    // Offset +0x138
    SBF_REGISTER_RO(dfsdm0_cnvtimr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x13C_to_0x1FC, uint32_t, 49)
    // control register 1
    // Offset +0x200
    SBF_REGISTER_RW(dfsdm1_cr1, uint32_t, 0x0,
        SBF_FIELD(awfsel, 30:30, bool) 		// Analog watchdog fast mode select
        SBF_FIELD(fast, 29:29, bool) 		// Fast conversion mode selection for regular conversions
        SBF_FIELD(rch, 26:24, unsigned) 		// Regular channel selection
        SBF_FIELD(rdmaen, 21:21, bool) 		// DMA channel enabled to read data for the regular conversion
        SBF_FIELD(rsync, 19:19, bool) 		// Launch regular conversion synchronously with DFSDM0
        SBF_FIELD(rcont, 18:18, bool) 		// Continuous mode selection for regular conversions
        SBF_FIELD(rswstart, 17:17, bool) 		// Software start of a conversion on the regular channel
        SBF_FIELD(jexten, 14:13, unsigned) 		// Trigger enable and trigger edge selection for injected conversions
        SBF_FIELD(jextsel, 10:8, unsigned) 		// Trigger signal selection for launching injected conversions
        SBF_FIELD(jdmaen, 5:5, bool) 		// DMA channel enabled to read data for the injected channel group
        SBF_FIELD(jscan, 4:4, bool) 		// Scanning conversion mode for injected conversions
        SBF_FIELD(jsync, 3:3, bool) 		// Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger
        SBF_FIELD(jswstart, 1:1, bool) 		// Start a conversion of the injected group of channels
        SBF_FIELD(dfen, 0:0, bool) 		// DFSDM enable
    )
    // control register 2
    // Offset +0x204
    SBF_REGISTER_RW(dfsdm1_cr2, uint32_t, 0x0,
        SBF_FIELD(awdch, 23:16, unsigned) 		// Analog watchdog channel selection
        SBF_FIELD(exch, 15:8, unsigned) 		// Extremes detector channel selection
        SBF_FIELD(ckabie, 6:6, bool) 		// Clock absence interrupt enable
        SBF_FIELD(scdie, 5:5, bool) 		// Short-circuit detector interrupt enable
        SBF_FIELD(awdie, 4:4, bool) 		// Analog watchdog interrupt enable
        SBF_FIELD(rovrie, 3:3, bool) 		// Regular data overrun interrupt enable
        SBF_FIELD(jovrie, 2:2, bool) 		// Injected data overrun interrupt enable
        SBF_FIELD(reocie, 1:1, bool) 		// Regular end of conversion interrupt enable
        SBF_FIELD(jeocie, 0:0, bool) 		// Injected end of conversion interrupt enable
    )
    // interrupt and status register
    // Offset +0x208
    SBF_REGISTER_RO(dfsdm1_isr, uint32_t, 0xFF0000,
        SBF_FIELD(scdf, 31:24, unsigned) 		// short-circuit detector flag
        SBF_FIELD(ckabf, 23:16, unsigned) 		// Clock absence flag
        SBF_FIELD(rcip, 14:14, bool) 		// Regular conversion in progress status
        SBF_FIELD(jcip, 13:13, bool) 		// Injected conversion in progress status
        SBF_FIELD(awdf, 4:4, bool) 		// Analog watchdog
        SBF_FIELD(rovrf, 3:3, bool) 		// Regular conversion overrun flag
        SBF_FIELD(jovrf, 2:2, bool) 		// Injected conversion overrun flag
        SBF_FIELD(reocf, 1:1, bool) 		// End of regular conversion flag
        SBF_FIELD(jeocf, 0:0, bool) 		// End of injected conversion flag
    )
    // interrupt flag clear register
    // Offset +0x20C
    SBF_REGISTER_RW(dfsdm1_icr, uint32_t, 0x0,
        SBF_FIELD(clrscdf, 31:24, unsigned) 		// Clear the short-circuit detector flag
        SBF_FIELD(clrckabf, 23:16, unsigned) 		// Clear the clock absence flag
        SBF_FIELD(clrrovrf, 3:3, bool) 		// Clear the regular conversion overrun flag
        SBF_FIELD(clrjovrf, 2:2, bool) 		// Clear the injected conversion overrun flag
    )
    // injected channel group selection register
    // Offset +0x210
    SBF_REGISTER_RW(dfsdm1_jchgr, uint32_t, 0x1,
        SBF_NO_FIELDS
    )
    // filter control register
    // Offset +0x214
    SBF_REGISTER_RW(dfsdm1_fcr, uint32_t, 0x0,
        SBF_FIELD(ford, 31:29, unsigned) 		// Sinc filter order
        SBF_FIELD(fosr, 25:16, unsigned) 		// Sinc filter oversampling ratio (decimation rate)
        SBF_FIELD(iosr, 7:0, unsigned) 		// Integrator oversampling ratio (averaging length)
    )
    // data register for injected group
    // Offset +0x218
    SBF_REGISTER_RO(dfsdm1_jdatar, uint32_t, 0x0,
        SBF_FIELD(jdata, 31:8, unsigned) 		// Injected group conversion data
        SBF_FIELD(jdatach, 2:0, unsigned) 		// Injected channel most recently converted
    )
    // data register for the regular channel
    // Offset +0x21C
    SBF_REGISTER_RO(dfsdm1_rdatar, uint32_t, 0x0,
        SBF_FIELD(rdata, 31:8, unsigned) 		// Regular channel conversion data
        SBF_FIELD(rpend, 4:4, bool) 		// Regular channel pending data
        SBF_FIELD(rdatach, 2:0, unsigned) 		// Regular channel most recently converted
    )
    // analog watchdog high threshold register
    // Offset +0x220
    SBF_REGISTER_RW(dfsdm1_awhtr, uint32_t, 0x0,
        SBF_FIELD(awht, 31:8, unsigned) 		// Analog watchdog high threshold
        SBF_FIELD(bkawh, 3:0, unsigned) 		// Break signal assignment to analog watchdog high threshold event
    )
    // analog watchdog low threshold register
    // Offset +0x224
    SBF_REGISTER_RW(dfsdm1_awltr, uint32_t, 0x0,
        SBF_FIELD(awlt, 31:8, unsigned) 		// Analog watchdog low threshold
        SBF_FIELD(bkawl, 3:0, unsigned) 		// Break signal assignment to analog watchdog low threshold event
    )
    // analog watchdog status register
    // Offset +0x228
    SBF_REGISTER_RO(dfsdm1_awsr, uint32_t, 0x0,
        SBF_FIELD(awhtf, 15:8, unsigned) 		// Analog watchdog high threshold flag
        SBF_FIELD(awltf, 7:0, unsigned) 		// Analog watchdog low threshold flag
    )
    // analog watchdog clear flag register
    // Offset +0x22C
    SBF_REGISTER_RW(dfsdm1_awcfr, uint32_t, 0x0,
        SBF_FIELD(clrawhtf, 15:8, unsigned) 		// Clear the analog watchdog high threshold flag
        SBF_FIELD(clrawltf, 7:0, unsigned) 		// Clear the analog watchdog low threshold flag
    )
    // Extremes detector maximum register
    // Offset +0x230
    SBF_REGISTER_RO(dfsdm1_exmax, uint32_t, 0x80000000,
        SBF_FIELD(exmax, 31:8, unsigned) 		// Extremes detector maximum value
        SBF_FIELD(exmaxch, 2:0, unsigned) 		// Extremes detector maximum data channel
    )
    // Extremes detector minimum register
    // Offset +0x234
    SBF_REGISTER_RO(dfsdm1_exmin, uint32_t, 0x7FFFFF00,
        SBF_FIELD(exmin, 31:8, unsigned) 		// EXMIN
        SBF_FIELD(exminch, 2:0, unsigned) 		// Extremes detector minimum data channel
    )
    // conversion timer register
    // Offset +0x238
    SBF_REGISTER_RO(dfsdm1_cnvtimr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x23C_to_0x2FC, uint32_t, 49)
    // control register 1
    // Offset +0x300
    SBF_REGISTER_RW(dfsdm2_cr1, uint32_t, 0x0,
        SBF_FIELD(awfsel, 30:30, bool) 		// Analog watchdog fast mode select
        SBF_FIELD(fast, 29:29, bool) 		// Fast conversion mode selection for regular conversions
        SBF_FIELD(rch, 26:24, unsigned) 		// Regular channel selection
        SBF_FIELD(rdmaen, 21:21, bool) 		// DMA channel enabled to read data for the regular conversion
        SBF_FIELD(rsync, 19:19, bool) 		// Launch regular conversion synchronously with DFSDM0
        SBF_FIELD(rcont, 18:18, bool) 		// Continuous mode selection for regular conversions
        SBF_FIELD(rswstart, 17:17, bool) 		// Software start of a conversion on the regular channel
        SBF_FIELD(jexten, 14:13, unsigned) 		// Trigger enable and trigger edge selection for injected conversions
        SBF_FIELD(jextsel, 10:8, unsigned) 		// Trigger signal selection for launching injected conversions
        SBF_FIELD(jdmaen, 5:5, bool) 		// DMA channel enabled to read data for the injected channel group
        SBF_FIELD(jscan, 4:4, bool) 		// Scanning conversion mode for injected conversions
        SBF_FIELD(jsync, 3:3, bool) 		// Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger
        SBF_FIELD(jswstart, 1:1, bool) 		// Start a conversion of the injected group of channels
        SBF_FIELD(dfen, 0:0, bool) 		// DFSDM enable
    )
    // control register 2
    // Offset +0x304
    SBF_REGISTER_RW(dfsdm2_cr2, uint32_t, 0x0,
        SBF_FIELD(awdch, 23:16, unsigned) 		// Analog watchdog channel selection
        SBF_FIELD(exch, 15:8, unsigned) 		// Extremes detector channel selection
        SBF_FIELD(ckabie, 6:6, bool) 		// Clock absence interrupt enable
        SBF_FIELD(scdie, 5:5, bool) 		// Short-circuit detector interrupt enable
        SBF_FIELD(awdie, 4:4, bool) 		// Analog watchdog interrupt enable
        SBF_FIELD(rovrie, 3:3, bool) 		// Regular data overrun interrupt enable
        SBF_FIELD(jovrie, 2:2, bool) 		// Injected data overrun interrupt enable
        SBF_FIELD(reocie, 1:1, bool) 		// Regular end of conversion interrupt enable
        SBF_FIELD(jeocie, 0:0, bool) 		// Injected end of conversion interrupt enable
    )
    // interrupt and status register
    // Offset +0x308
    SBF_REGISTER_RO(dfsdm2_isr, uint32_t, 0xFF0000,
        SBF_FIELD(scdf, 31:24, unsigned) 		// short-circuit detector flag
        SBF_FIELD(ckabf, 23:16, unsigned) 		// Clock absence flag
        SBF_FIELD(rcip, 14:14, bool) 		// Regular conversion in progress status
        SBF_FIELD(jcip, 13:13, bool) 		// Injected conversion in progress status
        SBF_FIELD(awdf, 4:4, bool) 		// Analog watchdog
        SBF_FIELD(rovrf, 3:3, bool) 		// Regular conversion overrun flag
        SBF_FIELD(jovrf, 2:2, bool) 		// Injected conversion overrun flag
        SBF_FIELD(reocf, 1:1, bool) 		// End of regular conversion flag
        SBF_FIELD(jeocf, 0:0, bool) 		// End of injected conversion flag
    )
    // interrupt flag clear register
    // Offset +0x30C
    SBF_REGISTER_RW(dfsdm2_icr, uint32_t, 0x0,
        SBF_FIELD(clrscdf, 31:24, unsigned) 		// Clear the short-circuit detector flag
        SBF_FIELD(clrckabf, 23:16, unsigned) 		// Clear the clock absence flag
        SBF_FIELD(clrrovrf, 3:3, bool) 		// Clear the regular conversion overrun flag
        SBF_FIELD(clrjovrf, 2:2, bool) 		// Clear the injected conversion overrun flag
    )
    // injected channel group selection register
    // Offset +0x310
    SBF_REGISTER_RW(dfsdm2_jchgr, uint32_t, 0x1,
        SBF_NO_FIELDS
    )
    // filter control register
    // Offset +0x314
    SBF_REGISTER_RW(dfsdm2_fcr, uint32_t, 0x0,
        SBF_FIELD(ford, 31:29, unsigned) 		// Sinc filter order
        SBF_FIELD(fosr, 25:16, unsigned) 		// Sinc filter oversampling ratio (decimation rate)
        SBF_FIELD(iosr, 7:0, unsigned) 		// Integrator oversampling ratio (averaging length)
    )
    // data register for injected group
    // Offset +0x318
    SBF_REGISTER_RO(dfsdm2_jdatar, uint32_t, 0x0,
        SBF_FIELD(jdata, 31:8, unsigned) 		// Injected group conversion data
        SBF_FIELD(jdatach, 2:0, unsigned) 		// Injected channel most recently converted
    )
    // data register for the regular channel
    // Offset +0x31C
    SBF_REGISTER_RO(dfsdm2_rdatar, uint32_t, 0x0,
        SBF_FIELD(rdata, 31:8, unsigned) 		// Regular channel conversion data
        SBF_FIELD(rpend, 4:4, bool) 		// Regular channel pending data
        SBF_FIELD(rdatach, 2:0, unsigned) 		// Regular channel most recently converted
    )
    // analog watchdog high threshold register
    // Offset +0x320
    SBF_REGISTER_RW(dfsdm2_awhtr, uint32_t, 0x0,
        SBF_FIELD(awht, 31:8, unsigned) 		// Analog watchdog high threshold
        SBF_FIELD(bkawh, 3:0, unsigned) 		// Break signal assignment to analog watchdog high threshold event
    )
    // analog watchdog low threshold register
    // Offset +0x324
    SBF_REGISTER_RW(dfsdm2_awltr, uint32_t, 0x0,
        SBF_FIELD(awlt, 31:8, unsigned) 		// Analog watchdog low threshold
        SBF_FIELD(bkawl, 3:0, unsigned) 		// Break signal assignment to analog watchdog low threshold event
    )
    // analog watchdog status register
    // Offset +0x328
    SBF_REGISTER_RO(dfsdm2_awsr, uint32_t, 0x0,
        SBF_FIELD(awhtf, 15:8, unsigned) 		// Analog watchdog high threshold flag
        SBF_FIELD(awltf, 7:0, unsigned) 		// Analog watchdog low threshold flag
    )
    // analog watchdog clear flag register
    // Offset +0x32C
    SBF_REGISTER_RW(dfsdm2_awcfr, uint32_t, 0x0,
        SBF_FIELD(clrawhtf, 15:8, unsigned) 		// Clear the analog watchdog high threshold flag
        SBF_FIELD(clrawltf, 7:0, unsigned) 		// Clear the analog watchdog low threshold flag
    )
    // Extremes detector maximum register
    // Offset +0x330
    SBF_REGISTER_RO(dfsdm2_exmax, uint32_t, 0x80000000,
        SBF_FIELD(exmax, 31:8, unsigned) 		// Extremes detector maximum value
        SBF_FIELD(exmaxch, 2:0, unsigned) 		// Extremes detector maximum data channel
    )
    // Extremes detector minimum register
    // Offset +0x334
    SBF_REGISTER_RO(dfsdm2_exmin, uint32_t, 0x7FFFFF00,
        SBF_FIELD(exmin, 31:8, unsigned) 		// EXMIN
        SBF_FIELD(exminch, 2:0, unsigned) 		// Extremes detector minimum data channel
    )
    // conversion timer register
    // Offset +0x338
    SBF_REGISTER_RO(dfsdm2_cnvtimr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x33C_to_0x3FC, uint32_t, 49)
    // control register 1
    // Offset +0x400
    SBF_REGISTER_RW(dfsdm3_cr1, uint32_t, 0x0,
        SBF_FIELD(awfsel, 30:30, bool) 		// Analog watchdog fast mode select
        SBF_FIELD(fast, 29:29, bool) 		// Fast conversion mode selection for regular conversions
        SBF_FIELD(rch, 26:24, unsigned) 		// Regular channel selection
        SBF_FIELD(rdmaen, 21:21, bool) 		// DMA channel enabled to read data for the regular conversion
        SBF_FIELD(rsync, 19:19, bool) 		// Launch regular conversion synchronously with DFSDM0
        SBF_FIELD(rcont, 18:18, bool) 		// Continuous mode selection for regular conversions
        SBF_FIELD(rswstart, 17:17, bool) 		// Software start of a conversion on the regular channel
        SBF_FIELD(jexten, 14:13, unsigned) 		// Trigger enable and trigger edge selection for injected conversions
        SBF_FIELD(jextsel, 10:8, unsigned) 		// Trigger signal selection for launching injected conversions
        SBF_FIELD(jdmaen, 5:5, bool) 		// DMA channel enabled to read data for the injected channel group
        SBF_FIELD(jscan, 4:4, bool) 		// Scanning conversion mode for injected conversions
        SBF_FIELD(jsync, 3:3, bool) 		// Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger
        SBF_FIELD(jswstart, 1:1, bool) 		// Start a conversion of the injected group of channels
        SBF_FIELD(dfen, 0:0, bool) 		// DFSDM enable
    )
    // control register 2
    // Offset +0x404
    SBF_REGISTER_RW(dfsdm3_cr2, uint32_t, 0x0,
        SBF_FIELD(awdch, 23:16, unsigned) 		// Analog watchdog channel selection
        SBF_FIELD(exch, 15:8, unsigned) 		// Extremes detector channel selection
        SBF_FIELD(ckabie, 6:6, bool) 		// Clock absence interrupt enable
        SBF_FIELD(scdie, 5:5, bool) 		// Short-circuit detector interrupt enable
        SBF_FIELD(awdie, 4:4, bool) 		// Analog watchdog interrupt enable
        SBF_FIELD(rovrie, 3:3, bool) 		// Regular data overrun interrupt enable
        SBF_FIELD(jovrie, 2:2, bool) 		// Injected data overrun interrupt enable
        SBF_FIELD(reocie, 1:1, bool) 		// Regular end of conversion interrupt enable
        SBF_FIELD(jeocie, 0:0, bool) 		// Injected end of conversion interrupt enable
    )
    // interrupt and status register
    // Offset +0x408
    SBF_REGISTER_RO(dfsdm3_isr, uint32_t, 0xFF0000,
        SBF_FIELD(scdf, 31:24, unsigned) 		// short-circuit detector flag
        SBF_FIELD(ckabf, 23:16, unsigned) 		// Clock absence flag
        SBF_FIELD(rcip, 14:14, bool) 		// Regular conversion in progress status
        SBF_FIELD(jcip, 13:13, bool) 		// Injected conversion in progress status
        SBF_FIELD(awdf, 4:4, bool) 		// Analog watchdog
        SBF_FIELD(rovrf, 3:3, bool) 		// Regular conversion overrun flag
        SBF_FIELD(jovrf, 2:2, bool) 		// Injected conversion overrun flag
        SBF_FIELD(reocf, 1:1, bool) 		// End of regular conversion flag
        SBF_FIELD(jeocf, 0:0, bool) 		// End of injected conversion flag
    )
    // interrupt flag clear register
    // Offset +0x40C
    SBF_REGISTER_RW(dfsdm3_icr, uint32_t, 0x0,
        SBF_FIELD(clrscdf, 31:24, unsigned) 		// Clear the short-circuit detector flag
        SBF_FIELD(clrckabf, 23:16, unsigned) 		// Clear the clock absence flag
        SBF_FIELD(clrrovrf, 3:3, bool) 		// Clear the regular conversion overrun flag
        SBF_FIELD(clrjovrf, 2:2, bool) 		// Clear the injected conversion overrun flag
    )
    // injected channel group selection register
    // Offset +0x410
    SBF_REGISTER_RW(dfsdm3_jchgr, uint32_t, 0x1,
        SBF_NO_FIELDS
    )
    // filter control register
    // Offset +0x414
    SBF_REGISTER_RW(dfsdm3_fcr, uint32_t, 0x0,
        SBF_FIELD(ford, 31:29, unsigned) 		// Sinc filter order
        SBF_FIELD(fosr, 25:16, unsigned) 		// Sinc filter oversampling ratio (decimation rate)
        SBF_FIELD(iosr, 7:0, unsigned) 		// Integrator oversampling ratio (averaging length)
    )
    // data register for injected group
    // Offset +0x418
    SBF_REGISTER_RO(dfsdm3_jdatar, uint32_t, 0x0,
        SBF_FIELD(jdata, 31:8, unsigned) 		// Injected group conversion data
        SBF_FIELD(jdatach, 2:0, unsigned) 		// Injected channel most recently converted
    )
    // data register for the regular channel
    // Offset +0x41C
    SBF_REGISTER_RO(dfsdm3_rdatar, uint32_t, 0x0,
        SBF_FIELD(rdata, 31:8, unsigned) 		// Regular channel conversion data
        SBF_FIELD(rpend, 4:4, bool) 		// Regular channel pending data
        SBF_FIELD(rdatach, 2:0, unsigned) 		// Regular channel most recently converted
    )
    // analog watchdog high threshold register
    // Offset +0x420
    SBF_REGISTER_RW(dfsdm3_awhtr, uint32_t, 0x0,
        SBF_FIELD(awht, 31:8, unsigned) 		// Analog watchdog high threshold
        SBF_FIELD(bkawh, 3:0, unsigned) 		// Break signal assignment to analog watchdog high threshold event
    )
    // analog watchdog low threshold register
    // Offset +0x424
    SBF_REGISTER_RW(dfsdm3_awltr, uint32_t, 0x0,
        SBF_FIELD(awlt, 31:8, unsigned) 		// Analog watchdog low threshold
        SBF_FIELD(bkawl, 3:0, unsigned) 		// Break signal assignment to analog watchdog low threshold event
    )
    // analog watchdog status register
    // Offset +0x428
    SBF_REGISTER_RO(dfsdm3_awsr, uint32_t, 0x0,
        SBF_FIELD(awhtf, 15:8, unsigned) 		// Analog watchdog high threshold flag
        SBF_FIELD(awltf, 7:0, unsigned) 		// Analog watchdog low threshold flag
    )
    // analog watchdog clear flag register
    // Offset +0x42C
    SBF_REGISTER_RW(dfsdm3_awcfr, uint32_t, 0x0,
        SBF_FIELD(clrawhtf, 15:8, unsigned) 		// Clear the analog watchdog high threshold flag
        SBF_FIELD(clrawltf, 7:0, unsigned) 		// Clear the analog watchdog low threshold flag
    )
    // Extremes detector maximum register
    // Offset +0x430
    SBF_REGISTER_RO(dfsdm3_exmax, uint32_t, 0x80000000,
        SBF_FIELD(exmax, 31:8, unsigned) 		// Extremes detector maximum value
        SBF_FIELD(exmaxch, 2:0, unsigned) 		// Extremes detector maximum data channel
    )
    // Extremes detector minimum register
    // Offset +0x434
    SBF_REGISTER_RO(dfsdm3_exmin, uint32_t, 0x7FFFFF00,
        SBF_FIELD(exmin, 31:8, unsigned) 		// EXMIN
        SBF_FIELD(exminch, 2:0, unsigned) 		// Extremes detector minimum data channel
    )
    // conversion timer register
    // Offset +0x438
    SBF_REGISTER_RO(dfsdm3_cnvtimr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Dfsdm registers


// Dma registers
struct Dma {
    // interrupt status register
    // Offset +0x0
    SBF_REGISTER_RO(isr, uint32_t, 0x0,
        SBF_FIELD(teif7, 27:27, bool) 		// Channel x transfer error flag (x = 1 ..7)
        SBF_FIELD(htif7, 26:26, bool) 		// Channel x half transfer flag (x = 1 ..7)
        SBF_FIELD(tcif7, 25:25, bool) 		// Channel x transfer complete flag (x = 1 ..7)
        SBF_FIELD(gif7, 24:24, bool) 		// Channel x global interrupt flag (x = 1 ..7)
        SBF_FIELD(teif6, 23:23, bool) 		// Channel x transfer error flag (x = 1 ..7)
        SBF_FIELD(htif6, 22:22, bool) 		// Channel x half transfer flag (x = 1 ..7)
        SBF_FIELD(tcif6, 21:21, bool) 		// Channel x transfer complete flag (x = 1 ..7)
        SBF_FIELD(gif6, 20:20, bool) 		// Channel x global interrupt flag (x = 1 ..7)
        SBF_FIELD(teif5, 19:19, bool) 		// Channel x transfer error flag (x = 1 ..7)
        SBF_FIELD(htif5, 18:18, bool) 		// Channel x half transfer flag (x = 1 ..7)
        SBF_FIELD(tcif5, 17:17, bool) 		// Channel x transfer complete flag (x = 1 ..7)
        SBF_FIELD(gif5, 16:16, bool) 		// Channel x global interrupt flag (x = 1 ..7)
        SBF_FIELD(teif4, 15:15, bool) 		// Channel x transfer error flag (x = 1 ..7)
        SBF_FIELD(htif4, 14:14, bool) 		// Channel x half transfer flag (x = 1 ..7)
        SBF_FIELD(tcif4, 13:13, bool) 		// Channel x transfer complete flag (x = 1 ..7)
        SBF_FIELD(gif4, 12:12, bool) 		// Channel x global interrupt flag (x = 1 ..7)
        SBF_FIELD(teif3, 11:11, bool) 		// Channel x transfer error flag (x = 1 ..7)
        SBF_FIELD(htif3, 10:10, bool) 		// Channel x half transfer flag (x = 1 ..7)
        SBF_FIELD(tcif3, 9:9, bool) 		// Channel x transfer complete flag (x = 1 ..7)
        SBF_FIELD(gif3, 8:8, bool) 		// Channel x global interrupt flag (x = 1 ..7)
        SBF_FIELD(teif2, 7:7, bool) 		// Channel x transfer error flag (x = 1 ..7)
        SBF_FIELD(htif2, 6:6, bool) 		// Channel x half transfer flag (x = 1 ..7)
        SBF_FIELD(tcif2, 5:5, bool) 		// Channel x transfer complete flag (x = 1 ..7)
        SBF_FIELD(gif2, 4:4, bool) 		// Channel x global interrupt flag (x = 1 ..7)
        SBF_FIELD(teif1, 3:3, bool) 		// Channel x transfer error flag (x = 1 ..7)
        SBF_FIELD(htif1, 2:2, bool) 		// Channel x half transfer flag (x = 1 ..7)
        SBF_FIELD(tcif1, 1:1, bool) 		// Channel x transfer complete flag (x = 1 ..7)
        SBF_FIELD(gif1, 0:0, bool) 		// Channel x global interrupt flag (x = 1 ..7)
    )
    // interrupt flag clear register
    // Offset +0x4
    SBF_REGISTER_WO(ifcr, uint32_t, 0x0,
        SBF_FIELD(cteif7, 27:27, bool) 		// Channel x transfer error clear (x = 1 ..7)
        SBF_FIELD(chtif7, 26:26, bool) 		// Channel x half transfer clear (x = 1 ..7)
        SBF_FIELD(ctcif7, 25:25, bool) 		// Channel x transfer complete clear (x = 1 ..7)
        SBF_FIELD(cgif7, 24:24, bool) 		// Channel x global interrupt clear (x = 1 ..7)
        SBF_FIELD(cteif6, 23:23, bool) 		// Channel x transfer error clear (x = 1 ..7)
        SBF_FIELD(chtif6, 22:22, bool) 		// Channel x half transfer clear (x = 1 ..7)
        SBF_FIELD(ctcif6, 21:21, bool) 		// Channel x transfer complete clear (x = 1 ..7)
        SBF_FIELD(cgif6, 20:20, bool) 		// Channel x global interrupt clear (x = 1 ..7)
        SBF_FIELD(cteif5, 19:19, bool) 		// Channel x transfer error clear (x = 1 ..7)
        SBF_FIELD(chtif5, 18:18, bool) 		// Channel x half transfer clear (x = 1 ..7)
        SBF_FIELD(ctcif5, 17:17, bool) 		// Channel x transfer complete clear (x = 1 ..7)
        SBF_FIELD(cgif5, 16:16, bool) 		// Channel x global interrupt clear (x = 1 ..7)
        SBF_FIELD(cteif4, 15:15, bool) 		// Channel x transfer error clear (x = 1 ..7)
        SBF_FIELD(chtif4, 14:14, bool) 		// Channel x half transfer clear (x = 1 ..7)
        SBF_FIELD(ctcif4, 13:13, bool) 		// Channel x transfer complete clear (x = 1 ..7)
        SBF_FIELD(cgif4, 12:12, bool) 		// Channel x global interrupt clear (x = 1 ..7)
        SBF_FIELD(cteif3, 11:11, bool) 		// Channel x transfer error clear (x = 1 ..7)
        SBF_FIELD(chtif3, 10:10, bool) 		// Channel x half transfer clear (x = 1 ..7)
        SBF_FIELD(ctcif3, 9:9, bool) 		// Channel x transfer complete clear (x = 1 ..7)
        SBF_FIELD(cgif3, 8:8, bool) 		// Channel x global interrupt clear (x = 1 ..7)
        SBF_FIELD(cteif2, 7:7, bool) 		// Channel x transfer error clear (x = 1 ..7)
        SBF_FIELD(chtif2, 6:6, bool) 		// Channel x half transfer clear (x = 1 ..7)
        SBF_FIELD(ctcif2, 5:5, bool) 		// Channel x transfer complete clear (x = 1 ..7)
        SBF_FIELD(cgif2, 4:4, bool) 		// Channel x global interrupt clear (x = 1 ..7)
        SBF_FIELD(cteif1, 3:3, bool) 		// Channel x transfer error clear (x = 1 ..7)
        SBF_FIELD(chtif1, 2:2, bool) 		// Channel x half transfer clear (x = 1 ..7)
        SBF_FIELD(ctcif1, 1:1, bool) 		// Channel x transfer complete clear (x = 1 ..7)
        SBF_FIELD(cgif1, 0:0, bool) 		// Channel x global interrupt clear (x = 1 ..7)
    )
    // channel x configuration register
    // Offset +0x8
    SBF_REGISTER_RW(ccr1, uint32_t, 0x0,
        SBF_FIELD(mem2mem, 14:14, bool) 		// Memory to memory mode
        SBF_FIELD(pl, 13:12, unsigned) 		// Channel priority level
        SBF_FIELD(msize, 11:10, unsigned) 		// Memory size
        SBF_FIELD(psize, 9:8, unsigned) 		// Peripheral size
        SBF_FIELD(minc, 7:7, bool) 		// Memory increment mode
        SBF_FIELD(pinc, 6:6, bool) 		// Peripheral increment mode
        SBF_FIELD(circ, 5:5, bool) 		// Circular mode
        SBF_FIELD(dir, 4:4, bool) 		// Data transfer direction
        SBF_FIELD(teie, 3:3, bool) 		// Transfer error interrupt enable
        SBF_FIELD(htie, 2:2, bool) 		// Half transfer interrupt enable
        SBF_FIELD(tcie, 1:1, bool) 		// Transfer complete interrupt enable
        SBF_FIELD(en, 0:0, bool) 		// Channel enable
    )
    // channel x number of data register
    // Offset +0xC
    SBF_REGISTER_RW(cndtr1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x peripheral address register
    // Offset +0x10
    SBF_REGISTER_RW(cpar1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x memory address register
    // Offset +0x14
    SBF_REGISTER_RW(cmar1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x18, uint32_t, 1)
    // channel x configuration register
    // Offset +0x1C
    SBF_REGISTER_RW(ccr2, uint32_t, 0x0,
        SBF_FIELD(mem2mem, 14:14, bool) 		// Memory to memory mode
        SBF_FIELD(pl, 13:12, unsigned) 		// Channel priority level
        SBF_FIELD(msize, 11:10, unsigned) 		// Memory size
        SBF_FIELD(psize, 9:8, unsigned) 		// Peripheral size
        SBF_FIELD(minc, 7:7, bool) 		// Memory increment mode
        SBF_FIELD(pinc, 6:6, bool) 		// Peripheral increment mode
        SBF_FIELD(circ, 5:5, bool) 		// Circular mode
        SBF_FIELD(dir, 4:4, bool) 		// Data transfer direction
        SBF_FIELD(teie, 3:3, bool) 		// Transfer error interrupt enable
        SBF_FIELD(htie, 2:2, bool) 		// Half transfer interrupt enable
        SBF_FIELD(tcie, 1:1, bool) 		// Transfer complete interrupt enable
        SBF_FIELD(en, 0:0, bool) 		// Channel enable
    )
    // channel x number of data register
    // Offset +0x20
    SBF_REGISTER_RW(cndtr2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x peripheral address register
    // Offset +0x24
    SBF_REGISTER_RW(cpar2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x memory address register
    // Offset +0x28
    SBF_REGISTER_RW(cmar2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x2C, uint32_t, 1)
    // channel x configuration register
    // Offset +0x30
    SBF_REGISTER_RW(ccr3, uint32_t, 0x0,
        SBF_FIELD(mem2mem, 14:14, bool) 		// Memory to memory mode
        SBF_FIELD(pl, 13:12, unsigned) 		// Channel priority level
        SBF_FIELD(msize, 11:10, unsigned) 		// Memory size
        SBF_FIELD(psize, 9:8, unsigned) 		// Peripheral size
        SBF_FIELD(minc, 7:7, bool) 		// Memory increment mode
        SBF_FIELD(pinc, 6:6, bool) 		// Peripheral increment mode
        SBF_FIELD(circ, 5:5, bool) 		// Circular mode
        SBF_FIELD(dir, 4:4, bool) 		// Data transfer direction
        SBF_FIELD(teie, 3:3, bool) 		// Transfer error interrupt enable
        SBF_FIELD(htie, 2:2, bool) 		// Half transfer interrupt enable
        SBF_FIELD(tcie, 1:1, bool) 		// Transfer complete interrupt enable
        SBF_FIELD(en, 0:0, bool) 		// Channel enable
    )
    // channel x number of data register
    // Offset +0x34
    SBF_REGISTER_RW(cndtr3, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x peripheral address register
    // Offset +0x38
    SBF_REGISTER_RW(cpar3, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x memory address register
    // Offset +0x3C
    SBF_REGISTER_RW(cmar3, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x40, uint32_t, 1)
    // channel x configuration register
    // Offset +0x44
    SBF_REGISTER_RW(ccr4, uint32_t, 0x0,
        SBF_FIELD(mem2mem, 14:14, bool) 		// Memory to memory mode
        SBF_FIELD(pl, 13:12, unsigned) 		// Channel priority level
        SBF_FIELD(msize, 11:10, unsigned) 		// Memory size
        SBF_FIELD(psize, 9:8, unsigned) 		// Peripheral size
        SBF_FIELD(minc, 7:7, bool) 		// Memory increment mode
        SBF_FIELD(pinc, 6:6, bool) 		// Peripheral increment mode
        SBF_FIELD(circ, 5:5, bool) 		// Circular mode
        SBF_FIELD(dir, 4:4, bool) 		// Data transfer direction
        SBF_FIELD(teie, 3:3, bool) 		// Transfer error interrupt enable
        SBF_FIELD(htie, 2:2, bool) 		// Half transfer interrupt enable
        SBF_FIELD(tcie, 1:1, bool) 		// Transfer complete interrupt enable
        SBF_FIELD(en, 0:0, bool) 		// Channel enable
    )
    // channel x number of data register
    // Offset +0x48
    SBF_REGISTER_RW(cndtr4, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x peripheral address register
    // Offset +0x4C
    SBF_REGISTER_RW(cpar4, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x memory address register
    // Offset +0x50
    SBF_REGISTER_RW(cmar4, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x54, uint32_t, 1)
    // channel x configuration register
    // Offset +0x58
    SBF_REGISTER_RW(ccr5, uint32_t, 0x0,
        SBF_FIELD(mem2mem, 14:14, bool) 		// Memory to memory mode
        SBF_FIELD(pl, 13:12, unsigned) 		// Channel priority level
        SBF_FIELD(msize, 11:10, unsigned) 		// Memory size
        SBF_FIELD(psize, 9:8, unsigned) 		// Peripheral size
        SBF_FIELD(minc, 7:7, bool) 		// Memory increment mode
        SBF_FIELD(pinc, 6:6, bool) 		// Peripheral increment mode
        SBF_FIELD(circ, 5:5, bool) 		// Circular mode
        SBF_FIELD(dir, 4:4, bool) 		// Data transfer direction
        SBF_FIELD(teie, 3:3, bool) 		// Transfer error interrupt enable
        SBF_FIELD(htie, 2:2, bool) 		// Half transfer interrupt enable
        SBF_FIELD(tcie, 1:1, bool) 		// Transfer complete interrupt enable
        SBF_FIELD(en, 0:0, bool) 		// Channel enable
    )
    // channel x number of data register
    // Offset +0x5C
    SBF_REGISTER_RW(cndtr5, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x peripheral address register
    // Offset +0x60
    SBF_REGISTER_RW(cpar5, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x memory address register
    // Offset +0x64
    SBF_REGISTER_RW(cmar5, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x68, uint32_t, 1)
    // channel x configuration register
    // Offset +0x6C
    SBF_REGISTER_RW(ccr6, uint32_t, 0x0,
        SBF_FIELD(mem2mem, 14:14, bool) 		// Memory to memory mode
        SBF_FIELD(pl, 13:12, unsigned) 		// Channel priority level
        SBF_FIELD(msize, 11:10, unsigned) 		// Memory size
        SBF_FIELD(psize, 9:8, unsigned) 		// Peripheral size
        SBF_FIELD(minc, 7:7, bool) 		// Memory increment mode
        SBF_FIELD(pinc, 6:6, bool) 		// Peripheral increment mode
        SBF_FIELD(circ, 5:5, bool) 		// Circular mode
        SBF_FIELD(dir, 4:4, bool) 		// Data transfer direction
        SBF_FIELD(teie, 3:3, bool) 		// Transfer error interrupt enable
        SBF_FIELD(htie, 2:2, bool) 		// Half transfer interrupt enable
        SBF_FIELD(tcie, 1:1, bool) 		// Transfer complete interrupt enable
        SBF_FIELD(en, 0:0, bool) 		// Channel enable
    )
    // channel x number of data register
    // Offset +0x70
    SBF_REGISTER_RW(cndtr6, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x peripheral address register
    // Offset +0x74
    SBF_REGISTER_RW(cpar6, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x memory address register
    // Offset +0x78
    SBF_REGISTER_RW(cmar6, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x7C, uint32_t, 1)
    // channel x configuration register
    // Offset +0x80
    SBF_REGISTER_RW(ccr7, uint32_t, 0x0,
        SBF_FIELD(mem2mem, 14:14, bool) 		// Memory to memory mode
        SBF_FIELD(pl, 13:12, unsigned) 		// Channel priority level
        SBF_FIELD(msize, 11:10, unsigned) 		// Memory size
        SBF_FIELD(psize, 9:8, unsigned) 		// Peripheral size
        SBF_FIELD(minc, 7:7, bool) 		// Memory increment mode
        SBF_FIELD(pinc, 6:6, bool) 		// Peripheral increment mode
        SBF_FIELD(circ, 5:5, bool) 		// Circular mode
        SBF_FIELD(dir, 4:4, bool) 		// Data transfer direction
        SBF_FIELD(teie, 3:3, bool) 		// Transfer error interrupt enable
        SBF_FIELD(htie, 2:2, bool) 		// Half transfer interrupt enable
        SBF_FIELD(tcie, 1:1, bool) 		// Transfer complete interrupt enable
        SBF_FIELD(en, 0:0, bool) 		// Channel enable
    )
    // channel x number of data register
    // Offset +0x84
    SBF_REGISTER_RW(cndtr7, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x peripheral address register
    // Offset +0x88
    SBF_REGISTER_RW(cpar7, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // channel x memory address register
    // Offset +0x8C
    SBF_REGISTER_RW(cmar7, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x90_to_0xA4, uint32_t, 6)
    // channel selection register
    // Offset +0xA8
    SBF_REGISTER_RW(cselr, uint32_t, 0x0,
        SBF_FIELD(c7s, 27:24, unsigned) 		// DMA channel 7 selection
        SBF_FIELD(c6s, 23:20, unsigned) 		// DMA channel 6 selection
        SBF_FIELD(c5s, 19:16, unsigned) 		// DMA channel 5 selection
        SBF_FIELD(c4s, 15:12, unsigned) 		// DMA channel 4 selection
        SBF_FIELD(c3s, 11:8, unsigned) 		// DMA channel 3 selection
        SBF_FIELD(c2s, 7:4, unsigned) 		// DMA channel 2 selection
        SBF_FIELD(c1s, 3:0, unsigned) 		// DMA channel 1 selection
    )

}; // Dma registers


// Exti registers
struct Exti {
    // Interrupt mask register
    // Offset +0x0
    SBF_REGISTER_RW(imr1, uint32_t, 0xFF820000,
        SBF_FIELD(mr31, 31:31, bool) 		// Interrupt Mask on line 31
        SBF_FIELD(mr30, 30:30, bool) 		// Interrupt Mask on line 30
        SBF_FIELD(mr29, 29:29, bool) 		// Interrupt Mask on line 29
        SBF_FIELD(mr28, 28:28, bool) 		// Interrupt Mask on line 28
        SBF_FIELD(mr27, 27:27, bool) 		// Interrupt Mask on line 27
        SBF_FIELD(mr26, 26:26, bool) 		// Interrupt Mask on line 26
        SBF_FIELD(mr25, 25:25, bool) 		// Interrupt Mask on line 25
        SBF_FIELD(mr24, 24:24, bool) 		// Interrupt Mask on line 24
        SBF_FIELD(mr23, 23:23, bool) 		// Interrupt Mask on line 23
        SBF_FIELD(mr22, 22:22, bool) 		// Interrupt Mask on line 22
        SBF_FIELD(mr21, 21:21, bool) 		// Interrupt Mask on line 21
        SBF_FIELD(mr20, 20:20, bool) 		// Interrupt Mask on line 20
        SBF_FIELD(mr19, 19:19, bool) 		// Interrupt Mask on line 19
        SBF_FIELD(mr18, 18:18, bool) 		// Interrupt Mask on line 18
        SBF_FIELD(mr17, 17:17, bool) 		// Interrupt Mask on line 17
        SBF_FIELD(mr16, 16:16, bool) 		// Interrupt Mask on line 16
        SBF_FIELD(mr15, 15:15, bool) 		// Interrupt Mask on line 15
        SBF_FIELD(mr14, 14:14, bool) 		// Interrupt Mask on line 14
        SBF_FIELD(mr13, 13:13, bool) 		// Interrupt Mask on line 13
        SBF_FIELD(mr12, 12:12, bool) 		// Interrupt Mask on line 12
        SBF_FIELD(mr11, 11:11, bool) 		// Interrupt Mask on line 11
        SBF_FIELD(mr10, 10:10, bool) 		// Interrupt Mask on line 10
        SBF_FIELD(mr9, 9:9, bool) 		// Interrupt Mask on line 9
        SBF_FIELD(mr8, 8:8, bool) 		// Interrupt Mask on line 8
        SBF_FIELD(mr7, 7:7, bool) 		// Interrupt Mask on line 7
        SBF_FIELD(mr6, 6:6, bool) 		// Interrupt Mask on line 6
        SBF_FIELD(mr5, 5:5, bool) 		// Interrupt Mask on line 5
        SBF_FIELD(mr4, 4:4, bool) 		// Interrupt Mask on line 4
        SBF_FIELD(mr3, 3:3, bool) 		// Interrupt Mask on line 3
        SBF_FIELD(mr2, 2:2, bool) 		// Interrupt Mask on line 2
        SBF_FIELD(mr1, 1:1, bool) 		// Interrupt Mask on line 1
        SBF_FIELD(mr0, 0:0, bool) 		// Interrupt Mask on line 0
    )
    // Event mask register
    // Offset +0x4
    SBF_REGISTER_RW(emr1, uint32_t, 0x0,
        SBF_FIELD(mr31, 31:31, bool) 		// Event Mask on line 31
        SBF_FIELD(mr30, 30:30, bool) 		// Event Mask on line 30
        SBF_FIELD(mr29, 29:29, bool) 		// Event Mask on line 29
        SBF_FIELD(mr28, 28:28, bool) 		// Event Mask on line 28
        SBF_FIELD(mr27, 27:27, bool) 		// Event Mask on line 27
        SBF_FIELD(mr26, 26:26, bool) 		// Event Mask on line 26
        SBF_FIELD(mr25, 25:25, bool) 		// Event Mask on line 25
        SBF_FIELD(mr24, 24:24, bool) 		// Event Mask on line 24
        SBF_FIELD(mr23, 23:23, bool) 		// Event Mask on line 23
        SBF_FIELD(mr22, 22:22, bool) 		// Event Mask on line 22
        SBF_FIELD(mr21, 21:21, bool) 		// Event Mask on line 21
        SBF_FIELD(mr20, 20:20, bool) 		// Event Mask on line 20
        SBF_FIELD(mr19, 19:19, bool) 		// Event Mask on line 19
        SBF_FIELD(mr18, 18:18, bool) 		// Event Mask on line 18
        SBF_FIELD(mr17, 17:17, bool) 		// Event Mask on line 17
        SBF_FIELD(mr16, 16:16, bool) 		// Event Mask on line 16
        SBF_FIELD(mr15, 15:15, bool) 		// Event Mask on line 15
        SBF_FIELD(mr14, 14:14, bool) 		// Event Mask on line 14
        SBF_FIELD(mr13, 13:13, bool) 		// Event Mask on line 13
        SBF_FIELD(mr12, 12:12, bool) 		// Event Mask on line 12
        SBF_FIELD(mr11, 11:11, bool) 		// Event Mask on line 11
        SBF_FIELD(mr10, 10:10, bool) 		// Event Mask on line 10
        SBF_FIELD(mr9, 9:9, bool) 		// Event Mask on line 9
        SBF_FIELD(mr8, 8:8, bool) 		// Event Mask on line 8
        SBF_FIELD(mr7, 7:7, bool) 		// Event Mask on line 7
        SBF_FIELD(mr6, 6:6, bool) 		// Event Mask on line 6
        SBF_FIELD(mr5, 5:5, bool) 		// Event Mask on line 5
        SBF_FIELD(mr4, 4:4, bool) 		// Event Mask on line 4
        SBF_FIELD(mr3, 3:3, bool) 		// Event Mask on line 3
        SBF_FIELD(mr2, 2:2, bool) 		// Event Mask on line 2
        SBF_FIELD(mr1, 1:1, bool) 		// Event Mask on line 1
        SBF_FIELD(mr0, 0:0, bool) 		// Event Mask on line 0
    )
    // Rising Trigger selection register
    // Offset +0x8
    SBF_REGISTER_RW(rtsr1, uint32_t, 0x0,
        SBF_FIELD(tr22, 22:22, bool) 		// Rising trigger event configuration of line 22
        SBF_FIELD(tr21, 21:21, bool) 		// Rising trigger event configuration of line 21
        SBF_FIELD(tr20, 20:20, bool) 		// Rising trigger event configuration of line 20
        SBF_FIELD(tr19, 19:19, bool) 		// Rising trigger event configuration of line 19
        SBF_FIELD(tr18, 18:18, bool) 		// Rising trigger event configuration of line 18
        SBF_FIELD(tr16, 16:16, bool) 		// Rising trigger event configuration of line 16
        SBF_FIELD(tr15, 15:15, bool) 		// Rising trigger event configuration of line 15
        SBF_FIELD(tr14, 14:14, bool) 		// Rising trigger event configuration of line 14
        SBF_FIELD(tr13, 13:13, bool) 		// Rising trigger event configuration of line 13
        SBF_FIELD(tr12, 12:12, bool) 		// Rising trigger event configuration of line 12
        SBF_FIELD(tr11, 11:11, bool) 		// Rising trigger event configuration of line 11
        SBF_FIELD(tr10, 10:10, bool) 		// Rising trigger event configuration of line 10
        SBF_FIELD(tr9, 9:9, bool) 		// Rising trigger event configuration of line 9
        SBF_FIELD(tr8, 8:8, bool) 		// Rising trigger event configuration of line 8
        SBF_FIELD(tr7, 7:7, bool) 		// Rising trigger event configuration of line 7
        SBF_FIELD(tr6, 6:6, bool) 		// Rising trigger event configuration of line 6
        SBF_FIELD(tr5, 5:5, bool) 		// Rising trigger event configuration of line 5
        SBF_FIELD(tr4, 4:4, bool) 		// Rising trigger event configuration of line 4
        SBF_FIELD(tr3, 3:3, bool) 		// Rising trigger event configuration of line 3
        SBF_FIELD(tr2, 2:2, bool) 		// Rising trigger event configuration of line 2
        SBF_FIELD(tr1, 1:1, bool) 		// Rising trigger event configuration of line 1
        SBF_FIELD(tr0, 0:0, bool) 		// Rising trigger event configuration of line 0
    )
    // Falling Trigger selection register
    // Offset +0xC
    SBF_REGISTER_RW(ftsr1, uint32_t, 0x0,
        SBF_FIELD(tr22, 22:22, bool) 		// Falling trigger event configuration of line 22
        SBF_FIELD(tr21, 21:21, bool) 		// Falling trigger event configuration of line 21
        SBF_FIELD(tr20, 20:20, bool) 		// Falling trigger event configuration of line 20
        SBF_FIELD(tr19, 19:19, bool) 		// Falling trigger event configuration of line 19
        SBF_FIELD(tr18, 18:18, bool) 		// Falling trigger event configuration of line 18
        SBF_FIELD(tr16, 16:16, bool) 		// Falling trigger event configuration of line 16
        SBF_FIELD(tr15, 15:15, bool) 		// Falling trigger event configuration of line 15
        SBF_FIELD(tr14, 14:14, bool) 		// Falling trigger event configuration of line 14
        SBF_FIELD(tr13, 13:13, bool) 		// Falling trigger event configuration of line 13
        SBF_FIELD(tr12, 12:12, bool) 		// Falling trigger event configuration of line 12
        SBF_FIELD(tr11, 11:11, bool) 		// Falling trigger event configuration of line 11
        SBF_FIELD(tr10, 10:10, bool) 		// Falling trigger event configuration of line 10
        SBF_FIELD(tr9, 9:9, bool) 		// Falling trigger event configuration of line 9
        SBF_FIELD(tr8, 8:8, bool) 		// Falling trigger event configuration of line 8
        SBF_FIELD(tr7, 7:7, bool) 		// Falling trigger event configuration of line 7
        SBF_FIELD(tr6, 6:6, bool) 		// Falling trigger event configuration of line 6
        SBF_FIELD(tr5, 5:5, bool) 		// Falling trigger event configuration of line 5
        SBF_FIELD(tr4, 4:4, bool) 		// Falling trigger event configuration of line 4
        SBF_FIELD(tr3, 3:3, bool) 		// Falling trigger event configuration of line 3
        SBF_FIELD(tr2, 2:2, bool) 		// Falling trigger event configuration of line 2
        SBF_FIELD(tr1, 1:1, bool) 		// Falling trigger event configuration of line 1
        SBF_FIELD(tr0, 0:0, bool) 		// Falling trigger event configuration of line 0
    )
    // Software interrupt event register
    // Offset +0x10
    SBF_REGISTER_RW(swier1, uint32_t, 0x0,
        SBF_FIELD(swier22, 22:22, bool) 		// Software Interrupt on line 22
        SBF_FIELD(swier21, 21:21, bool) 		// Software Interrupt on line 21
        SBF_FIELD(swier20, 20:20, bool) 		// Software Interrupt on line 20
        SBF_FIELD(swier19, 19:19, bool) 		// Software Interrupt on line 19
        SBF_FIELD(swier18, 18:18, bool) 		// Software Interrupt on line 18
        SBF_FIELD(swier16, 16:16, bool) 		// Software Interrupt on line 16
        SBF_FIELD(swier15, 15:15, bool) 		// Software Interrupt on line 15
        SBF_FIELD(swier14, 14:14, bool) 		// Software Interrupt on line 14
        SBF_FIELD(swier13, 13:13, bool) 		// Software Interrupt on line 13
        SBF_FIELD(swier12, 12:12, bool) 		// Software Interrupt on line 12
        SBF_FIELD(swier11, 11:11, bool) 		// Software Interrupt on line 11
        SBF_FIELD(swier10, 10:10, bool) 		// Software Interrupt on line 10
        SBF_FIELD(swier9, 9:9, bool) 		// Software Interrupt on line 9
        SBF_FIELD(swier8, 8:8, bool) 		// Software Interrupt on line 8
        SBF_FIELD(swier7, 7:7, bool) 		// Software Interrupt on line 7
        SBF_FIELD(swier6, 6:6, bool) 		// Software Interrupt on line 6
        SBF_FIELD(swier5, 5:5, bool) 		// Software Interrupt on line 5
        SBF_FIELD(swier4, 4:4, bool) 		// Software Interrupt on line 4
        SBF_FIELD(swier3, 3:3, bool) 		// Software Interrupt on line 3
        SBF_FIELD(swier2, 2:2, bool) 		// Software Interrupt on line 2
        SBF_FIELD(swier1, 1:1, bool) 		// Software Interrupt on line 1
        SBF_FIELD(swier0, 0:0, bool) 		// Software Interrupt on line 0
    )
    // Pending register
    // Offset +0x14
    SBF_REGISTER_RW(pr1, uint32_t, 0x0,
        SBF_FIELD(pr22, 22:22, bool) 		// Pending bit 22
        SBF_FIELD(pr21, 21:21, bool) 		// Pending bit 21
        SBF_FIELD(pr20, 20:20, bool) 		// Pending bit 20
        SBF_FIELD(pr19, 19:19, bool) 		// Pending bit 19
        SBF_FIELD(pr18, 18:18, bool) 		// Pending bit 18
        SBF_FIELD(pr16, 16:16, bool) 		// Pending bit 16
        SBF_FIELD(pr15, 15:15, bool) 		// Pending bit 15
        SBF_FIELD(pr14, 14:14, bool) 		// Pending bit 14
        SBF_FIELD(pr13, 13:13, bool) 		// Pending bit 13
        SBF_FIELD(pr12, 12:12, bool) 		// Pending bit 12
        SBF_FIELD(pr11, 11:11, bool) 		// Pending bit 11
        SBF_FIELD(pr10, 10:10, bool) 		// Pending bit 10
        SBF_FIELD(pr9, 9:9, bool) 		// Pending bit 9
        SBF_FIELD(pr8, 8:8, bool) 		// Pending bit 8
        SBF_FIELD(pr7, 7:7, bool) 		// Pending bit 7
        SBF_FIELD(pr6, 6:6, bool) 		// Pending bit 6
        SBF_FIELD(pr5, 5:5, bool) 		// Pending bit 5
        SBF_FIELD(pr4, 4:4, bool) 		// Pending bit 4
        SBF_FIELD(pr3, 3:3, bool) 		// Pending bit 3
        SBF_FIELD(pr2, 2:2, bool) 		// Pending bit 2
        SBF_FIELD(pr1, 1:1, bool) 		// Pending bit 1
        SBF_FIELD(pr0, 0:0, bool) 		// Pending bit 0
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x18_to_0x1C, uint32_t, 2)
    // Interrupt mask register
    // Offset +0x20
    SBF_REGISTER_RW(imr2, uint32_t, 0xFFFFFF87,
        SBF_FIELD(mr39, 7:7, bool) 		// Interrupt Mask on external/internal line 39
        SBF_FIELD(mr38, 6:6, bool) 		// Interrupt Mask on external/internal line 38
        SBF_FIELD(mr37, 5:5, bool) 		// Interrupt Mask on external/internal line 37
        SBF_FIELD(mr36, 4:4, bool) 		// Interrupt Mask on external/internal line 36
        SBF_FIELD(mr35, 3:3, bool) 		// Interrupt Mask on external/internal line 35
        SBF_FIELD(mr34, 2:2, bool) 		// Interrupt Mask on external/internal line 34
        SBF_FIELD(mr33, 1:1, bool) 		// Interrupt Mask on external/internal line 33
        SBF_FIELD(mr32, 0:0, bool) 		// Interrupt Mask on external/internal line 32
    )
    // Event mask register
    // Offset +0x24
    SBF_REGISTER_RW(emr2, uint32_t, 0x0,
        SBF_FIELD(mr39, 7:7, bool) 		// Event mask on external/internal line 39
        SBF_FIELD(mr38, 6:6, bool) 		// Event mask on external/internal line 38
        SBF_FIELD(mr37, 5:5, bool) 		// Event mask on external/internal line 37
        SBF_FIELD(mr36, 4:4, bool) 		// Event mask on external/internal line 36
        SBF_FIELD(mr35, 3:3, bool) 		// Event mask on external/internal line 35
        SBF_FIELD(mr34, 2:2, bool) 		// Event mask on external/internal line 34
        SBF_FIELD(mr33, 1:1, bool) 		// Event mask on external/internal line 33
        SBF_FIELD(mr32, 0:0, bool) 		// Event mask on external/internal line 32
    )
    // Rising Trigger selection register
    // Offset +0x28
    SBF_REGISTER_RW(rtsr2, uint32_t, 0x0,
        SBF_FIELD(rt38, 6:6, bool) 		// Rising trigger event configuration bit of line 38
        SBF_FIELD(rt37, 5:5, bool) 		// Rising trigger event configuration bit of line 37
        SBF_FIELD(rt36, 4:4, bool) 		// Rising trigger event configuration bit of line 36
        SBF_FIELD(rt35, 3:3, bool) 		// Rising trigger event configuration bit of line 35
    )
    // Falling Trigger selection register
    // Offset +0x2C
    SBF_REGISTER_RW(ftsr2, uint32_t, 0x0,
        SBF_FIELD(ft38, 6:6, bool) 		// Falling trigger event configuration bit of line 38
        SBF_FIELD(ft37, 5:5, bool) 		// Falling trigger event configuration bit of line 37
        SBF_FIELD(ft36, 4:4, bool) 		// Falling trigger event configuration bit of line 36
        SBF_FIELD(ft35, 3:3, bool) 		// Falling trigger event configuration bit of line 35
    )
    // Software interrupt event register
    // Offset +0x30
    SBF_REGISTER_RW(swier2, uint32_t, 0x0,
        SBF_FIELD(swi38, 6:6, bool) 		// Software interrupt on line 38
        SBF_FIELD(swi37, 5:5, bool) 		// Software interrupt on line 37
        SBF_FIELD(swi36, 4:4, bool) 		// Software interrupt on line 36
        SBF_FIELD(swi35, 3:3, bool) 		// Software interrupt on line 35
    )
    // Pending register
    // Offset +0x34
    SBF_REGISTER_RW(pr2, uint32_t, 0x0,
        SBF_FIELD(pif38, 6:6, bool) 		// Pending interrupt flag on line 38
        SBF_FIELD(pif37, 5:5, bool) 		// Pending interrupt flag on line 37
        SBF_FIELD(pif36, 4:4, bool) 		// Pending interrupt flag on line 36
        SBF_FIELD(pif35, 3:3, bool) 		// Pending interrupt flag on line 35
    )

}; // Exti registers


// Fsmc registers
struct Fsmc {
    // SRAM/NOR-Flash chip-select control register 1
    // Offset +0x0
    SBF_REGISTER_RW(bcr1, uint32_t, 0x30D0,
        SBF_FIELD(wfdis, 21:21, bool) 		// Write FIFO Disable
        SBF_FIELD(cclken, 20:20, bool) 		// CCLKEN
        SBF_FIELD(cburstrw, 19:19, bool) 		// CBURSTRW
        SBF_FIELD(asyncwait, 15:15, bool) 		// ASYNCWAIT
        SBF_FIELD(extmod, 14:14, bool) 		// EXTMOD
        SBF_FIELD(waiten, 13:13, bool) 		// WAITEN
        SBF_FIELD(wren, 12:12, bool) 		// WREN
        SBF_FIELD(waitcfg, 11:11, bool) 		// WAITCFG
        SBF_FIELD(waitpol, 9:9, bool) 		// WAITPOL
        SBF_FIELD(bursten, 8:8, bool) 		// BURSTEN
        SBF_FIELD(faccen, 6:6, bool) 		// FACCEN
        SBF_FIELD(mwid, 5:4, unsigned) 		// MWID
        SBF_FIELD(mtyp, 3:2, unsigned) 		// MTYP
        SBF_FIELD(muxen, 1:1, bool) 		// MUXEN
        SBF_FIELD(mbken, 0:0, bool) 		// MBKEN
    )
    // SRAM/NOR-Flash chip-select timing register 1
    // Offset +0x4
    SBF_REGISTER_RW(btr1, uint32_t, 0xFFFFFFFF,
        SBF_FIELD(accmod, 29:28, unsigned) 		// ACCMOD
        SBF_FIELD(datlat, 27:24, unsigned) 		// DATLAT
        SBF_FIELD(clkdiv, 23:20, unsigned) 		// CLKDIV
        SBF_FIELD(busturn, 19:16, unsigned) 		// BUSTURN
        SBF_FIELD(datast, 15:8, unsigned) 		// DATAST
        SBF_FIELD(addhld, 7:4, unsigned) 		// ADDHLD
        SBF_FIELD(addset, 3:0, unsigned) 		// ADDSET
    )
    // SRAM/NOR-Flash chip-select control register 2
    // Offset +0x8
    SBF_REGISTER_RW(bcr2, uint32_t, 0x30D0,
        SBF_FIELD(cburstrw, 19:19, bool) 		// CBURSTRW
        SBF_FIELD(asyncwait, 15:15, bool) 		// ASYNCWAIT
        SBF_FIELD(extmod, 14:14, bool) 		// EXTMOD
        SBF_FIELD(waiten, 13:13, bool) 		// WAITEN
        SBF_FIELD(wren, 12:12, bool) 		// WREN
        SBF_FIELD(waitcfg, 11:11, bool) 		// WAITCFG
        SBF_FIELD(wrapmod, 10:10, bool) 		// WRAPMOD
        SBF_FIELD(waitpol, 9:9, bool) 		// WAITPOL
        SBF_FIELD(bursten, 8:8, bool) 		// BURSTEN
        SBF_FIELD(faccen, 6:6, bool) 		// FACCEN
        SBF_FIELD(mwid, 5:4, unsigned) 		// MWID
        SBF_FIELD(mtyp, 3:2, unsigned) 		// MTYP
        SBF_FIELD(muxen, 1:1, bool) 		// MUXEN
        SBF_FIELD(mbken, 0:0, bool) 		// MBKEN
    )
    // SRAM/NOR-Flash chip-select timing register 2
    // Offset +0xC
    SBF_REGISTER_RW(btr2, uint32_t, 0xFFFFFFFF,
        SBF_FIELD(accmod, 29:28, unsigned) 		// ACCMOD
        SBF_FIELD(datlat, 27:24, unsigned) 		// DATLAT
        SBF_FIELD(clkdiv, 23:20, unsigned) 		// CLKDIV
        SBF_FIELD(busturn, 19:16, unsigned) 		// BUSTURN
        SBF_FIELD(datast, 15:8, unsigned) 		// DATAST
        SBF_FIELD(addhld, 7:4, unsigned) 		// ADDHLD
        SBF_FIELD(addset, 3:0, unsigned) 		// ADDSET
    )
    // SRAM/NOR-Flash chip-select control register 3
    // Offset +0x10
    SBF_REGISTER_RW(bcr3, uint32_t, 0x30D0,
        SBF_FIELD(cburstrw, 19:19, bool) 		// CBURSTRW
        SBF_FIELD(asyncwait, 15:15, bool) 		// ASYNCWAIT
        SBF_FIELD(extmod, 14:14, bool) 		// EXTMOD
        SBF_FIELD(waiten, 13:13, bool) 		// WAITEN
        SBF_FIELD(wren, 12:12, bool) 		// WREN
        SBF_FIELD(waitcfg, 11:11, bool) 		// WAITCFG
        SBF_FIELD(wrapmod, 10:10, bool) 		// WRAPMOD
        SBF_FIELD(waitpol, 9:9, bool) 		// WAITPOL
        SBF_FIELD(bursten, 8:8, bool) 		// BURSTEN
        SBF_FIELD(faccen, 6:6, bool) 		// FACCEN
        SBF_FIELD(mwid, 5:4, unsigned) 		// MWID
        SBF_FIELD(mtyp, 3:2, unsigned) 		// MTYP
        SBF_FIELD(muxen, 1:1, bool) 		// MUXEN
        SBF_FIELD(mbken, 0:0, bool) 		// MBKEN
    )
    // SRAM/NOR-Flash chip-select timing register 3
    // Offset +0x14
    SBF_REGISTER_RW(btr3, uint32_t, 0xFFFFFFFF,
        SBF_FIELD(accmod, 29:28, unsigned) 		// ACCMOD
        SBF_FIELD(datlat, 27:24, unsigned) 		// DATLAT
        SBF_FIELD(clkdiv, 23:20, unsigned) 		// CLKDIV
        SBF_FIELD(busturn, 19:16, unsigned) 		// BUSTURN
        SBF_FIELD(datast, 15:8, unsigned) 		// DATAST
        SBF_FIELD(addhld, 7:4, unsigned) 		// ADDHLD
        SBF_FIELD(addset, 3:0, unsigned) 		// ADDSET
    )
    // SRAM/NOR-Flash chip-select control register 4
    // Offset +0x18
    SBF_REGISTER_RW(bcr4, uint32_t, 0x30D0,
        SBF_FIELD(cburstrw, 19:19, bool) 		// CBURSTRW
        SBF_FIELD(asyncwait, 15:15, bool) 		// ASYNCWAIT
        SBF_FIELD(extmod, 14:14, bool) 		// EXTMOD
        SBF_FIELD(waiten, 13:13, bool) 		// WAITEN
        SBF_FIELD(wren, 12:12, bool) 		// WREN
        SBF_FIELD(waitcfg, 11:11, bool) 		// WAITCFG
        SBF_FIELD(wrapmod, 10:10, bool) 		// WRAPMOD
        SBF_FIELD(waitpol, 9:9, bool) 		// WAITPOL
        SBF_FIELD(bursten, 8:8, bool) 		// BURSTEN
        SBF_FIELD(faccen, 6:6, bool) 		// FACCEN
        SBF_FIELD(mwid, 5:4, unsigned) 		// MWID
        SBF_FIELD(mtyp, 3:2, unsigned) 		// MTYP
        SBF_FIELD(muxen, 1:1, bool) 		// MUXEN
        SBF_FIELD(mbken, 0:0, bool) 		// MBKEN
    )
    // SRAM/NOR-Flash chip-select timing register 4
    // Offset +0x1C
    SBF_REGISTER_RW(btr4, uint32_t, 0xFFFFFFFF,
        SBF_FIELD(accmod, 29:28, unsigned) 		// ACCMOD
        SBF_FIELD(datlat, 27:24, unsigned) 		// DATLAT
        SBF_FIELD(clkdiv, 23:20, unsigned) 		// CLKDIV
        SBF_FIELD(busturn, 19:16, unsigned) 		// BUSTURN
        SBF_FIELD(datast, 15:8, unsigned) 		// DATAST
        SBF_FIELD(addhld, 7:4, unsigned) 		// ADDHLD
        SBF_FIELD(addset, 3:0, unsigned) 		// ADDSET
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x20_to_0x7C, uint32_t, 24)
    // PC Card/NAND Flash control register 3
    // Offset +0x80
    SBF_REGISTER_RW(pcr, uint32_t, 0x18,
        SBF_FIELD(eccps, 19:17, unsigned) 		// ECCPS
        SBF_FIELD(tar, 16:13, unsigned) 		// TAR
        SBF_FIELD(tclr, 12:9, unsigned) 		// TCLR
        SBF_FIELD(eccen, 6:6, bool) 		// ECCEN
        SBF_FIELD(pwid, 5:4, unsigned) 		// PWID
        SBF_FIELD(ptyp, 3:3, bool) 		// PTYP
        SBF_FIELD(pbken, 2:2, bool) 		// PBKEN
        SBF_FIELD(pwaiten, 1:1, bool) 		// PWAITEN
    )
    // FIFO status and interrupt register 3
    // Offset +0x84
    SBF_REGISTER_RW(sr, uint32_t, 0x40,
        SBF_FIELD(fempt, 6:6, bool) 		// FEMPT
        SBF_FIELD(ifen, 5:5, bool) 		// IFEN
        SBF_FIELD(ilen, 4:4, bool) 		// ILEN
        SBF_FIELD(iren, 3:3, bool) 		// IREN
        SBF_FIELD(ifs, 2:2, bool) 		// IFS
        SBF_FIELD(ils, 1:1, bool) 		// ILS
        SBF_FIELD(irs, 0:0, bool) 		// IRS
    )
    // Common memory space timing register 3
    // Offset +0x88
    SBF_REGISTER_RW(pmem, uint32_t, 0xFCFCFCFC,
        SBF_FIELD(memhizx, 31:24, unsigned) 		// MEMHIZx
        SBF_FIELD(memholdx, 23:16, unsigned) 		// MEMHOLDx
        SBF_FIELD(memwaitx, 15:8, unsigned) 		// MEMWAITx
        SBF_FIELD(memsetx, 7:0, unsigned) 		// MEMSETx
    )
    // Attribute memory space timing register 3
    // Offset +0x8C
    SBF_REGISTER_RW(patt, uint32_t, 0xFCFCFCFC,
        SBF_FIELD(atthizx, 31:24, unsigned) 		// ATTHIZx
        SBF_FIELD(attholdx, 23:16, unsigned) 		// ATTHOLDx
        SBF_FIELD(attwaitx, 15:8, unsigned) 		// ATTWAITx
        SBF_FIELD(attsetx, 7:0, unsigned) 		// ATTSETx
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x90, uint32_t, 1)
    // ECC result register 3
    // Offset +0x94
    SBF_REGISTER_RO(eccr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x98_to_0x100, uint32_t, 27)
    // SRAM/NOR-Flash write timing registers 1
    // Offset +0x104
    SBF_REGISTER_RW(bwtr1, uint32_t, 0xFFFFFFF,
        SBF_FIELD(accmod, 29:28, unsigned) 		// ACCMOD
        SBF_FIELD(datlat, 27:24, unsigned) 		// DATLAT
        SBF_FIELD(clkdiv, 23:20, unsigned) 		// CLKDIV
        SBF_FIELD(datast, 15:8, unsigned) 		// DATAST
        SBF_FIELD(addhld, 7:4, unsigned) 		// ADDHLD
        SBF_FIELD(addset, 3:0, unsigned) 		// ADDSET
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x108, uint32_t, 1)
    // SRAM/NOR-Flash write timing registers 2
    // Offset +0x10C
    SBF_REGISTER_RW(bwtr2, uint32_t, 0xFFFFFFF,
        SBF_FIELD(accmod, 29:28, unsigned) 		// ACCMOD
        SBF_FIELD(datlat, 27:24, unsigned) 		// DATLAT
        SBF_FIELD(clkdiv, 23:20, unsigned) 		// CLKDIV
        SBF_FIELD(datast, 15:8, unsigned) 		// DATAST
        SBF_FIELD(addhld, 7:4, unsigned) 		// ADDHLD
        SBF_FIELD(addset, 3:0, unsigned) 		// ADDSET
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x110, uint32_t, 1)
    // SRAM/NOR-Flash write timing registers 3
    // Offset +0x114
    SBF_REGISTER_RW(bwtr3, uint32_t, 0xFFFFFFF,
        SBF_FIELD(accmod, 29:28, unsigned) 		// ACCMOD
        SBF_FIELD(datlat, 27:24, unsigned) 		// DATLAT
        SBF_FIELD(clkdiv, 23:20, unsigned) 		// CLKDIV
        SBF_FIELD(datast, 15:8, unsigned) 		// DATAST
        SBF_FIELD(addhld, 7:4, unsigned) 		// ADDHLD
        SBF_FIELD(addset, 3:0, unsigned) 		// ADDSET
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x118, uint32_t, 1)
    // SRAM/NOR-Flash write timing registers 4
    // Offset +0x11C
    SBF_REGISTER_RW(bwtr4, uint32_t, 0xFFFFFFF,
        SBF_FIELD(accmod, 29:28, unsigned) 		// ACCMOD
        SBF_FIELD(datlat, 27:24, unsigned) 		// DATLAT
        SBF_FIELD(clkdiv, 23:20, unsigned) 		// CLKDIV
        SBF_FIELD(datast, 15:8, unsigned) 		// DATAST
        SBF_FIELD(addhld, 7:4, unsigned) 		// ADDHLD
        SBF_FIELD(addset, 3:0, unsigned) 		// ADDSET
    )

}; // Fsmc registers


// Firewall registers
struct Firewall {
    // Code segment start address
    // Offset +0x0
    SBF_REGISTER_RW(cssa, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Code segment length
    // Offset +0x4
    SBF_REGISTER_RW(csl, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Non-volatile data segment start address
    // Offset +0x8
    SBF_REGISTER_RW(nvdssa, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Non-volatile data segment length
    // Offset +0xC
    SBF_REGISTER_RW(nvdsl, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Volatile data segment start address
    // Offset +0x10
    SBF_REGISTER_RW(vdssa, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Volatile data segment length
    // Offset +0x14
    SBF_REGISTER_RW(vdsl, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x18_to_0x1C, uint32_t, 2)
    // Configuration register
    // Offset +0x20
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(vde, 2:2, bool) 		// Volatile data execution
        SBF_FIELD(vds, 1:1, bool) 		// Volatile data shared
        SBF_FIELD(fpa, 0:0, bool) 		// Firewall pre alarm
    )

}; // Firewall registers


// Flash registers
struct Flash {
    // Access control register
    // Offset +0x0
    SBF_REGISTER_RW(acr, uint32_t, 0x600,
        SBF_FIELD(sleep_pd, 14:14, bool) 		// Flash Power-down mode during Low-power sleep mode
        SBF_FIELD(run_pd, 13:13, bool) 		// Flash Power-down mode during Low-power run mode
        SBF_FIELD(dcrst, 12:12, bool) 		// Data cache reset
        SBF_FIELD(icrst, 11:11, bool) 		// Instruction cache reset
        SBF_FIELD(dcen, 10:10, bool) 		// Data cache enable
        SBF_FIELD(icen, 9:9, bool) 		// Instruction cache enable
        SBF_FIELD(prften, 8:8, bool) 		// Prefetch enable
        SBF_FIELD(latency, 2:0, unsigned) 		// Latency
    )
    // Power down key register
    // Offset +0x4
    SBF_REGISTER_WO(pdkeyr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Flash key register
    // Offset +0x8
    SBF_REGISTER_WO(keyr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Option byte key register
    // Offset +0xC
    SBF_REGISTER_WO(optkeyr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Status register
    // Offset +0x10
    SBF_REGISTER_RW(sr, uint32_t, 0x0,
        SBF_FIELD(bsy, 16:16, bool) 		// Busy
        SBF_FIELD(optverr, 15:15, bool) 		// Option validity error
        SBF_FIELD(rderr, 14:14, bool) 		// PCROP read error
        SBF_FIELD(fasterr, 9:9, bool) 		// Fast programming error
        SBF_FIELD(miserr, 8:8, bool) 		// Fast programming data miss error
        SBF_FIELD(pgserr, 7:7, bool) 		// Programming sequence error
        SBF_FIELD(sizerr, 6:6, bool) 		// Size error
        SBF_FIELD(pgaerr, 5:5, bool) 		// Programming alignment error
        SBF_FIELD(wrperr, 4:4, bool) 		// Write protected error
        SBF_FIELD(progerr, 3:3, bool) 		// Programming error
        SBF_FIELD(operr, 1:1, bool) 		// Operation error
        SBF_FIELD(eop, 0:0, bool) 		// End of operation
    )
    // Flash control register
    // Offset +0x14
    SBF_REGISTER_RW(cr, uint32_t, 0xC0000000,
        SBF_FIELD(lock, 31:31, bool) 		// FLASH_CR Lock
        SBF_FIELD(optlock, 30:30, bool) 		// Options Lock
        SBF_FIELD(obl_launch, 27:27, bool) 		// Force the option byte loading
        SBF_FIELD(rderrie, 26:26, bool) 		// PCROP read error interrupt enable
        SBF_FIELD(errie, 25:25, bool) 		// Error interrupt enable
        SBF_FIELD(eopie, 24:24, bool) 		// End of operation interrupt enable
        SBF_FIELD(fstpg, 18:18, bool) 		// Fast programming
        SBF_FIELD(optstrt, 17:17, bool) 		// Options modification start
        SBF_FIELD(start, 16:16, bool) 		// Start
        SBF_FIELD(mer2, 15:15, bool) 		// Bank 2 Mass erase
        SBF_FIELD(bker, 11:11, bool) 		// Bank erase
        SBF_FIELD(pnb, 10:3, unsigned) 		// Page number
        SBF_FIELD(mer1, 2:2, bool) 		// Bank 1 Mass erase
        SBF_FIELD(per, 1:1, bool) 		// Page erase
        SBF_FIELD(pg, 0:0, bool) 		// Programming
    )
    // Flash ECC register
    // Offset +0x18
    SBF_REGISTER_RW(eccr, uint32_t, 0x0,
        SBF_FIELD(eccd, 31:31, bool) 		// ECC detection
        SBF_FIELD(eccc, 30:30, bool) 		// ECC correction
        SBF_FIELD(eccie, 24:24, bool) 		// ECC correction interrupt enable
        SBF_FIELD(sysf_ecc, 20:20, bool) 		// System Flash ECC fail
        SBF_FIELD(bk_ecc, 19:19, bool) 		// ECC fail bank
        SBF_FIELD(addr_ecc, 18:0, unsigned) 		// ECC fail address
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x1C, uint32_t, 1)
    // Flash option register
    // Offset +0x20
    SBF_REGISTER_RW(optr, uint32_t, 0xF0000000,
        SBF_FIELD(sram2_rst, 25:25, bool) 		// SRAM2 Erase when system reset
        SBF_FIELD(sram2_pe, 24:24, bool) 		// SRAM2 parity check enable
        SBF_FIELD(nboot1, 23:23, bool) 		// Boot configuration
        SBF_FIELD(dualbank, 21:21, bool) 		// Dual-Bank on 512 KB or 256 KB Flash memory devices
        SBF_FIELD(bfb2, 20:20, bool) 		// Dual-bank boot
        SBF_FIELD(wwdg_sw, 19:19, bool) 		// Window watchdog selection
        SBF_FIELD(iwdg_stdby, 18:18, bool) 		// Independent watchdog counter freeze in Standby mode
        SBF_FIELD(iwdg_stop, 17:17, bool) 		// Independent watchdog counter freeze in Stop mode
        SBF_FIELD(idwg_sw, 16:16, bool) 		// Independent watchdog selection
        SBF_FIELD(nrst_stdby, 13:13, bool) 		// nRST_STDBY
        SBF_FIELD(nrst_stop, 12:12, bool) 		// nRST_STOP
        SBF_FIELD(bor_lev, 10:8, unsigned) 		// BOR reset Level
        SBF_FIELD(rdp, 7:0, unsigned) 		// Read protection level
    )
    // Flash Bank 1 PCROP Start address register
    // Offset +0x24
    SBF_REGISTER_RW(pcrop1sr, uint32_t, 0xFFFF0000,
        SBF_NO_FIELDS
    )
    // Flash Bank 1 PCROP End address register
    // Offset +0x28
    SBF_REGISTER_RW(pcrop1er, uint32_t, 0xFFF0000,
        SBF_FIELD(pcrop_rdp, 31:31, bool) 		// PCROP area preserved when RDP level decreased
        SBF_FIELD(pcrop1_end, 15:0, unsigned) 		// Bank 1 PCROP area end offset
    )
    // Flash Bank 1 WRP area A address register
    // Offset +0x2C
    SBF_REGISTER_RW(wrp1ar, uint32_t, 0xFF00FF00,
        SBF_FIELD(wrp1a_end, 23:16, unsigned) 		// Bank 1 WRP first area A end offset
        SBF_FIELD(wrp1a_strt, 7:0, unsigned) 		// Bank 1 WRP first area start offset
    )
    // Flash Bank 1 WRP area B address register
    // Offset +0x30
    SBF_REGISTER_RW(wrp1br, uint32_t, 0xFF00FF00,
        SBF_FIELD(wrp1b_strt, 23:16, unsigned) 		// Bank 1 WRP second area B end offset
        SBF_FIELD(wrp1b_end, 7:0, unsigned) 		// Bank 1 WRP second area B start offset
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x34_to_0x40, uint32_t, 4)
    // Flash Bank 2 PCROP Start address register
    // Offset +0x44
    SBF_REGISTER_RW(pcrop2sr, uint32_t, 0xFFFF0000,
        SBF_NO_FIELDS
    )
    // Flash Bank 2 PCROP End address register
    // Offset +0x48
    SBF_REGISTER_RW(pcrop2er, uint32_t, 0xFFFF0000,
        SBF_NO_FIELDS
    )
    // Flash Bank 2 WRP area A address register
    // Offset +0x4C
    SBF_REGISTER_RW(wrp2ar, uint32_t, 0xFF00FF00,
        SBF_FIELD(wrp2a_end, 23:16, unsigned) 		// Bank 2 WRP first area A end offset
        SBF_FIELD(wrp2a_strt, 7:0, unsigned) 		// Bank 2 WRP first area A start offset
    )
    // Flash Bank 2 WRP area B address register
    // Offset +0x50
    SBF_REGISTER_RW(wrp2br, uint32_t, 0xFF00FF00,
        SBF_FIELD(wrp2b_end, 23:16, unsigned) 		// Bank 2 WRP second area B end offset
        SBF_FIELD(wrp2b_strt, 7:0, unsigned) 		// Bank 2 WRP second area B start offset
    )

}; // Flash registers


// Gpio registers
struct Gpio {
    // GPIO port mode register
    // Offset +0x0
    SBF_REGISTER_RW(moder, uint32_t, 0x0,
        SBF_FIELD(moder15, 31:30, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder14, 29:28, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder13, 27:26, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder12, 25:24, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder11, 23:22, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder10, 21:20, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder9, 19:18, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder8, 17:16, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder7, 15:14, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder6, 13:12, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder5, 11:10, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder4, 9:8, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder3, 7:6, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder2, 5:4, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder1, 3:2, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(moder0, 1:0, unsigned) 		// Port x configuration bits (y = 0..15)
    )
    // GPIO port output type register
    // Offset +0x4
    SBF_REGISTER_RW(otyper, uint32_t, 0x0,
        SBF_FIELD(ot15, 15:15, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot14, 14:14, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot13, 13:13, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot12, 12:12, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot11, 11:11, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot10, 10:10, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot9, 9:9, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot8, 8:8, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot7, 7:7, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot6, 6:6, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot5, 5:5, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot4, 4:4, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot3, 3:3, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot2, 2:2, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot1, 1:1, bool) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ot0, 0:0, bool) 		// Port x configuration bits (y = 0..15)
    )
    // GPIO port output speed register
    // Offset +0x8
    SBF_REGISTER_RW(ospeedr, uint32_t, 0x0,
        SBF_FIELD(ospeedr15, 31:30, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr14, 29:28, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr13, 27:26, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr12, 25:24, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr11, 23:22, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr10, 21:20, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr9, 19:18, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr8, 17:16, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr7, 15:14, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr6, 13:12, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr5, 11:10, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr4, 9:8, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr3, 7:6, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr2, 5:4, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr1, 3:2, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(ospeedr0, 1:0, unsigned) 		// Port x configuration bits (y = 0..15)
    )
    // GPIO port pull-up/pull-down register
    // Offset +0xC
    SBF_REGISTER_RW(pupdr, uint32_t, 0x0,
        SBF_FIELD(pupdr15, 31:30, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr14, 29:28, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr13, 27:26, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr12, 25:24, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr11, 23:22, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr10, 21:20, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr9, 19:18, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr8, 17:16, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr7, 15:14, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr6, 13:12, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr5, 11:10, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr4, 9:8, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr3, 7:6, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr2, 5:4, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr1, 3:2, unsigned) 		// Port x configuration bits (y = 0..15)
        SBF_FIELD(pupdr0, 1:0, unsigned) 		// Port x configuration bits (y = 0..15)
    )
    // GPIO port input data register
    // Offset +0x10
    SBF_REGISTER_RO(idr, uint32_t, 0x0,
        SBF_FIELD(idr15, 15:15, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr14, 14:14, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr13, 13:13, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr12, 12:12, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr11, 11:11, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr10, 10:10, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr9, 9:9, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr8, 8:8, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr7, 7:7, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr6, 6:6, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr5, 5:5, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr4, 4:4, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr3, 3:3, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr2, 2:2, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr1, 1:1, bool) 		// Port input data (y = 0..15)
        SBF_FIELD(idr0, 0:0, bool) 		// Port input data (y = 0..15)
    )
    // GPIO port output data register
    // Offset +0x14
    SBF_REGISTER_RW(odr, uint32_t, 0x0,
        SBF_FIELD(odr15, 15:15, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr14, 14:14, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr13, 13:13, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr12, 12:12, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr11, 11:11, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr10, 10:10, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr9, 9:9, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr8, 8:8, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr7, 7:7, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr6, 6:6, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr5, 5:5, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr4, 4:4, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr3, 3:3, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr2, 2:2, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr1, 1:1, bool) 		// Port output data (y = 0..15)
        SBF_FIELD(odr0, 0:0, bool) 		// Port output data (y = 0..15)
    )
    // GPIO port bit set/reset register
    // Offset +0x18
    SBF_REGISTER_WO(bsrr, uint32_t, 0x0,
        SBF_FIELD(br15, 31:31, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br14, 30:30, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br13, 29:29, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br12, 28:28, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br11, 27:27, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br10, 26:26, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br9, 25:25, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br8, 24:24, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br7, 23:23, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br6, 22:22, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br5, 21:21, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br4, 20:20, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br3, 19:19, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br2, 18:18, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br1, 17:17, bool) 		// Port x reset bit y (y = 0..15)
        SBF_FIELD(br0, 16:16, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs15, 15:15, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs14, 14:14, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs13, 13:13, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs12, 12:12, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs11, 11:11, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs10, 10:10, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs9, 9:9, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs8, 8:8, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs7, 7:7, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs6, 6:6, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs5, 5:5, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs4, 4:4, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs3, 3:3, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs2, 2:2, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs1, 1:1, bool) 		// Port x set bit y (y= 0..15)
        SBF_FIELD(bs0, 0:0, bool) 		// Port x set bit y (y= 0..15)
    )
    // GPIO port configuration lock register
    // Offset +0x1C
    SBF_REGISTER_RW(lckr, uint32_t, 0x0,
        SBF_FIELD(lckk, 16:16, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck15, 15:15, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck14, 14:14, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck13, 13:13, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck12, 12:12, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck11, 11:11, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck10, 10:10, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck9, 9:9, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck8, 8:8, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck7, 7:7, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck6, 6:6, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck5, 5:5, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck4, 4:4, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck3, 3:3, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck2, 2:2, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck1, 1:1, bool) 		// Port x lock bit y (y= 0..15)
        SBF_FIELD(lck0, 0:0, bool) 		// Port x lock bit y (y= 0..15)
    )
    // GPIO alternate function low register
    // Offset +0x20
    SBF_REGISTER_RW(afrl, uint32_t, 0x0,
        SBF_FIELD(afrl7, 31:28, unsigned) 		// Alternate function selection for port x bit y (y = 0..7)
        SBF_FIELD(afrl6, 27:24, unsigned) 		// Alternate function selection for port x bit y (y = 0..7)
        SBF_FIELD(afrl5, 23:20, unsigned) 		// Alternate function selection for port x bit y (y = 0..7)
        SBF_FIELD(afrl4, 19:16, unsigned) 		// Alternate function selection for port x bit y (y = 0..7)
        SBF_FIELD(afrl3, 15:12, unsigned) 		// Alternate function selection for port x bit y (y = 0..7)
        SBF_FIELD(afrl2, 11:8, unsigned) 		// Alternate function selection for port x bit y (y = 0..7)
        SBF_FIELD(afrl1, 7:4, unsigned) 		// Alternate function selection for port x bit y (y = 0..7)
        SBF_FIELD(afrl0, 3:0, unsigned) 		// Alternate function selection for port x bit y (y = 0..7)
    )
    // GPIO alternate function high register
    // Offset +0x24
    SBF_REGISTER_RW(afrh, uint32_t, 0x0,
        SBF_FIELD(afrh15, 31:28, unsigned) 		// Alternate function selection for port x bit y (y = 8..15)
        SBF_FIELD(afrh14, 27:24, unsigned) 		// Alternate function selection for port x bit y (y = 8..15)
        SBF_FIELD(afrh13, 23:20, unsigned) 		// Alternate function selection for port x bit y (y = 8..15)
        SBF_FIELD(afrh12, 19:16, unsigned) 		// Alternate function selection for port x bit y (y = 8..15)
        SBF_FIELD(afrh11, 15:12, unsigned) 		// Alternate function selection for port x bit y (y = 8..15)
        SBF_FIELD(afrh10, 11:8, unsigned) 		// Alternate function selection for port x bit y (y = 8..15)
        SBF_FIELD(afrh9, 7:4, unsigned) 		// Alternate function selection for port x bit y (y = 8..15)
        SBF_FIELD(afrh8, 3:0, unsigned) 		// Alternate function selection for port x bit y (y = 8..15)
    )

}; // Gpio registers


// I2c registers
struct I2c {
    // Control register 1
    // Offset +0x0
    SBF_REGISTER_RW(cr1, uint32_t, 0x0,
        SBF_FIELD(pecen, 23:23, bool) 		// PEC enable
        SBF_FIELD(alerten, 22:22, bool) 		// SMBUS alert enable
        SBF_FIELD(smbden, 21:21, bool) 		// SMBus Device Default address enable
        SBF_FIELD(smbhen, 20:20, bool) 		// SMBus Host address enable
        SBF_FIELD(gcen, 19:19, bool) 		// General call enable
        SBF_FIELD(wupen, 18:18, bool) 		// Wakeup from STOP enable
        SBF_FIELD(nostretch, 17:17, bool) 		// Clock stretching disable
        SBF_FIELD(sbc, 16:16, bool) 		// Slave byte control
        SBF_FIELD(rxdmaen, 15:15, bool) 		// DMA reception requests enable
        SBF_FIELD(txdmaen, 14:14, bool) 		// DMA transmission requests enable
        SBF_FIELD(anfoff, 12:12, bool) 		// Analog noise filter OFF
        SBF_FIELD(dnf, 11:8, unsigned) 		// Digital noise filter
        SBF_FIELD(errie, 7:7, bool) 		// Error interrupts enable
        SBF_FIELD(tcie, 6:6, bool) 		// Transfer Complete interrupt enable
        SBF_FIELD(stopie, 5:5, bool) 		// STOP detection Interrupt enable
        SBF_FIELD(nackie, 4:4, bool) 		// Not acknowledge received interrupt enable
        SBF_FIELD(addrie, 3:3, bool) 		// Address match interrupt enable (slave only)
        SBF_FIELD(rxie, 2:2, bool) 		// RX Interrupt enable
        SBF_FIELD(txie, 1:1, bool) 		// TX Interrupt enable
        SBF_FIELD(pe, 0:0, bool) 		// Peripheral enable
    )
    // Control register 2
    // Offset +0x4
    SBF_REGISTER_RW(cr2, uint32_t, 0x0,
        SBF_FIELD(pecbyte, 26:26, bool) 		// Packet error checking byte
        SBF_FIELD(autoend, 25:25, bool) 		// Automatic end mode (master mode)
        SBF_FIELD(reload, 24:24, bool) 		// NBYTES reload mode
        SBF_FIELD(nbytes, 23:16, unsigned) 		// Number of bytes
        SBF_FIELD(nack, 15:15, bool) 		// NACK generation (slave mode)
        SBF_FIELD(stop, 14:14, bool) 		// Stop generation (master mode)
        SBF_FIELD(start, 13:13, bool) 		// Start generation
        SBF_FIELD(head10r, 12:12, bool) 		// 10-bit address header only read direction (master receiver mode)
        SBF_FIELD(add10, 11:11, bool) 		// 10-bit addressing mode (master mode)
        SBF_FIELD(rd_wrn, 10:10, bool) 		// Transfer direction (master mode)
        SBF_FIELD(sadd, 9:0, unsigned) 		// Slave address bit (master mode)
    )
    // Own address register 1
    // Offset +0x8
    SBF_REGISTER_RW(oar1, uint32_t, 0x0,
        SBF_FIELD(oa1en, 15:15, bool) 		// Own Address 1 enable
        SBF_FIELD(oa1mode, 10:10, bool) 		// Own Address 1 10-bit mode
        SBF_FIELD(oa1, 9:0, unsigned) 		// Interface address
    )
    // Own address register 2
    // Offset +0xC
    SBF_REGISTER_RW(oar2, uint32_t, 0x0,
        SBF_FIELD(oa2en, 15:15, bool) 		// Own Address 2 enable
        SBF_FIELD(oa2msk, 10:8, unsigned) 		// Own Address 2 masks
        SBF_FIELD(oa2, 7:1, unsigned) 		// Interface address
    )
    // Timing register
    // Offset +0x10
    SBF_REGISTER_RW(timingr, uint32_t, 0x0,
        SBF_FIELD(presc, 31:28, unsigned) 		// Timing prescaler
        SBF_FIELD(scldel, 23:20, unsigned) 		// Data setup time
        SBF_FIELD(sdadel, 19:16, unsigned) 		// Data hold time
        SBF_FIELD(sclh, 15:8, unsigned) 		// SCL high period (master mode)
        SBF_FIELD(scll, 7:0, unsigned) 		// SCL low period (master mode)
    )
    // Status register 1
    // Offset +0x14
    SBF_REGISTER_RW(timeoutr, uint32_t, 0x0,
        SBF_FIELD(texten, 31:31, bool) 		// Extended clock timeout enable
        SBF_FIELD(timeoutb, 27:16, unsigned) 		// Bus timeout B
        SBF_FIELD(timouten, 15:15, bool) 		// Clock timeout enable
        SBF_FIELD(tidle, 12:12, bool) 		// Idle clock timeout detection
        SBF_FIELD(timeouta, 11:0, unsigned) 		// Bus timeout A
    )
    // Interrupt and Status register
    // Offset +0x18
    SBF_REGISTER_RW(isr, uint32_t, 0x1,
        SBF_FIELD(addcode, 23:17, unsigned) 		// Address match code (Slave mode)
        SBF_FIELD(dir, 16:16, bool) 		// Transfer direction (Slave mode)
        SBF_FIELD(busy, 15:15, bool) 		// Bus busy
        SBF_FIELD(alert, 13:13, bool) 		// SMBus alert
        SBF_FIELD(timeout, 12:12, bool) 		// Timeout or t_low detection flag
        SBF_FIELD(pecerr, 11:11, bool) 		// PEC Error in reception
        SBF_FIELD(ovr, 10:10, bool) 		// Overrun/Underrun (slave mode)
        SBF_FIELD(arlo, 9:9, bool) 		// Arbitration lost
        SBF_FIELD(berr, 8:8, bool) 		// Bus error
        SBF_FIELD(tcr, 7:7, bool) 		// Transfer Complete Reload
        SBF_FIELD(tc, 6:6, bool) 		// Transfer Complete (master mode)
        SBF_FIELD(stopf, 5:5, bool) 		// Stop detection flag
        SBF_FIELD(nackf, 4:4, bool) 		// Not acknowledge received flag
        SBF_FIELD(addr, 3:3, bool) 		// Address matched (slave mode)
        SBF_FIELD(rxne, 2:2, bool) 		// Receive data register not empty (receivers)
        SBF_FIELD(txis, 1:1, bool) 		// Transmit interrupt status (transmitters)
        SBF_FIELD(txe, 0:0, bool) 		// Transmit data register empty (transmitters)
    )
    // Interrupt clear register
    // Offset +0x1C
    SBF_REGISTER_WO(icr, uint32_t, 0x0,
        SBF_FIELD(alertcf, 13:13, bool) 		// Alert flag clear
        SBF_FIELD(timoutcf, 12:12, bool) 		// Timeout detection flag clear
        SBF_FIELD(peccf, 11:11, bool) 		// PEC Error flag clear
        SBF_FIELD(ovrcf, 10:10, bool) 		// Overrun/Underrun flag clear
        SBF_FIELD(arlocf, 9:9, bool) 		// Arbitration lost flag clear
        SBF_FIELD(berrcf, 8:8, bool) 		// Bus error flag clear
        SBF_FIELD(stopcf, 5:5, bool) 		// Stop detection flag clear
        SBF_FIELD(nackcf, 4:4, bool) 		// Not Acknowledge flag clear
        SBF_FIELD(addrcf, 3:3, bool) 		// Address Matched flag clear
    )
    // PEC register
    // Offset +0x20
    SBF_REGISTER_RO(pecr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Receive data register
    // Offset +0x24
    SBF_REGISTER_RO(rxdr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Transmit data register
    // Offset +0x28
    SBF_REGISTER_RW(txdr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // I2c registers


// Iwdg registers
struct Iwdg {
    // Key register
    // Offset +0x0
    SBF_REGISTER_WO(kr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Prescaler register
    // Offset +0x4
    SBF_REGISTER_RW(pr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Reload register
    // Offset +0x8
    SBF_REGISTER_RW(rlr, uint32_t, 0xFFF,
        SBF_NO_FIELDS
    )
    // Status register
    // Offset +0xC
    SBF_REGISTER_RO(sr, uint32_t, 0x0,
        SBF_FIELD(wvu, 2:2, bool) 		// Watchdog counter window value update
        SBF_FIELD(rvu, 1:1, bool) 		// Watchdog counter reload value update
        SBF_FIELD(pvu, 0:0, bool) 		// Watchdog prescaler value update
    )
    // Window register
    // Offset +0x10
    SBF_REGISTER_RW(winr, uint32_t, 0xFFF,
        SBF_NO_FIELDS
    )

}; // Iwdg registers


// Lcd registers
struct Lcd {
    // control register
    // Offset +0x0
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(bufen, 8:8, bool) 		// Voltage output buffer enable
        SBF_FIELD(mux_seg, 7:7, bool) 		// Mux segment enable
        SBF_FIELD(bias, 6:5, unsigned) 		// Bias selector
        SBF_FIELD(duty, 4:2, unsigned) 		// Duty selection
        SBF_FIELD(vsel, 1:1, bool) 		// Voltage source selection
        SBF_FIELD(lcden, 0:0, bool) 		// LCD controller enable
    )
    // frame control register
    // Offset +0x4
    SBF_REGISTER_RW(fcr, uint32_t, 0x0,
        SBF_FIELD(ps, 25:22, unsigned) 		// PS 16-bit prescaler
        SBF_FIELD(div, 21:18, unsigned) 		// DIV clock divider
        SBF_FIELD(blink, 17:16, unsigned) 		// Blink mode selection
        SBF_FIELD(blinkf, 15:13, unsigned) 		// Blink frequency selection
        SBF_FIELD(cc, 12:10, unsigned) 		// Contrast control
        SBF_FIELD(dead, 9:7, unsigned) 		// Dead time duration
        SBF_FIELD(pon, 6:4, unsigned) 		// Pulse ON duration
        SBF_FIELD(uddie, 3:3, bool) 		// Update display done interrupt enable
        SBF_FIELD(sofie, 1:1, bool) 		// Start of frame interrupt enable
        SBF_FIELD(hd, 0:0, bool) 		// High drive enable
    )
    // status register
    // Offset +0x8
    SBF_REGISTER_RW(sr, uint32_t, 0x20,
        SBF_FIELD(fcrsf, 5:5, bool) 		// LCD Frame Control Register Synchronization flag
        SBF_FIELD(rdy, 4:4, bool) 		// Ready flag
        SBF_FIELD(udd, 3:3, bool) 		// Update Display Done
        SBF_FIELD(udr, 2:2, bool) 		// Update display request
        SBF_FIELD(sof, 1:1, bool) 		// Start of frame flag
        SBF_FIELD(ens, 0:0, bool) 		// ENS
    )
    // clear register
    // Offset +0xC
    SBF_REGISTER_WO(clr, uint32_t, 0x0,
        SBF_FIELD(uddc, 3:3, bool) 		// Update display done clear
        SBF_FIELD(sofc, 1:1, bool) 		// Start of frame flag clear
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x10, uint32_t, 1)
    // display memory
    // Offset +0x14
    SBF_REGISTER_RW(ram_com0, uint32_t, 0x0,
        SBF_FIELD(s30, 30:30, bool) 		// S30
        SBF_FIELD(s29, 29:29, bool) 		// S29
        SBF_FIELD(s28, 28:28, bool) 		// S28
        SBF_FIELD(s27, 27:27, bool) 		// S27
        SBF_FIELD(s26, 26:26, bool) 		// S26
        SBF_FIELD(s25, 25:25, bool) 		// S25
        SBF_FIELD(s24, 24:24, bool) 		// S24
        SBF_FIELD(s23, 23:23, bool) 		// S23
        SBF_FIELD(s22, 22:22, bool) 		// S22
        SBF_FIELD(s21, 21:21, bool) 		// S21
        SBF_FIELD(s20, 20:20, bool) 		// S20
        SBF_FIELD(s19, 19:19, bool) 		// S19
        SBF_FIELD(s18, 18:18, bool) 		// S18
        SBF_FIELD(s17, 17:17, bool) 		// S17
        SBF_FIELD(s16, 16:16, bool) 		// S16
        SBF_FIELD(s15, 15:15, bool) 		// S15
        SBF_FIELD(s14, 14:14, bool) 		// S14
        SBF_FIELD(s13, 13:13, bool) 		// S13
        SBF_FIELD(s12, 12:12, bool) 		// S12
        SBF_FIELD(s11, 11:11, bool) 		// S11
        SBF_FIELD(s10, 10:10, bool) 		// S10
        SBF_FIELD(s09, 9:9, bool) 		// S09
        SBF_FIELD(s08, 8:8, bool) 		// S08
        SBF_FIELD(s07, 7:7, bool) 		// S07
        SBF_FIELD(s06, 6:6, bool) 		// S06
        SBF_FIELD(s05, 5:5, bool) 		// S05
        SBF_FIELD(s04, 4:4, bool) 		// S04
        SBF_FIELD(s03, 3:3, bool) 		// S03
        SBF_FIELD(s02, 2:2, bool) 		// S02
        SBF_FIELD(s01, 1:1, bool) 		// S01
        SBF_FIELD(s00, 0:0, bool) 		// S00
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x18, uint32_t, 1)
    // display memory
    // Offset +0x1C
    SBF_REGISTER_RW(ram_com1, uint32_t, 0x0,
        SBF_FIELD(s31, 31:31, bool) 		// S31
        SBF_FIELD(s30, 30:30, bool) 		// S30
        SBF_FIELD(s29, 29:29, bool) 		// S29
        SBF_FIELD(s28, 28:28, bool) 		// S28
        SBF_FIELD(s27, 27:27, bool) 		// S27
        SBF_FIELD(s26, 26:26, bool) 		// S26
        SBF_FIELD(s25, 25:25, bool) 		// S25
        SBF_FIELD(s24, 24:24, bool) 		// S24
        SBF_FIELD(s23, 23:23, bool) 		// S23
        SBF_FIELD(s22, 22:22, bool) 		// S22
        SBF_FIELD(s21, 21:21, bool) 		// S21
        SBF_FIELD(s20, 20:20, bool) 		// S20
        SBF_FIELD(s19, 19:19, bool) 		// S19
        SBF_FIELD(s18, 18:18, bool) 		// S18
        SBF_FIELD(s17, 17:17, bool) 		// S17
        SBF_FIELD(s16, 16:16, bool) 		// S16
        SBF_FIELD(s15, 15:15, bool) 		// S15
        SBF_FIELD(s14, 14:14, bool) 		// S14
        SBF_FIELD(s13, 13:13, bool) 		// S13
        SBF_FIELD(s12, 12:12, bool) 		// S12
        SBF_FIELD(s11, 11:11, bool) 		// S11
        SBF_FIELD(s10, 10:10, bool) 		// S10
        SBF_FIELD(s09, 9:9, bool) 		// S09
        SBF_FIELD(s08, 8:8, bool) 		// S08
        SBF_FIELD(s07, 7:7, bool) 		// S07
        SBF_FIELD(s06, 6:6, bool) 		// S06
        SBF_FIELD(s05, 5:5, bool) 		// S05
        SBF_FIELD(s04, 4:4, bool) 		// S04
        SBF_FIELD(s03, 3:3, bool) 		// S03
        SBF_FIELD(s02, 2:2, bool) 		// S02
        SBF_FIELD(s01, 1:1, bool) 		// S01
        SBF_FIELD(s00, 0:0, bool) 		// S00
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x20, uint32_t, 1)
    // display memory
    // Offset +0x24
    SBF_REGISTER_RW(ram_com2, uint32_t, 0x0,
        SBF_FIELD(s31, 31:31, bool) 		// S31
        SBF_FIELD(s30, 30:30, bool) 		// S30
        SBF_FIELD(s29, 29:29, bool) 		// S29
        SBF_FIELD(s28, 28:28, bool) 		// S28
        SBF_FIELD(s27, 27:27, bool) 		// S27
        SBF_FIELD(s26, 26:26, bool) 		// S26
        SBF_FIELD(s25, 25:25, bool) 		// S25
        SBF_FIELD(s24, 24:24, bool) 		// S24
        SBF_FIELD(s23, 23:23, bool) 		// S23
        SBF_FIELD(s22, 22:22, bool) 		// S22
        SBF_FIELD(s21, 21:21, bool) 		// S21
        SBF_FIELD(s20, 20:20, bool) 		// S20
        SBF_FIELD(s19, 19:19, bool) 		// S19
        SBF_FIELD(s18, 18:18, bool) 		// S18
        SBF_FIELD(s17, 17:17, bool) 		// S17
        SBF_FIELD(s16, 16:16, bool) 		// S16
        SBF_FIELD(s15, 15:15, bool) 		// S15
        SBF_FIELD(s14, 14:14, bool) 		// S14
        SBF_FIELD(s13, 13:13, bool) 		// S13
        SBF_FIELD(s12, 12:12, bool) 		// S12
        SBF_FIELD(s11, 11:11, bool) 		// S11
        SBF_FIELD(s10, 10:10, bool) 		// S10
        SBF_FIELD(s09, 9:9, bool) 		// S09
        SBF_FIELD(s08, 8:8, bool) 		// S08
        SBF_FIELD(s07, 7:7, bool) 		// S07
        SBF_FIELD(s06, 6:6, bool) 		// S06
        SBF_FIELD(s05, 5:5, bool) 		// S05
        SBF_FIELD(s04, 4:4, bool) 		// S04
        SBF_FIELD(s03, 3:3, bool) 		// S03
        SBF_FIELD(s02, 2:2, bool) 		// S02
        SBF_FIELD(s01, 1:1, bool) 		// S01
        SBF_FIELD(s00, 0:0, bool) 		// S00
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x28, uint32_t, 1)
    // display memory
    // Offset +0x2C
    SBF_REGISTER_RW(ram_com3, uint32_t, 0x0,
        SBF_FIELD(s31, 31:31, bool) 		// S31
        SBF_FIELD(s30, 30:30, bool) 		// S30
        SBF_FIELD(s29, 29:29, bool) 		// S29
        SBF_FIELD(s28, 28:28, bool) 		// S28
        SBF_FIELD(s27, 27:27, bool) 		// S27
        SBF_FIELD(s26, 26:26, bool) 		// S26
        SBF_FIELD(s25, 25:25, bool) 		// S25
        SBF_FIELD(s24, 24:24, bool) 		// S24
        SBF_FIELD(s23, 23:23, bool) 		// S23
        SBF_FIELD(s22, 22:22, bool) 		// S22
        SBF_FIELD(s21, 21:21, bool) 		// S21
        SBF_FIELD(s20, 20:20, bool) 		// S20
        SBF_FIELD(s19, 19:19, bool) 		// S19
        SBF_FIELD(s18, 18:18, bool) 		// S18
        SBF_FIELD(s17, 17:17, bool) 		// S17
        SBF_FIELD(s16, 16:16, bool) 		// S16
        SBF_FIELD(s15, 15:15, bool) 		// S15
        SBF_FIELD(s14, 14:14, bool) 		// S14
        SBF_FIELD(s13, 13:13, bool) 		// S13
        SBF_FIELD(s12, 12:12, bool) 		// S12
        SBF_FIELD(s11, 11:11, bool) 		// S11
        SBF_FIELD(s10, 10:10, bool) 		// S10
        SBF_FIELD(s09, 9:9, bool) 		// S09
        SBF_FIELD(s08, 8:8, bool) 		// S08
        SBF_FIELD(s07, 7:7, bool) 		// S07
        SBF_FIELD(s06, 6:6, bool) 		// S06
        SBF_FIELD(s05, 5:5, bool) 		// S05
        SBF_FIELD(s04, 4:4, bool) 		// S04
        SBF_FIELD(s03, 3:3, bool) 		// S03
        SBF_FIELD(s02, 2:2, bool) 		// S02
        SBF_FIELD(s01, 1:1, bool) 		// S01
        SBF_FIELD(s00, 0:0, bool) 		// S00
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x30, uint32_t, 1)
    // display memory
    // Offset +0x34
    SBF_REGISTER_RW(ram_com4, uint32_t, 0x0,
        SBF_FIELD(s31, 31:31, bool) 		// S31
        SBF_FIELD(s30, 30:30, bool) 		// S30
        SBF_FIELD(s29, 29:29, bool) 		// S29
        SBF_FIELD(s28, 28:28, bool) 		// S28
        SBF_FIELD(s27, 27:27, bool) 		// S27
        SBF_FIELD(s26, 26:26, bool) 		// S26
        SBF_FIELD(s25, 25:25, bool) 		// S25
        SBF_FIELD(s24, 24:24, bool) 		// S24
        SBF_FIELD(s23, 23:23, bool) 		// S23
        SBF_FIELD(s22, 22:22, bool) 		// S22
        SBF_FIELD(s21, 21:21, bool) 		// S21
        SBF_FIELD(s20, 20:20, bool) 		// S20
        SBF_FIELD(s19, 19:19, bool) 		// S19
        SBF_FIELD(s18, 18:18, bool) 		// S18
        SBF_FIELD(s17, 17:17, bool) 		// S17
        SBF_FIELD(s16, 16:16, bool) 		// S16
        SBF_FIELD(s15, 15:15, bool) 		// S15
        SBF_FIELD(s14, 14:14, bool) 		// S14
        SBF_FIELD(s13, 13:13, bool) 		// S13
        SBF_FIELD(s12, 12:12, bool) 		// S12
        SBF_FIELD(s11, 11:11, bool) 		// S11
        SBF_FIELD(s10, 10:10, bool) 		// S10
        SBF_FIELD(s09, 9:9, bool) 		// S09
        SBF_FIELD(s08, 8:8, bool) 		// S08
        SBF_FIELD(s07, 7:7, bool) 		// S07
        SBF_FIELD(s06, 6:6, bool) 		// S06
        SBF_FIELD(s05, 5:5, bool) 		// S05
        SBF_FIELD(s04, 4:4, bool) 		// S04
        SBF_FIELD(s03, 3:3, bool) 		// S03
        SBF_FIELD(s02, 2:2, bool) 		// S02
        SBF_FIELD(s01, 1:1, bool) 		// S01
        SBF_FIELD(s00, 0:0, bool) 		// S00
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x38, uint32_t, 1)
    // display memory
    // Offset +0x3C
    SBF_REGISTER_RW(ram_com5, uint32_t, 0x0,
        SBF_FIELD(s31, 31:31, bool) 		// S31
        SBF_FIELD(s30, 30:30, bool) 		// S30
        SBF_FIELD(s29, 29:29, bool) 		// S29
        SBF_FIELD(s28, 28:28, bool) 		// S28
        SBF_FIELD(s27, 27:27, bool) 		// S27
        SBF_FIELD(s26, 26:26, bool) 		// S26
        SBF_FIELD(s25, 25:25, bool) 		// S25
        SBF_FIELD(s24, 24:24, bool) 		// S24
        SBF_FIELD(s23, 23:23, bool) 		// S23
        SBF_FIELD(s22, 22:22, bool) 		// S22
        SBF_FIELD(s21, 21:21, bool) 		// S21
        SBF_FIELD(s20, 20:20, bool) 		// S20
        SBF_FIELD(s19, 19:19, bool) 		// S19
        SBF_FIELD(s18, 18:18, bool) 		// S18
        SBF_FIELD(s17, 17:17, bool) 		// S17
        SBF_FIELD(s16, 16:16, bool) 		// S16
        SBF_FIELD(s15, 15:15, bool) 		// S15
        SBF_FIELD(s14, 14:14, bool) 		// S14
        SBF_FIELD(s13, 13:13, bool) 		// S13
        SBF_FIELD(s12, 12:12, bool) 		// S12
        SBF_FIELD(s11, 11:11, bool) 		// S11
        SBF_FIELD(s10, 10:10, bool) 		// S10
        SBF_FIELD(s09, 9:9, bool) 		// S09
        SBF_FIELD(s08, 8:8, bool) 		// S08
        SBF_FIELD(s07, 7:7, bool) 		// S07
        SBF_FIELD(s06, 6:6, bool) 		// S06
        SBF_FIELD(s05, 5:5, bool) 		// S05
        SBF_FIELD(s04, 4:4, bool) 		// S04
        SBF_FIELD(s03, 3:3, bool) 		// S03
        SBF_FIELD(s02, 2:2, bool) 		// S02
        SBF_FIELD(s01, 1:1, bool) 		// S01
        SBF_FIELD(s00, 0:0, bool) 		// S00
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x40, uint32_t, 1)
    // display memory
    // Offset +0x44
    SBF_REGISTER_RW(ram_com6, uint32_t, 0x0,
        SBF_FIELD(s31, 31:31, bool) 		// S31
        SBF_FIELD(s30, 30:30, bool) 		// S30
        SBF_FIELD(s29, 29:29, bool) 		// S29
        SBF_FIELD(s28, 28:28, bool) 		// S28
        SBF_FIELD(s27, 27:27, bool) 		// S27
        SBF_FIELD(s26, 26:26, bool) 		// S26
        SBF_FIELD(s25, 25:25, bool) 		// S25
        SBF_FIELD(s24, 24:24, bool) 		// S24
        SBF_FIELD(s23, 23:23, bool) 		// S23
        SBF_FIELD(s22, 22:22, bool) 		// S22
        SBF_FIELD(s21, 21:21, bool) 		// S21
        SBF_FIELD(s20, 20:20, bool) 		// S20
        SBF_FIELD(s19, 19:19, bool) 		// S19
        SBF_FIELD(s18, 18:18, bool) 		// S18
        SBF_FIELD(s17, 17:17, bool) 		// S17
        SBF_FIELD(s16, 16:16, bool) 		// S16
        SBF_FIELD(s15, 15:15, bool) 		// S15
        SBF_FIELD(s14, 14:14, bool) 		// S14
        SBF_FIELD(s13, 13:13, bool) 		// S13
        SBF_FIELD(s12, 12:12, bool) 		// S12
        SBF_FIELD(s11, 11:11, bool) 		// S11
        SBF_FIELD(s10, 10:10, bool) 		// S10
        SBF_FIELD(s09, 9:9, bool) 		// S09
        SBF_FIELD(s08, 8:8, bool) 		// S08
        SBF_FIELD(s07, 7:7, bool) 		// S07
        SBF_FIELD(s06, 6:6, bool) 		// S06
        SBF_FIELD(s05, 5:5, bool) 		// S05
        SBF_FIELD(s04, 4:4, bool) 		// S04
        SBF_FIELD(s03, 3:3, bool) 		// S03
        SBF_FIELD(s02, 2:2, bool) 		// S02
        SBF_FIELD(s01, 1:1, bool) 		// S01
        SBF_FIELD(s00, 0:0, bool) 		// S00
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x48, uint32_t, 1)
    // display memory
    // Offset +0x4C
    SBF_REGISTER_RW(ram_com7, uint32_t, 0x0,
        SBF_FIELD(s31, 31:31, bool) 		// S31
        SBF_FIELD(s30, 30:30, bool) 		// S30
        SBF_FIELD(s29, 29:29, bool) 		// S29
        SBF_FIELD(s28, 28:28, bool) 		// S28
        SBF_FIELD(s27, 27:27, bool) 		// S27
        SBF_FIELD(s26, 26:26, bool) 		// S26
        SBF_FIELD(s25, 25:25, bool) 		// S25
        SBF_FIELD(s24, 24:24, bool) 		// S24
        SBF_FIELD(s23, 23:23, bool) 		// S23
        SBF_FIELD(s22, 22:22, bool) 		// S22
        SBF_FIELD(s21, 21:21, bool) 		// S21
        SBF_FIELD(s20, 20:20, bool) 		// S20
        SBF_FIELD(s19, 19:19, bool) 		// S19
        SBF_FIELD(s18, 18:18, bool) 		// S18
        SBF_FIELD(s17, 17:17, bool) 		// S17
        SBF_FIELD(s16, 16:16, bool) 		// S16
        SBF_FIELD(s15, 15:15, bool) 		// S15
        SBF_FIELD(s14, 14:14, bool) 		// S14
        SBF_FIELD(s13, 13:13, bool) 		// S13
        SBF_FIELD(s12, 12:12, bool) 		// S12
        SBF_FIELD(s11, 11:11, bool) 		// S11
        SBF_FIELD(s10, 10:10, bool) 		// S10
        SBF_FIELD(s09, 9:9, bool) 		// S09
        SBF_FIELD(s08, 8:8, bool) 		// S08
        SBF_FIELD(s07, 7:7, bool) 		// S07
        SBF_FIELD(s06, 6:6, bool) 		// S06
        SBF_FIELD(s05, 5:5, bool) 		// S05
        SBF_FIELD(s04, 4:4, bool) 		// S04
        SBF_FIELD(s03, 3:3, bool) 		// S03
        SBF_FIELD(s02, 2:2, bool) 		// S02
        SBF_FIELD(s01, 1:1, bool) 		// S01
        SBF_FIELD(s00, 0:0, bool) 		// S00
    )

}; // Lcd registers


// Lptim registers
struct Lptim {
    // Interrupt and Status Register
    // Offset +0x0
    SBF_REGISTER_RO(isr, uint32_t, 0x0,
        SBF_FIELD(down, 6:6, bool) 		// Counter direction change up to down
        SBF_FIELD(up, 5:5, bool) 		// Counter direction change down to up
        SBF_FIELD(arrok, 4:4, bool) 		// Autoreload register update OK
        SBF_FIELD(cmpok, 3:3, bool) 		// Compare register update OK
        SBF_FIELD(exttrig, 2:2, bool) 		// External trigger edge event
        SBF_FIELD(arrm, 1:1, bool) 		// Autoreload match
        SBF_FIELD(cmpm, 0:0, bool) 		// Compare match
    )
    // Interrupt Clear Register
    // Offset +0x4
    SBF_REGISTER_WO(icr, uint32_t, 0x0,
        SBF_FIELD(downcf, 6:6, bool) 		// Direction change to down Clear Flag
        SBF_FIELD(upcf, 5:5, bool) 		// Direction change to UP Clear Flag
        SBF_FIELD(arrokcf, 4:4, bool) 		// Autoreload register update OK Clear Flag
        SBF_FIELD(cmpokcf, 3:3, bool) 		// Compare register update OK Clear Flag
        SBF_FIELD(exttrigcf, 2:2, bool) 		// External trigger valid edge Clear Flag
        SBF_FIELD(arrmcf, 1:1, bool) 		// Autoreload match Clear Flag
        SBF_FIELD(cmpmcf, 0:0, bool) 		// compare match Clear Flag
    )
    // Interrupt Enable Register
    // Offset +0x8
    SBF_REGISTER_RW(ier, uint32_t, 0x0,
        SBF_FIELD(downie, 6:6, bool) 		// Direction change to down Interrupt Enable
        SBF_FIELD(upie, 5:5, bool) 		// Direction change to UP Interrupt Enable
        SBF_FIELD(arrokie, 4:4, bool) 		// Autoreload register update OK Interrupt Enable
        SBF_FIELD(cmpokie, 3:3, bool) 		// Compare register update OK Interrupt Enable
        SBF_FIELD(exttrigie, 2:2, bool) 		// External trigger valid edge Interrupt Enable
        SBF_FIELD(arrmie, 1:1, bool) 		// Autoreload match Interrupt Enable
        SBF_FIELD(cmpmie, 0:0, bool) 		// Compare match Interrupt Enable
    )
    // Configuration Register
    // Offset +0xC
    SBF_REGISTER_RW(cfgr, uint32_t, 0x0,
        SBF_FIELD(enc, 24:24, bool) 		// Encoder mode enable
        SBF_FIELD(countmode, 23:23, bool) 		// counter mode enabled
        SBF_FIELD(preload, 22:22, bool) 		// Registers update mode
        SBF_FIELD(wavpol, 21:21, bool) 		// Waveform shape polarity
        SBF_FIELD(wave, 20:20, bool) 		// Waveform shape
        SBF_FIELD(timout, 19:19, bool) 		// Timeout enable
        SBF_FIELD(trigen, 18:17, unsigned) 		// Trigger enable and polarity
        SBF_FIELD(trigsel, 15:13, unsigned) 		// Trigger selector
        SBF_FIELD(presc, 11:9, unsigned) 		// Clock prescaler
        SBF_FIELD(trgflt, 7:6, unsigned) 		// Configurable digital filter for trigger
        SBF_FIELD(ckflt, 4:3, unsigned) 		// Configurable digital filter for external clock
        SBF_FIELD(ckpol, 2:1, unsigned) 		// Clock Polarity
        SBF_FIELD(cksel, 0:0, bool) 		// Clock selector
    )
    // Control Register
    // Offset +0x10
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(cntstrt, 2:2, bool) 		// Timer start in continuous mode
        SBF_FIELD(sngstrt, 1:1, bool) 		// LPTIM start in single mode
        SBF_FIELD(enable, 0:0, bool) 		// LPTIM Enable
    )
    // Compare Register
    // Offset +0x14
    SBF_REGISTER_RW(cmp, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Autoreload Register
    // Offset +0x18
    SBF_REGISTER_RW(arr, uint32_t, 0x1,
        SBF_NO_FIELDS
    )
    // Counter Register
    // Offset +0x1C
    SBF_REGISTER_RO(cnt, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Lptim registers


// Nvic registers
struct Nvic {
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x0, uint32_t, 1)
    // Interrupt Controller Type Register
    // Offset +0x4
    SBF_REGISTER_RO(ictr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x8_to_0xFC, uint32_t, 62)
    // Interrupt Set-Enable Register
    // Offset +0x100
    SBF_REGISTER_RW(iser0, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Interrupt Set-Enable Register
    // Offset +0x104
    SBF_REGISTER_RW(iser1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Interrupt Set-Enable Register
    // Offset +0x108
    SBF_REGISTER_RW(iser2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x10C_to_0x17C, uint32_t, 29)
    // Interrupt Clear-Enable Register
    // Offset +0x180
    SBF_REGISTER_RW(icer0, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Interrupt Clear-Enable Register
    // Offset +0x184
    SBF_REGISTER_RW(icer1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Interrupt Clear-Enable Register
    // Offset +0x188
    SBF_REGISTER_RW(icer2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x18C_to_0x1FC, uint32_t, 29)
    // Interrupt Set-Pending Register
    // Offset +0x200
    SBF_REGISTER_RW(ispr0, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Interrupt Set-Pending Register
    // Offset +0x204
    SBF_REGISTER_RW(ispr1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Interrupt Set-Pending Register
    // Offset +0x208
    SBF_REGISTER_RW(ispr2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x20C_to_0x27C, uint32_t, 29)
    // Interrupt Clear-Pending Register
    // Offset +0x280
    SBF_REGISTER_RW(icpr0, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Interrupt Clear-Pending Register
    // Offset +0x284
    SBF_REGISTER_RW(icpr1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Interrupt Clear-Pending Register
    // Offset +0x288
    SBF_REGISTER_RW(icpr2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x28C_to_0x2FC, uint32_t, 29)
    // Interrupt Active Bit Register
    // Offset +0x300
    SBF_REGISTER_RO(iabr0, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Interrupt Active Bit Register
    // Offset +0x304
    SBF_REGISTER_RO(iabr1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Interrupt Active Bit Register
    // Offset +0x308
    SBF_REGISTER_RO(iabr2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x30C_to_0x3FC, uint32_t, 61)
    // Interrupt Priority Register
    // Offset +0x400
    SBF_REGISTER_RW(ipr0, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x404
    SBF_REGISTER_RW(ipr1, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x408
    SBF_REGISTER_RW(ipr2, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x40C
    SBF_REGISTER_RW(ipr3, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x410
    SBF_REGISTER_RW(ipr4, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x414
    SBF_REGISTER_RW(ipr5, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x418
    SBF_REGISTER_RW(ipr6, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x41C
    SBF_REGISTER_RW(ipr7, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x420
    SBF_REGISTER_RW(ipr8, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x424
    SBF_REGISTER_RW(ipr9, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x428
    SBF_REGISTER_RW(ipr10, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x42C
    SBF_REGISTER_RW(ipr11, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x430
    SBF_REGISTER_RW(ipr12, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x434
    SBF_REGISTER_RW(ipr13, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x438
    SBF_REGISTER_RW(ipr14, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x43C
    SBF_REGISTER_RW(ipr15, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x440
    SBF_REGISTER_RW(ipr16, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x444
    SBF_REGISTER_RW(ipr17, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x448
    SBF_REGISTER_RW(ipr18, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x44C
    SBF_REGISTER_RW(ipr19, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    // Interrupt Priority Register
    // Offset +0x450
    SBF_REGISTER_RW(ipr20, uint32_t, 0x0,
        SBF_FIELD(ipr_n3, 31:24, unsigned) 		// IPR_N3
        SBF_FIELD(ipr_n2, 23:16, unsigned) 		// IPR_N2
        SBF_FIELD(ipr_n1, 15:8, unsigned) 		// IPR_N1
        SBF_FIELD(ipr_n0, 7:0, unsigned) 		// IPR_N0
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x454_to_0xEFC, uint32_t, 683)
    // Software Triggered Interrupt Register
    // Offset +0xF00
    SBF_REGISTER_WO(stir, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Nvic registers


// Opamp registers
struct Opamp {
    // OPAMP1 control/status register
    // Offset +0x0
    SBF_REGISTER_RW(opamp1_csr, uint32_t, 0x0,
        SBF_FIELD(opa_range, 31:31, bool) 		// Operational amplifier power supply range for stability
        SBF_FIELD(calout, 15:15, bool) 		// Operational amplifier calibration output
        SBF_FIELD(usertrim, 14:14, bool) 		// allows to switch from AOP offset trimmed values to AOP offset 
        SBF_FIELD(calsel, 13:13, bool) 		// Calibration selection
        SBF_FIELD(calon, 12:12, bool) 		// Calibration mode enabled
        SBF_FIELD(vp_sel, 10:10, bool) 		// Non inverted input selection
        SBF_FIELD(vm_sel, 9:8, unsigned) 		// Inverting input selection
        SBF_FIELD(pga_gain, 5:4, unsigned) 		// Operational amplifier Programmable amplifier gain value
        SBF_FIELD(opamode, 3:2, unsigned) 		// Operational amplifier PGA mode
        SBF_FIELD(opalpm, 1:1, bool) 		// Operational amplifier Low Power Mode
        SBF_FIELD(opaen, 0:0, bool) 		// Operational amplifier Enable
    )
    // OPAMP1 offset trimming register in normal mode
    // Offset +0x4
    SBF_REGISTER_RW(opamp1_otr, uint32_t, 0x0,
        SBF_FIELD(trimoffsetp, 12:8, unsigned) 		// Trim for PMOS differential pairs
        SBF_FIELD(trimoffsetn, 4:0, unsigned) 		// Trim for NMOS differential pairs
    )
    // OPAMP1 offset trimming register in low-power mode
    // Offset +0x8
    SBF_REGISTER_RW(opamp1_lpotr, uint32_t, 0x0,
        SBF_FIELD(trimlpoffsetp, 12:8, unsigned) 		// Trim for PMOS differential pairs
        SBF_FIELD(trimlpoffsetn, 4:0, unsigned) 		// Trim for NMOS differential pairs
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0xC, uint32_t, 1)
    // OPAMP2 control/status register
    // Offset +0x10
    SBF_REGISTER_RW(opamp2_csr, uint32_t, 0x0,
        SBF_FIELD(calout, 15:15, bool) 		// Operational amplifier calibration output
        SBF_FIELD(usertrim, 14:14, bool) 		// allows to switch from AOP offset trimmed values to AOP offset
        SBF_FIELD(calsel, 13:13, bool) 		// Calibration selection
        SBF_FIELD(calon, 12:12, bool) 		// Calibration mode enabled
        SBF_FIELD(vp_sel, 10:10, bool) 		// Non inverted input selection
        SBF_FIELD(vm_sel, 9:8, unsigned) 		// Inverting input selection
        SBF_FIELD(pga_gain, 5:4, unsigned) 		// Operational amplifier Programmable amplifier gain value
        SBF_FIELD(opamode, 3:2, unsigned) 		// Operational amplifier PGA mode
        SBF_FIELD(opalpm, 1:1, bool) 		// Operational amplifier Low Power Mode
        SBF_FIELD(opaen, 0:0, bool) 		// Operational amplifier Enable
    )
    // OPAMP2 offset trimming register in normal mode
    // Offset +0x14
    SBF_REGISTER_RW(opamp2_otr, uint32_t, 0x0,
        SBF_FIELD(trimoffsetp, 12:8, unsigned) 		// Trim for PMOS differential pairs
        SBF_FIELD(trimoffsetn, 4:0, unsigned) 		// Trim for NMOS differential pairs
    )
    // OPAMP2 offset trimming register in low-power mode
    // Offset +0x18
    SBF_REGISTER_RW(opamp2_lpotr, uint32_t, 0x0,
        SBF_FIELD(trimlpoffsetp, 12:8, unsigned) 		// Trim for PMOS differential pairs
        SBF_FIELD(trimlpoffsetn, 4:0, unsigned) 		// Trim for NMOS differential pairs
    )

}; // Opamp registers


// Usb_otg_fs registers
struct Usb_otg_fs {
    // OTG_FS power and clock gating control register (OTG_FS_PCGCCTL)
    // Offset +0x0
    SBF_REGISTER_RW(fs_pcgcctl, uint32_t, 0x0,
        SBF_FIELD(physusp, 4:4, bool) 		// PHY Suspended
        SBF_FIELD(gatehclk, 1:1, bool) 		// Gate HCLK
        SBF_FIELD(stppclk, 0:0, bool) 		// Stop PHY clock
    )

}; // Usb_otg_fs registers


// Pwr registers
struct Pwr {
    // Power control register 1
    // Offset +0x0
    SBF_REGISTER_RW(cr1, uint32_t, 0x200,
        SBF_FIELD(lpr, 14:14, bool) 		// Low-power run
        SBF_FIELD(vos, 10:9, unsigned) 		// Voltage scaling range selection
        SBF_FIELD(dbp, 8:8, bool) 		// Disable backup domain write protection
        SBF_FIELD(lpms, 2:0, unsigned) 		// Low-power mode selection
    )
    // Power control register 2
    // Offset +0x4
    SBF_REGISTER_RW(cr2, uint32_t, 0x0,
        SBF_FIELD(usv, 10:10, bool) 		// VDDUSB USB supply valid
        SBF_FIELD(iosv, 9:9, bool) 		// VDDIO2 Independent I/Os supply valid
        SBF_FIELD(pvme4, 7:7, bool) 		// Peripheral voltage monitoring 4 enable: VDDA vs. 2.2V
        SBF_FIELD(pvme3, 6:6, bool) 		// Peripheral voltage monitoring 3 enable: VDDA vs. 1.62V
        SBF_FIELD(pvme2, 5:5, bool) 		// Peripheral voltage monitoring 2 enable: VDDIO2 vs. 0.9V
        SBF_FIELD(pvme1, 4:4, bool) 		// Peripheral voltage monitoring 1 enable: VDDUSB vs. 1.2V
        SBF_FIELD(pls, 3:1, unsigned) 		// Power voltage detector level selection
        SBF_FIELD(pvde, 0:0, bool) 		// Power voltage detector enable
    )
    // Power control register 3
    // Offset +0x8
    SBF_REGISTER_RW(cr3, uint32_t, 0x8000,
        SBF_FIELD(ewf, 15:15, bool) 		// Enable internal wakeup line
        SBF_FIELD(apc, 10:10, bool) 		// Apply pull-up and pull-down configuration
        SBF_FIELD(rrs, 8:8, bool) 		// SRAM2 retention in Standby mode
        SBF_FIELD(ewup5, 4:4, bool) 		// Enable Wakeup pin WKUP5
        SBF_FIELD(ewup4, 3:3, bool) 		// Enable Wakeup pin WKUP4
        SBF_FIELD(ewup3, 2:2, bool) 		// Enable Wakeup pin WKUP3
        SBF_FIELD(ewup2, 1:1, bool) 		// Enable Wakeup pin WKUP2
        SBF_FIELD(ewup1, 0:0, bool) 		// Enable Wakeup pin WKUP1
    )
    // Power control register 4
    // Offset +0xC
    SBF_REGISTER_RW(cr4, uint32_t, 0x0,
        SBF_FIELD(vbrs, 9:9, bool) 		// VBAT battery charging resistor selection
        SBF_FIELD(vbe, 8:8, bool) 		// VBAT battery charging enable
        SBF_FIELD(wp5, 4:4, bool) 		// Wakeup pin WKUP5 polarity
        SBF_FIELD(wp4, 3:3, bool) 		// Wakeup pin WKUP4 polarity
        SBF_FIELD(wp3, 2:2, bool) 		// Wakeup pin WKUP3 polarity
        SBF_FIELD(wp2, 1:1, bool) 		// Wakeup pin WKUP2 polarity
        SBF_FIELD(wp1, 0:0, bool) 		// Wakeup pin WKUP1 polarity
    )
    // Power status register 1
    // Offset +0x10
    SBF_REGISTER_RO(sr1, uint32_t, 0x0,
        SBF_FIELD(wufi, 15:15, bool) 		// Wakeup flag internal
        SBF_FIELD(csbf, 8:8, bool) 		// Standby flag
        SBF_FIELD(cwuf5, 4:4, bool) 		// Wakeup flag 5
        SBF_FIELD(cwuf4, 3:3, bool) 		// Wakeup flag 4
        SBF_FIELD(cwuf3, 2:2, bool) 		// Wakeup flag 3
        SBF_FIELD(cwuf2, 1:1, bool) 		// Wakeup flag 2
        SBF_FIELD(cwuf1, 0:0, bool) 		// Wakeup flag 1
    )
    // Power status register 2
    // Offset +0x14
    SBF_REGISTER_RO(sr2, uint32_t, 0x0,
        SBF_FIELD(pvmo4, 15:15, bool) 		// Peripheral voltage monitoring output: VDDA vs. 2.2 V
        SBF_FIELD(pvmo3, 14:14, bool) 		// Peripheral voltage monitoring output: VDDA vs. 1.62 V
        SBF_FIELD(pvmo2, 13:13, bool) 		// Peripheral voltage monitoring output: VDDIO2 vs. 0.9 V
        SBF_FIELD(pvmo1, 12:12, bool) 		// Peripheral voltage monitoring output: VDDUSB vs. 1.2 V
        SBF_FIELD(pvdo, 11:11, bool) 		// Power voltage detector output
        SBF_FIELD(vosf, 10:10, bool) 		// Voltage scaling flag
        SBF_FIELD(reglpf, 9:9, bool) 		// Low-power regulator flag
        SBF_FIELD(reglps, 8:8, bool) 		// Low-power regulator started
    )
    // Power status clear register
    // Offset +0x18
    SBF_REGISTER_WO(scr, uint32_t, 0x0,
        SBF_FIELD(sbf, 8:8, bool) 		// Clear standby flag
        SBF_FIELD(wuf5, 4:4, bool) 		// Clear wakeup flag 5
        SBF_FIELD(wuf4, 3:3, bool) 		// Clear wakeup flag 4
        SBF_FIELD(wuf3, 2:2, bool) 		// Clear wakeup flag 3
        SBF_FIELD(wuf2, 1:1, bool) 		// Clear wakeup flag 2
        SBF_FIELD(wuf1, 0:0, bool) 		// Clear wakeup flag 1
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x1C, uint32_t, 1)
    // Power Port A pull-up control register
    // Offset +0x20
    SBF_REGISTER_RW(pucra, uint32_t, 0x0,
        SBF_FIELD(pu15, 15:15, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu14, 14:14, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu13, 13:13, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu12, 12:12, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu11, 11:11, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu10, 10:10, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu9, 9:9, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu8, 8:8, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu7, 7:7, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu6, 6:6, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu5, 5:5, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu4, 4:4, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu3, 3:3, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu2, 2:2, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu1, 1:1, bool) 		// Port A pull-up bit y (y=0..15)
        SBF_FIELD(pu0, 0:0, bool) 		// Port A pull-up bit y (y=0..15)
    )
    // Power Port A pull-down control register
    // Offset +0x24
    SBF_REGISTER_RW(pdcra, uint32_t, 0x0,
        SBF_FIELD(pd15, 15:15, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd14, 14:14, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd13, 13:13, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd12, 12:12, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd11, 11:11, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd10, 10:10, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd9, 9:9, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd8, 8:8, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd7, 7:7, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd6, 6:6, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd5, 5:5, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd4, 4:4, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd3, 3:3, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd2, 2:2, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd1, 1:1, bool) 		// Port A pull-down bit y (y=0..15)
        SBF_FIELD(pd0, 0:0, bool) 		// Port A pull-down bit y (y=0..15)
    )
    // Power Port B pull-up control register
    // Offset +0x28
    SBF_REGISTER_RW(pucrb, uint32_t, 0x0,
        SBF_FIELD(pu15, 15:15, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu14, 14:14, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu13, 13:13, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu12, 12:12, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu11, 11:11, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu10, 10:10, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu9, 9:9, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu8, 8:8, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu7, 7:7, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu6, 6:6, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu5, 5:5, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu4, 4:4, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu3, 3:3, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu2, 2:2, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu1, 1:1, bool) 		// Port B pull-up bit y (y=0..15)
        SBF_FIELD(pu0, 0:0, bool) 		// Port B pull-up bit y (y=0..15)
    )
    // Power Port B pull-down control register
    // Offset +0x2C
    SBF_REGISTER_RW(pdcrb, uint32_t, 0x0,
        SBF_FIELD(pd15, 15:15, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd14, 14:14, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd13, 13:13, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd12, 12:12, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd11, 11:11, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd10, 10:10, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd9, 9:9, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd8, 8:8, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd7, 7:7, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd6, 6:6, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd5, 5:5, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd4, 4:4, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd3, 3:3, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd2, 2:2, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd1, 1:1, bool) 		// Port B pull-down bit y (y=0..15)
        SBF_FIELD(pd0, 0:0, bool) 		// Port B pull-down bit y (y=0..15)
    )
    // Power Port C pull-up control register
    // Offset +0x30
    SBF_REGISTER_RW(pucrc, uint32_t, 0x0,
        SBF_FIELD(pu15, 15:15, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu14, 14:14, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu13, 13:13, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu12, 12:12, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu11, 11:11, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu10, 10:10, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu9, 9:9, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu8, 8:8, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu7, 7:7, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu6, 6:6, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu5, 5:5, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu4, 4:4, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu3, 3:3, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu2, 2:2, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu1, 1:1, bool) 		// Port C pull-up bit y (y=0..15)
        SBF_FIELD(pu0, 0:0, bool) 		// Port C pull-up bit y (y=0..15)
    )
    // Power Port C pull-down control register
    // Offset +0x34
    SBF_REGISTER_RW(pdcrc, uint32_t, 0x0,
        SBF_FIELD(pd15, 15:15, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd14, 14:14, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd13, 13:13, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd12, 12:12, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd11, 11:11, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd10, 10:10, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd9, 9:9, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd8, 8:8, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd7, 7:7, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd6, 6:6, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd5, 5:5, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd4, 4:4, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd3, 3:3, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd2, 2:2, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd1, 1:1, bool) 		// Port C pull-down bit y (y=0..15)
        SBF_FIELD(pd0, 0:0, bool) 		// Port C pull-down bit y (y=0..15)
    )
    // Power Port D pull-up control register
    // Offset +0x38
    SBF_REGISTER_RW(pucrd, uint32_t, 0x0,
        SBF_FIELD(pu15, 15:15, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu14, 14:14, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu13, 13:13, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu12, 12:12, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu11, 11:11, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu10, 10:10, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu9, 9:9, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu8, 8:8, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu7, 7:7, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu6, 6:6, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu5, 5:5, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu4, 4:4, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu3, 3:3, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu2, 2:2, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu1, 1:1, bool) 		// Port D pull-up bit y (y=0..15)
        SBF_FIELD(pu0, 0:0, bool) 		// Port D pull-up bit y (y=0..15)
    )
    // Power Port D pull-down control register
    // Offset +0x3C
    SBF_REGISTER_RW(pdcrd, uint32_t, 0x0,
        SBF_FIELD(pd15, 15:15, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd14, 14:14, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd13, 13:13, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd12, 12:12, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd11, 11:11, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd10, 10:10, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd9, 9:9, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd8, 8:8, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd7, 7:7, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd6, 6:6, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd5, 5:5, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd4, 4:4, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd3, 3:3, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd2, 2:2, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd1, 1:1, bool) 		// Port D pull-down bit y (y=0..15)
        SBF_FIELD(pd0, 0:0, bool) 		// Port D pull-down bit y (y=0..15)
    )
    // Power Port E pull-up control register
    // Offset +0x40
    SBF_REGISTER_RW(pucre, uint32_t, 0x0,
        SBF_FIELD(pu15, 15:15, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu14, 14:14, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu13, 13:13, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu12, 12:12, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu11, 11:11, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu10, 10:10, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu9, 9:9, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu8, 8:8, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu7, 7:7, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu6, 6:6, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu5, 5:5, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu4, 4:4, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu3, 3:3, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu2, 2:2, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu1, 1:1, bool) 		// Port E pull-up bit y (y=0..15)
        SBF_FIELD(pu0, 0:0, bool) 		// Port E pull-up bit y (y=0..15)
    )
    // Power Port E pull-down control register
    // Offset +0x44
    SBF_REGISTER_RW(pdcre, uint32_t, 0x0,
        SBF_FIELD(pd15, 15:15, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd14, 14:14, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd13, 13:13, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd12, 12:12, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd11, 11:11, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd10, 10:10, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd9, 9:9, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd8, 8:8, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd7, 7:7, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd6, 6:6, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd5, 5:5, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd4, 4:4, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd3, 3:3, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd2, 2:2, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd1, 1:1, bool) 		// Port E pull-down bit y (y=0..15)
        SBF_FIELD(pd0, 0:0, bool) 		// Port E pull-down bit y (y=0..15)
    )
    // Power Port F pull-up control register
    // Offset +0x48
    SBF_REGISTER_RW(pucrf, uint32_t, 0x0,
        SBF_FIELD(pu15, 15:15, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu14, 14:14, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu13, 13:13, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu12, 12:12, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu11, 11:11, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu10, 10:10, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu9, 9:9, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu8, 8:8, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu7, 7:7, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu6, 6:6, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu5, 5:5, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu4, 4:4, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu3, 3:3, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu2, 2:2, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu1, 1:1, bool) 		// Port F pull-up bit y (y=0..15)
        SBF_FIELD(pu0, 0:0, bool) 		// Port F pull-up bit y (y=0..15)
    )
    // Power Port F pull-down control register
    // Offset +0x4C
    SBF_REGISTER_RW(pdcrf, uint32_t, 0x0,
        SBF_FIELD(pd15, 15:15, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd14, 14:14, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd13, 13:13, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd12, 12:12, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd11, 11:11, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd10, 10:10, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd9, 9:9, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd8, 8:8, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd7, 7:7, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd6, 6:6, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd5, 5:5, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd4, 4:4, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd3, 3:3, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd2, 2:2, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd1, 1:1, bool) 		// Port F pull-down bit y (y=0..15)
        SBF_FIELD(pd0, 0:0, bool) 		// Port F pull-down bit y (y=0..15)
    )
    // Power Port G pull-up control register
    // Offset +0x50
    SBF_REGISTER_RW(pucrg, uint32_t, 0x0,
        SBF_FIELD(pu15, 15:15, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu14, 14:14, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu13, 13:13, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu12, 12:12, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu11, 11:11, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu10, 10:10, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu9, 9:9, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu8, 8:8, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu7, 7:7, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu6, 6:6, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu5, 5:5, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu4, 4:4, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu3, 3:3, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu2, 2:2, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu1, 1:1, bool) 		// Port G pull-up bit y (y=0..15)
        SBF_FIELD(pu0, 0:0, bool) 		// Port G pull-up bit y (y=0..15)
    )
    // Power Port G pull-down control register
    // Offset +0x54
    SBF_REGISTER_RW(pdcrg, uint32_t, 0x0,
        SBF_FIELD(pd15, 15:15, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd14, 14:14, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd13, 13:13, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd12, 12:12, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd11, 11:11, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd10, 10:10, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd9, 9:9, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd8, 8:8, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd7, 7:7, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd6, 6:6, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd5, 5:5, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd4, 4:4, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd3, 3:3, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd2, 2:2, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd1, 1:1, bool) 		// Port G pull-down bit y (y=0..15)
        SBF_FIELD(pd0, 0:0, bool) 		// Port G pull-down bit y (y=0..15)
    )
    // Power Port H pull-up control register
    // Offset +0x58
    SBF_REGISTER_RW(pucrh, uint32_t, 0x0,
        SBF_FIELD(pu1, 1:1, bool) 		// Port H pull-up bit y (y=0..1)
        SBF_FIELD(pu0, 0:0, bool) 		// Port H pull-up bit y (y=0..1)
    )
    // Power Port H pull-down control register
    // Offset +0x5C
    SBF_REGISTER_RW(pdcrh, uint32_t, 0x0,
        SBF_FIELD(pd1, 1:1, bool) 		// Port H pull-down bit y (y=0..1)
        SBF_FIELD(pd0, 0:0, bool) 		// Port H pull-down bit y (y=0..1)
    )

}; // Pwr registers


// Quadspi registers
struct Quadspi {
    // control register
    // Offset +0x0
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(prescaler, 31:24, unsigned) 		// Clock prescaler
        SBF_FIELD(pmm, 23:23, bool) 		// Polling match mode
        SBF_FIELD(apms, 22:22, bool) 		// Automatic poll mode stop
        SBF_FIELD(toie, 20:20, bool) 		// TimeOut interrupt enable
        SBF_FIELD(smie, 19:19, bool) 		// Status match interrupt enable
        SBF_FIELD(ftie, 18:18, bool) 		// FIFO threshold interrupt enable
        SBF_FIELD(tcie, 17:17, bool) 		// Transfer complete interrupt enable
        SBF_FIELD(teie, 16:16, bool) 		// Transfer error interrupt enable
        SBF_FIELD(fthres, 12:8, unsigned) 		// IFO threshold level
        SBF_FIELD(fsel, 7:7, bool) 		// FLASH memory selection
        SBF_FIELD(dfm, 6:6, bool) 		// Dual-flash mode
        SBF_FIELD(sshift, 4:4, bool) 		// Sample shift
        SBF_FIELD(tcen, 3:3, bool) 		// Timeout counter enable
        SBF_FIELD(dmaen, 2:2, bool) 		// DMA enable
        SBF_FIELD(abort, 1:1, bool) 		// Abort request
        SBF_FIELD(en, 0:0, bool) 		// Enable
    )
    // device configuration register
    // Offset +0x4
    SBF_REGISTER_RW(dcr, uint32_t, 0x0,
        SBF_FIELD(fsize, 20:16, unsigned) 		// FLASH memory size
        SBF_FIELD(csht, 10:8, unsigned) 		// Chip select high time
        SBF_FIELD(ckmode, 0:0, bool) 		// Mode 0 / mode 3
    )
    // status register
    // Offset +0x8
    SBF_REGISTER_RO(sr, uint32_t, 0x0,
        SBF_FIELD(flevel, 14:8, unsigned) 		// FIFO level
        SBF_FIELD(busy, 5:5, bool) 		// Busy
        SBF_FIELD(tof, 4:4, bool) 		// Timeout flag
        SBF_FIELD(smf, 3:3, bool) 		// Status match flag
        SBF_FIELD(ftf, 2:2, bool) 		// FIFO threshold flag
        SBF_FIELD(tcf, 1:1, bool) 		// Transfer complete flag
        SBF_FIELD(tef, 0:0, bool) 		// Transfer error flag
    )
    // flag clear register
    // Offset +0xC
    SBF_REGISTER_RW(fcr, uint32_t, 0x0,
        SBF_FIELD(ctof, 4:4, bool) 		// Clear timeout flag
        SBF_FIELD(csmf, 3:3, bool) 		// Clear status match flag
        SBF_FIELD(ctcf, 1:1, bool) 		// Clear transfer complete flag
        SBF_FIELD(ctef, 0:0, bool) 		// Clear transfer error flag
    )
    // data length register
    // Offset +0x10
    SBF_REGISTER_RW(dlr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // communication configuration register
    // Offset +0x14
    SBF_REGISTER_RW(ccr, uint32_t, 0x0,
        SBF_FIELD(ddrm, 31:31, bool) 		// Double data rate mode
        SBF_FIELD(dhhc, 30:30, bool) 		// DDR hold half cycle
        SBF_FIELD(sioo, 28:28, bool) 		// Send instruction only once mode
        SBF_FIELD(fmode, 27:26, unsigned) 		// Functional mode
        SBF_FIELD(dmode, 25:24, unsigned) 		// Data mode
        SBF_FIELD(dcyc, 22:18, unsigned) 		// Number of dummy cycles
        SBF_FIELD(absize, 17:16, unsigned) 		// Alternate bytes size
        SBF_FIELD(abmode, 15:14, unsigned) 		// Alternate bytes mode
        SBF_FIELD(adsize, 13:12, unsigned) 		// Address size
        SBF_FIELD(admode, 11:10, unsigned) 		// Address mode
        SBF_FIELD(imode, 9:8, unsigned) 		// Instruction mode
        SBF_FIELD(instruction, 7:0, unsigned) 		// Instruction
    )
    // address register
    // Offset +0x18
    SBF_REGISTER_RW(ar, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // ABR
    // Offset +0x1C
    SBF_REGISTER_RW(abr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // data register
    // Offset +0x20
    SBF_REGISTER_RW(dr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // polling status mask register
    // Offset +0x24
    SBF_REGISTER_RW(psmkr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // polling status match register
    // Offset +0x28
    SBF_REGISTER_RW(psmar, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // polling interval register
    // Offset +0x2C
    SBF_REGISTER_RW(pir, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // low-power timeout register
    // Offset +0x30
    SBF_REGISTER_RW(lptr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Quadspi registers


// Rcc registers
struct Rcc {
    // Clock control register
    // Offset +0x0
    SBF_REGISTER_RW(cr, uint32_t, 0x63,
        SBF_FIELD(pllsai2rdy, 29:29, bool) 		// SAI2 PLL clock ready flag
        SBF_FIELD(pllsai2on, 28:28, bool) 		// SAI2 PLL enable
        SBF_FIELD(pllsai1rdy, 27:27, bool) 		// SAI1 PLL clock ready flag
        SBF_FIELD(pllsai1on, 26:26, bool) 		// SAI1 PLL enable
        SBF_FIELD(pllrdy, 25:25, bool) 		// Main PLL clock ready flag
        SBF_FIELD(pllon, 24:24, bool) 		// Main PLL enable
        SBF_FIELD(csson, 19:19, bool) 		// Clock security system enable
        SBF_FIELD(hsebyp, 18:18, bool) 		// HSE crystal oscillator bypass
        SBF_FIELD(hserdy, 17:17, bool) 		// HSE clock ready flag
        SBF_FIELD(hseon, 16:16, bool) 		// HSE clock enable
        SBF_FIELD(hsiasfs, 11:11, bool) 		// HSI automatic start from Stop
        SBF_FIELD(hsirdy, 10:10, bool) 		// HSI clock ready flag
        SBF_FIELD(hsikeron, 9:9, bool) 		// HSI always enable for peripheral kernels
        SBF_FIELD(hsion, 8:8, bool) 		// HSI clock enable
        SBF_FIELD(msirange, 7:4, unsigned) 		// MSI clock ranges
        SBF_FIELD(msirgsel, 3:3, bool) 		// MSI clock range selection
        SBF_FIELD(msipllen, 2:2, bool) 		// MSI clock PLL enable
        SBF_FIELD(msirdy, 1:1, bool) 		// MSI clock ready flag
        SBF_FIELD(msion, 0:0, bool) 		// MSI clock enable
    )
    // Internal clock sources calibration register
    // Offset +0x4
    SBF_REGISTER_RW(icscr, uint32_t, 0x10000000,
        SBF_FIELD(hsitrim, 28:24, unsigned) 		// HSI clock trimming
        SBF_FIELD(hsical, 23:16, unsigned) 		// HSI clock calibration
        SBF_FIELD(msitrim, 15:8, unsigned) 		// MSI clock trimming
        SBF_FIELD(msical, 7:0, unsigned) 		// MSI clock calibration
    )
    // Clock configuration register
    // Offset +0x8
    SBF_REGISTER_RW(cfgr, uint32_t, 0x0,
        SBF_FIELD(mcopre, 30:28, unsigned) 		// Microcontroller clock output prescaler
        SBF_FIELD(mcosel, 26:24, unsigned) 		// Microcontroller clock output
        SBF_FIELD(stopwuck, 15:15, bool) 		// Wakeup from Stop and CSS backup clock selection
        SBF_FIELD(ppre2, 13:11, unsigned) 		// APB high-speed prescaler (APB2)
        SBF_FIELD(ppre1, 10:8, unsigned) 		// PB low-speed prescaler (APB1)
        SBF_FIELD(hpre, 7:4, unsigned) 		// AHB prescaler
        SBF_FIELD(sws, 3:2, unsigned) 		// System clock switch status
        SBF_FIELD(sw, 1:0, unsigned) 		// System clock switch
    )
    // PLL configuration register
    // Offset +0xC
    SBF_REGISTER_RW(pllcfgr, uint32_t, 0x1000,
        SBF_FIELD(pllr, 26:25, unsigned) 		// Main PLL division factor for PLLCLK (system clock)
        SBF_FIELD(pllren, 24:24, bool) 		// Main PLL PLLCLK output enable
        SBF_FIELD(pllq, 22:21, unsigned) 		// Main PLL division factor for PLLUSB1CLK(48 MHz clock)
        SBF_FIELD(pllqen, 20:20, bool) 		// Main PLL PLLUSB1CLK output enable
        SBF_FIELD(pllp, 17:17, bool) 		// Main PLL division factor for PLLSAI3CLK (SAI1 and SAI2 clock)
        SBF_FIELD(pllpen, 16:16, bool) 		// Main PLL PLLSAI3CLK output enable
        SBF_FIELD(plln, 14:8, unsigned) 		// Main PLL multiplication factor for VCO
        SBF_FIELD(pllm, 6:4, unsigned) 		// Division factor for the main PLL and audio PLL (PLLSAI1 and PLLSAI2) input clock
        SBF_FIELD(pllsrc, 1:0, unsigned) 		// Main PLL, PLLSAI1 and PLLSAI2 entry clock source
    )
    // PLLSAI1 configuration register
    // Offset +0x10
    SBF_REGISTER_RW(pllsai1cfgr, uint32_t, 0x1000,
        SBF_FIELD(pllsai1r, 26:25, unsigned) 		// PLLSAI1 division factor for PLLADC1CLK (ADC clock)
        SBF_FIELD(pllsai1ren, 24:24, bool) 		// PLLSAI1 PLLADC1CLK output enable
        SBF_FIELD(pllsai1q, 22:21, unsigned) 		// SAI1PLL division factor for PLLUSB2CLK (48 MHz clock)
        SBF_FIELD(pllsai1qen, 20:20, bool) 		// SAI1PLL PLLUSB2CLK output enable
        SBF_FIELD(pllsai1p, 17:17, bool) 		// SAI1PLL division factor for PLLSAI1CLK (SAI1 or SAI2 clock)
        SBF_FIELD(pllsai1pen, 16:16, bool) 		// SAI1PLL PLLSAI1CLK output enable
        SBF_FIELD(pllsai1n, 14:8, unsigned) 		// SAI1PLL multiplication factor for VCO
    )
    // PLLSAI2 configuration register
    // Offset +0x14
    SBF_REGISTER_RW(pllsai2cfgr, uint32_t, 0x1000,
        SBF_FIELD(pllsai2r, 26:25, unsigned) 		// PLLSAI2 division factor for PLLADC2CLK (ADC clock)
        SBF_FIELD(pllsai2ren, 24:24, bool) 		// PLLSAI2 PLLADC2CLK output enable
        SBF_FIELD(pllsai2p, 17:17, bool) 		// SAI1PLL division factor for PLLSAI2CLK (SAI1 or SAI2 clock)
        SBF_FIELD(pllsai2pen, 16:16, bool) 		// SAI2PLL PLLSAI2CLK output enable
        SBF_FIELD(pllsai2n, 14:8, unsigned) 		// SAI2PLL multiplication factor for VCO
    )
    // Clock interrupt enable register
    // Offset +0x18
    SBF_REGISTER_RW(cier, uint32_t, 0x0,
        SBF_FIELD(lsecssie, 9:9, bool) 		// LSE clock security system interrupt enable
        SBF_FIELD(pllsai2rdyie, 7:7, bool) 		// PLLSAI2 ready interrupt enable
        SBF_FIELD(pllsai1rdyie, 6:6, bool) 		// PLLSAI1 ready interrupt enable
        SBF_FIELD(pllrdyie, 5:5, bool) 		// PLL ready interrupt enable
        SBF_FIELD(hserdyie, 4:4, bool) 		// HSE ready interrupt enable
        SBF_FIELD(hsirdyie, 3:3, bool) 		// HSI ready interrupt enable
        SBF_FIELD(msirdyie, 2:2, bool) 		// MSI ready interrupt enable
        SBF_FIELD(lserdyie, 1:1, bool) 		// LSE ready interrupt enable
        SBF_FIELD(lsirdyie, 0:0, bool) 		// LSI ready interrupt enable
    )
    // Clock interrupt flag register
    // Offset +0x1C
    SBF_REGISTER_RO(cifr, uint32_t, 0x0,
        SBF_FIELD(lsecssf, 9:9, bool) 		// LSE Clock security system interrupt flag
        SBF_FIELD(cssf, 8:8, bool) 		// Clock security system interrupt flag
        SBF_FIELD(pllsai2rdyf, 7:7, bool) 		// PLLSAI2 ready interrupt flag
        SBF_FIELD(pllsai1rdyf, 6:6, bool) 		// PLLSAI1 ready interrupt flag
        SBF_FIELD(pllrdyf, 5:5, bool) 		// PLL ready interrupt flag
        SBF_FIELD(hserdyf, 4:4, bool) 		// HSE ready interrupt flag
        SBF_FIELD(hsirdyf, 3:3, bool) 		// HSI ready interrupt flag
        SBF_FIELD(msirdyf, 2:2, bool) 		// MSI ready interrupt flag
        SBF_FIELD(lserdyf, 1:1, bool) 		// LSE ready interrupt flag
        SBF_FIELD(lsirdyf, 0:0, bool) 		// LSI ready interrupt flag
    )
    // Clock interrupt clear register
    // Offset +0x20
    SBF_REGISTER_WO(cicr, uint32_t, 0x0,
        SBF_FIELD(lsecssc, 9:9, bool) 		// LSE Clock security system interrupt clear
        SBF_FIELD(cssc, 8:8, bool) 		// Clock security system interrupt clear
        SBF_FIELD(pllsai2rdyc, 7:7, bool) 		// PLLSAI2 ready interrupt clear
        SBF_FIELD(pllsai1rdyc, 6:6, bool) 		// PLLSAI1 ready interrupt clear
        SBF_FIELD(pllrdyc, 5:5, bool) 		// PLL ready interrupt clear
        SBF_FIELD(hserdyc, 4:4, bool) 		// HSE ready interrupt clear
        SBF_FIELD(hsirdyc, 3:3, bool) 		// HSI ready interrupt clear
        SBF_FIELD(msirdyc, 2:2, bool) 		// MSI ready interrupt clear
        SBF_FIELD(lserdyc, 1:1, bool) 		// LSE ready interrupt clear
        SBF_FIELD(lsirdyc, 0:0, bool) 		// LSI ready interrupt clear
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x24, uint32_t, 1)
    // AHB1 peripheral reset register
    // Offset +0x28
    SBF_REGISTER_RW(ahb1rstr, uint32_t, 0x0,
        SBF_FIELD(tscrst, 16:16, bool) 		// Touch Sensing Controller reset
        SBF_FIELD(crcrst, 11:11, bool) 		// Reserved
        SBF_FIELD(flashrst, 8:8, bool) 		// Flash memory interface reset
        SBF_FIELD(dma2rst, 1:1, bool) 		// DMA2 reset
        SBF_FIELD(dma1rst, 0:0, bool) 		// DMA1 reset
    )
    // AHB2 peripheral reset register
    // Offset +0x2C
    SBF_REGISTER_RW(ahb2rstr, uint32_t, 0x0,
        SBF_FIELD(rngrst, 18:18, bool) 		// Random number generator reset
        SBF_FIELD(aesrst, 16:16, bool) 		// AES hardware accelerator reset
        SBF_FIELD(adcrst, 13:13, bool) 		// ADC reset
        SBF_FIELD(otgfsrst, 12:12, bool) 		// USB OTG FS reset
        SBF_FIELD(gpiohrst, 7:7, bool) 		// IO port H reset
        SBF_FIELD(gpiogrst, 6:6, bool) 		// IO port G reset
        SBF_FIELD(gpiofrst, 5:5, bool) 		// IO port F reset
        SBF_FIELD(gpioerst, 4:4, bool) 		// IO port E reset
        SBF_FIELD(gpiodrst, 3:3, bool) 		// IO port D reset
        SBF_FIELD(gpiocrst, 2:2, bool) 		// IO port C reset
        SBF_FIELD(gpiobrst, 1:1, bool) 		// IO port B reset
        SBF_FIELD(gpioarst, 0:0, bool) 		// IO port A reset
    )
    // AHB3 peripheral reset register
    // Offset +0x30
    SBF_REGISTER_RW(ahb3rstr, uint32_t, 0x0,
        SBF_FIELD(qspirst, 8:8, bool) 		// Quad SPI memory interface reset
        SBF_FIELD(fmcrst, 0:0, bool) 		// Flexible memory controller reset
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x34, uint32_t, 1)
    // APB1 peripheral reset register 1
    // Offset +0x38
    SBF_REGISTER_RW(apb1rstr1, uint32_t, 0x0,
        SBF_FIELD(lptim1rst, 31:31, bool) 		// Low Power Timer 1 reset
        SBF_FIELD(opamprst, 30:30, bool) 		// OPAMP interface reset
        SBF_FIELD(dac1rst, 29:29, bool) 		// DAC1 interface reset
        SBF_FIELD(pwrrst, 28:28, bool) 		// Power interface reset
        SBF_FIELD(can1rst, 25:25, bool) 		// CAN1 reset
        SBF_FIELD(i2c3rst, 23:23, bool) 		// I2C3 reset
        SBF_FIELD(i2c2rst, 22:22, bool) 		// I2C2 reset
        SBF_FIELD(i2c1rst, 21:21, bool) 		// I2C1 reset
        SBF_FIELD(uart5rst, 20:20, bool) 		// UART5 reset
        SBF_FIELD(uart4rst, 19:19, bool) 		// UART4 reset
        SBF_FIELD(usart3rst, 18:18, bool) 		// USART3 reset
        SBF_FIELD(usart2rst, 17:17, bool) 		// USART2 reset
        SBF_FIELD(spi3rst, 15:15, bool) 		// SPI3 reset
        SBF_FIELD(spi2rst, 14:14, bool) 		// SPI2 reset
        SBF_FIELD(lcdrst, 9:9, bool) 		// LCD interface reset
        SBF_FIELD(tim7rst, 5:5, bool) 		// TIM7 timer reset
        SBF_FIELD(tim6rst, 4:4, bool) 		// TIM6 timer reset
        SBF_FIELD(tim5rst, 3:3, bool) 		// TIM5 timer reset
        SBF_FIELD(tim4rst, 2:2, bool) 		// TIM3 timer reset
        SBF_FIELD(tim3rst, 1:1, bool) 		// TIM3 timer reset
        SBF_FIELD(tim2rst, 0:0, bool) 		// TIM2 timer reset
    )
    // APB1 peripheral reset register 2
    // Offset +0x3C
    SBF_REGISTER_RW(apb1rstr2, uint32_t, 0x0,
        SBF_FIELD(lptim2rst, 5:5, bool) 		// Low-power timer 2 reset
        SBF_FIELD(swpmi1rst, 2:2, bool) 		// Single wire protocol reset
        SBF_FIELD(lpuart1rst, 0:0, bool) 		// Low-power UART 1 reset
    )
    // APB2 peripheral reset register
    // Offset +0x40
    SBF_REGISTER_RW(apb2rstr, uint32_t, 0x0,
        SBF_FIELD(dfsdmrst, 24:24, bool) 		// Digital filters for sigma-delata modulators (DFSDM) reset
        SBF_FIELD(sai2rst, 22:22, bool) 		// Serial audio interface 2 (SAI2) reset
        SBF_FIELD(sai1rst, 21:21, bool) 		// Serial audio interface 1 (SAI1) reset
        SBF_FIELD(tim17rst, 18:18, bool) 		// TIM17 timer reset
        SBF_FIELD(tim16rst, 17:17, bool) 		// TIM16 timer reset
        SBF_FIELD(tim15rst, 16:16, bool) 		// TIM15 timer reset
        SBF_FIELD(usart1rst, 14:14, bool) 		// USART1 reset
        SBF_FIELD(tim8rst, 13:13, bool) 		// TIM8 timer reset
        SBF_FIELD(spi1rst, 12:12, bool) 		// SPI1 reset
        SBF_FIELD(tim1rst, 11:11, bool) 		// TIM1 timer reset
        SBF_FIELD(sdmmcrst, 10:10, bool) 		// SDMMC reset
        SBF_FIELD(syscfgrst, 0:0, bool) 		// System configuration (SYSCFG) reset
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x44, uint32_t, 1)
    // AHB1 peripheral clock enable register
    // Offset +0x48
    SBF_REGISTER_RW(ahb1enr, uint32_t, 0x100,
        SBF_FIELD(tscen, 16:16, bool) 		// Touch Sensing Controller clock enable
        SBF_FIELD(crcen, 11:11, bool) 		// Reserved
        SBF_FIELD(flashen, 8:8, bool) 		// Flash memory interface clock enable
        SBF_FIELD(dma2en, 1:1, bool) 		// DMA2 clock enable
        SBF_FIELD(dma1en, 0:0, bool) 		// DMA1 clock enable
    )
    // AHB2 peripheral clock enable register
    // Offset +0x4C
    SBF_REGISTER_RW(ahb2enr, uint32_t, 0x0,
        SBF_FIELD(rngen, 18:18, bool) 		// Random Number Generator clock enable
        SBF_FIELD(aesen, 16:16, bool) 		// AES accelerator clock enable
        SBF_FIELD(adcen, 13:13, bool) 		// ADC clock enable
        SBF_FIELD(otgfsen, 12:12, bool) 		// OTG full speed clock enable
        SBF_FIELD(gpiohen, 7:7, bool) 		// IO port H clock enable
        SBF_FIELD(gpiogen, 6:6, bool) 		// IO port G clock enable
        SBF_FIELD(gpiofen, 5:5, bool) 		// IO port F clock enable
        SBF_FIELD(gpioeen, 4:4, bool) 		// IO port E clock enable
        SBF_FIELD(gpioden, 3:3, bool) 		// IO port D clock enable
        SBF_FIELD(gpiocen, 2:2, bool) 		// IO port C clock enable
        SBF_FIELD(gpioben, 1:1, bool) 		// IO port B clock enable
        SBF_FIELD(gpioaen, 0:0, bool) 		// IO port A clock enable
    )
    // AHB3 peripheral clock enable register
    // Offset +0x50
    SBF_REGISTER_RW(ahb3enr, uint32_t, 0x0,
        SBF_FIELD(qspien, 8:8, bool) 		// QSPIEN
        SBF_FIELD(fmcen, 0:0, bool) 		// Flexible memory controller clock enable
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x54, uint32_t, 1)
    // APB1ENR1
    // Offset +0x58
    SBF_REGISTER_RW(apb1enr1, uint32_t, 0x0,
        SBF_FIELD(lptim1en, 31:31, bool) 		// Low power timer 1 clock enable
        SBF_FIELD(opampen, 30:30, bool) 		// OPAMP interface clock enable
        SBF_FIELD(dac1en, 29:29, bool) 		// DAC1 interface clock enable
        SBF_FIELD(pwren, 28:28, bool) 		// Power interface clock enable
        SBF_FIELD(can1en, 25:25, bool) 		// CAN1 clock enable
        SBF_FIELD(i2c3en, 23:23, bool) 		// I2C3 clock enable
        SBF_FIELD(i2c2en, 22:22, bool) 		// I2C2 clock enable
        SBF_FIELD(i2c1en, 21:21, bool) 		// I2C1 clock enable
        SBF_FIELD(uart5en, 20:20, bool) 		// UART5 clock enable
        SBF_FIELD(uart4en, 19:19, bool) 		// UART4 clock enable
        SBF_FIELD(usart3en, 18:18, bool) 		// USART3 clock enable
        SBF_FIELD(usart2en, 17:17, bool) 		// USART2 clock enable
        SBF_FIELD(sp3en, 15:15, bool) 		// SPI3 clock enable
        SBF_FIELD(spi2en, 14:14, bool) 		// SPI2 clock enable
        SBF_FIELD(wwdgen, 11:11, bool) 		// Window watchdog clock enable
        SBF_FIELD(lcden, 9:9, bool) 		// LCD clock enable
        SBF_FIELD(tim7en, 5:5, bool) 		// TIM7 timer clock enable
        SBF_FIELD(tim6en, 4:4, bool) 		// TIM6 timer clock enable
        SBF_FIELD(tim5en, 3:3, bool) 		// Reserved
        SBF_FIELD(tim4en, 2:2, bool) 		// TIM4 timer clock enable
        SBF_FIELD(tim3en, 1:1, bool) 		// TIM3 timer clock enable
        SBF_FIELD(tim2en, 0:0, bool) 		// TIM2 timer clock enable
    )
    // APB1 peripheral clock enable register 2
    // Offset +0x5C
    SBF_REGISTER_RW(apb1enr2, uint32_t, 0x0,
        SBF_FIELD(lptim2en, 5:5, bool) 		// LPTIM2EN
        SBF_FIELD(swpmi1en, 2:2, bool) 		// Single wire protocol clock enable
        SBF_FIELD(lpuart1en, 0:0, bool) 		// Low power UART 1 clock enable
    )
    // APB2ENR
    // Offset +0x60
    SBF_REGISTER_RW(apb2enr, uint32_t, 0x0,
        SBF_FIELD(dfsdmen, 24:24, bool) 		// DFSDM timer clock enable
        SBF_FIELD(sai2en, 22:22, bool) 		// SAI2 clock enable
        SBF_FIELD(sai1en, 21:21, bool) 		// SAI1 clock enable
        SBF_FIELD(tim17en, 18:18, bool) 		// TIM17 timer clock enable
        SBF_FIELD(tim16en, 17:17, bool) 		// TIM16 timer clock enable
        SBF_FIELD(tim15en, 16:16, bool) 		// TIM15 timer clock enable
        SBF_FIELD(usart1en, 14:14, bool) 		// USART1clock enable
        SBF_FIELD(tim8en, 13:13, bool) 		// TIM8 timer clock enable
        SBF_FIELD(spi1en, 12:12, bool) 		// SPI1 clock enable
        SBF_FIELD(tim1en, 11:11, bool) 		// TIM1 timer clock enable
        SBF_FIELD(sdmmcen, 10:10, bool) 		// SDMMC clock enable
        SBF_FIELD(firewallen, 7:7, bool) 		// Firewall clock enable
        SBF_FIELD(syscfgen, 0:0, bool) 		// SYSCFG clock enable
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x64, uint32_t, 1)
    // AHB1 peripheral clocks enable in Sleep and Stop modes register
    // Offset +0x68
    SBF_REGISTER_RW(ahb1smenr, uint32_t, 0x11303,
        SBF_FIELD(tscsmen, 16:16, bool) 		// Touch Sensing Controller clocks enable during Sleep and Stop modes
        SBF_FIELD(crcsmen, 11:11, bool) 		// CRCSMEN
        SBF_FIELD(sram1smen, 9:9, bool) 		// SRAM1 interface clocks enable during Sleep and Stop modes
        SBF_FIELD(flashsmen, 8:8, bool) 		// Flash memory interface clocks enable during Sleep and Stop modes
        SBF_FIELD(dma2smen, 1:1, bool) 		// DMA2 clocks enable during Sleep and Stop modes
        SBF_FIELD(dma1smen, 0:0, bool) 		// DMA1 clocks enable during Sleep and Stop modes
    )
    // AHB2 peripheral clocks enable in Sleep and Stop modes register
    // Offset +0x6C
    SBF_REGISTER_RW(ahb2smenr, uint32_t, 0x532FF,
        SBF_FIELD(rngsmen, 18:18, bool) 		// Random Number Generator clocks enable during Sleep and Stop modes
        SBF_FIELD(aessmen, 16:16, bool) 		// AES accelerator clocks enable during Sleep and Stop modes
        SBF_FIELD(adcfssmen, 13:13, bool) 		// ADC clocks enable during Sleep and Stop modes
        SBF_FIELD(otgfssmen, 12:12, bool) 		// OTG full speed clocks enable during Sleep and Stop modes
        SBF_FIELD(sram2smen, 9:9, bool) 		// SRAM2 interface clocks enable during Sleep and Stop modes
        SBF_FIELD(gpiohsmen, 7:7, bool) 		// IO port H clocks enable during Sleep and Stop modes
        SBF_FIELD(gpiogsmen, 6:6, bool) 		// IO port G clocks enable during Sleep and Stop modes
        SBF_FIELD(gpiofsmen, 5:5, bool) 		// IO port F clocks enable during Sleep and Stop modes
        SBF_FIELD(gpioesmen, 4:4, bool) 		// IO port E clocks enable during Sleep and Stop modes
        SBF_FIELD(gpiodsmen, 3:3, bool) 		// IO port D clocks enable during Sleep and Stop modes
        SBF_FIELD(gpiocsmen, 2:2, bool) 		// IO port C clocks enable during Sleep and Stop modes
        SBF_FIELD(gpiobsmen, 1:1, bool) 		// IO port B clocks enable during Sleep and Stop modes
        SBF_FIELD(gpioasmen, 0:0, bool) 		// IO port A clocks enable during Sleep and Stop modes
    )
    // AHB3 peripheral clocks enable in Sleep and Stop modes register
    // Offset +0x70
    SBF_REGISTER_RW(ahb3smenr, uint32_t, 0x101,
        SBF_FIELD(qspismen, 8:8, bool) 		// QSPISMEN
        SBF_FIELD(fmcsmen, 0:0, bool) 		// Flexible memory controller clocks enable during Sleep and Stop modes
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x74, uint32_t, 1)
    // APB1SMENR1
    // Offset +0x78
    SBF_REGISTER_RW(apb1smenr1, uint32_t, 0xF2FECA3F,
        SBF_FIELD(lptim1smen, 31:31, bool) 		// Low power timer 1 clocks enable during Sleep and Stop modes
        SBF_FIELD(opampsmen, 30:30, bool) 		// OPAMP interface clocks enable during Sleep and Stop modes
        SBF_FIELD(dac1smen, 29:29, bool) 		// DAC1 interface clocks enable during Sleep and Stop modes
        SBF_FIELD(pwrsmen, 28:28, bool) 		// Power interface clocks enable during Sleep and Stop modes
        SBF_FIELD(can1smen, 25:25, bool) 		// CAN1 clocks enable during Sleep and Stop modes
        SBF_FIELD(i2c3smen, 23:23, bool) 		// I2C3 clocks enable during Sleep and Stop modes
        SBF_FIELD(i2c2smen, 22:22, bool) 		// I2C2 clocks enable during Sleep and Stop modes
        SBF_FIELD(i2c1smen, 21:21, bool) 		// I2C1 clocks enable during Sleep and Stop modes
        SBF_FIELD(uart5smen, 20:20, bool) 		// UART5 clocks enable during Sleep and Stop modes
        SBF_FIELD(uart4smen, 19:19, bool) 		// UART4 clocks enable during Sleep and Stop modes
        SBF_FIELD(usart3smen, 18:18, bool) 		// USART3 clocks enable during Sleep and Stop modes
        SBF_FIELD(usart2smen, 17:17, bool) 		// USART2 clocks enable during Sleep and Stop modes
        SBF_FIELD(sp3smen, 15:15, bool) 		// SPI3 clocks enable during Sleep and Stop modes
        SBF_FIELD(spi2smen, 14:14, bool) 		// SPI2 clocks enable during Sleep and Stop modes
        SBF_FIELD(wwdgsmen, 11:11, bool) 		// Window watchdog clocks enable during Sleep and Stop modes
        SBF_FIELD(lcdsmen, 9:9, bool) 		// LCD clocks enable during Sleep and Stop modes
        SBF_FIELD(tim7smen, 5:5, bool) 		// TIM7 timer clocks enable during Sleep and Stop modes
        SBF_FIELD(tim6smen, 4:4, bool) 		// TIM6 timer clocks enable during Sleep and Stop modes
        SBF_FIELD(tim5smen, 3:3, bool) 		// Reserved
        SBF_FIELD(tim4smen, 2:2, bool) 		// TIM4 timer clocks enable during Sleep and Stop modes
        SBF_FIELD(tim3smen, 1:1, bool) 		// TIM3 timer clocks enable during Sleep and Stop modes
        SBF_FIELD(tim2smen, 0:0, bool) 		// TIM2 timer clocks enable during Sleep and Stop modes
    )
    // APB1 peripheral clocks enable in Sleep and Stop modes register 2
    // Offset +0x7C
    SBF_REGISTER_RW(apb1smenr2, uint32_t, 0x25,
        SBF_FIELD(lptim2smen, 5:5, bool) 		// LPTIM2SMEN
        SBF_FIELD(swpmi1smen, 2:2, bool) 		// Single wire protocol clocks enable during Sleep and Stop modes
        SBF_FIELD(lpuart1smen, 0:0, bool) 		// Low power UART 1 clocks enable during Sleep and Stop modes
    )
    // APB2SMENR
    // Offset +0x80
    SBF_REGISTER_RW(apb2smenr, uint32_t, 0x1677C01,
        SBF_FIELD(dfsdmsmen, 24:24, bool) 		// DFSDM timer clocks enable during Sleep and Stop modes
        SBF_FIELD(sai2smen, 22:22, bool) 		// SAI2 clocks enable during Sleep and Stop modes
        SBF_FIELD(sai1smen, 21:21, bool) 		// SAI1 clocks enable during Sleep and Stop modes
        SBF_FIELD(tim17smen, 18:18, bool) 		// TIM17 timer clocks enable during Sleep and Stop modes
        SBF_FIELD(tim16smen, 17:17, bool) 		// TIM16 timer clocks enable during Sleep and Stop modes
        SBF_FIELD(tim15smen, 16:16, bool) 		// TIM15 timer clocks enable during Sleep and Stop modes
        SBF_FIELD(usart1smen, 14:14, bool) 		// USART1clocks enable during Sleep and Stop modes
        SBF_FIELD(tim8smen, 13:13, bool) 		// TIM8 timer clocks enable during Sleep and Stop modes
        SBF_FIELD(spi1smen, 12:12, bool) 		// SPI1 clocks enable during Sleep and Stop modes
        SBF_FIELD(tim1smen, 11:11, bool) 		// TIM1 timer clocks enable during Sleep and Stop modes
        SBF_FIELD(sdmmcsmen, 10:10, bool) 		// SDMMC clocks enable during Sleep and Stop modes
        SBF_FIELD(syscfgsmen, 0:0, bool) 		// SYSCFG clocks enable during Sleep and Stop modes
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x84, uint32_t, 1)
    // CCIPR
    // Offset +0x88
    SBF_REGISTER_RW(ccipr, uint32_t, 0x0,
        SBF_FIELD(dfsdmsel, 31:31, bool) 		// DFSDM clock source selection
        SBF_FIELD(swpmi1sel, 30:30, bool) 		// SWPMI1 clock source selection
        SBF_FIELD(adcsel, 29:28, unsigned) 		// ADCs clock source selection
        SBF_FIELD(clk48sel, 27:26, unsigned) 		// 48 MHz clock source selection
        SBF_FIELD(sai2sel, 25:24, unsigned) 		// SAI2 clock source selection
        SBF_FIELD(sai1sel, 23:22, unsigned) 		// SAI1 clock source selection
        SBF_FIELD(lptim2sel, 21:20, unsigned) 		// Low power timer 2 clock source selection
        SBF_FIELD(lptim1sel, 19:18, unsigned) 		// Low power timer 1 clock source selection
        SBF_FIELD(i2c3sel, 17:16, unsigned) 		// I2C3 clock source selection
        SBF_FIELD(i2c2sel, 15:14, unsigned) 		// I2C2 clock source selection
        SBF_FIELD(i2c1sel, 13:12, unsigned) 		// I2C1 clock source selection
        SBF_FIELD(lpuart1sel, 11:10, unsigned) 		// LPUART1 clock source selection
        SBF_FIELD(uart5sel, 9:8, unsigned) 		// UART5 clock source selection
        SBF_FIELD(uart4sel, 7:6, unsigned) 		// UART4 clock source selection
        SBF_FIELD(usart3sel, 5:4, unsigned) 		// USART3 clock source selection
        SBF_FIELD(usart2sel, 3:2, unsigned) 		// USART2 clock source selection
        SBF_FIELD(usart1sel, 1:0, unsigned) 		// USART1 clock source selection
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x8C, uint32_t, 1)
    // BDCR
    // Offset +0x90
    SBF_REGISTER_RW(bdcr, uint32_t, 0x0,
        SBF_FIELD(lscosel, 25:25, bool) 		// Low speed clock output selection
        SBF_FIELD(lscoen, 24:24, bool) 		// Low speed clock output enable
        SBF_FIELD(bdrst, 16:16, bool) 		// Backup domain software reset
        SBF_FIELD(rtcen, 15:15, bool) 		// RTC clock enable
        SBF_FIELD(rtcsel, 9:8, unsigned) 		// RTC clock source selection
        SBF_FIELD(lsecssd, 6:6, bool) 		// LSECSSD
        SBF_FIELD(lsecsson, 5:5, bool) 		// LSECSSON
        SBF_FIELD(lsedrv, 4:3, unsigned) 		// SE oscillator drive capability
        SBF_FIELD(lsebyp, 2:2, bool) 		// LSE oscillator bypass
        SBF_FIELD(lserdy, 1:1, bool) 		// LSE oscillator ready
        SBF_FIELD(lseon, 0:0, bool) 		// LSE oscillator enable
    )
    // CSR
    // Offset +0x94
    SBF_REGISTER_RW(csr, uint32_t, 0xC000600,
        SBF_FIELD(lpwrstf, 31:31, bool) 		// Low-power reset flag
        SBF_FIELD(wwdgrstf, 30:30, bool) 		// Window watchdog reset flag
        SBF_FIELD(iwdgrstf, 29:29, bool) 		// Independent window watchdog reset flag
        SBF_FIELD(sftrstf, 28:28, bool) 		// Software reset flag
        SBF_FIELD(borrstf, 27:27, bool) 		// BOR flag
        SBF_FIELD(pinrstf, 26:26, bool) 		// Pin reset flag
        SBF_FIELD(oblrstf, 25:25, bool) 		// Option byte loader reset flag
        SBF_FIELD(firewallrstf, 24:24, bool) 		// Firewall reset flag
        SBF_FIELD(rmvf, 23:23, bool) 		// Remove reset flag
        SBF_FIELD(msisrange, 11:8, unsigned) 		// SI range after Standby mode
        SBF_FIELD(lsirdy, 1:1, bool) 		// LSI oscillator ready
        SBF_FIELD(lsion, 0:0, bool) 		// LSI oscillator enable
    )

}; // Rcc registers


// Rng registers
struct Rng {
    // control register
    // Offset +0x0
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(ie, 3:3, bool) 		// Interrupt enable
        SBF_FIELD(rngen, 2:2, bool) 		// Random number generator enable
    )
    // status register
    // Offset +0x4
    SBF_REGISTER_RW(sr, uint32_t, 0x0,
        SBF_FIELD(seis, 6:6, bool) 		// Seed error interrupt status
        SBF_FIELD(ceis, 5:5, bool) 		// Clock error interrupt status
        SBF_FIELD(secs, 2:2, bool) 		// Seed error current status
        SBF_FIELD(cecs, 1:1, bool) 		// Clock error current status
        SBF_FIELD(drdy, 0:0, bool) 		// Data ready
    )
    // data register
    // Offset +0x8
    SBF_REGISTER_RO(dr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Rng registers


// Rtc registers
struct Rtc {
    // time register
    // Offset +0x0
    SBF_REGISTER_RW(tr, uint32_t, 0x0,
        SBF_FIELD(pm, 22:22, bool) 		// AM/PM notation
        SBF_FIELD(ht, 21:20, unsigned) 		// Hour tens in BCD format
        SBF_FIELD(hu, 19:16, unsigned) 		// Hour units in BCD format
        SBF_FIELD(mnt, 14:12, unsigned) 		// Minute tens in BCD format
        SBF_FIELD(mnu, 11:8, unsigned) 		// Minute units in BCD format
        SBF_FIELD(st, 6:4, unsigned) 		// Second tens in BCD format
        SBF_FIELD(su, 3:0, unsigned) 		// Second units in BCD format
    )
    // date register
    // Offset +0x4
    SBF_REGISTER_RW(dr, uint32_t, 0x2101,
        SBF_FIELD(yt, 23:20, unsigned) 		// Year tens in BCD format
        SBF_FIELD(yu, 19:16, unsigned) 		// Year units in BCD format
        SBF_FIELD(wdu, 15:13, unsigned) 		// Week day units
        SBF_FIELD(mt, 12:12, bool) 		// Month tens in BCD format
        SBF_FIELD(mu, 11:8, unsigned) 		// Month units in BCD format
        SBF_FIELD(dt, 5:4, unsigned) 		// Date tens in BCD format
        SBF_FIELD(du, 3:0, unsigned) 		// Date units in BCD format
    )
    // control register
    // Offset +0x8
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(itse, 24:24, bool) 		// timestamp on internal event enable
        SBF_FIELD(coe, 23:23, bool) 		// Calibration output enable
        SBF_FIELD(osel, 22:21, unsigned) 		// Output selection
        SBF_FIELD(pol, 20:20, bool) 		// Output polarity
        SBF_FIELD(cosel, 19:19, bool) 		// Calibration output selection
        SBF_FIELD(bkp, 18:18, bool) 		// Backup
        SBF_FIELD(sub1h, 17:17, bool) 		// Subtract 1 hour (winter time change)
        SBF_FIELD(add1h, 16:16, bool) 		// Add 1 hour (summer time change)
        SBF_FIELD(tsie, 15:15, bool) 		// Time-stamp interrupt enable
        SBF_FIELD(wutie, 14:14, bool) 		// Wakeup timer interrupt enable
        SBF_FIELD(alrbie, 13:13, bool) 		// Alarm B interrupt enable
        SBF_FIELD(alraie, 12:12, bool) 		// Alarm A interrupt enable
        SBF_FIELD(tse, 11:11, bool) 		// Time stamp enable
        SBF_FIELD(wute, 10:10, bool) 		// Wakeup timer enable
        SBF_FIELD(alrbe, 9:9, bool) 		// Alarm B enable
        SBF_FIELD(alrae, 8:8, bool) 		// Alarm A enable
        SBF_FIELD(fmt, 6:6, bool) 		// Hour format
        SBF_FIELD(bypshad, 5:5, bool) 		// Bypass the shadow registers
        SBF_FIELD(refckon, 4:4, bool) 		// Reference clock detection enable (50 or 60 Hz)
        SBF_FIELD(tsedge, 3:3, bool) 		// Time-stamp event active edge
        SBF_FIELD(wcksel, 2:0, unsigned) 		// Wakeup clock selection
    )
    // initialization and status register
    // Offset +0xC
    SBF_REGISTER_RW(isr, uint32_t, 0x7,
        SBF_FIELD(recalpf, 16:16, bool) 		// Recalibration pending Flag
        SBF_FIELD(tamp3f, 15:15, bool) 		// RTC_TAMP3 detection flag
        SBF_FIELD(tamp2f, 14:14, bool) 		// RTC_TAMP2 detection flag
        SBF_FIELD(tamp1f, 13:13, bool) 		// Tamper detection flag
        SBF_FIELD(tsovf, 12:12, bool) 		// Time-stamp overflow flag
        SBF_FIELD(tsf, 11:11, bool) 		// Time-stamp flag
        SBF_FIELD(wutf, 10:10, bool) 		// Wakeup timer flag
        SBF_FIELD(alrbf, 9:9, bool) 		// Alarm B flag
        SBF_FIELD(alraf, 8:8, bool) 		// Alarm A flag
        SBF_FIELD(init, 7:7, bool) 		// Initialization mode
        SBF_FIELD(initf, 6:6, bool) 		// Initialization flag
        SBF_FIELD(rsf, 5:5, bool) 		// Registers synchronization flag
        SBF_FIELD(inits, 4:4, bool) 		// Initialization status flag
        SBF_FIELD(shpf, 3:3, bool) 		// Shift operation pending
        SBF_FIELD(wutwf, 2:2, bool) 		// Wakeup timer write flag
        SBF_FIELD(alrbwf, 1:1, bool) 		// Alarm B write flag
        SBF_FIELD(alrawf, 0:0, bool) 		// Alarm A write flag
    )
    // prescaler register
    // Offset +0x10
    SBF_REGISTER_RW(prer, uint32_t, 0x7F00FF,
        SBF_FIELD(prediv_a, 22:16, unsigned) 		// Asynchronous prescaler factor
        SBF_FIELD(prediv_s, 14:0, unsigned) 		// Synchronous prescaler factor
    )
    // wakeup timer register
    // Offset +0x14
    SBF_REGISTER_RW(wutr, uint32_t, 0xFFFF,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x18, uint32_t, 1)
    // alarm A register
    // Offset +0x1C
    SBF_REGISTER_RW(alrmar, uint32_t, 0x0,
        SBF_FIELD(msk4, 31:31, bool) 		// Alarm A date mask
        SBF_FIELD(wdsel, 30:30, bool) 		// Week day selection
        SBF_FIELD(dt, 29:28, unsigned) 		// Date tens in BCD format
        SBF_FIELD(du, 27:24, unsigned) 		// Date units or day in BCD format
        SBF_FIELD(msk3, 23:23, bool) 		// Alarm A hours mask
        SBF_FIELD(pm, 22:22, bool) 		// AM/PM notation
        SBF_FIELD(ht, 21:20, unsigned) 		// Hour tens in BCD format
        SBF_FIELD(hu, 19:16, unsigned) 		// Hour units in BCD format
        SBF_FIELD(msk2, 15:15, bool) 		// Alarm A minutes mask
        SBF_FIELD(mnt, 14:12, unsigned) 		// Minute tens in BCD format
        SBF_FIELD(mnu, 11:8, unsigned) 		// Minute units in BCD format
        SBF_FIELD(msk1, 7:7, bool) 		// Alarm A seconds mask
        SBF_FIELD(st, 6:4, unsigned) 		// Second tens in BCD format
        SBF_FIELD(su, 3:0, unsigned) 		// Second units in BCD format
    )
    // alarm B register
    // Offset +0x20
    SBF_REGISTER_RW(alrmbr, uint32_t, 0x0,
        SBF_FIELD(msk4, 31:31, bool) 		// Alarm B date mask
        SBF_FIELD(wdsel, 30:30, bool) 		// Week day selection
        SBF_FIELD(dt, 29:28, unsigned) 		// Date tens in BCD format
        SBF_FIELD(du, 27:24, unsigned) 		// Date units or day in BCD format
        SBF_FIELD(msk3, 23:23, bool) 		// Alarm B hours mask
        SBF_FIELD(pm, 22:22, bool) 		// AM/PM notation
        SBF_FIELD(ht, 21:20, unsigned) 		// Hour tens in BCD format
        SBF_FIELD(hu, 19:16, unsigned) 		// Hour units in BCD format
        SBF_FIELD(msk2, 15:15, bool) 		// Alarm B minutes mask
        SBF_FIELD(mnt, 14:12, unsigned) 		// Minute tens in BCD format
        SBF_FIELD(mnu, 11:8, unsigned) 		// Minute units in BCD format
        SBF_FIELD(msk1, 7:7, bool) 		// Alarm B seconds mask
        SBF_FIELD(st, 6:4, unsigned) 		// Second tens in BCD format
        SBF_FIELD(su, 3:0, unsigned) 		// Second units in BCD format
    )
    // write protection register
    // Offset +0x24
    SBF_REGISTER_WO(wpr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // sub second register
    // Offset +0x28
    SBF_REGISTER_RO(ssr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // shift control register
    // Offset +0x2C
    SBF_REGISTER_WO(shiftr, uint32_t, 0x0,
        SBF_FIELD(add1s, 31:31, bool) 		// Add one second
        SBF_FIELD(subfs, 14:0, unsigned) 		// Subtract a fraction of a second
    )
    // time stamp time register
    // Offset +0x30
    SBF_REGISTER_RO(tstr, uint32_t, 0x0,
        SBF_FIELD(pm, 22:22, bool) 		// AM/PM notation
        SBF_FIELD(ht, 21:20, unsigned) 		// Hour tens in BCD format
        SBF_FIELD(hu, 19:16, unsigned) 		// Hour units in BCD format
        SBF_FIELD(mnt, 14:12, unsigned) 		// Minute tens in BCD format
        SBF_FIELD(mnu, 11:8, unsigned) 		// Minute units in BCD format
        SBF_FIELD(st, 6:4, unsigned) 		// Second tens in BCD format
        SBF_FIELD(su, 3:0, unsigned) 		// Second units in BCD format
    )
    // time stamp date register
    // Offset +0x34
    SBF_REGISTER_RO(tsdr, uint32_t, 0x0,
        SBF_FIELD(wdu, 15:13, unsigned) 		// Week day units
        SBF_FIELD(mt, 12:12, bool) 		// Month tens in BCD format
        SBF_FIELD(mu, 11:8, unsigned) 		// Month units in BCD format
        SBF_FIELD(dt, 5:4, unsigned) 		// Date tens in BCD format
        SBF_FIELD(du, 3:0, unsigned) 		// Date units in BCD format
    )
    // timestamp sub second register
    // Offset +0x38
    SBF_REGISTER_RO(tsssr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // calibration register
    // Offset +0x3C
    SBF_REGISTER_RW(calr, uint32_t, 0x0,
        SBF_FIELD(calp, 15:15, bool) 		// Increase frequency of RTC by 488.5 ppm
        SBF_FIELD(calw8, 14:14, bool) 		// Use an 8-second calibration cycle period
        SBF_FIELD(calw16, 13:13, bool) 		// Use a 16-second calibration cycle period
        SBF_FIELD(calm, 8:0, unsigned) 		// Calibration minus
    )
    // tamper configuration register
    // Offset +0x40
    SBF_REGISTER_RW(tampcr, uint32_t, 0x0,
        SBF_FIELD(tamp3mf, 24:24, bool) 		// Tamper 3 mask flag
        SBF_FIELD(tamp3noerase, 23:23, bool) 		// Tamper 3 no erase
        SBF_FIELD(tamp3ie, 22:22, bool) 		// Tamper 3 interrupt enable
        SBF_FIELD(tamp2mf, 21:21, bool) 		// Tamper 2 mask flag
        SBF_FIELD(tamp2noerase, 20:20, bool) 		// Tamper 2 no erase
        SBF_FIELD(tamp2ie, 19:19, bool) 		// Tamper 2 interrupt enable
        SBF_FIELD(tamp1mf, 18:18, bool) 		// Tamper 1 mask flag
        SBF_FIELD(tamp1noerase, 17:17, bool) 		// Tamper 1 no erase
        SBF_FIELD(tamp1ie, 16:16, bool) 		// Tamper 1 interrupt enable
        SBF_FIELD(tamppudis, 15:15, bool) 		// TAMPER pull-up disable
        SBF_FIELD(tampprch, 14:13, unsigned) 		// Tamper precharge duration
        SBF_FIELD(tampflt, 12:11, unsigned) 		// Tamper filter count
        SBF_FIELD(tampfreq, 10:8, unsigned) 		// Tamper sampling frequency
        SBF_FIELD(tampts, 7:7, bool) 		// Activate timestamp on tamper detection event
        SBF_FIELD(tamp3trg, 6:6, bool) 		// Active level for tamper 3
        SBF_FIELD(tamp3e, 5:5, bool) 		// Tamper 3 detection enable
        SBF_FIELD(tamp2trg, 4:4, bool) 		// Active level for tamper 2
        SBF_FIELD(tamp2e, 3:3, bool) 		// Tamper 2 detection enable
        SBF_FIELD(tampie, 2:2, bool) 		// Tamper interrupt enable
        SBF_FIELD(tamp1trg, 1:1, bool) 		// Active level for tamper 1
        SBF_FIELD(tamp1e, 0:0, bool) 		// Tamper 1 detection enable
    )
    // alarm A sub second register
    // Offset +0x44
    SBF_REGISTER_RW(alrmassr, uint32_t, 0x0,
        SBF_FIELD(maskss, 27:24, unsigned) 		// Mask the most-significant bits starting at this bit
        SBF_FIELD(ss, 14:0, unsigned) 		// Sub seconds value
    )
    // alarm B sub second register
    // Offset +0x48
    SBF_REGISTER_RW(alrmbssr, uint32_t, 0x0,
        SBF_FIELD(maskss, 27:24, unsigned) 		// Mask the most-significant bits starting at this bit
        SBF_FIELD(ss, 14:0, unsigned) 		// Sub seconds value
    )
    // option register
    // Offset +0x4C
    SBF_REGISTER_RW(optr, uint32_t, 0x0,
        SBF_FIELD(rtc_out_rmp, 1:1, bool) 		// RTC_OUT remap
        SBF_FIELD(rtc_alarm_type, 0:0, bool) 		// RTC_ALARM on PC13 output type
    )
    // backup register
    // Offset +0x50
    SBF_REGISTER_RW(bkp0r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x54
    SBF_REGISTER_RW(bkp1r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x58
    SBF_REGISTER_RW(bkp2r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x5C
    SBF_REGISTER_RW(bkp3r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x60
    SBF_REGISTER_RW(bkp4r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x64
    SBF_REGISTER_RW(bkp5r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x68
    SBF_REGISTER_RW(bkp6r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x6C
    SBF_REGISTER_RW(bkp7r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x70
    SBF_REGISTER_RW(bkp8r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x74
    SBF_REGISTER_RW(bkp9r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x78
    SBF_REGISTER_RW(bkp10r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x7C
    SBF_REGISTER_RW(bkp11r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x80
    SBF_REGISTER_RW(bkp12r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x84
    SBF_REGISTER_RW(bkp13r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x88
    SBF_REGISTER_RW(bkp14r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x8C
    SBF_REGISTER_RW(bkp15r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x90
    SBF_REGISTER_RW(bkp16r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x94
    SBF_REGISTER_RW(bkp17r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x98
    SBF_REGISTER_RW(bkp18r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0x9C
    SBF_REGISTER_RW(bkp19r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xA0
    SBF_REGISTER_RW(bkp20r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xA4
    SBF_REGISTER_RW(bkp21r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xA8
    SBF_REGISTER_RW(bkp22r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xAC
    SBF_REGISTER_RW(bkp23r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xB0
    SBF_REGISTER_RW(bkp24r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xB4
    SBF_REGISTER_RW(bkp25r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xB8
    SBF_REGISTER_RW(bkp26r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xBC
    SBF_REGISTER_RW(bkp27r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xC0
    SBF_REGISTER_RW(bkp28r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xC4
    SBF_REGISTER_RW(bkp29r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xC8
    SBF_REGISTER_RW(bkp30r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // backup register
    // Offset +0xCC
    SBF_REGISTER_RW(bkp31r, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Rtc registers


// Sai registers
struct Sai {
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x0, uint32_t, 1)
    // AConfiguration register 1
    // Offset +0x4
    SBF_REGISTER_RW(acr1, uint32_t, 0x40,
        SBF_FIELD(mcjdiv, 23:20, unsigned) 		// Master clock divider
        SBF_FIELD(nodiv, 19:19, bool) 		// No divider
        SBF_FIELD(dmaen, 17:17, bool) 		// DMA enable
        SBF_FIELD(saiaen, 16:16, bool) 		// Audio block A enable
        SBF_FIELD(outdri, 13:13, bool) 		// Output drive
        SBF_FIELD(mono, 12:12, bool) 		// Mono mode
        SBF_FIELD(syncen, 11:10, unsigned) 		// Synchronization enable
        SBF_FIELD(ckstr, 9:9, bool) 		// Clock strobing edge
        SBF_FIELD(lsbfirst, 8:8, bool) 		// Least significant bit first
        SBF_FIELD(ds, 7:5, unsigned) 		// Data size
        SBF_FIELD(prtcfg, 3:2, unsigned) 		// Protocol configuration
        SBF_FIELD(mode, 1:0, unsigned) 		// Audio block mode
    )
    // AConfiguration register 2
    // Offset +0x8
    SBF_REGISTER_RW(acr2, uint32_t, 0x0,
        SBF_FIELD(comp, 15:14, unsigned) 		// Companding mode
        SBF_FIELD(cpl, 13:13, bool) 		// Complement bit
        SBF_FIELD(mutecn, 12:7, unsigned) 		// Mute counter
        SBF_FIELD(muteval, 6:6, bool) 		// Mute value
        SBF_FIELD(mute, 5:5, bool) 		// Mute
        SBF_FIELD(tris, 4:4, bool) 		// Tristate management on data line
        SBF_FIELD(fflus, 3:3, bool) 		// FIFO flush
        SBF_FIELD(fth, 2:0, unsigned) 		// FIFO threshold
    )
    // AFRCR
    // Offset +0xC
    SBF_REGISTER_RW(afrcr, uint32_t, 0x7,
        SBF_FIELD(fsoff, 18:18, bool) 		// Frame synchronization offset
        SBF_FIELD(fspol, 17:17, bool) 		// Frame synchronization polarity
        SBF_FIELD(fsdef, 16:16, bool) 		// Frame synchronization definition
        SBF_FIELD(fsall, 14:8, unsigned) 		// Frame synchronization active level length
        SBF_FIELD(frl, 7:0, unsigned) 		// Frame length
    )
    // ASlot register
    // Offset +0x10
    SBF_REGISTER_RW(aslotr, uint32_t, 0x0,
        SBF_FIELD(sloten, 31:16, unsigned) 		// Slot enable
        SBF_FIELD(nbslot, 11:8, unsigned) 		// Number of slots in an audio frame
        SBF_FIELD(slotsz, 7:6, unsigned) 		// Slot size
        SBF_FIELD(fboff, 4:0, unsigned) 		// First bit offset
    )
    // AInterrupt mask register2
    // Offset +0x14
    SBF_REGISTER_RW(aim, uint32_t, 0x0,
        SBF_FIELD(lfsdet, 6:6, bool) 		// Late frame synchronization detection interrupt enable
        SBF_FIELD(afsdetie, 5:5, bool) 		// Anticipated frame synchronization detection interrupt enable
        SBF_FIELD(cnrdyie, 4:4, bool) 		// Codec not ready interrupt enable
        SBF_FIELD(freqie, 3:3, bool) 		// FIFO request interrupt enable
        SBF_FIELD(wckcfg, 2:2, bool) 		// Wrong clock configuration interrupt enable
        SBF_FIELD(mutedet, 1:1, bool) 		// Mute detection interrupt enable
        SBF_FIELD(ovrudrie, 0:0, bool) 		// Overrun/underrun interrupt enable
    )
    // AStatus register
    // Offset +0x18
    SBF_REGISTER_RW(asr, uint32_t, 0x0,
        SBF_FIELD(flvl, 18:16, unsigned) 		// FIFO level threshold
        SBF_FIELD(lfsdet, 6:6, bool) 		// Late frame synchronization detection
        SBF_FIELD(afsdet, 5:5, bool) 		// Anticipated frame synchronization detection
        SBF_FIELD(cnrdy, 4:4, bool) 		// Codec not ready
        SBF_FIELD(freq, 3:3, bool) 		// FIFO request
        SBF_FIELD(wckcfg, 2:2, bool) 		// Wrong clock configuration flag. This bit is read only
        SBF_FIELD(mutedet, 1:1, bool) 		// Mute detection
        SBF_FIELD(ovrudr, 0:0, bool) 		// Overrun / underrun
    )
    // AClear flag register
    // Offset +0x1C
    SBF_REGISTER_RW(aclrfr, uint32_t, 0x0,
        SBF_FIELD(lfsdet, 6:6, bool) 		// Clear late frame synchronization detection flag
        SBF_FIELD(cafsdet, 5:5, bool) 		// Clear anticipated frame synchronization detection flag
        SBF_FIELD(cnrdy, 4:4, bool) 		// Clear codec not ready flag
        SBF_FIELD(wckcfg, 2:2, bool) 		// Clear wrong clock configuration flag
        SBF_FIELD(mutedet, 1:1, bool) 		// Mute detection flag
        SBF_FIELD(ovrudr, 0:0, bool) 		// Clear overrun / underrun
    )
    // AData register
    // Offset +0x20
    SBF_REGISTER_RW(adr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // BConfiguration register 1
    // Offset +0x24
    SBF_REGISTER_RW(bcr1, uint32_t, 0x40,
        SBF_FIELD(mcjdiv, 23:20, unsigned) 		// Master clock divider
        SBF_FIELD(nodiv, 19:19, bool) 		// No divider
        SBF_FIELD(dmaen, 17:17, bool) 		// DMA enable
        SBF_FIELD(saiben, 16:16, bool) 		// Audio block B enable
        SBF_FIELD(outdri, 13:13, bool) 		// Output drive
        SBF_FIELD(mono, 12:12, bool) 		// Mono mode
        SBF_FIELD(syncen, 11:10, unsigned) 		// Synchronization enable
        SBF_FIELD(ckstr, 9:9, bool) 		// Clock strobing edge
        SBF_FIELD(lsbfirst, 8:8, bool) 		// Least significant bit first
        SBF_FIELD(ds, 7:5, unsigned) 		// Data size
        SBF_FIELD(prtcfg, 3:2, unsigned) 		// Protocol configuration
        SBF_FIELD(mode, 1:0, unsigned) 		// Audio block mode
    )
    // BConfiguration register 2
    // Offset +0x28
    SBF_REGISTER_RW(bcr2, uint32_t, 0x0,
        SBF_FIELD(comp, 15:14, unsigned) 		// Companding mode
        SBF_FIELD(cpl, 13:13, bool) 		// Complement bit
        SBF_FIELD(mutecn, 12:7, unsigned) 		// Mute counter
        SBF_FIELD(muteval, 6:6, bool) 		// Mute value
        SBF_FIELD(mute, 5:5, bool) 		// Mute
        SBF_FIELD(tris, 4:4, bool) 		// Tristate management on data line
        SBF_FIELD(fflus, 3:3, bool) 		// FIFO flush
        SBF_FIELD(fth, 2:0, unsigned) 		// FIFO threshold
    )
    // BFRCR
    // Offset +0x2C
    SBF_REGISTER_RW(bfrcr, uint32_t, 0x7,
        SBF_FIELD(fsoff, 18:18, bool) 		// Frame synchronization offset
        SBF_FIELD(fspol, 17:17, bool) 		// Frame synchronization polarity
        SBF_FIELD(fsdef, 16:16, bool) 		// Frame synchronization definition
        SBF_FIELD(fsall, 14:8, unsigned) 		// Frame synchronization active level length
        SBF_FIELD(frl, 7:0, unsigned) 		// Frame length
    )
    // BSlot register
    // Offset +0x30
    SBF_REGISTER_RW(bslotr, uint32_t, 0x0,
        SBF_FIELD(sloten, 31:16, unsigned) 		// Slot enable
        SBF_FIELD(nbslot, 11:8, unsigned) 		// Number of slots in an audio frame
        SBF_FIELD(slotsz, 7:6, unsigned) 		// Slot size
        SBF_FIELD(fboff, 4:0, unsigned) 		// First bit offset
    )
    // BInterrupt mask register2
    // Offset +0x34
    SBF_REGISTER_RW(bim, uint32_t, 0x0,
        SBF_FIELD(lfsdetie, 6:6, bool) 		// Late frame synchronization detection interrupt enable
        SBF_FIELD(afsdetie, 5:5, bool) 		// Anticipated frame synchronization detection interrupt enable
        SBF_FIELD(cnrdyie, 4:4, bool) 		// Codec not ready interrupt enable
        SBF_FIELD(freqie, 3:3, bool) 		// FIFO request interrupt enable
        SBF_FIELD(wckcfg, 2:2, bool) 		// Wrong clock configuration interrupt enable
        SBF_FIELD(mutedet, 1:1, bool) 		// Mute detection interrupt enable
        SBF_FIELD(ovrudrie, 0:0, bool) 		// Overrun/underrun interrupt enable
    )
    // BStatus register
    // Offset +0x38
    SBF_REGISTER_RO(bsr, uint32_t, 0x0,
        SBF_FIELD(flvl, 18:16, unsigned) 		// FIFO level threshold
        SBF_FIELD(lfsdet, 6:6, bool) 		// Late frame synchronization detection
        SBF_FIELD(afsdet, 5:5, bool) 		// Anticipated frame synchronization detection
        SBF_FIELD(cnrdy, 4:4, bool) 		// Codec not ready
        SBF_FIELD(freq, 3:3, bool) 		// FIFO request
        SBF_FIELD(wckcfg, 2:2, bool) 		// Wrong clock configuration flag
        SBF_FIELD(mutedet, 1:1, bool) 		// Mute detection
        SBF_FIELD(ovrudr, 0:0, bool) 		// Overrun / underrun
    )
    // BClear flag register
    // Offset +0x3C
    SBF_REGISTER_WO(bclrfr, uint32_t, 0x0,
        SBF_FIELD(lfsdet, 6:6, bool) 		// Clear late frame synchronization detection flag
        SBF_FIELD(cafsdet, 5:5, bool) 		// Clear anticipated frame synchronization detection flag
        SBF_FIELD(cnrdy, 4:4, bool) 		// Clear codec not ready flag
        SBF_FIELD(wckcfg, 2:2, bool) 		// Clear wrong clock configuration flag
        SBF_FIELD(mutedet, 1:1, bool) 		// Mute detection flag
        SBF_FIELD(ovrudr, 0:0, bool) 		// Clear overrun / underrun
    )
    // BData register
    // Offset +0x40
    SBF_REGISTER_RW(bdr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Sai registers


// Sdio registers
struct Sdio {
    // power control register
    // Offset +0x0
    SBF_REGISTER_RW(power, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // SDI clock control register
    // Offset +0x4
    SBF_REGISTER_RW(clkcr, uint32_t, 0x0,
        SBF_FIELD(hwfc_en, 14:14, bool) 		// HW Flow Control enable
        SBF_FIELD(negedge, 13:13, bool) 		// SDIO_CK dephasing selection bit
        SBF_FIELD(widbus, 12:11, unsigned) 		// Wide bus mode enable bit
        SBF_FIELD(bypass, 10:10, bool) 		// Clock divider bypass enable bit
        SBF_FIELD(pwrsav, 9:9, bool) 		// Power saving configuration bit
        SBF_FIELD(clken, 8:8, bool) 		// Clock enable bit
        SBF_FIELD(clkdiv, 7:0, unsigned) 		// Clock divide factor
    )
    // argument register
    // Offset +0x8
    SBF_REGISTER_RW(arg, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // command register
    // Offset +0xC
    SBF_REGISTER_RW(cmd, uint32_t, 0x0,
        SBF_FIELD(ce_atacmd, 14:14, bool) 		// CE-ATA command
        SBF_FIELD(nien, 13:13, bool) 		// not Interrupt Enable
        SBF_FIELD(encmdcompl, 12:12, bool) 		// Enable CMD completion
        SBF_FIELD(sdiosuspend, 11:11, bool) 		// SD I/O suspend command
        SBF_FIELD(cpsmen, 10:10, bool) 		// Command path state machine (CPSM) Enable bit
        SBF_FIELD(waitpend, 9:9, bool) 		// CPSM Waits for ends of data transfer (CmdPend internal signal)
        SBF_FIELD(waitint, 8:8, bool) 		// CPSM waits for interrupt request
        SBF_FIELD(waitresp, 7:6, unsigned) 		// Wait for response bits
        SBF_FIELD(cmdindex, 5:0, unsigned) 		// Command index
    )
    // command response register
    // Offset +0x10
    SBF_REGISTER_RO(respcmd, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // response 1..4 register
    // Offset +0x14
    SBF_REGISTER_RO(resp1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // response 1..4 register
    // Offset +0x18
    SBF_REGISTER_RO(resp2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // response 1..4 register
    // Offset +0x1C
    SBF_REGISTER_RO(resp3, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // response 1..4 register
    // Offset +0x20
    SBF_REGISTER_RO(resp4, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // data timer register
    // Offset +0x24
    SBF_REGISTER_RW(dtimer, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // data length register
    // Offset +0x28
    SBF_REGISTER_RW(dlen, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // data control register
    // Offset +0x2C
    SBF_REGISTER_RW(dctrl, uint32_t, 0x0,
        SBF_FIELD(sdioen, 11:11, bool) 		// SD I/O enable functions
        SBF_FIELD(rwmod, 10:10, bool) 		// Read wait mode
        SBF_FIELD(rwstop, 9:9, bool) 		// Read wait stop
        SBF_FIELD(rwstart, 8:8, bool) 		// Read wait start
        SBF_FIELD(dblocksize, 7:4, unsigned) 		// Data block size
        SBF_FIELD(dmaen, 3:3, bool) 		// DMA enable bit
        SBF_FIELD(dtmode, 2:2, bool) 		// Data transfer mode selection 1: Stream or SDIO multibyte data transfer
        SBF_FIELD(dtdir, 1:1, bool) 		// Data transfer direction selection
        SBF_FIELD(dten, 0:0, bool) 		// DTEN
    )
    // data counter register
    // Offset +0x30
    SBF_REGISTER_RO(dcount, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // status register
    // Offset +0x34
    SBF_REGISTER_RO(sta, uint32_t, 0x0,
        SBF_FIELD(ceataend, 23:23, bool) 		// CE-ATA command completion signal received for CMD61
        SBF_FIELD(sdioit, 22:22, bool) 		// SDIO interrupt received
        SBF_FIELD(rxdavl, 21:21, bool) 		// Data available in receive FIFO
        SBF_FIELD(txdavl, 20:20, bool) 		// Data available in transmit FIFO
        SBF_FIELD(rxfifoe, 19:19, bool) 		// Receive FIFO empty
        SBF_FIELD(txfifoe, 18:18, bool) 		// Transmit FIFO empty
        SBF_FIELD(rxfifof, 17:17, bool) 		// Receive FIFO full
        SBF_FIELD(txfifof, 16:16, bool) 		// Transmit FIFO full
        SBF_FIELD(rxfifohf, 15:15, bool) 		// Receive FIFO half full: there are at least 8 words in the FIFO
        SBF_FIELD(txfifohe, 14:14, bool) 		// Transmit FIFO half empty: at least 8 words can be written into the FIFO
        SBF_FIELD(rxact, 13:13, bool) 		// Data receive in progress
        SBF_FIELD(txact, 12:12, bool) 		// Data transmit in progress
        SBF_FIELD(cmdact, 11:11, bool) 		// Command transfer in progress
        SBF_FIELD(dbckend, 10:10, bool) 		// Data block sent/received (CRC check passed)
        SBF_FIELD(stbiterr, 9:9, bool) 		// Start bit not detected on all data signals in wide bus mode
        SBF_FIELD(dataend, 8:8, bool) 		// Data end (data counter, SDIDCOUNT, is zero)
        SBF_FIELD(cmdsent, 7:7, bool) 		// Command sent (no response required)
        SBF_FIELD(cmdrend, 6:6, bool) 		// Command response received (CRC check passed)
        SBF_FIELD(rxoverr, 5:5, bool) 		// Received FIFO overrun error
        SBF_FIELD(txunderr, 4:4, bool) 		// Transmit FIFO underrun error
        SBF_FIELD(dtimeout, 3:3, bool) 		// Data timeout
        SBF_FIELD(ctimeout, 2:2, bool) 		// Command response timeout
        SBF_FIELD(dcrcfail, 1:1, bool) 		// Data block sent/received (CRC check failed)
        SBF_FIELD(ccrcfail, 0:0, bool) 		// Command response received (CRC check failed)
    )
    // interrupt clear register
    // Offset +0x38
    SBF_REGISTER_RW(icr, uint32_t, 0x0,
        SBF_FIELD(ceataendc, 23:23, bool) 		// CEATAEND flag clear bit
        SBF_FIELD(sdioitc, 22:22, bool) 		// SDIOIT flag clear bit
        SBF_FIELD(dbckendc, 10:10, bool) 		// DBCKEND flag clear bit
        SBF_FIELD(stbiterrc, 9:9, bool) 		// STBITERR flag clear bit
        SBF_FIELD(dataendc, 8:8, bool) 		// DATAEND flag clear bit
        SBF_FIELD(cmdsentc, 7:7, bool) 		// CMDSENT flag clear bit
        SBF_FIELD(cmdrendc, 6:6, bool) 		// CMDREND flag clear bit
        SBF_FIELD(rxoverrc, 5:5, bool) 		// RXOVERR flag clear bit
        SBF_FIELD(txunderrc, 4:4, bool) 		// TXUNDERR flag clear bit
        SBF_FIELD(dtimeoutc, 3:3, bool) 		// DTIMEOUT flag clear bit
        SBF_FIELD(ctimeoutc, 2:2, bool) 		// CTIMEOUT flag clear bit
        SBF_FIELD(dcrcfailc, 1:1, bool) 		// DCRCFAIL flag clear bit
        SBF_FIELD(ccrcfailc, 0:0, bool) 		// CCRCFAIL flag clear bit
    )
    // mask register
    // Offset +0x3C
    SBF_REGISTER_RW(mask, uint32_t, 0x0,
        SBF_FIELD(ceataendie, 23:23, bool) 		// CE-ATA command completion signal received interrupt enable
        SBF_FIELD(sdioitie, 22:22, bool) 		// SDIO mode interrupt received interrupt enable
        SBF_FIELD(rxdavlie, 21:21, bool) 		// Data available in Rx FIFO interrupt enable
        SBF_FIELD(txdavlie, 20:20, bool) 		// Data available in Tx FIFO interrupt enable
        SBF_FIELD(rxfifoeie, 19:19, bool) 		// Rx FIFO empty interrupt enable
        SBF_FIELD(txfifoeie, 18:18, bool) 		// Tx FIFO empty interrupt enable
        SBF_FIELD(rxfifofie, 17:17, bool) 		// Rx FIFO full interrupt enable
        SBF_FIELD(txfifofie, 16:16, bool) 		// Tx FIFO full interrupt enable
        SBF_FIELD(rxfifohfie, 15:15, bool) 		// Rx FIFO half full interrupt enable
        SBF_FIELD(txfifoheie, 14:14, bool) 		// Tx FIFO half empty interrupt enable
        SBF_FIELD(rxactie, 13:13, bool) 		// Data receive acting interrupt enable
        SBF_FIELD(txactie, 12:12, bool) 		// Data transmit acting interrupt enable
        SBF_FIELD(cmdactie, 11:11, bool) 		// Command acting interrupt enable
        SBF_FIELD(dbckendie, 10:10, bool) 		// Data block end interrupt enable
        SBF_FIELD(stbiterrie, 9:9, bool) 		// Start bit error interrupt enable
        SBF_FIELD(dataendie, 8:8, bool) 		// Data end interrupt enable
        SBF_FIELD(cmdsentie, 7:7, bool) 		// Command sent interrupt enable
        SBF_FIELD(cmdrendie, 6:6, bool) 		// Command response received interrupt enable
        SBF_FIELD(rxoverrie, 5:5, bool) 		// Rx FIFO overrun error interrupt enable
        SBF_FIELD(txunderrie, 4:4, bool) 		// Tx FIFO underrun error interrupt enable
        SBF_FIELD(dtimeoutie, 3:3, bool) 		// Data timeout interrupt enable
        SBF_FIELD(ctimeoutie, 2:2, bool) 		// Command timeout interrupt enable
        SBF_FIELD(dcrcfailie, 1:1, bool) 		// Data CRC fail interrupt enable
        SBF_FIELD(ccrcfailie, 0:0, bool) 		// Command CRC fail interrupt enable
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x40_to_0x44, uint32_t, 2)
    // FIFO counter register
    // Offset +0x48
    SBF_REGISTER_RO(fifocnt, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x4C_to_0x7C, uint32_t, 13)
    // data FIFO register
    // Offset +0x80
    SBF_REGISTER_RW(fifo, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Sdio registers


// Spi registers
struct Spi {
    // control register 1
    // Offset +0x0
    SBF_REGISTER_RW(cr1, uint32_t, 0x0,
        SBF_FIELD(bidimode, 15:15, bool) 		// Bidirectional data mode enable
        SBF_FIELD(bidioe, 14:14, bool) 		// Output enable in bidirectional mode
        SBF_FIELD(crcen, 13:13, bool) 		// Hardware CRC calculation enable
        SBF_FIELD(crcnext, 12:12, bool) 		// CRC transfer next
        SBF_FIELD(dff, 11:11, bool) 		// Data frame format
        SBF_FIELD(rxonly, 10:10, bool) 		// Receive only
        SBF_FIELD(ssm, 9:9, bool) 		// Software slave management
        SBF_FIELD(ssi, 8:8, bool) 		// Internal slave select
        SBF_FIELD(lsbfirst, 7:7, bool) 		// Frame format
        SBF_FIELD(spe, 6:6, bool) 		// SPI enable
        SBF_FIELD(br, 5:3, unsigned) 		// Baud rate control
        SBF_FIELD(mstr, 2:2, bool) 		// Master selection
        SBF_FIELD(cpol, 1:1, bool) 		// Clock polarity
        SBF_FIELD(cpha, 0:0, bool) 		// Clock phase
    )
    // control register 2
    // Offset +0x4
    SBF_REGISTER_RW(cr2, uint32_t, 0x0,
        SBF_FIELD(ldma_tx, 14:14, bool) 		// Last DMA transfer for transmission
        SBF_FIELD(ldma_rx, 13:13, bool) 		// Last DMA transfer for reception
        SBF_FIELD(frxth, 12:12, bool) 		// FIFO reception threshold
        SBF_FIELD(ds, 11:8, unsigned) 		// Data size
        SBF_FIELD(txeie, 7:7, bool) 		// Tx buffer empty interrupt enable
        SBF_FIELD(rxneie, 6:6, bool) 		// RX buffer not empty interrupt enable
        SBF_FIELD(errie, 5:5, bool) 		// Error interrupt enable
        SBF_FIELD(frf, 4:4, bool) 		// Frame format
        SBF_FIELD(nssp, 3:3, bool) 		// NSS pulse management
        SBF_FIELD(ssoe, 2:2, bool) 		// SS output enable
        SBF_FIELD(txdmaen, 1:1, bool) 		// Tx buffer DMA enable
        SBF_FIELD(rxdmaen, 0:0, bool) 		// Rx buffer DMA enable
    )
    // status register
    // Offset +0x8
    SBF_REGISTER_RW(sr, uint32_t, 0x2,
        SBF_FIELD(ftlvl, 12:11, unsigned) 		// FIFO transmission level
        SBF_FIELD(frlvl, 10:9, unsigned) 		// FIFO reception level
        SBF_FIELD(tifrfe, 8:8, bool) 		// TI frame format error
        SBF_FIELD(bsy, 7:7, bool) 		// Busy flag
        SBF_FIELD(ovr, 6:6, bool) 		// Overrun flag
        SBF_FIELD(modf, 5:5, bool) 		// Mode fault
        SBF_FIELD(crcerr, 4:4, bool) 		// CRC error flag
        SBF_FIELD(txe, 1:1, bool) 		// Transmit buffer empty
        SBF_FIELD(rxne, 0:0, bool) 		// Receive buffer not empty
    )
    // data register
    // Offset +0xC
    SBF_REGISTER_RW(dr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // CRC polynomial register
    // Offset +0x10
    SBF_REGISTER_RW(crcpr, uint32_t, 0x7,
        SBF_NO_FIELDS
    )
    // RX CRC register
    // Offset +0x14
    SBF_REGISTER_RO(rxcrcr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // TX CRC register
    // Offset +0x18
    SBF_REGISTER_RO(txcrcr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Spi registers


// Swpmi registers
struct Swpmi {
    // SWPMI Configuration/Control register
    // Offset +0x0
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(deact, 10:10, bool) 		// Single wire protocol master interface deactivate
        SBF_FIELD(swpme, 5:5, bool) 		// Single wire protocol master interface enable
        SBF_FIELD(lpbk, 4:4, bool) 		// Loopback mode enable
        SBF_FIELD(txmode, 3:3, bool) 		// Transmission buffering mode
        SBF_FIELD(rxmode, 2:2, bool) 		// Reception buffering mode
        SBF_FIELD(txdma, 1:1, bool) 		// Transmission DMA enable
        SBF_FIELD(rxdma, 0:0, bool) 		// Reception DMA enable
    )
    // SWPMI Bitrate register
    // Offset +0x4
    SBF_REGISTER_RW(brr, uint32_t, 0x1,
        SBF_NO_FIELDS
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x8, uint32_t, 1)
    // SWPMI Interrupt and Status register
    // Offset +0xC
    SBF_REGISTER_RO(isr, uint32_t, 0x2C2,
        SBF_FIELD(deactf, 10:10, bool) 		// DEACTIVATED flag
        SBF_FIELD(susp, 9:9, bool) 		// SUSPEND flag
        SBF_FIELD(srf, 8:8, bool) 		// Slave resume flag
        SBF_FIELD(tcf, 7:7, bool) 		// Transfer complete flag
        SBF_FIELD(txe, 6:6, bool) 		// Transmit data register empty
        SBF_FIELD(rxne, 5:5, bool) 		// Receive data register not empty
        SBF_FIELD(txunrf, 4:4, bool) 		// Transmit underrun error flag
        SBF_FIELD(rxovrf, 3:3, bool) 		// Receive overrun error flag
        SBF_FIELD(rxberf, 2:2, bool) 		// Receive CRC error flag
        SBF_FIELD(txbef, 1:1, bool) 		// Transmit buffer empty flag
        SBF_FIELD(rxbff, 0:0, bool) 		// Receive buffer full flag
    )
    // SWPMI Interrupt Flag Clear register
    // Offset +0x10
    SBF_REGISTER_WO(icr, uint32_t, 0x0,
        SBF_FIELD(csrf, 8:8, bool) 		// Clear slave resume flag
        SBF_FIELD(ctcf, 7:7, bool) 		// Clear transfer complete flag
        SBF_FIELD(ctxunrf, 4:4, bool) 		// Clear transmit underrun error flag
        SBF_FIELD(crxovrf, 3:3, bool) 		// Clear receive overrun error flag
        SBF_FIELD(crxberf, 2:2, bool) 		// Clear receive CRC error flag
        SBF_FIELD(ctxbef, 1:1, bool) 		// Clear transmit buffer empty flag
        SBF_FIELD(crxbff, 0:0, bool) 		// Clear receive buffer full flag
    )
    // SWPMI Interrupt Enable register
    // Offset +0x14
    SBF_REGISTER_RW(ier, uint32_t, 0x0,
        SBF_FIELD(srie, 8:8, bool) 		// Slave resume interrupt enable
        SBF_FIELD(tcie, 7:7, bool) 		// Transmit complete interrupt enable
        SBF_FIELD(tie, 6:6, bool) 		// Transmit interrupt enable
        SBF_FIELD(rie, 5:5, bool) 		// Receive interrupt enable
        SBF_FIELD(txunrie, 4:4, bool) 		// Transmit underrun error interrupt enable
        SBF_FIELD(rxovrie, 3:3, bool) 		// Receive overrun error interrupt enable
        SBF_FIELD(rxberie, 2:2, bool) 		// Receive CRC error interrupt enable
        SBF_FIELD(txbeie, 1:1, bool) 		// Transmit buffer empty interrupt enable
        SBF_FIELD(rxbfie, 0:0, bool) 		// Receive buffer full interrupt enable
    )
    // SWPMI Receive Frame Length register
    // Offset +0x18
    SBF_REGISTER_RO(rfl, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // SWPMI Transmit data register
    // Offset +0x1C
    SBF_REGISTER_WO(tdr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // SWPMI Receive data register
    // Offset +0x20
    SBF_REGISTER_RO(rdr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Swpmi registers


// Syscfg registers
struct Syscfg {
    // memory remap register
    // Offset +0x0
    SBF_REGISTER_RW(memrmp, uint32_t, 0x0,
        SBF_FIELD(fb_mode, 8:8, bool) 		// Flash Bank mode selection
        SBF_FIELD(qfs, 3:3, bool) 		// QUADSPI memory mapping swap
        SBF_FIELD(mem_mode, 2:0, unsigned) 		// Memory mapping selection
    )
    // configuration register 1
    // Offset +0x4
    SBF_REGISTER_RW(cfgr1, uint32_t, 0x7C000001,
        SBF_FIELD(fpu_ie, 31:26, unsigned) 		// Floating Point Unit interrupts enable bits
        SBF_FIELD(i2c3_fmp, 22:22, bool) 		// I2C3 Fast-mode Plus driving capability activation
        SBF_FIELD(i2c2_fmp, 21:21, bool) 		// I2C2 Fast-mode Plus driving capability activation
        SBF_FIELD(i2c1_fmp, 20:20, bool) 		// I2C1 Fast-mode Plus driving capability activation
        SBF_FIELD(i2c_pb9_fmp, 19:19, bool) 		// Fast-mode Plus (Fm+) driving capability activation on PB9
        SBF_FIELD(i2c_pb8_fmp, 18:18, bool) 		// Fast-mode Plus (Fm+) driving capability activation on PB8
        SBF_FIELD(i2c_pb7_fmp, 17:17, bool) 		// Fast-mode Plus (Fm+) driving capability activation on PB7
        SBF_FIELD(i2c_pb6_fmp, 16:16, bool) 		// Fast-mode Plus (Fm+) driving capability activation on PB6
        SBF_FIELD(boosten, 8:8, bool) 		// I/O analog switch voltage booster enable
        SBF_FIELD(fwdis, 0:0, bool) 		// Firewall disable
    )
    // external interrupt configuration register 1
    // Offset +0x8
    SBF_REGISTER_RW(exticr1, uint32_t, 0x0,
        SBF_FIELD(exti3, 14:12, unsigned) 		// EXTI 3 configuration bits
        SBF_FIELD(exti2, 10:8, unsigned) 		// EXTI 2 configuration bits
        SBF_FIELD(exti1, 6:4, unsigned) 		// EXTI 1 configuration bits
        SBF_FIELD(exti0, 2:0, unsigned) 		// EXTI 0 configuration bits
    )
    // external interrupt configuration register 2
    // Offset +0xC
    SBF_REGISTER_RW(exticr2, uint32_t, 0x0,
        SBF_FIELD(exti7, 14:12, unsigned) 		// EXTI 7 configuration bits
        SBF_FIELD(exti6, 10:8, unsigned) 		// EXTI 6 configuration bits
        SBF_FIELD(exti5, 6:4, unsigned) 		// EXTI 5 configuration bits
        SBF_FIELD(exti4, 2:0, unsigned) 		// EXTI 4 configuration bits
    )
    // external interrupt configuration register 3
    // Offset +0x10
    SBF_REGISTER_RW(exticr3, uint32_t, 0x0,
        SBF_FIELD(exti11, 14:12, unsigned) 		// EXTI 11 configuration bits
        SBF_FIELD(exti10, 10:8, unsigned) 		// EXTI 10 configuration bits
        SBF_FIELD(exti9, 6:4, unsigned) 		// EXTI 9 configuration bits
        SBF_FIELD(exti8, 2:0, unsigned) 		// EXTI 8 configuration bits
    )
    // external interrupt configuration register 4
    // Offset +0x14
    SBF_REGISTER_RW(exticr4, uint32_t, 0x0,
        SBF_FIELD(exti15, 14:12, unsigned) 		// EXTI15 configuration bits
        SBF_FIELD(exti14, 10:8, unsigned) 		// EXTI14 configuration bits
        SBF_FIELD(exti13, 6:4, unsigned) 		// EXTI13 configuration bits
        SBF_FIELD(exti12, 2:0, unsigned) 		// EXTI12 configuration bits
    )
    // SCSR
    // Offset +0x18
    SBF_REGISTER_RW(scsr, uint32_t, 0x0,
        SBF_FIELD(sram2bsy, 1:1, bool) 		// SRAM2 busy by erase operation
        SBF_FIELD(sram2er, 0:0, bool) 		// SRAM2 Erase
    )
    // CFGR2
    // Offset +0x1C
    SBF_REGISTER_RW(cfgr2, uint32_t, 0x0,
        SBF_FIELD(spf, 8:8, bool) 		// SRAM2 parity error flag
        SBF_FIELD(eccl, 3:3, bool) 		// ECC Lock
        SBF_FIELD(pvdl, 2:2, bool) 		// PVD lock enable bit
        SBF_FIELD(spl, 1:1, bool) 		// SRAM2 parity lock bit
        SBF_FIELD(cll, 0:0, bool) 		//  Cortex-M4 LOCKUP (Hardfault) output enable bit
    )
    // SWPR
    // Offset +0x20
    SBF_REGISTER_WO(swpr, uint32_t, 0x0,
        SBF_FIELD(p31wp, 31:31, bool) 		// SRAM2 page 31 write protection
        SBF_FIELD(p30wp, 30:30, bool) 		// P30WP
        SBF_FIELD(p29wp, 29:29, bool) 		// P29WP
        SBF_FIELD(p28wp, 28:28, bool) 		// P28WP
        SBF_FIELD(p27wp, 27:27, bool) 		// P27WP
        SBF_FIELD(p26wp, 26:26, bool) 		// P26WP
        SBF_FIELD(p25wp, 25:25, bool) 		// P25WP
        SBF_FIELD(p24wp, 24:24, bool) 		// P24WP
        SBF_FIELD(p23wp, 23:23, bool) 		// P23WP
        SBF_FIELD(p22wp, 22:22, bool) 		// P22WP
        SBF_FIELD(p21wp, 21:21, bool) 		// P21WP
        SBF_FIELD(p20wp, 20:20, bool) 		// P20WP
        SBF_FIELD(p19wp, 19:19, bool) 		// P19WP
        SBF_FIELD(p18wp, 18:18, bool) 		// P18WP
        SBF_FIELD(p17wp, 17:17, bool) 		// P17WP
        SBF_FIELD(p16wp, 16:16, bool) 		// P16WP
        SBF_FIELD(p15wp, 15:15, bool) 		// P15WP
        SBF_FIELD(p14wp, 14:14, bool) 		// P14WP
        SBF_FIELD(p13wp, 13:13, bool) 		// P13WP
        SBF_FIELD(p12wp, 12:12, bool) 		// P12WP
        SBF_FIELD(p11wp, 11:11, bool) 		// P11WP
        SBF_FIELD(p10wp, 10:10, bool) 		// P10WP
        SBF_FIELD(p9wp, 9:9, bool) 		// P9WP
        SBF_FIELD(p8wp, 8:8, bool) 		// P8WP
        SBF_FIELD(p7wp, 7:7, bool) 		// P7WP
        SBF_FIELD(p6wp, 6:6, bool) 		// P6WP
        SBF_FIELD(p5wp, 5:5, bool) 		// P5WP
        SBF_FIELD(p4wp, 4:4, bool) 		// P4WP
        SBF_FIELD(p3wp, 3:3, bool) 		// P3WP
        SBF_FIELD(p2wp, 2:2, bool) 		// P2WP
        SBF_FIELD(p1wp, 1:1, bool) 		// P1WP
        SBF_FIELD(p0wp, 0:0, bool) 		// P0WP
    )
    // SKR
    // Offset +0x24
    SBF_REGISTER_WO(skr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Syscfg registers


// Tim registers
struct Tim {
    // control register 1
    // Offset +0x0
    SBF_REGISTER_RW(cr1, uint32_t, 0x0,
        SBF_FIELD(ckd, 9:8, unsigned) 		// Clock division
        SBF_FIELD(arpe, 7:7, bool) 		// Auto-reload preload enable
        SBF_FIELD(cms, 6:5, unsigned) 		// Center-aligned mode selection
        SBF_FIELD(dir, 4:4, bool) 		// Direction
        SBF_FIELD(opm, 3:3, bool) 		// One-pulse mode
        SBF_FIELD(urs, 2:2, bool) 		// Update request source
        SBF_FIELD(udis, 1:1, bool) 		// Update disable
        SBF_FIELD(cen, 0:0, bool) 		// Counter enable
    )
    // control register 2
    // Offset +0x4
    SBF_REGISTER_RW(cr2, uint32_t, 0x0,
        SBF_FIELD(ois4, 14:14, bool) 		// Output Idle state 4
        SBF_FIELD(ois3n, 13:13, bool) 		// Output Idle state 3
        SBF_FIELD(ois3, 12:12, bool) 		// Output Idle state 3
        SBF_FIELD(ois2n, 11:11, bool) 		// Output Idle state 2
        SBF_FIELD(ois2, 10:10, bool) 		// Output Idle state 2
        SBF_FIELD(ois1n, 9:9, bool) 		// Output Idle state 1
        SBF_FIELD(ois1, 8:8, bool) 		// Output Idle state 1
        SBF_FIELD(ti1s, 7:7, bool) 		// TI1 selection
        SBF_FIELD(mms, 6:4, unsigned) 		// Master mode selection
        SBF_FIELD(ccds, 3:3, bool) 		// Capture/compare DMA selection
        SBF_FIELD(ccus, 2:2, bool) 		// Capture/compare control update selection
        SBF_FIELD(ccpc, 0:0, bool) 		// Capture/compare preloaded control
    )
    // slave mode control register
    // Offset +0x8
    SBF_REGISTER_RW(smcr, uint32_t, 0x0,
        SBF_FIELD(etp, 15:15, bool) 		// External trigger polarity
        SBF_FIELD(ece, 14:14, bool) 		// External clock enable
        SBF_FIELD(etps, 13:12, unsigned) 		// External trigger prescaler
        SBF_FIELD(etf, 11:8, unsigned) 		// External trigger filter
        SBF_FIELD(msm, 7:7, bool) 		// Master/Slave mode
        SBF_FIELD(ts, 6:4, unsigned) 		// Trigger selection
        SBF_FIELD(sms, 2:0, unsigned) 		// Slave mode selection
    )
    // DMA/Interrupt enable register
    // Offset +0xC
    SBF_REGISTER_RW(dier, uint32_t, 0x0,
        SBF_FIELD(tde, 14:14, bool) 		// Trigger DMA request enable
        SBF_FIELD(comde, 13:13, bool) 		// COM DMA request enable
        SBF_FIELD(cc4de, 12:12, bool) 		// Capture/Compare 4 DMA request enable
        SBF_FIELD(cc3de, 11:11, bool) 		// Capture/Compare 3 DMA request enable
        SBF_FIELD(cc2de, 10:10, bool) 		// Capture/Compare 2 DMA request enable
        SBF_FIELD(cc1de, 9:9, bool) 		// Capture/Compare 1 DMA request enable
        SBF_FIELD(ude, 8:8, bool) 		// Update DMA request enable
        SBF_FIELD(bie, 7:7, bool) 		// Break interrupt enable
        SBF_FIELD(tie, 6:6, bool) 		// Trigger interrupt enable
        SBF_FIELD(comie, 5:5, bool) 		// COM interrupt enable
        SBF_FIELD(cc4ie, 4:4, bool) 		// Capture/Compare 4 interrupt enable
        SBF_FIELD(cc3ie, 3:3, bool) 		// Capture/Compare 3 interrupt enable
        SBF_FIELD(cc2ie, 2:2, bool) 		// Capture/Compare 2 interrupt enable
        SBF_FIELD(cc1ie, 1:1, bool) 		// Capture/Compare 1 interrupt enable
        SBF_FIELD(uie, 0:0, bool) 		// Update interrupt enable
    )
    // status register
    // Offset +0x10
    SBF_REGISTER_RW(sr, uint32_t, 0x0,
        SBF_FIELD(cc4of, 12:12, bool) 		// Capture/Compare 4 overcapture flag
        SBF_FIELD(cc3of, 11:11, bool) 		// Capture/Compare 3 overcapture flag
        SBF_FIELD(cc2of, 10:10, bool) 		// Capture/compare 2 overcapture flag
        SBF_FIELD(cc1of, 9:9, bool) 		// Capture/Compare 1 overcapture flag
        SBF_FIELD(bif, 7:7, bool) 		// Break interrupt flag
        SBF_FIELD(tif, 6:6, bool) 		// Trigger interrupt flag
        SBF_FIELD(comif, 5:5, bool) 		// COM interrupt flag
        SBF_FIELD(cc4if, 4:4, bool) 		// Capture/Compare 4 interrupt flag
        SBF_FIELD(cc3if, 3:3, bool) 		// Capture/Compare 3 interrupt flag
        SBF_FIELD(cc2if, 2:2, bool) 		// Capture/Compare 2 interrupt flag
        SBF_FIELD(cc1if, 1:1, bool) 		// Capture/compare 1 interrupt flag
        SBF_FIELD(uif, 0:0, bool) 		// Update interrupt flag
    )
    // event generation register
    // Offset +0x14
    SBF_REGISTER_WO(egr, uint32_t, 0x0,
        SBF_FIELD(bg, 7:7, bool) 		// Break generation
        SBF_FIELD(tg, 6:6, bool) 		// Trigger generation
        SBF_FIELD(comg, 5:5, bool) 		// Capture/Compare control update generation
        SBF_FIELD(cc4g, 4:4, bool) 		// Capture/compare 4 generation
        SBF_FIELD(cc3g, 3:3, bool) 		// Capture/compare 3 generation
        SBF_FIELD(cc2g, 2:2, bool) 		// Capture/compare 2 generation
        SBF_FIELD(cc1g, 1:1, bool) 		// Capture/compare 1 generation
        SBF_FIELD(ug, 0:0, bool) 		// Update generation
    )
    // capture/compare mode register 1 (input mode)
    // Offset +0x18
    SBF_REGISTER_RW(ccmr1_input, uint32_t, 0x0,
        SBF_FIELD(ic2f, 15:12, unsigned) 		// Input capture 2 filter
        SBF_FIELD(ic2pcs, 11:10, unsigned) 		// Input capture 2 prescaler
        SBF_FIELD(cc2s, 9:8, unsigned) 		// Capture/Compare 2 selection
        SBF_FIELD(ic1f, 7:4, unsigned) 		// Input capture 1 filter
        SBF_FIELD(icpcs, 3:2, unsigned) 		// Input capture 1 prescaler
        SBF_FIELD(cc1s, 1:0, unsigned) 		// Capture/Compare 1 selection
    )
    // capture/compare mode register 2 (input mode)
    // Offset +0x1C
    SBF_REGISTER_RW(ccmr2_input, uint32_t, 0x0,
        SBF_FIELD(ic4f, 15:12, unsigned) 		// Input capture 4 filter
        SBF_FIELD(ic4psc, 11:10, unsigned) 		// Input capture 4 prescaler
        SBF_FIELD(cc4s, 9:8, unsigned) 		// Capture/Compare 4 selection
        SBF_FIELD(ic3f, 7:4, unsigned) 		// Input capture 3 filter
        SBF_FIELD(ic3psc, 3:2, unsigned) 		// Input capture 3 prescaler
        SBF_FIELD(cc3s, 1:0, unsigned) 		// Capture/compare 3 selection
    )
    // capture/compare enable register
    // Offset +0x20
    SBF_REGISTER_RW(ccer, uint32_t, 0x0,
        SBF_FIELD(cc4p, 13:13, bool) 		// Capture/Compare 3 output Polarity
        SBF_FIELD(cc4e, 12:12, bool) 		// Capture/Compare 4 output enable
        SBF_FIELD(cc3np, 11:11, bool) 		// Capture/Compare 3 output Polarity
        SBF_FIELD(cc3ne, 10:10, bool) 		// Capture/Compare 3 complementary output enable
        SBF_FIELD(cc3p, 9:9, bool) 		// Capture/Compare 3 output Polarity
        SBF_FIELD(cc3e, 8:8, bool) 		// Capture/Compare 3 output enable
        SBF_FIELD(cc2np, 7:7, bool) 		// Capture/Compare 2 output Polarity
        SBF_FIELD(cc2ne, 6:6, bool) 		// Capture/Compare 2 complementary output enable
        SBF_FIELD(cc2p, 5:5, bool) 		// Capture/Compare 2 output Polarity
        SBF_FIELD(cc2e, 4:4, bool) 		// Capture/Compare 2 output enable
        SBF_FIELD(cc1np, 3:3, bool) 		// Capture/Compare 1 output Polarity
        SBF_FIELD(cc1ne, 2:2, bool) 		// Capture/Compare 1 complementary output enable
        SBF_FIELD(cc1p, 1:1, bool) 		// Capture/Compare 1 output Polarity
        SBF_FIELD(cc1e, 0:0, bool) 		// Capture/Compare 1 output enable
    )
    // counter
    // Offset +0x24
    SBF_REGISTER_RW(cnt, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // prescaler
    // Offset +0x28
    SBF_REGISTER_RW(psc, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // auto-reload register
    // Offset +0x2C
    SBF_REGISTER_RW(arr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // repetition counter register
    // Offset +0x30
    SBF_REGISTER_RW(rcr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // capture/compare register 1
    // Offset +0x34
    SBF_REGISTER_RW(ccr1, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // capture/compare register 2
    // Offset +0x38
    SBF_REGISTER_RW(ccr2, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // capture/compare register 3
    // Offset +0x3C
    SBF_REGISTER_RW(ccr3, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // capture/compare register 4
    // Offset +0x40
    SBF_REGISTER_RW(ccr4, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // break and dead-time register
    // Offset +0x44
    SBF_REGISTER_RW(bdtr, uint32_t, 0x0,
        SBF_FIELD(moe, 15:15, bool) 		// Main output enable
        SBF_FIELD(aoe, 14:14, bool) 		// Automatic output enable
        SBF_FIELD(bkp, 13:13, bool) 		// Break polarity
        SBF_FIELD(bke, 12:12, bool) 		// Break enable
        SBF_FIELD(ossr, 11:11, bool) 		// Off-state selection for Run mode
        SBF_FIELD(ossi, 10:10, bool) 		// Off-state selection for Idle mode
        SBF_FIELD(lock, 9:8, unsigned) 		// Lock configuration
        SBF_FIELD(dtg, 7:0, unsigned) 		// Dead-time generator setup
    )
    // DMA control register
    // Offset +0x48
    SBF_REGISTER_RW(dcr, uint32_t, 0x0,
        SBF_FIELD(dbl, 12:8, unsigned) 		// DMA burst length
        SBF_FIELD(dba, 4:0, unsigned) 		// DMA base address
    )
    // DMA address for full transfer
    // Offset +0x4C
    SBF_REGISTER_RW(dmar, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // DMA address for full transfer
    // Offset +0x50
    SBF_REGISTER_RW(or1, uint32_t, 0x0,
        SBF_FIELD(ti1_rmp, 4:4, bool) 		// Input Capture 1 remap
        SBF_FIELD(etr_adc3_rmp, 3:2, unsigned) 		// External trigger remap on ADC3 analog watchdog
        SBF_FIELD(etr_adc2_rmp, 1:0, unsigned) 		// External trigger remap on ADC2 analog watchdog
    )
    // capture/compare mode register 2 (output mode)
    // Offset +0x54
    SBF_REGISTER_RW(ccmr3_output, uint32_t, 0x0,
        SBF_FIELD(oc6m_bit3, 24:24, bool) 		// Output Compare 6 mode bit 3
        SBF_FIELD(oc5m_bit3, 18:16, unsigned) 		// Output Compare 5 mode bit 3
        SBF_FIELD(oc6ce, 15:15, bool) 		// Output compare 6 clear enable
        SBF_FIELD(oc6m, 14:12, unsigned) 		// Output compare 6 mode
        SBF_FIELD(oc6pe, 11:11, bool) 		// Output compare 6 preload enable
        SBF_FIELD(oc6fe, 10:10, bool) 		// Output compare 6 fast enable
        SBF_FIELD(oc5ce, 7:7, bool) 		// Output compare 5 clear enable
        SBF_FIELD(oc5m, 6:4, unsigned) 		// Output compare 5 mode
        SBF_FIELD(oc5pe, 3:3, bool) 		// Output compare 5 preload enable
        SBF_FIELD(oc5fe, 2:2, bool) 		// Output compare 5 fast enable
    )
    // capture/compare register 4
    // Offset +0x58
    SBF_REGISTER_RW(ccr5, uint32_t, 0x0,
        SBF_FIELD(gc5c3, 31:31, bool) 		// Group Channel 5 and Channel 3
        SBF_FIELD(gc5c2, 30:30, bool) 		// Group Channel 5 and Channel 2
        SBF_FIELD(gc5c1, 29:29, bool) 		// Group Channel 5 and Channel 1
        SBF_FIELD(ccr5, 15:0, unsigned) 		// Capture/Compare value
    )
    // capture/compare register 4
    // Offset +0x5C
    SBF_REGISTER_RW(ccr6, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // DMA address for full transfer
    // Offset +0x60
    SBF_REGISTER_RW(or2, uint32_t, 0x1,
        SBF_FIELD(etrsel, 16:14, unsigned) 		// ETR source selection
        SBF_FIELD(bkcmp2p, 11:11, bool) 		// BRK COMP2 input polarity
        SBF_FIELD(bkcmp1p, 10:10, bool) 		// BRK COMP1 input polarity
        SBF_FIELD(bkinp, 9:9, bool) 		// BRK BKIN input polarity
        SBF_FIELD(bkdfbk2e, 8:8, bool) 		// BRK DFSDM_BREAK2 enable
        SBF_FIELD(bkcmp2e, 2:2, bool) 		// BRK COMP2 enable
        SBF_FIELD(bkcmp1e, 1:1, bool) 		// BRK COMP1 enable
        SBF_FIELD(bkine, 0:0, bool) 		// BRK BKIN input enable
    )
    // DMA address for full transfer
    // Offset +0x64
    SBF_REGISTER_RW(or3, uint32_t, 0x1,
        SBF_FIELD(bk2cmp2p, 11:11, bool) 		// BRK2 COMP2 input polarity
        SBF_FIELD(bk2cmp1p, 10:10, bool) 		// BRK2 COMP1 input polarity
        SBF_FIELD(bk2inp, 9:9, bool) 		// BRK2 BKIN input polarity
        SBF_FIELD(bk2dfbk3e, 8:8, bool) 		// BRK2 DFSDM_BREAK3 enable
        SBF_FIELD(bk2cmp2e, 2:2, bool) 		// BRK2 COMP2 enable
        SBF_FIELD(bk2cmp1e, 1:1, bool) 		// BRK2 COMP1 enable
        SBF_FIELD(bk2ine, 0:0, bool) 		// BRK2 BKIN input enable
    )

}; // Tim registers


// Tsc registers
struct Tsc {
    // control register
    // Offset +0x0
    SBF_REGISTER_RW(cr, uint32_t, 0x0,
        SBF_FIELD(ctph, 31:28, unsigned) 		// Charge transfer pulse high
        SBF_FIELD(ctpl, 27:24, unsigned) 		// Charge transfer pulse low
        SBF_FIELD(ssd, 23:17, unsigned) 		// Spread spectrum deviation
        SBF_FIELD(sse, 16:16, bool) 		// Spread spectrum enable
        SBF_FIELD(sspsc, 15:15, bool) 		// Spread spectrum prescaler
        SBF_FIELD(pgpsc, 14:12, unsigned) 		// pulse generator prescaler
        SBF_FIELD(mcv, 7:5, unsigned) 		// Max count value
        SBF_FIELD(iodef, 4:4, bool) 		// I/O Default mode
        SBF_FIELD(syncpol, 3:3, bool) 		// Synchronization pin polarity
        SBF_FIELD(am, 2:2, bool) 		// Acquisition mode
        SBF_FIELD(start, 1:1, bool) 		// Start a new acquisition
        SBF_FIELD(tsce, 0:0, bool) 		// Touch sensing controller enable
    )
    // interrupt enable register
    // Offset +0x4
    SBF_REGISTER_RW(ier, uint32_t, 0x0,
        SBF_FIELD(mceie, 1:1, bool) 		// Max count error interrupt enable
        SBF_FIELD(eoaie, 0:0, bool) 		// End of acquisition interrupt enable
    )
    // interrupt clear register
    // Offset +0x8
    SBF_REGISTER_RW(icr, uint32_t, 0x0,
        SBF_FIELD(mceic, 1:1, bool) 		// Max count error interrupt clear
        SBF_FIELD(eoaic, 0:0, bool) 		// End of acquisition interrupt clear
    )
    // interrupt status register
    // Offset +0xC
    SBF_REGISTER_RW(isr, uint32_t, 0x0,
        SBF_FIELD(mcef, 1:1, bool) 		// Max count error flag
        SBF_FIELD(eoaf, 0:0, bool) 		// End of acquisition flag
    )
    // I/O hysteresis control register
    // Offset +0x10
    SBF_REGISTER_RW(iohcr, uint32_t, 0xFFFFFFFF,
        SBF_FIELD(g8_io4, 31:31, bool) 		// G8_IO4
        SBF_FIELD(g8_io3, 30:30, bool) 		// G8_IO3
        SBF_FIELD(g8_io2, 29:29, bool) 		// G8_IO2
        SBF_FIELD(g8_io1, 28:28, bool) 		// G8_IO1
        SBF_FIELD(g7_io4, 27:27, bool) 		// G7_IO4
        SBF_FIELD(g7_io3, 26:26, bool) 		// G7_IO3
        SBF_FIELD(g7_io2, 25:25, bool) 		// G7_IO2
        SBF_FIELD(g7_io1, 24:24, bool) 		// G7_IO1
        SBF_FIELD(g6_io4, 23:23, bool) 		// G6_IO4
        SBF_FIELD(g6_io3, 22:22, bool) 		// G6_IO3
        SBF_FIELD(g6_io2, 21:21, bool) 		// G6_IO2
        SBF_FIELD(g6_io1, 20:20, bool) 		// G6_IO1
        SBF_FIELD(g5_io4, 19:19, bool) 		// G5_IO4
        SBF_FIELD(g5_io3, 18:18, bool) 		// G5_IO3
        SBF_FIELD(g5_io2, 17:17, bool) 		// G5_IO2
        SBF_FIELD(g5_io1, 16:16, bool) 		// G5_IO1
        SBF_FIELD(g4_io4, 15:15, bool) 		// G4_IO4
        SBF_FIELD(g4_io3, 14:14, bool) 		// G4_IO3
        SBF_FIELD(g4_io2, 13:13, bool) 		// G4_IO2
        SBF_FIELD(g4_io1, 12:12, bool) 		// G4_IO1
        SBF_FIELD(g3_io4, 11:11, bool) 		// G3_IO4
        SBF_FIELD(g3_io3, 10:10, bool) 		// G3_IO3
        SBF_FIELD(g3_io2, 9:9, bool) 		// G3_IO2
        SBF_FIELD(g3_io1, 8:8, bool) 		// G3_IO1
        SBF_FIELD(g2_io4, 7:7, bool) 		// G2_IO4
        SBF_FIELD(g2_io3, 6:6, bool) 		// G2_IO3
        SBF_FIELD(g2_io2, 5:5, bool) 		// G2_IO2
        SBF_FIELD(g2_io1, 4:4, bool) 		// G2_IO1
        SBF_FIELD(g1_io4, 3:3, bool) 		// G1_IO4
        SBF_FIELD(g1_io3, 2:2, bool) 		// G1_IO3
        SBF_FIELD(g1_io2, 1:1, bool) 		// G1_IO2
        SBF_FIELD(g1_io1, 0:0, bool) 		// G1_IO1
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x14, uint32_t, 1)
    // I/O analog switch control register
    // Offset +0x18
    SBF_REGISTER_RW(ioascr, uint32_t, 0x0,
        SBF_FIELD(g8_io4, 31:31, bool) 		// G8_IO4
        SBF_FIELD(g8_io3, 30:30, bool) 		// G8_IO3
        SBF_FIELD(g8_io2, 29:29, bool) 		// G8_IO2
        SBF_FIELD(g8_io1, 28:28, bool) 		// G8_IO1
        SBF_FIELD(g7_io4, 27:27, bool) 		// G7_IO4
        SBF_FIELD(g7_io3, 26:26, bool) 		// G7_IO3
        SBF_FIELD(g7_io2, 25:25, bool) 		// G7_IO2
        SBF_FIELD(g7_io1, 24:24, bool) 		// G7_IO1
        SBF_FIELD(g6_io4, 23:23, bool) 		// G6_IO4
        SBF_FIELD(g6_io3, 22:22, bool) 		// G6_IO3
        SBF_FIELD(g6_io2, 21:21, bool) 		// G6_IO2
        SBF_FIELD(g6_io1, 20:20, bool) 		// G6_IO1
        SBF_FIELD(g5_io4, 19:19, bool) 		// G5_IO4
        SBF_FIELD(g5_io3, 18:18, bool) 		// G5_IO3
        SBF_FIELD(g5_io2, 17:17, bool) 		// G5_IO2
        SBF_FIELD(g5_io1, 16:16, bool) 		// G5_IO1
        SBF_FIELD(g4_io4, 15:15, bool) 		// G4_IO4
        SBF_FIELD(g4_io3, 14:14, bool) 		// G4_IO3
        SBF_FIELD(g4_io2, 13:13, bool) 		// G4_IO2
        SBF_FIELD(g4_io1, 12:12, bool) 		// G4_IO1
        SBF_FIELD(g3_io4, 11:11, bool) 		// G3_IO4
        SBF_FIELD(g3_io3, 10:10, bool) 		// G3_IO3
        SBF_FIELD(g3_io2, 9:9, bool) 		// G3_IO2
        SBF_FIELD(g3_io1, 8:8, bool) 		// G3_IO1
        SBF_FIELD(g2_io4, 7:7, bool) 		// G2_IO4
        SBF_FIELD(g2_io3, 6:6, bool) 		// G2_IO3
        SBF_FIELD(g2_io2, 5:5, bool) 		// G2_IO2
        SBF_FIELD(g2_io1, 4:4, bool) 		// G2_IO1
        SBF_FIELD(g1_io4, 3:3, bool) 		// G1_IO4
        SBF_FIELD(g1_io3, 2:2, bool) 		// G1_IO3
        SBF_FIELD(g1_io2, 1:1, bool) 		// G1_IO2
        SBF_FIELD(g1_io1, 0:0, bool) 		// G1_IO1
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x1C, uint32_t, 1)
    // I/O sampling control register
    // Offset +0x20
    SBF_REGISTER_RW(ioscr, uint32_t, 0x0,
        SBF_FIELD(g8_io4, 31:31, bool) 		// G8_IO4
        SBF_FIELD(g8_io3, 30:30, bool) 		// G8_IO3
        SBF_FIELD(g8_io2, 29:29, bool) 		// G8_IO2
        SBF_FIELD(g8_io1, 28:28, bool) 		// G8_IO1
        SBF_FIELD(g7_io4, 27:27, bool) 		// G7_IO4
        SBF_FIELD(g7_io3, 26:26, bool) 		// G7_IO3
        SBF_FIELD(g7_io2, 25:25, bool) 		// G7_IO2
        SBF_FIELD(g7_io1, 24:24, bool) 		// G7_IO1
        SBF_FIELD(g6_io4, 23:23, bool) 		// G6_IO4
        SBF_FIELD(g6_io3, 22:22, bool) 		// G6_IO3
        SBF_FIELD(g6_io2, 21:21, bool) 		// G6_IO2
        SBF_FIELD(g6_io1, 20:20, bool) 		// G6_IO1
        SBF_FIELD(g5_io4, 19:19, bool) 		// G5_IO4
        SBF_FIELD(g5_io3, 18:18, bool) 		// G5_IO3
        SBF_FIELD(g5_io2, 17:17, bool) 		// G5_IO2
        SBF_FIELD(g5_io1, 16:16, bool) 		// G5_IO1
        SBF_FIELD(g4_io4, 15:15, bool) 		// G4_IO4
        SBF_FIELD(g4_io3, 14:14, bool) 		// G4_IO3
        SBF_FIELD(g4_io2, 13:13, bool) 		// G4_IO2
        SBF_FIELD(g4_io1, 12:12, bool) 		// G4_IO1
        SBF_FIELD(g3_io4, 11:11, bool) 		// G3_IO4
        SBF_FIELD(g3_io3, 10:10, bool) 		// G3_IO3
        SBF_FIELD(g3_io2, 9:9, bool) 		// G3_IO2
        SBF_FIELD(g3_io1, 8:8, bool) 		// G3_IO1
        SBF_FIELD(g2_io4, 7:7, bool) 		// G2_IO4
        SBF_FIELD(g2_io3, 6:6, bool) 		// G2_IO3
        SBF_FIELD(g2_io2, 5:5, bool) 		// G2_IO2
        SBF_FIELD(g2_io1, 4:4, bool) 		// G2_IO1
        SBF_FIELD(g1_io4, 3:3, bool) 		// G1_IO4
        SBF_FIELD(g1_io3, 2:2, bool) 		// G1_IO3
        SBF_FIELD(g1_io2, 1:1, bool) 		// G1_IO2
        SBF_FIELD(g1_io1, 0:0, bool) 		// G1_IO1
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x24, uint32_t, 1)
    // I/O channel control register
    // Offset +0x28
    SBF_REGISTER_RW(ioccr, uint32_t, 0x0,
        SBF_FIELD(g8_io4, 31:31, bool) 		// G8_IO4
        SBF_FIELD(g8_io3, 30:30, bool) 		// G8_IO3
        SBF_FIELD(g8_io2, 29:29, bool) 		// G8_IO2
        SBF_FIELD(g8_io1, 28:28, bool) 		// G8_IO1
        SBF_FIELD(g7_io4, 27:27, bool) 		// G7_IO4
        SBF_FIELD(g7_io3, 26:26, bool) 		// G7_IO3
        SBF_FIELD(g7_io2, 25:25, bool) 		// G7_IO2
        SBF_FIELD(g7_io1, 24:24, bool) 		// G7_IO1
        SBF_FIELD(g6_io4, 23:23, bool) 		// G6_IO4
        SBF_FIELD(g6_io3, 22:22, bool) 		// G6_IO3
        SBF_FIELD(g6_io2, 21:21, bool) 		// G6_IO2
        SBF_FIELD(g6_io1, 20:20, bool) 		// G6_IO1
        SBF_FIELD(g5_io4, 19:19, bool) 		// G5_IO4
        SBF_FIELD(g5_io3, 18:18, bool) 		// G5_IO3
        SBF_FIELD(g5_io2, 17:17, bool) 		// G5_IO2
        SBF_FIELD(g5_io1, 16:16, bool) 		// G5_IO1
        SBF_FIELD(g4_io4, 15:15, bool) 		// G4_IO4
        SBF_FIELD(g4_io3, 14:14, bool) 		// G4_IO3
        SBF_FIELD(g4_io2, 13:13, bool) 		// G4_IO2
        SBF_FIELD(g4_io1, 12:12, bool) 		// G4_IO1
        SBF_FIELD(g3_io4, 11:11, bool) 		// G3_IO4
        SBF_FIELD(g3_io3, 10:10, bool) 		// G3_IO3
        SBF_FIELD(g3_io2, 9:9, bool) 		// G3_IO2
        SBF_FIELD(g3_io1, 8:8, bool) 		// G3_IO1
        SBF_FIELD(g2_io4, 7:7, bool) 		// G2_IO4
        SBF_FIELD(g2_io3, 6:6, bool) 		// G2_IO3
        SBF_FIELD(g2_io2, 5:5, bool) 		// G2_IO2
        SBF_FIELD(g2_io1, 4:4, bool) 		// G2_IO1
        SBF_FIELD(g1_io4, 3:3, bool) 		// G1_IO4
        SBF_FIELD(g1_io3, 2:2, bool) 		// G1_IO3
        SBF_FIELD(g1_io2, 1:1, bool) 		// G1_IO2
        SBF_FIELD(g1_io1, 0:0, bool) 		// G1_IO1
    )
    //  Alignment padding
    SBF_REGISTER_RSVD(__padding_0x2C, uint32_t, 1)
    // I/O group control status register
    // Offset +0x30
    SBF_REGISTER_RW(iogcsr, uint32_t, 0x0,
        SBF_FIELD(g8s, 23:23, bool) 		// Analog I/O group x status
        SBF_FIELD(g7s, 22:22, bool) 		// Analog I/O group x status
        SBF_FIELD(g6s, 21:21, bool) 		// Analog I/O group x status
        SBF_FIELD(g5s, 20:20, bool) 		// Analog I/O group x status
        SBF_FIELD(g4s, 19:19, bool) 		// Analog I/O group x status
        SBF_FIELD(g3s, 18:18, bool) 		// Analog I/O group x status
        SBF_FIELD(g2s, 17:17, bool) 		// Analog I/O group x status
        SBF_FIELD(g1s, 16:16, bool) 		// Analog I/O group x status
        SBF_FIELD(g8e, 7:7, bool) 		// Analog I/O group x enable
        SBF_FIELD(g7e, 6:6, bool) 		// Analog I/O group x enable
        SBF_FIELD(g6e, 5:5, bool) 		// Analog I/O group x enable
        SBF_FIELD(g5e, 4:4, bool) 		// Analog I/O group x enable
        SBF_FIELD(g4e, 3:3, bool) 		// Analog I/O group x enable
        SBF_FIELD(g3e, 2:2, bool) 		// Analog I/O group x enable
        SBF_FIELD(g2e, 1:1, bool) 		// Analog I/O group x enable
        SBF_FIELD(g1e, 0:0, bool) 		// Analog I/O group x enable
    )
    // I/O group x counter register
    // Offset +0x34
    SBF_REGISTER_RO(iog1cr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // I/O group x counter register
    // Offset +0x38
    SBF_REGISTER_RO(iog2cr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // I/O group x counter register
    // Offset +0x3C
    SBF_REGISTER_RO(iog3cr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // I/O group x counter register
    // Offset +0x40
    SBF_REGISTER_RO(iog4cr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // I/O group x counter register
    // Offset +0x44
    SBF_REGISTER_RO(iog5cr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // I/O group x counter register
    // Offset +0x48
    SBF_REGISTER_RO(iog6cr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // I/O group x counter register
    // Offset +0x4C
    SBF_REGISTER_RO(iog7cr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // I/O group x counter register
    // Offset +0x50
    SBF_REGISTER_RO(iog8cr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Tsc registers


// Usart registers
struct Usart {
    // Control register 1
    // Offset +0x0
    SBF_REGISTER_RW(cr1, uint32_t, 0x0,
        SBF_FIELD(m1, 28:28, bool) 		// Word length
        SBF_FIELD(eobie, 27:27, bool) 		// End of Block interrupt enable
        SBF_FIELD(rtoie, 26:26, bool) 		// Receiver timeout interrupt enable
        SBF_FIELD(deat4, 25:25, bool) 		// Driver Enable assertion time
        SBF_FIELD(deat3, 24:24, bool) 		// DEAT3
        SBF_FIELD(deat2, 23:23, bool) 		// DEAT2
        SBF_FIELD(deat1, 22:22, bool) 		// DEAT1
        SBF_FIELD(deat0, 21:21, bool) 		// DEAT0
        SBF_FIELD(dedt4, 20:20, bool) 		// Driver Enable de-assertion time
        SBF_FIELD(dedt3, 19:19, bool) 		// DEDT3
        SBF_FIELD(dedt2, 18:18, bool) 		// DEDT2
        SBF_FIELD(dedt1, 17:17, bool) 		// DEDT1
        SBF_FIELD(dedt0, 16:16, bool) 		// DEDT0
        SBF_FIELD(over8, 15:15, bool) 		// Oversampling mode
        SBF_FIELD(cmie, 14:14, bool) 		// Character match interrupt enable
        SBF_FIELD(mme, 13:13, bool) 		// Mute mode enable
        SBF_FIELD(m0, 12:12, bool) 		// Word length
        SBF_FIELD(wake, 11:11, bool) 		// Receiver wakeup method
        SBF_FIELD(pce, 10:10, bool) 		// Parity control enable
        SBF_FIELD(ps, 9:9, bool) 		// Parity selection
        SBF_FIELD(peie, 8:8, bool) 		// PE interrupt enable
        SBF_FIELD(txeie, 7:7, bool) 		// interrupt enable
        SBF_FIELD(tcie, 6:6, bool) 		// Transmission complete interrupt enable
        SBF_FIELD(rxneie, 5:5, bool) 		// RXNE interrupt enable
        SBF_FIELD(idleie, 4:4, bool) 		// IDLE interrupt enable
        SBF_FIELD(te, 3:3, bool) 		// Transmitter enable
        SBF_FIELD(re, 2:2, bool) 		// Receiver enable
        SBF_FIELD(uesm, 1:1, bool) 		// USART enable in Stop mode
        SBF_FIELD(ue, 0:0, bool) 		// USART enable
    )
    // Control register 2
    // Offset +0x4
    SBF_REGISTER_RW(cr2, uint32_t, 0x0,
        SBF_FIELD(add4_7, 31:28, unsigned) 		// Address of the USART node
        SBF_FIELD(add0_3, 27:24, unsigned) 		// Address of the USART node
        SBF_FIELD(rtoen, 23:23, bool) 		// Receiver timeout enable
        SBF_FIELD(abrmod1, 22:22, bool) 		// Auto baud rate mode
        SBF_FIELD(abrmod0, 21:21, bool) 		// ABRMOD0
        SBF_FIELD(abren, 20:20, bool) 		// Auto baud rate enable
        SBF_FIELD(msbfirst, 19:19, bool) 		// Most significant bit first
        SBF_FIELD(tainv, 18:18, bool) 		// Binary data inversion
        SBF_FIELD(txinv, 17:17, bool) 		// TX pin active level inversion
        SBF_FIELD(rxinv, 16:16, bool) 		// RX pin active level inversion
        SBF_FIELD(swap, 15:15, bool) 		// Swap TX/RX pins
        SBF_FIELD(linen, 14:14, bool) 		// LIN mode enable
        SBF_FIELD(stop, 13:12, unsigned) 		// STOP bits
        SBF_FIELD(clken, 11:11, bool) 		// Clock enable
        SBF_FIELD(cpol, 10:10, bool) 		// Clock polarity
        SBF_FIELD(cpha, 9:9, bool) 		// Clock phase
        SBF_FIELD(lbcl, 8:8, bool) 		// Last bit clock pulse
        SBF_FIELD(lbdie, 6:6, bool) 		// LIN break detection interrupt enable
        SBF_FIELD(lbdl, 5:5, bool) 		// LIN break detection length
        SBF_FIELD(addm7, 4:4, bool) 		// 7-bit Address Detection/4-bit Address Detection
    )
    // Control register 3
    // Offset +0x8
    SBF_REGISTER_RW(cr3, uint32_t, 0x0,
        SBF_FIELD(wufie, 22:22, bool) 		// Wakeup from Stop mode interrupt enable
        SBF_FIELD(wus, 21:20, unsigned) 		// Wakeup from Stop mode interrupt flag selection
        SBF_FIELD(scarcnt, 19:17, unsigned) 		// Smartcard auto-retry count
        SBF_FIELD(dep, 15:15, bool) 		// Driver enable polarity selection
        SBF_FIELD(dem, 14:14, bool) 		// Driver enable mode
        SBF_FIELD(ddre, 13:13, bool) 		// DMA Disable on Reception Error
        SBF_FIELD(ovrdis, 12:12, bool) 		// Overrun Disable
        SBF_FIELD(onebit, 11:11, bool) 		// One sample bit method enable
        SBF_FIELD(ctsie, 10:10, bool) 		// CTS interrupt enable
        SBF_FIELD(ctse, 9:9, bool) 		// CTS enable
        SBF_FIELD(rtse, 8:8, bool) 		// RTS enable
        SBF_FIELD(dmat, 7:7, bool) 		// DMA enable transmitter
        SBF_FIELD(dmar, 6:6, bool) 		// DMA enable receiver
        SBF_FIELD(scen, 5:5, bool) 		// Smartcard mode enable
        SBF_FIELD(nack, 4:4, bool) 		// Smartcard NACK enable
        SBF_FIELD(hdsel, 3:3, bool) 		// Half-duplex selection
        SBF_FIELD(irlp, 2:2, bool) 		// Ir low-power
        SBF_FIELD(iren, 1:1, bool) 		// Ir mode enable
        SBF_FIELD(eie, 0:0, bool) 		// Error interrupt enable
    )
    // Baud rate register
    // Offset +0xC
    SBF_REGISTER_RW(brr, uint32_t, 0x0,
        SBF_FIELD(div_mantissa, 15:4, unsigned) 		// DIV_Mantissa
        SBF_FIELD(div_fraction, 3:0, unsigned) 		// DIV_Fraction
    )
    // Guard time and prescaler register
    // Offset +0x10
    SBF_REGISTER_RW(gtpr, uint32_t, 0x0,
        SBF_FIELD(gt, 15:8, unsigned) 		// Guard time value
        SBF_FIELD(psc, 7:0, unsigned) 		// Prescaler value
    )
    // Receiver timeout register
    // Offset +0x14
    SBF_REGISTER_RW(rtor, uint32_t, 0x0,
        SBF_FIELD(blen, 31:24, unsigned) 		// Block Length
        SBF_FIELD(rto, 23:0, unsigned) 		// Receiver timeout value
    )
    // Request register
    // Offset +0x18
    SBF_REGISTER_WO(rqr, uint32_t, 0x0,
        SBF_FIELD(txfrq, 4:4, bool) 		// Transmit data flush request
        SBF_FIELD(rxfrq, 3:3, bool) 		// Receive data flush request
        SBF_FIELD(mmrq, 2:2, bool) 		// Mute mode request
        SBF_FIELD(sbkrq, 1:1, bool) 		// Send break request
        SBF_FIELD(abrrq, 0:0, bool) 		// Auto baud rate request
    )
    // Interrupt & status register
    // Offset +0x1C
    SBF_REGISTER_RO(isr, uint32_t, 0xC0,
        SBF_FIELD(reack, 22:22, bool) 		// REACK
        SBF_FIELD(teack, 21:21, bool) 		// TEACK
        SBF_FIELD(wuf, 20:20, bool) 		// WUF
        SBF_FIELD(rwu, 19:19, bool) 		// RWU
        SBF_FIELD(sbkf, 18:18, bool) 		// SBKF
        SBF_FIELD(cmf, 17:17, bool) 		// CMF
        SBF_FIELD(busy, 16:16, bool) 		// BUSY
        SBF_FIELD(abrf, 15:15, bool) 		// ABRF
        SBF_FIELD(abre, 14:14, bool) 		// ABRE
        SBF_FIELD(eobf, 12:12, bool) 		// EOBF
        SBF_FIELD(rtof, 11:11, bool) 		// RTOF
        SBF_FIELD(cts, 10:10, bool) 		// CTS
        SBF_FIELD(ctsif, 9:9, bool) 		// CTSIF
        SBF_FIELD(lbdf, 8:8, bool) 		// LBDF
        SBF_FIELD(txe, 7:7, bool) 		// TXE
        SBF_FIELD(tc, 6:6, bool) 		// TC
        SBF_FIELD(rxne, 5:5, bool) 		// RXNE
        SBF_FIELD(idle, 4:4, bool) 		// IDLE
        SBF_FIELD(ore, 3:3, bool) 		// ORE
        SBF_FIELD(nf, 2:2, bool) 		// NF
        SBF_FIELD(fe, 1:1, bool) 		// FE
        SBF_FIELD(pe, 0:0, bool) 		// PE
    )
    // Interrupt flag clear register
    // Offset +0x20
    SBF_REGISTER_WO(icr, uint32_t, 0x0,
        SBF_FIELD(wucf, 20:20, bool) 		// Wakeup from Stop mode clear flag
        SBF_FIELD(cmcf, 17:17, bool) 		// Character match clear flag
        SBF_FIELD(eobcf, 12:12, bool) 		// End of block clear flag
        SBF_FIELD(rtocf, 11:11, bool) 		// Receiver timeout clear flag
        SBF_FIELD(ctscf, 9:9, bool) 		// CTS clear flag
        SBF_FIELD(lbdcf, 8:8, bool) 		// LIN break detection clear flag
        SBF_FIELD(tccf, 6:6, bool) 		// Transmission complete clear flag
        SBF_FIELD(idlecf, 4:4, bool) 		// Idle line detected clear flag
        SBF_FIELD(orecf, 3:3, bool) 		// Overrun error clear flag
        SBF_FIELD(ncf, 2:2, bool) 		// Noise detected clear flag
        SBF_FIELD(fecf, 1:1, bool) 		// Framing error clear flag
        SBF_FIELD(pecf, 0:0, bool) 		// Parity error clear flag
    )
    // Receive data register
    // Offset +0x24
    SBF_REGISTER_RO(rdr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )
    // Transmit data register
    // Offset +0x28
    SBF_REGISTER_RW(tdr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Usart registers


// Vref registers
struct Vref {
    // VREF control and status register
    // Offset +0x0
    SBF_REGISTER_RW(csr, uint32_t, 0x2,
        SBF_FIELD(vrr, 3:3, bool) 		// Voltage reference buffer ready
        SBF_FIELD(vrs, 2:2, bool) 		// Voltage reference scale
        SBF_FIELD(hiz, 1:1, bool) 		// High impedance mode
        SBF_FIELD(envr, 0:0, bool) 		// Voltage reference buffer enable
    )
    // calibration control register
    // Offset +0x4
    SBF_REGISTER_RW(ccr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Vref registers


// Wwdg registers
struct Wwdg {
    // Control register
    // Offset +0x0
    SBF_REGISTER_RW(cr, uint32_t, 0x7F,
        SBF_FIELD(wdga, 7:7, bool) 		// Activation bit
        SBF_FIELD(t, 6:0, unsigned) 		// 7-bit counter (MSB to LSB)
    )
    // Configuration register
    // Offset +0x4
    SBF_REGISTER_RW(cfr, uint32_t, 0x7F,
        SBF_FIELD(ewi, 9:9, bool) 		// Early wakeup interrupt
        SBF_FIELD(wdgtb, 8:7, unsigned) 		// Timer base
        SBF_FIELD(w, 6:0, unsigned) 		// 7-bit window value
    )
    // Status register
    // Offset +0x8
    SBF_REGISTER_RW(sr, uint32_t, 0x0,
        SBF_NO_FIELDS
    )

}; // Wwdg registers


// Analog-to-Digital Converter
constexpr uintptr_t kBaseAddress_adc1 = 0x50040000;
Adc * const adc1 = reinterpret_cast<Adc * const>(kBaseAddress_adc1); 

// Analog-to-Digital Converter
constexpr uintptr_t kBaseAddress_adc123_common = 0x50040300;
Adc * const adc123_common = reinterpret_cast<Adc * const>(kBaseAddress_adc123_common); 

// Analog-to-Digital Converter
constexpr uintptr_t kBaseAddress_adc2 = 0x50040100;
Adc * const adc2 = reinterpret_cast<Adc * const>(kBaseAddress_adc2); 

// Analog-to-Digital Converter
constexpr uintptr_t kBaseAddress_adc3 = 0x50040200;
Adc * const adc3 = reinterpret_cast<Adc * const>(kBaseAddress_adc3); 

// Advanced encryption standard hardware accelerator
constexpr uintptr_t kBaseAddress_aes = 0x50060000;
Aes * const aes = reinterpret_cast<Aes * const>(kBaseAddress_aes); 

// Controller area network
constexpr uintptr_t kBaseAddress_can = 0x40006400;
Can * const can = reinterpret_cast<Can * const>(kBaseAddress_can); 

// Comparator
constexpr uintptr_t kBaseAddress_comp = 0x40010200;
Comp * const comp = reinterpret_cast<Comp * const>(kBaseAddress_comp); 

// Cyclic redundancy check calculation unit
constexpr uintptr_t kBaseAddress_crc = 0x40023000;
Crc * const crc = reinterpret_cast<Crc * const>(kBaseAddress_crc); 

// Digital-to-analog converter
constexpr uintptr_t kBaseAddress_dac = 0x40007400;
Dac * const dac = reinterpret_cast<Dac * const>(kBaseAddress_dac); 

// Debug support
constexpr uintptr_t kBaseAddress_dbgmcu = 0xE0042000;
Dbgmcu * const dbgmcu = reinterpret_cast<Dbgmcu * const>(kBaseAddress_dbgmcu); 

// Digital filter for sigma delta modulators
constexpr uintptr_t kBaseAddress_dfsdm = 0x40016000;
Dfsdm * const dfsdm = reinterpret_cast<Dfsdm * const>(kBaseAddress_dfsdm); 

// Direct memory access controller
constexpr uintptr_t kBaseAddress_dma1 = 0x40020000;
Dma * const dma1 = reinterpret_cast<Dma * const>(kBaseAddress_dma1); 

// Direct memory access controller
constexpr uintptr_t kBaseAddress_dma2 = 0x40020400;
Dma * const dma2 = reinterpret_cast<Dma * const>(kBaseAddress_dma2); 

// External interrupt/event controller
constexpr uintptr_t kBaseAddress_exti = 0x40010400;
Exti * const exti = reinterpret_cast<Exti * const>(kBaseAddress_exti); 

// Flexible memory controller
constexpr uintptr_t kBaseAddress_fmc = 0x60000000;
Fsmc * const fmc = reinterpret_cast<Fsmc * const>(kBaseAddress_fmc); 

// Firewall
constexpr uintptr_t kBaseAddress_firewall = 0x40011C00;
Firewall * const firewall = reinterpret_cast<Firewall * const>(kBaseAddress_firewall); 

// Flash
constexpr uintptr_t kBaseAddress_flash = 0x40022000;
Flash * const flash = reinterpret_cast<Flash * const>(kBaseAddress_flash); 

// General-purpose I/Os
constexpr uintptr_t kBaseAddress_gpioa = 0x48000000;
Gpio * const gpioa = reinterpret_cast<Gpio * const>(kBaseAddress_gpioa); 

// General-purpose I/Os
constexpr uintptr_t kBaseAddress_gpiob = 0x48000400;
Gpio * const gpiob = reinterpret_cast<Gpio * const>(kBaseAddress_gpiob); 

// General-purpose I/Os
constexpr uintptr_t kBaseAddress_gpioc = 0x48000800;
Gpio * const gpioc = reinterpret_cast<Gpio * const>(kBaseAddress_gpioc); 

// General-purpose I/Os
constexpr uintptr_t kBaseAddress_gpiod = 0x48000C00;
Gpio * const gpiod = reinterpret_cast<Gpio * const>(kBaseAddress_gpiod); 

// General-purpose I/Os
constexpr uintptr_t kBaseAddress_gpioe = 0x48001000;
Gpio * const gpioe = reinterpret_cast<Gpio * const>(kBaseAddress_gpioe); 

// General-purpose I/Os
constexpr uintptr_t kBaseAddress_gpiof = 0x48001400;
Gpio * const gpiof = reinterpret_cast<Gpio * const>(kBaseAddress_gpiof); 

// General-purpose I/Os
constexpr uintptr_t kBaseAddress_gpiog = 0x48001800;
Gpio * const gpiog = reinterpret_cast<Gpio * const>(kBaseAddress_gpiog); 

// General-purpose I/Os
constexpr uintptr_t kBaseAddress_gpioh = 0x48001C00;
Gpio * const gpioh = reinterpret_cast<Gpio * const>(kBaseAddress_gpioh); 

// Inter-integrated circuit
constexpr uintptr_t kBaseAddress_i2c1 = 0x40005400;
I2c * const i2c1 = reinterpret_cast<I2c * const>(kBaseAddress_i2c1); 

// Inter-integrated circuit
constexpr uintptr_t kBaseAddress_i2c2 = 0x40005800;
I2c * const i2c2 = reinterpret_cast<I2c * const>(kBaseAddress_i2c2); 

// Inter-integrated circuit
constexpr uintptr_t kBaseAddress_i2c3 = 0x40005C00;
I2c * const i2c3 = reinterpret_cast<I2c * const>(kBaseAddress_i2c3); 

// Independent watchdog
constexpr uintptr_t kBaseAddress_iwdg = 0x40003000;
Iwdg * const iwdg = reinterpret_cast<Iwdg * const>(kBaseAddress_iwdg); 

// Liquid crystal display controller
constexpr uintptr_t kBaseAddress_lcd = 0x40002400;
Lcd * const lcd = reinterpret_cast<Lcd * const>(kBaseAddress_lcd); 

// Low power timer
constexpr uintptr_t kBaseAddress_lptim1 = 0x40007C00;
Lptim * const lptim1 = reinterpret_cast<Lptim * const>(kBaseAddress_lptim1); 

// Low power timer
constexpr uintptr_t kBaseAddress_lptim2 = 0x40009400;
Lptim * const lptim2 = reinterpret_cast<Lptim * const>(kBaseAddress_lptim2); 

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kBaseAddress_lpuart1 = 0x40008000;
Usart * const lpuart1 = reinterpret_cast<Usart * const>(kBaseAddress_lpuart1); 

// Nested Vectored Interrupt Controller
constexpr uintptr_t kBaseAddress_nvic = 0xE000E000;
Nvic * const nvic = reinterpret_cast<Nvic * const>(kBaseAddress_nvic); 

// Operational amplifiers
constexpr uintptr_t kBaseAddress_opamp = 0x40007800;
Opamp * const opamp = reinterpret_cast<Opamp * const>(kBaseAddress_opamp); 

// USB on the go full speed
constexpr uintptr_t kBaseAddress_otg_fs_device = 0x50000800;
Usb_otg_fs * const otg_fs_device = reinterpret_cast<Usb_otg_fs * const>(kBaseAddress_otg_fs_device); 

// USB on the go full speed
constexpr uintptr_t kBaseAddress_otg_fs_global = 0x50000000;
Usb_otg_fs * const otg_fs_global = reinterpret_cast<Usb_otg_fs * const>(kBaseAddress_otg_fs_global); 

// USB on the go full speed
constexpr uintptr_t kBaseAddress_otg_fs_host = 0x50000400;
Usb_otg_fs * const otg_fs_host = reinterpret_cast<Usb_otg_fs * const>(kBaseAddress_otg_fs_host); 

// USB on the go full speed
constexpr uintptr_t kBaseAddress_otg_fs_pwrclk = 0x50000E00;
Usb_otg_fs * const otg_fs_pwrclk = reinterpret_cast<Usb_otg_fs * const>(kBaseAddress_otg_fs_pwrclk); 

// Power control
constexpr uintptr_t kBaseAddress_pwr = 0x40007000;
Pwr * const pwr = reinterpret_cast<Pwr * const>(kBaseAddress_pwr); 

// QuadSPI interface
constexpr uintptr_t kBaseAddress_quadspi = 0xA0001000;
Quadspi * const quadspi = reinterpret_cast<Quadspi * const>(kBaseAddress_quadspi); 

// Reset and clock control
constexpr uintptr_t kBaseAddress_rcc = 0x40021000;
Rcc * const rcc = reinterpret_cast<Rcc * const>(kBaseAddress_rcc); 

// Random number generator
constexpr uintptr_t kBaseAddress_rng = 0x50060800;
Rng * const rng = reinterpret_cast<Rng * const>(kBaseAddress_rng); 

// Real-time clock
constexpr uintptr_t kBaseAddress_rtc = 0x40002800;
Rtc * const rtc = reinterpret_cast<Rtc * const>(kBaseAddress_rtc); 

// Serial audio interface
constexpr uintptr_t kBaseAddress_sai1 = 0x40015400;
Sai * const sai1 = reinterpret_cast<Sai * const>(kBaseAddress_sai1); 

// Serial audio interface
constexpr uintptr_t kBaseAddress_sai2 = 0x40015800;
Sai * const sai2 = reinterpret_cast<Sai * const>(kBaseAddress_sai2); 

// Secure digital input/output interface
constexpr uintptr_t kBaseAddress_sdmmc = 0x40012800;
Sdio * const sdmmc = reinterpret_cast<Sdio * const>(kBaseAddress_sdmmc); 

// Serial peripheral interface/Inter-IC sound
constexpr uintptr_t kBaseAddress_spi1 = 0x40013000;
Spi * const spi1 = reinterpret_cast<Spi * const>(kBaseAddress_spi1); 

// Serial peripheral interface/Inter-IC sound
constexpr uintptr_t kBaseAddress_spi2 = 0x40003800;
Spi * const spi2 = reinterpret_cast<Spi * const>(kBaseAddress_spi2); 

// Serial peripheral interface/Inter-IC sound
constexpr uintptr_t kBaseAddress_spi3 = 0x40003C00;
Spi * const spi3 = reinterpret_cast<Spi * const>(kBaseAddress_spi3); 

// Single Wire Protocol Master Interface
constexpr uintptr_t kBaseAddress_swpmi1 = 0x40008800;
Swpmi * const swpmi1 = reinterpret_cast<Swpmi * const>(kBaseAddress_swpmi1); 

// System configuration controller
constexpr uintptr_t kBaseAddress_syscfg = 0x40010000;
Syscfg * const syscfg = reinterpret_cast<Syscfg * const>(kBaseAddress_syscfg); 

// Advanced-timers
constexpr uintptr_t kBaseAddress_tim1 = 0x40012C00;
Tim * const tim1 = reinterpret_cast<Tim * const>(kBaseAddress_tim1); 

// General purpose timers
constexpr uintptr_t kBaseAddress_tim15 = 0x40014000;
Tim * const tim15 = reinterpret_cast<Tim * const>(kBaseAddress_tim15); 

// General purpose timers
constexpr uintptr_t kBaseAddress_tim16 = 0x40014400;
Tim * const tim16 = reinterpret_cast<Tim * const>(kBaseAddress_tim16); 

// General purpose timers
constexpr uintptr_t kBaseAddress_tim17 = 0x40014800;
Tim * const tim17 = reinterpret_cast<Tim * const>(kBaseAddress_tim17); 

// General-purpose-timers
constexpr uintptr_t kBaseAddress_tim2 = 0x40000000;
Tim * const tim2 = reinterpret_cast<Tim * const>(kBaseAddress_tim2); 

// General-purpose-timers
constexpr uintptr_t kBaseAddress_tim3 = 0x40000400;
Tim * const tim3 = reinterpret_cast<Tim * const>(kBaseAddress_tim3); 

// General-purpose-timers
constexpr uintptr_t kBaseAddress_tim4 = 0x40000800;
Tim * const tim4 = reinterpret_cast<Tim * const>(kBaseAddress_tim4); 

// General-purpose-timers
constexpr uintptr_t kBaseAddress_tim5 = 0x40000C00;
Tim * const tim5 = reinterpret_cast<Tim * const>(kBaseAddress_tim5); 

// Basic-timers
constexpr uintptr_t kBaseAddress_tim6 = 0x40001000;
Tim * const tim6 = reinterpret_cast<Tim * const>(kBaseAddress_tim6); 

// Basic-timers
constexpr uintptr_t kBaseAddress_tim7 = 0x40001400;
Tim * const tim7 = reinterpret_cast<Tim * const>(kBaseAddress_tim7); 

// Advanced-timers
constexpr uintptr_t kBaseAddress_tim8 = 0x40013400;
Tim * const tim8 = reinterpret_cast<Tim * const>(kBaseAddress_tim8); 

// Touch sensing controller
constexpr uintptr_t kBaseAddress_tsc = 0x40024000;
Tsc * const tsc = reinterpret_cast<Tsc * const>(kBaseAddress_tsc); 

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kBaseAddress_uart4 = 0x40004C00;
Usart * const uart4 = reinterpret_cast<Usart * const>(kBaseAddress_uart4); 

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kBaseAddress_uart5 = 0x40005000;
Usart * const uart5 = reinterpret_cast<Usart * const>(kBaseAddress_uart5); 

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kBaseAddress_usart1 = 0x40013800;
Usart * const usart1 = reinterpret_cast<Usart * const>(kBaseAddress_usart1); 

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kBaseAddress_usart2 = 0x40004400;
Usart * const usart2 = reinterpret_cast<Usart * const>(kBaseAddress_usart2); 

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kBaseAddress_usart3 = 0x40004800;
Usart * const usart3 = reinterpret_cast<Usart * const>(kBaseAddress_usart3); 

// Voltage reference buffer
constexpr uintptr_t kBaseAddress_vref = 0x40010030;
Vref * const vref = reinterpret_cast<Vref * const>(kBaseAddress_vref); 

// System window watchdog
constexpr uintptr_t kBaseAddress_wwdg = 0x40002C00;
Wwdg * const wwdg = reinterpret_cast<Wwdg * const>(kBaseAddress_wwdg); 


} // namespace Stm32l4x6


#endif // _STM32L4x6_H_
