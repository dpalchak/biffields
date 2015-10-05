

#ifndef _STM32F091x_H_
#define _STM32F091x_H_

#include "types.h"
#include "bitfield.h"
#include "enumfield.h"
#include "boolfield.h"


namespace Stm32f091x {

using regulator::BitField;
using regulator::BoolField;
using regulator::EnumField;


// Crs registers
struct Crs {
    ////////////////////////////////////////////////////////////////////////////
    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x00002000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 13, 8> trim;
        BoolField<32, 7> swsync;  // Generate software SYNC event
        BoolField<32, 6> autotrimen;  // Automatic trimming enable
        BoolField<32, 5> cen;  // Frequency error counter enable
        BoolField<32, 3> esyncie;  // Expected SYNC interrupt enable
        BoolField<32, 2> errie;  // Synchronization or trimming error interrupt enable
        BoolField<32, 1> syncwarnie;  // SYNC warning interrupt enable
        BoolField<32, 0> syncokie;  // SYNC event OK interrupt enable
    };

    union Cfgr {
    public:
        constexpr static uint32_t kResetValue = 0x2022BB7F;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cfgr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 31> syncpol;  // SYNC polarity selection
        BitField<32, 29, 28> syncsrc;
        BitField<32, 26, 24> syncdiv;
        BitField<32, 23, 16> felim;
        BitField<32, 15, 0> reload;
    };

    union Isr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Isr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 16> fecap;
        BoolField<32, 15> fedir;  // Frequency error direction
        BoolField<32, 10> trimovf;  // Trimming overflow or underflow
        BoolField<32, 9> syncmiss;  // SYNC missed
        BoolField<32, 8> syncerr;  // SYNC error
        BoolField<32, 3> esyncf;  // Expected SYNC flag
        BoolField<32, 2> errf;  // Error flag
        BoolField<32, 1> syncwarnf;  // SYNC warning flag
        BoolField<32, 0> syncokf;  // SYNC event OK flag
    };

    union Icr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Icr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 3> esyncc;  // Expected SYNC clear flag
        BoolField<32, 2> errc;  // Error clear flag
        BoolField<32, 1> syncwarnc;  // SYNC warning clear flag
        BoolField<32, 0> syncokc;  // SYNC event OK clear flag
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cr cr; // [+0x0] control register
    Cfgr cfgr; // [+0x4] configuration register
    Isr isr; // [+0x8] interrupt and status register
    Icr icr; // [+0xC] interrupt flag clear register

}; // Crs registers


// Usb registers
struct Usb {
    ////////////////////////////////////////////////////////////////////////////
    union Ep0r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ep0r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 3, 0> ea;
        BitField<32, 5, 4> stat_tx;
        BoolField<32, 6> dtog_tx;  // Data Toggle, for transmission transfers
        BoolField<32, 7> ctr_tx;  // Correct Transfer for transmission
        BoolField<32, 8> ep_kind;  // Endpoint kind
        BitField<32, 10, 9> ep_type;
        BoolField<32, 11> setup;  // Setup transaction completed
        BitField<32, 13, 12> stat_rx;
        BoolField<32, 14> dtog_rx;  // Data Toggle, for reception transfers
        BoolField<32, 15> ctr_rx;  // Correct transfer for reception
    };

    union Ep1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ep1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 3, 0> ea;
        BitField<32, 5, 4> stat_tx;
        BoolField<32, 6> dtog_tx;  // Data Toggle, for transmission transfers
        BoolField<32, 7> ctr_tx;  // Correct Transfer for transmission
        BoolField<32, 8> ep_kind;  // Endpoint kind
        BitField<32, 10, 9> ep_type;
        BoolField<32, 11> setup;  // Setup transaction completed
        BitField<32, 13, 12> stat_rx;
        BoolField<32, 14> dtog_rx;  // Data Toggle, for reception transfers
        BoolField<32, 15> ctr_rx;  // Correct transfer for reception
    };

    union Ep2r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ep2r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 3, 0> ea;
        BitField<32, 5, 4> stat_tx;
        BoolField<32, 6> dtog_tx;  // Data Toggle, for transmission transfers
        BoolField<32, 7> ctr_tx;  // Correct Transfer for transmission
        BoolField<32, 8> ep_kind;  // Endpoint kind
        BitField<32, 10, 9> ep_type;
        BoolField<32, 11> setup;  // Setup transaction completed
        BitField<32, 13, 12> stat_rx;
        BoolField<32, 14> dtog_rx;  // Data Toggle, for reception transfers
        BoolField<32, 15> ctr_rx;  // Correct transfer for reception
    };

    union Ep3r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ep3r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 3, 0> ea;
        BitField<32, 5, 4> stat_tx;
        BoolField<32, 6> dtog_tx;  // Data Toggle, for transmission transfers
        BoolField<32, 7> ctr_tx;  // Correct Transfer for transmission
        BoolField<32, 8> ep_kind;  // Endpoint kind
        BitField<32, 10, 9> ep_type;
        BoolField<32, 11> setup;  // Setup transaction completed
        BitField<32, 13, 12> stat_rx;
        BoolField<32, 14> dtog_rx;  // Data Toggle, for reception transfers
        BoolField<32, 15> ctr_rx;  // Correct transfer for reception
    };

    union Ep4r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ep4r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 3, 0> ea;
        BitField<32, 5, 4> stat_tx;
        BoolField<32, 6> dtog_tx;  // Data Toggle, for transmission transfers
        BoolField<32, 7> ctr_tx;  // Correct Transfer for transmission
        BoolField<32, 8> ep_kind;  // Endpoint kind
        BitField<32, 10, 9> ep_type;
        BoolField<32, 11> setup;  // Setup transaction completed
        BitField<32, 13, 12> stat_rx;
        BoolField<32, 14> dtog_rx;  // Data Toggle, for reception transfers
        BoolField<32, 15> ctr_rx;  // Correct transfer for reception
    };

    union Ep5r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ep5r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 3, 0> ea;
        BitField<32, 5, 4> stat_tx;
        BoolField<32, 6> dtog_tx;  // Data Toggle, for transmission transfers
        BoolField<32, 7> ctr_tx;  // Correct Transfer for transmission
        BoolField<32, 8> ep_kind;  // Endpoint kind
        BitField<32, 10, 9> ep_type;
        BoolField<32, 11> setup;  // Setup transaction completed
        BitField<32, 13, 12> stat_rx;
        BoolField<32, 14> dtog_rx;  // Data Toggle, for reception transfers
        BoolField<32, 15> ctr_rx;  // Correct transfer for reception
    };

    union Ep6r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ep6r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 3, 0> ea;
        BitField<32, 5, 4> stat_tx;
        BoolField<32, 6> dtog_tx;  // Data Toggle, for transmission transfers
        BoolField<32, 7> ctr_tx;  // Correct Transfer for transmission
        BoolField<32, 8> ep_kind;  // Endpoint kind
        BitField<32, 10, 9> ep_type;
        BoolField<32, 11> setup;  // Setup transaction completed
        BitField<32, 13, 12> stat_rx;
        BoolField<32, 14> dtog_rx;  // Data Toggle, for reception transfers
        BoolField<32, 15> ctr_rx;  // Correct transfer for reception
    };

    union Ep7r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ep7r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 3, 0> ea;
        BitField<32, 5, 4> stat_tx;
        BoolField<32, 6> dtog_tx;  // Data Toggle, for transmission transfers
        BoolField<32, 7> ctr_tx;  // Correct Transfer for transmission
        BoolField<32, 8> ep_kind;  // Endpoint kind
        BitField<32, 10, 9> ep_type;
        BoolField<32, 11> setup;  // Setup transaction completed
        BitField<32, 13, 12> stat_rx;
        BoolField<32, 14> dtog_rx;  // Data Toggle, for reception transfers
        BoolField<32, 15> ctr_rx;  // Correct transfer for reception
    };

    union Cntr {
    public:
        constexpr static uint32_t kResetValue = 0x00000003;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cntr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fres;  // Force USB Reset
        BoolField<32, 1> pdwn;  // Power down
        BoolField<32, 2> lpmode;  // Low-power mode
        BoolField<32, 3> fsusp;  // Force suspend
        BoolField<32, 4> resume;  // Resume request
        BoolField<32, 5> l1resume;  // LPM L1 Resume request
        BoolField<32, 7> l1reqm;  // LPM L1 state request interrupt mask
        BoolField<32, 8> esofm;  // Expected start of frame interrupt mask
        BoolField<32, 9> sofm;  // Start of frame interrupt mask
        BoolField<32, 10> resetm;  // USB reset interrupt mask
        BoolField<32, 11> suspm;  // Suspend mode interrupt mask
        BoolField<32, 12> wkupm;  // Wakeup interrupt mask
        BoolField<32, 13> errm;  // Error interrupt mask
        BoolField<32, 14> pmaovrm;  // Packet memory area over / underrun interrupt mask
        BoolField<32, 15> ctrm;  // Correct transfer interrupt mask
    };

    union Istr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Istr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 3, 0> ep_id;
        BoolField<32, 4> dir;  // Direction of transaction
        BoolField<32, 7> l1req;  // LPM L1 state request
        BoolField<32, 8> esof;  // Expected start frame
        BoolField<32, 9> sof;  // start of frame
        BoolField<32, 10> reset;  // reset request
        BoolField<32, 11> susp;  // Suspend mode request
        BoolField<32, 12> wkup;  // Wakeup
        BoolField<32, 13> err;  // Error
        BoolField<32, 14> pmaovr;  // Packet memory area over / underrun
        BoolField<32, 15> ctr;  // Correct transfer
    };

    union Fnr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Fnr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 10, 0> fn;
        BitField<32, 12, 11> lsof;
        BoolField<32, 13> lck;  // Locked
        BoolField<32, 14> rxdm;  // Receive data - line status
        BoolField<32, 15> rxdp;  // Receive data + line status
    };

    union Daddr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Daddr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 6, 0> add;
        BoolField<32, 7> ef;  // Enable function
    };

    union Btable {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Btable() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 3> btable;
    };

    union Lpmcsr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Lpmcsr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> lpmen;  // LPM support enable
        BoolField<32, 1> lpmack;  // LPM Token acknowledge enable
        BoolField<32, 3> remwake;  // bRemoteWake value
        BitField<32, 7, 4> besl;
    };

    union Bcdr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Bcdr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> bcden;  // Battery charging detector (BCD) enable
        BoolField<32, 1> dcden;  // Data contact detection (DCD) mode enable
        BoolField<32, 2> pden;  // Primary detection (PD) mode enable
        BoolField<32, 3> sden;  // Secondary detection (SD) mode enable
        BoolField<32, 4> dcdet;  // Data contact detection (DCD) status
        BoolField<32, 5> pdet;  // Primary detection (PD) status
        BoolField<32, 6> sdet;  // Secondary detection (SD) status
        BoolField<32, 7> ps2det;  // DM pull-up detection status
        BoolField<32, 15> dppu;  // DP pull-up control
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Ep0r ep0r; // [+0x0] endpoint 0 register
    Ep1r ep1r; // [+0x4] endpoint 1 register
    Ep2r ep2r; // [+0x8] endpoint 2 register
    Ep3r ep3r; // [+0xC] endpoint 3 register
    Ep4r ep4r; // [+0x10] endpoint 4 register
    Ep5r ep5r; // [+0x14] endpoint 5 register
    Ep6r ep6r; // [+0x18] endpoint 6 register
    Ep7r ep7r; // [+0x1C] endpoint 7 register
    uint32_t __padding_20_3C[8]; // [+0x20 - 0x3C] Padding for alignment
    Cntr cntr; // [+0x40] control register
    Istr istr; // [+0x44] interrupt status register
    Fnr fnr; // [+0x48] frame number register
    Daddr daddr; // [+0x4C] device address
    Btable btable; // [+0x50] Buffer table address
    Lpmcsr lpmcsr; // [+0x54] LPM control and status register
    Bcdr bcdr; // [+0x58] Battery charging detector

}; // Usb registers


// Dma registers
struct Dma {
    ////////////////////////////////////////////////////////////////////////////
    union Isr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Isr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> gif1;  // Channel 1 Global interrupt flag
        BoolField<32, 1> tcif1;  // Channel 1 Transfer Complete flag
        BoolField<32, 2> htif1;  // Channel 1 Half Transfer Complete flag
        BoolField<32, 3> teif1;  // Channel 1 Transfer Error flag
        BoolField<32, 4> gif2;  // Channel 2 Global interrupt flag
        BoolField<32, 5> tcif2;  // Channel 2 Transfer Complete flag
        BoolField<32, 6> htif2;  // Channel 2 Half Transfer Complete flag
        BoolField<32, 7> teif2;  // Channel 2 Transfer Error flag
        BoolField<32, 8> gif3;  // Channel 3 Global interrupt flag
        BoolField<32, 9> tcif3;  // Channel 3 Transfer Complete flag
        BoolField<32, 10> htif3;  // Channel 3 Half Transfer Complete flag
        BoolField<32, 11> teif3;  // Channel 3 Transfer Error flag
        BoolField<32, 12> gif4;  // Channel 4 Global interrupt flag
        BoolField<32, 13> tcif4;  // Channel 4 Transfer Complete flag
        BoolField<32, 14> htif4;  // Channel 4 Half Transfer Complete flag
        BoolField<32, 15> teif4;  // Channel 4 Transfer Error flag
        BoolField<32, 16> gif5;  // Channel 5 Global interrupt flag
        BoolField<32, 17> tcif5;  // Channel 5 Transfer Complete flag
        BoolField<32, 18> htif5;  // Channel 5 Half Transfer Complete flag
        BoolField<32, 19> teif5;  // Channel 5 Transfer Error flag
        BoolField<32, 20> gif6;  // Channel 6 Global interrupt flag
        BoolField<32, 21> tcif6;  // Channel 6 Transfer Complete flag
        BoolField<32, 22> htif6;  // Channel 6 Half Transfer Complete flag
        BoolField<32, 23> teif6;  // Channel 6 Transfer Error flag
        BoolField<32, 24> gif7;  // Channel 7 Global interrupt flag
        BoolField<32, 25> tcif7;  // Channel 7 Transfer Complete flag
        BoolField<32, 26> htif7;  // Channel 7 Half Transfer Complete flag
        BoolField<32, 27> teif7;  // Channel 7 Transfer Error flag
    };

    union Ifcr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ifcr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> cgif1;  // Channel 1 Global interrupt clear
        BoolField<32, 1> ctcif1;  // Channel 1 Transfer Complete clear
        BoolField<32, 2> chtif1;  // Channel 1 Half Transfer clear
        BoolField<32, 3> cteif1;  // Channel 1 Transfer Error clear
        BoolField<32, 4> cgif2;  // Channel 2 Global interrupt clear
        BoolField<32, 5> ctcif2;  // Channel 2 Transfer Complete clear
        BoolField<32, 6> chtif2;  // Channel 2 Half Transfer clear
        BoolField<32, 7> cteif2;  // Channel 2 Transfer Error clear
        BoolField<32, 8> cgif3;  // Channel 3 Global interrupt clear
        BoolField<32, 9> ctcif3;  // Channel 3 Transfer Complete clear
        BoolField<32, 10> chtif3;  // Channel 3 Half Transfer clear
        BoolField<32, 11> cteif3;  // Channel 3 Transfer Error clear
        BoolField<32, 12> cgif4;  // Channel 4 Global interrupt clear
        BoolField<32, 13> ctcif4;  // Channel 4 Transfer Complete clear
        BoolField<32, 14> chtif4;  // Channel 4 Half Transfer clear
        BoolField<32, 15> cteif4;  // Channel 4 Transfer Error clear
        BoolField<32, 16> cgif5;  // Channel 5 Global interrupt clear
        BoolField<32, 17> ctcif5;  // Channel 5 Transfer Complete clear
        BoolField<32, 18> chtif5;  // Channel 5 Half Transfer clear
        BoolField<32, 19> cteif5;  // Channel 5 Transfer Error clear
        BoolField<32, 20> cgif6;  // Channel 6 Global interrupt clear
        BoolField<32, 21> ctcif6;  // Channel 6 Transfer Complete clear
        BoolField<32, 22> chtif6;  // Channel 6 Half Transfer clear
        BoolField<32, 23> cteif6;  // Channel 6 Transfer Error clear
        BoolField<32, 24> cgif7;  // Channel 7 Global interrupt clear
        BoolField<32, 25> ctcif7;  // Channel 7 Transfer Complete clear
        BoolField<32, 26> chtif7;  // Channel 7 Half Transfer clear
        BoolField<32, 27> cteif7;  // Channel 7 Transfer Error clear
    };

    union Ccr1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ccr1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> en;  // Channel enable
        BoolField<32, 1> tcie;  // Transfer complete interrupt enable
        BoolField<32, 2> htie;  // Half Transfer interrupt enable
        BoolField<32, 3> teie;  // Transfer error interrupt enable
        BoolField<32, 4> dir;  // Data transfer direction
        BoolField<32, 5> circ;  // Circular mode
        BoolField<32, 6> pinc;  // Peripheral increment mode
        BoolField<32, 7> minc;  // Memory increment mode
        BitField<32, 9, 8> psize;
        BitField<32, 11, 10> msize;
        BitField<32, 13, 12> pl;
        BoolField<32, 14> mem2mem;  // Memory to memory mode
    };

    union Cndtr1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cndtr1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> ndt;
    };

    using Cpar1 = uint32_t;

    using Cmar1 = uint32_t;

    union Ccr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ccr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> en;  // Channel enable
        BoolField<32, 1> tcie;  // Transfer complete interrupt enable
        BoolField<32, 2> htie;  // Half Transfer interrupt enable
        BoolField<32, 3> teie;  // Transfer error interrupt enable
        BoolField<32, 4> dir;  // Data transfer direction
        BoolField<32, 5> circ;  // Circular mode
        BoolField<32, 6> pinc;  // Peripheral increment mode
        BoolField<32, 7> minc;  // Memory increment mode
        BitField<32, 9, 8> psize;
        BitField<32, 11, 10> msize;
        BitField<32, 13, 12> pl;
        BoolField<32, 14> mem2mem;  // Memory to memory mode
    };

    union Cndtr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cndtr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> ndt;
    };

    using Cpar2 = uint32_t;

    using Cmar2 = uint32_t;

    union Ccr3 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ccr3() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> en;  // Channel enable
        BoolField<32, 1> tcie;  // Transfer complete interrupt enable
        BoolField<32, 2> htie;  // Half Transfer interrupt enable
        BoolField<32, 3> teie;  // Transfer error interrupt enable
        BoolField<32, 4> dir;  // Data transfer direction
        BoolField<32, 5> circ;  // Circular mode
        BoolField<32, 6> pinc;  // Peripheral increment mode
        BoolField<32, 7> minc;  // Memory increment mode
        BitField<32, 9, 8> psize;
        BitField<32, 11, 10> msize;
        BitField<32, 13, 12> pl;
        BoolField<32, 14> mem2mem;  // Memory to memory mode
    };

    union Cndtr3 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cndtr3() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> ndt;
    };

    using Cpar3 = uint32_t;

    using Cmar3 = uint32_t;

    union Ccr4 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ccr4() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> en;  // Channel enable
        BoolField<32, 1> tcie;  // Transfer complete interrupt enable
        BoolField<32, 2> htie;  // Half Transfer interrupt enable
        BoolField<32, 3> teie;  // Transfer error interrupt enable
        BoolField<32, 4> dir;  // Data transfer direction
        BoolField<32, 5> circ;  // Circular mode
        BoolField<32, 6> pinc;  // Peripheral increment mode
        BoolField<32, 7> minc;  // Memory increment mode
        BitField<32, 9, 8> psize;
        BitField<32, 11, 10> msize;
        BitField<32, 13, 12> pl;
        BoolField<32, 14> mem2mem;  // Memory to memory mode
    };

    union Cndtr4 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cndtr4() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> ndt;
    };

    using Cpar4 = uint32_t;

    using Cmar4 = uint32_t;

    union Ccr5 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ccr5() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> en;  // Channel enable
        BoolField<32, 1> tcie;  // Transfer complete interrupt enable
        BoolField<32, 2> htie;  // Half Transfer interrupt enable
        BoolField<32, 3> teie;  // Transfer error interrupt enable
        BoolField<32, 4> dir;  // Data transfer direction
        BoolField<32, 5> circ;  // Circular mode
        BoolField<32, 6> pinc;  // Peripheral increment mode
        BoolField<32, 7> minc;  // Memory increment mode
        BitField<32, 9, 8> psize;
        BitField<32, 11, 10> msize;
        BitField<32, 13, 12> pl;
        BoolField<32, 14> mem2mem;  // Memory to memory mode
    };

    union Cndtr5 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cndtr5() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> ndt;
    };

    using Cpar5 = uint32_t;

    using Cmar5 = uint32_t;

    union Ccr6 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ccr6() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> en;  // Channel enable
        BoolField<32, 1> tcie;  // Transfer complete interrupt enable
        BoolField<32, 2> htie;  // Half Transfer interrupt enable
        BoolField<32, 3> teie;  // Transfer error interrupt enable
        BoolField<32, 4> dir;  // Data transfer direction
        BoolField<32, 5> circ;  // Circular mode
        BoolField<32, 6> pinc;  // Peripheral increment mode
        BoolField<32, 7> minc;  // Memory increment mode
        BitField<32, 9, 8> psize;
        BitField<32, 11, 10> msize;
        BitField<32, 13, 12> pl;
        BoolField<32, 14> mem2mem;  // Memory to memory mode
    };

    union Cndtr6 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cndtr6() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> ndt;
    };

    using Cpar6 = uint32_t;

    using Cmar6 = uint32_t;

    union Ccr7 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ccr7() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> en;  // Channel enable
        BoolField<32, 1> tcie;  // Transfer complete interrupt enable
        BoolField<32, 2> htie;  // Half Transfer interrupt enable
        BoolField<32, 3> teie;  // Transfer error interrupt enable
        BoolField<32, 4> dir;  // Data transfer direction
        BoolField<32, 5> circ;  // Circular mode
        BoolField<32, 6> pinc;  // Peripheral increment mode
        BoolField<32, 7> minc;  // Memory increment mode
        BitField<32, 9, 8> psize;
        BitField<32, 11, 10> msize;
        BitField<32, 13, 12> pl;
        BoolField<32, 14> mem2mem;  // Memory to memory mode
    };

    union Cndtr7 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cndtr7() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> ndt;
    };

    using Cpar7 = uint32_t;

    using Cmar7 = uint32_t;

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Isr isr; // [+0x0] DMA interrupt status register (DMA_ISR)
    Ifcr ifcr; // [+0x4] DMA interrupt flag clear register (DMA_IFCR)
    Ccr1 ccr1; // [+0x8] DMA channel configuration register (DMA_CCR)
    Cndtr1 cndtr1; // [+0xC] DMA channel 1 number of data register
    Cpar1 cpar1; // [+0x10] DMA channel 1 peripheral address register
    Cmar1 cmar1; // [+0x14] DMA channel 1 memory address register
    uint32_t __padding_18_18[1]; // [+0x18 - 0x18] Padding for alignment
    Ccr2 ccr2; // [+0x1C] DMA channel configuration register (DMA_CCR)
    Cndtr2 cndtr2; // [+0x20] DMA channel 2 number of data register
    Cpar2 cpar2; // [+0x24] DMA channel 2 peripheral address register
    Cmar2 cmar2; // [+0x28] DMA channel 2 memory address register
    uint32_t __padding_2C_2C[1]; // [+0x2C - 0x2C] Padding for alignment
    Ccr3 ccr3; // [+0x30] DMA channel configuration register (DMA_CCR)
    Cndtr3 cndtr3; // [+0x34] DMA channel 3 number of data register
    Cpar3 cpar3; // [+0x38] DMA channel 3 peripheral address register
    Cmar3 cmar3; // [+0x3C] DMA channel 3 memory address register
    uint32_t __padding_40_40[1]; // [+0x40 - 0x40] Padding for alignment
    Ccr4 ccr4; // [+0x44] DMA channel configuration register (DMA_CCR)
    Cndtr4 cndtr4; // [+0x48] DMA channel 4 number of data register
    Cpar4 cpar4; // [+0x4C] DMA channel 4 peripheral address register
    Cmar4 cmar4; // [+0x50] DMA channel 4 memory address register
    uint32_t __padding_54_54[1]; // [+0x54 - 0x54] Padding for alignment
    Ccr5 ccr5; // [+0x58] DMA channel configuration register (DMA_CCR)
    Cndtr5 cndtr5; // [+0x5C] DMA channel 5 number of data register
    Cpar5 cpar5; // [+0x60] DMA channel 5 peripheral address register
    Cmar5 cmar5; // [+0x64] DMA channel 5 memory address register
    uint32_t __padding_68_68[1]; // [+0x68 - 0x68] Padding for alignment
    Ccr6 ccr6; // [+0x6C] DMA channel configuration register (DMA_CCR)
    Cndtr6 cndtr6; // [+0x70] DMA channel 6 number of data register
    Cpar6 cpar6; // [+0x74] DMA channel 6 peripheral address register
    Cmar6 cmar6; // [+0x78] DMA channel 6 memory address register
    uint32_t __padding_7C_7C[1]; // [+0x7C - 0x7C] Padding for alignment
    Ccr7 ccr7; // [+0x80] DMA channel configuration register (DMA_CCR)
    Cndtr7 cndtr7; // [+0x84] DMA channel 7 number of data register
    Cpar7 cpar7; // [+0x88] DMA channel 7 peripheral address register
    Cmar7 cmar7; // [+0x8C] DMA channel 7 memory address register

}; // Dma registers


// Flash registers
struct Flash {
    ////////////////////////////////////////////////////////////////////////////
    union Acr {
    public:
        constexpr static uint32_t kResetValue = 0x00000030;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Acr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 2, 0> latency;
        BoolField<32, 4> prftbe;  // PRFTBE
        BoolField<32, 5> prftbs;  // PRFTBS
    };

    using Keyr = uint32_t;

    using Optkeyr = uint32_t;

    union Sr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Sr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 5> eop;  // End of operation
        BoolField<32, 4> wrprt;  // Write protection error
        BoolField<32, 2> pgerr;  // Programming error
        BoolField<32, 0> bsy;  // Busy
    };

    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000080;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 13> force_optload;  // Force option byte loading
        BoolField<32, 12> eopie;  // End of operation interrupt enable
        BoolField<32, 10> errie;  // Error interrupt enable
        BoolField<32, 9> optwre;  // Option bytes write enable
        BoolField<32, 7> lock;  // Lock
        BoolField<32, 6> strt;  // Start
        BoolField<32, 5> opter;  // Option byte erase
        BoolField<32, 4> optpg;  // Option byte programming
        BoolField<32, 2> mer;  // Mass erase
        BoolField<32, 1> per;  // Page erase
        BoolField<32, 0> pg;  // Programming
    };

    using Ar = uint32_t;

    union Obr {
    public:
        constexpr static uint32_t kResetValue = 0x03FFFFF2;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Obr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> data1;
        BitField<32, 23, 16> data0;
        BoolField<32, 13> vdda_monitor;  // VDDA_MONITOR
        BoolField<32, 12> boot1;  // BOOT1
        BoolField<32, 10> nrst_stdby;  // nRST_STDBY
        BoolField<32, 9> nrst_stop;  // nRST_STOP
        BoolField<32, 8> wdg_sw;  // WDG_SW
        BoolField<32, 2> level2_prot;  // Level 2 protection status
        BoolField<32, 1> level1_prot;  // Level 1 protection status
        BoolField<32, 0> opterr;  // Option byte error
    };

    using Wrpr = uint32_t;

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Acr acr; // [+0x0] Flash access control register
    Keyr keyr; // [+0x4] Flash key register
    Optkeyr optkeyr; // [+0x8] Flash option key register
    Sr sr; // [+0xC] Flash status register
    Cr cr; // [+0x10] Flash control register
    Ar ar; // [+0x14] Flash address register
    uint32_t __padding_18_18[1]; // [+0x18 - 0x18] Padding for alignment
    Obr obr; // [+0x1C] Option byte register
    Wrpr wrpr; // [+0x20] Write protection register

}; // Flash registers


// Tsc registers
struct Tsc {
    ////////////////////////////////////////////////////////////////////////////
    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 28> ctph;
        BitField<32, 27, 24> ctpl;
        BitField<32, 23, 17> ssd;
        BoolField<32, 16> sse;  // Spread spectrum enable
        BoolField<32, 15> sspsc;  // Spread spectrum prescaler
        BitField<32, 14, 12> pgpsc;
        BitField<32, 7, 5> mcv;
        BoolField<32, 4> iodef;  // I/O Default mode
        BoolField<32, 3> syncpol;  // Synchronization pin polarity
        BoolField<32, 2> am;  // Acquisition mode
        BoolField<32, 1> start;  // Start a new acquisition
        BoolField<32, 0> tsce;  // Touch sensing controller enable
    };

    union Ier {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ier() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 1> mceie;  // Max count error interrupt enable
        BoolField<32, 0> eoaie;  // End of acquisition interrupt enable
    };

    union Icr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Icr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 1> mceic;  // Max count error interrupt clear
        BoolField<32, 0> eoaic;  // End of acquisition interrupt clear
    };

    union Isr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Isr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 1> mcef;  // Max count error flag
        BoolField<32, 0> eoaf;  // End of acquisition flag
    };

    union Iohcr {
    public:
        constexpr static uint32_t kResetValue = 0xFFFFFFFF;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Iohcr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 23> g6_io4;  // G6_IO4 Schmitt trigger hysteresis mode
        BoolField<32, 22> g6_io3;  // G6_IO3 Schmitt trigger hysteresis mode
        BoolField<32, 21> g6_io2;  // G6_IO2 Schmitt trigger hysteresis mode
        BoolField<32, 20> g6_io1;  // G6_IO1 Schmitt trigger hysteresis mode
        BoolField<32, 19> g5_io4;  // G5_IO4 Schmitt trigger hysteresis mode
        BoolField<32, 18> g5_io3;  // G5_IO3 Schmitt trigger hysteresis mode
        BoolField<32, 17> g5_io2;  // G5_IO2 Schmitt trigger hysteresis mode
        BoolField<32, 16> g5_io1;  // G5_IO1 Schmitt trigger hysteresis mode
        BoolField<32, 15> g4_io4;  // G4_IO4 Schmitt trigger hysteresis mode
        BoolField<32, 14> g4_io3;  // G4_IO3 Schmitt trigger hysteresis mode
        BoolField<32, 13> g4_io2;  // G4_IO2 Schmitt trigger hysteresis mode
        BoolField<32, 12> g4_io1;  // G4_IO1 Schmitt trigger hysteresis mode
        BoolField<32, 11> g3_io4;  // G3_IO4 Schmitt trigger hysteresis mode
        BoolField<32, 10> g3_io3;  // G3_IO3 Schmitt trigger hysteresis mode
        BoolField<32, 9> g3_io2;  // G3_IO2 Schmitt trigger hysteresis mode
        BoolField<32, 8> g3_io1;  // G3_IO1 Schmitt trigger hysteresis mode
        BoolField<32, 7> g2_io4;  // G2_IO4 Schmitt trigger hysteresis mode
        BoolField<32, 6> g2_io3;  // G2_IO3 Schmitt trigger hysteresis mode
        BoolField<32, 5> g2_io2;  // G2_IO2 Schmitt trigger hysteresis mode
        BoolField<32, 4> g2_io1;  // G2_IO1 Schmitt trigger hysteresis mode
        BoolField<32, 3> g1_io4;  // G1_IO4 Schmitt trigger hysteresis mode
        BoolField<32, 2> g1_io3;  // G1_IO3 Schmitt trigger hysteresis mode
        BoolField<32, 1> g1_io2;  // G1_IO2 Schmitt trigger hysteresis mode
        BoolField<32, 0> g1_io1;  // G1_IO1 Schmitt trigger hysteresis mode
    };

    union Ioascr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ioascr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 23> g6_io4;  // G6_IO4 analog switch enable
        BoolField<32, 22> g6_io3;  // G6_IO3 analog switch enable
        BoolField<32, 21> g6_io2;  // G6_IO2 analog switch enable
        BoolField<32, 20> g6_io1;  // G6_IO1 analog switch enable
        BoolField<32, 19> g5_io4;  // G5_IO4 analog switch enable
        BoolField<32, 18> g5_io3;  // G5_IO3 analog switch enable
        BoolField<32, 17> g5_io2;  // G5_IO2 analog switch enable
        BoolField<32, 16> g5_io1;  // G5_IO1 analog switch enable
        BoolField<32, 15> g4_io4;  // G4_IO4 analog switch enable
        BoolField<32, 14> g4_io3;  // G4_IO3 analog switch enable
        BoolField<32, 13> g4_io2;  // G4_IO2 analog switch enable
        BoolField<32, 12> g4_io1;  // G4_IO1 analog switch enable
        BoolField<32, 11> g3_io4;  // G3_IO4 analog switch enable
        BoolField<32, 10> g3_io3;  // G3_IO3 analog switch enable
        BoolField<32, 9> g3_io2;  // G3_IO2 analog switch enable
        BoolField<32, 8> g3_io1;  // G3_IO1 analog switch enable
        BoolField<32, 7> g2_io4;  // G2_IO4 analog switch enable
        BoolField<32, 6> g2_io3;  // G2_IO3 analog switch enable
        BoolField<32, 5> g2_io2;  // G2_IO2 analog switch enable
        BoolField<32, 4> g2_io1;  // G2_IO1 analog switch enable
        BoolField<32, 3> g1_io4;  // G1_IO4 analog switch enable
        BoolField<32, 2> g1_io3;  // G1_IO3 analog switch enable
        BoolField<32, 1> g1_io2;  // G1_IO2 analog switch enable
        BoolField<32, 0> g1_io1;  // G1_IO1 analog switch enable
    };

    union Ioscr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ioscr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 23> g6_io4;  // G6_IO4 sampling mode
        BoolField<32, 22> g6_io3;  // G6_IO3 sampling mode
        BoolField<32, 21> g6_io2;  // G6_IO2 sampling mode
        BoolField<32, 20> g6_io1;  // G6_IO1 sampling mode
        BoolField<32, 19> g5_io4;  // G5_IO4 sampling mode
        BoolField<32, 18> g5_io3;  // G5_IO3 sampling mode
        BoolField<32, 17> g5_io2;  // G5_IO2 sampling mode
        BoolField<32, 16> g5_io1;  // G5_IO1 sampling mode
        BoolField<32, 15> g4_io4;  // G4_IO4 sampling mode
        BoolField<32, 14> g4_io3;  // G4_IO3 sampling mode
        BoolField<32, 13> g4_io2;  // G4_IO2 sampling mode
        BoolField<32, 12> g4_io1;  // G4_IO1 sampling mode
        BoolField<32, 11> g3_io4;  // G3_IO4 sampling mode
        BoolField<32, 10> g3_io3;  // G3_IO3 sampling mode
        BoolField<32, 9> g3_io2;  // G3_IO2 sampling mode
        BoolField<32, 8> g3_io1;  // G3_IO1 sampling mode
        BoolField<32, 7> g2_io4;  // G2_IO4 sampling mode
        BoolField<32, 6> g2_io3;  // G2_IO3 sampling mode
        BoolField<32, 5> g2_io2;  // G2_IO2 sampling mode
        BoolField<32, 4> g2_io1;  // G2_IO1 sampling mode
        BoolField<32, 3> g1_io4;  // G1_IO4 sampling mode
        BoolField<32, 2> g1_io3;  // G1_IO3 sampling mode
        BoolField<32, 1> g1_io2;  // G1_IO2 sampling mode
        BoolField<32, 0> g1_io1;  // G1_IO1 sampling mode
    };

    union Ioccr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ioccr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 23> g6_io4;  // G6_IO4 channel mode
        BoolField<32, 22> g6_io3;  // G6_IO3 channel mode
        BoolField<32, 21> g6_io2;  // G6_IO2 channel mode
        BoolField<32, 20> g6_io1;  // G6_IO1 channel mode
        BoolField<32, 19> g5_io4;  // G5_IO4 channel mode
        BoolField<32, 18> g5_io3;  // G5_IO3 channel mode
        BoolField<32, 17> g5_io2;  // G5_IO2 channel mode
        BoolField<32, 16> g5_io1;  // G5_IO1 channel mode
        BoolField<32, 15> g4_io4;  // G4_IO4 channel mode
        BoolField<32, 14> g4_io3;  // G4_IO3 channel mode
        BoolField<32, 13> g4_io2;  // G4_IO2 channel mode
        BoolField<32, 12> g4_io1;  // G4_IO1 channel mode
        BoolField<32, 11> g3_io4;  // G3_IO4 channel mode
        BoolField<32, 10> g3_io3;  // G3_IO3 channel mode
        BoolField<32, 9> g3_io2;  // G3_IO2 channel mode
        BoolField<32, 8> g3_io1;  // G3_IO1 channel mode
        BoolField<32, 7> g2_io4;  // G2_IO4 channel mode
        BoolField<32, 6> g2_io3;  // G2_IO3 channel mode
        BoolField<32, 5> g2_io2;  // G2_IO2 channel mode
        BoolField<32, 4> g2_io1;  // G2_IO1 channel mode
        BoolField<32, 3> g1_io4;  // G1_IO4 channel mode
        BoolField<32, 2> g1_io3;  // G1_IO3 channel mode
        BoolField<32, 1> g1_io2;  // G1_IO2 channel mode
        BoolField<32, 0> g1_io1;  // G1_IO1 channel mode
    };

    union Iogcsr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Iogcsr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 23> g8s;  // Analog I/O group x status
        BoolField<32, 22> g7s;  // Analog I/O group x status
        BoolField<32, 21> g6s;  // Analog I/O group x status
        BoolField<32, 20> g5s;  // Analog I/O group x status
        BoolField<32, 19> g4s;  // Analog I/O group x status
        BoolField<32, 18> g3s;  // Analog I/O group x status
        BoolField<32, 17> g2s;  // Analog I/O group x status
        BoolField<32, 16> g1s;  // Analog I/O group x status
        BoolField<32, 7> g8e;  // Analog I/O group x enable
        BoolField<32, 6> g7e;  // Analog I/O group x enable
        BoolField<32, 5> g6e;  // Analog I/O group x enable
        BoolField<32, 4> g5e;  // Analog I/O group x enable
        BoolField<32, 3> g4e;  // Analog I/O group x enable
        BoolField<32, 2> g3e;  // Analog I/O group x enable
        BoolField<32, 1> g2e;  // Analog I/O group x enable
        BoolField<32, 0> g1e;  // Analog I/O group x enable
    };

    union Iog1cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Iog1cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 13, 0> cnt;
    };

    union Iog2cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Iog2cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 13, 0> cnt;
    };

    union Iog3cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Iog3cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 13, 0> cnt;
    };

    union Iog4cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Iog4cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 13, 0> cnt;
    };

    union Iog5cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Iog5cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 13, 0> cnt;
    };

    union Iog6cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Iog6cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 13, 0> cnt;
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cr cr; // [+0x0] control register
    Ier ier; // [+0x4] interrupt enable register
    Icr icr; // [+0x8] interrupt clear register
    Isr isr; // [+0xC] interrupt status register
    Iohcr iohcr; // [+0x10] I/O hysteresis control register
    uint32_t __padding_14_14[1]; // [+0x14 - 0x14] Padding for alignment
    Ioascr ioascr; // [+0x18] I/O analog switch control register
    uint32_t __padding_1C_1C[1]; // [+0x1C - 0x1C] Padding for alignment
    Ioscr ioscr; // [+0x20] I/O sampling control register
    uint32_t __padding_24_24[1]; // [+0x24 - 0x24] Padding for alignment
    Ioccr ioccr; // [+0x28] I/O channel control register
    uint32_t __padding_2C_2C[1]; // [+0x2C - 0x2C] Padding for alignment
    Iogcsr iogcsr; // [+0x30] I/O group control status register
    Iog1cr iog1cr; // [+0x34] I/O group x counter register
    Iog2cr iog2cr; // [+0x38] I/O group x counter register
    Iog3cr iog3cr; // [+0x3C] I/O group x counter register
    Iog4cr iog4cr; // [+0x40] I/O group x counter register
    Iog5cr iog5cr; // [+0x44] I/O group x counter register
    Iog6cr iog6cr; // [+0x48] I/O group x counter register

}; // Tsc registers


// Crc registers
struct Crc {
    ////////////////////////////////////////////////////////////////////////////
    using Dr = uint32_t;

    union Idr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Idr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 0> idr;
    };

    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> reset;  // reset bit
        BitField<32, 6, 5> rev_in;
        BoolField<32, 7> rev_out;  // Reverse output data
    };

    using Init = uint32_t;

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Dr dr; // [+0x0] Data register
    Idr idr; // [+0x4] Independent data register
    Cr cr; // [+0x8] Control register
    Init init; // [+0xC] Initial CRC value

}; // Crc registers


// Can registers
struct Can {
    ////////////////////////////////////////////////////////////////////////////
    union Can_mcr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_mcr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 16> dbf;  // DBF
        BoolField<32, 15> reset;  // RESET
        BoolField<32, 7> ttcm;  // TTCM
        BoolField<32, 6> abom;  // ABOM
        BoolField<32, 5> awum;  // AWUM
        BoolField<32, 4> nart;  // NART
        BoolField<32, 3> rflm;  // RFLM
        BoolField<32, 2> txfp;  // TXFP
        BoolField<32, 1> sleep;  // SLEEP
        BoolField<32, 0> inrq;  // INRQ
    };

    union Can_msr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_msr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 11> rx;  // RX
        BoolField<32, 10> samp;  // SAMP
        BoolField<32, 9> rxm;  // RXM
        BoolField<32, 8> txm;  // TXM
        BoolField<32, 4> slaki;  // SLAKI
        BoolField<32, 3> wkui;  // WKUI
        BoolField<32, 2> erri;  // ERRI
        BoolField<32, 1> slak;  // SLAK
        BoolField<32, 0> inak;  // INAK
    };

    union Can_tsr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_tsr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 31> low2;  // Lowest priority flag for mailbox 2
        BoolField<32, 30> low1;  // Lowest priority flag for mailbox 1
        BoolField<32, 29> low0;  // Lowest priority flag for mailbox 0
        BoolField<32, 28> tme2;  // Lowest priority flag for mailbox 2
        BoolField<32, 27> tme1;  // Lowest priority flag for mailbox 1
        BoolField<32, 26> tme0;  // Lowest priority flag for mailbox 0
        BitField<32, 25, 24> code;
        BoolField<32, 23> abrq2;  // ABRQ2
        BoolField<32, 19> terr2;  // TERR2
        BoolField<32, 18> alst2;  // ALST2
        BoolField<32, 17> txok2;  // TXOK2
        BoolField<32, 16> rqcp2;  // RQCP2
        BoolField<32, 15> abrq1;  // ABRQ1
        BoolField<32, 11> terr1;  // TERR1
        BoolField<32, 10> alst1;  // ALST1
        BoolField<32, 9> txok1;  // TXOK1
        BoolField<32, 8> rqcp1;  // RQCP1
        BoolField<32, 7> abrq0;  // ABRQ0
        BoolField<32, 3> terr0;  // TERR0
        BoolField<32, 2> alst0;  // ALST0
        BoolField<32, 1> txok0;  // TXOK0
        BoolField<32, 0> rqcp0;  // RQCP0
    };

    union Can_rf0r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_rf0r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 5> rfom0;  // RFOM0
        BoolField<32, 4> fovr0;  // FOVR0
        BoolField<32, 3> full0;  // FULL0
        BitField<32, 1, 0> fmp0;
    };

    union Can_rf1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_rf1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 5> rfom1;  // RFOM1
        BoolField<32, 4> fovr1;  // FOVR1
        BoolField<32, 3> full1;  // FULL1
        BitField<32, 1, 0> fmp1;
    };

    union Can_ier {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_ier() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 17> slkie;  // SLKIE
        BoolField<32, 16> wkuie;  // WKUIE
        BoolField<32, 15> errie;  // ERRIE
        BoolField<32, 11> lecie;  // LECIE
        BoolField<32, 10> bofie;  // BOFIE
        BoolField<32, 9> epvie;  // EPVIE
        BoolField<32, 8> ewgie;  // EWGIE
        BoolField<32, 6> fovie1;  // FOVIE1
        BoolField<32, 5> ffie1;  // FFIE1
        BoolField<32, 4> fmpie1;  // FMPIE1
        BoolField<32, 3> fovie0;  // FOVIE0
        BoolField<32, 2> ffie0;  // FFIE0
        BoolField<32, 1> fmpie0;  // FMPIE0
        BoolField<32, 0> tmeie;  // TMEIE
    };

    union Can_esr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_esr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> rec;
        BitField<32, 23, 16> tec;
        BitField<32, 6, 4> lec;
        BoolField<32, 2> boff;  // BOFF
        BoolField<32, 1> epvf;  // EPVF
        BoolField<32, 0> ewgf;  // EWGF
    };

    union Can_btr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_btr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 31> silm;  // SILM
        BoolField<32, 30> lbkm;  // LBKM
        BitField<32, 25, 24> sjw;
        BitField<32, 22, 20> ts2;
        BitField<32, 19, 16> ts1;
        BitField<32, 9, 0> brp;
    };

    union Can_ti0r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_ti0r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 21> stid;
        BitField<32, 20, 3> exid;
        BoolField<32, 2> ide;  // IDE
        BoolField<32, 1> rtr;  // RTR
        BoolField<32, 0> txrq;  // TXRQ
    };

    union Can_tdt0r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_tdt0r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 16> time;
        BoolField<32, 8> tgt;  // TGT
        BitField<32, 3, 0> dlc;
    };

    union Can_tdl0r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_tdl0r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> data3;
        BitField<32, 23, 16> data2;
        BitField<32, 15, 8> data1;
        BitField<32, 7, 0> data0;
    };

    union Can_tdh0r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_tdh0r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> data7;
        BitField<32, 23, 16> data6;
        BitField<32, 15, 8> data5;
        BitField<32, 7, 0> data4;
    };

    union Can_ti1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_ti1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 21> stid;
        BitField<32, 20, 3> exid;
        BoolField<32, 2> ide;  // IDE
        BoolField<32, 1> rtr;  // RTR
        BoolField<32, 0> txrq;  // TXRQ
    };

    union Can_tdt1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_tdt1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 16> time;
        BoolField<32, 8> tgt;  // TGT
        BitField<32, 3, 0> dlc;
    };

    union Can_tdl1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_tdl1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> data3;
        BitField<32, 23, 16> data2;
        BitField<32, 15, 8> data1;
        BitField<32, 7, 0> data0;
    };

    union Can_tdh1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_tdh1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> data7;
        BitField<32, 23, 16> data6;
        BitField<32, 15, 8> data5;
        BitField<32, 7, 0> data4;
    };

    union Can_ti2r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_ti2r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 21> stid;
        BitField<32, 20, 3> exid;
        BoolField<32, 2> ide;  // IDE
        BoolField<32, 1> rtr;  // RTR
        BoolField<32, 0> txrq;  // TXRQ
    };

    union Can_tdt2r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_tdt2r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 16> time;
        BoolField<32, 8> tgt;  // TGT
        BitField<32, 3, 0> dlc;
    };

    union Can_tdl2r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_tdl2r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> data3;
        BitField<32, 23, 16> data2;
        BitField<32, 15, 8> data1;
        BitField<32, 7, 0> data0;
    };

    union Can_tdh2r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_tdh2r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> data7;
        BitField<32, 23, 16> data6;
        BitField<32, 15, 8> data5;
        BitField<32, 7, 0> data4;
    };

    union Can_ri0r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_ri0r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 21> stid;
        BitField<32, 20, 3> exid;
        BoolField<32, 2> ide;  // IDE
        BoolField<32, 1> rtr;  // RTR
    };

    union Can_rdt0r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_rdt0r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 16> time;
        BitField<32, 15, 8> fmi;
        BitField<32, 3, 0> dlc;
    };

    union Can_rdl0r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_rdl0r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> data3;
        BitField<32, 23, 16> data2;
        BitField<32, 15, 8> data1;
        BitField<32, 7, 0> data0;
    };

    union Can_rdh0r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_rdh0r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> data7;
        BitField<32, 23, 16> data6;
        BitField<32, 15, 8> data5;
        BitField<32, 7, 0> data4;
    };

    union Can_ri1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_ri1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 21> stid;
        BitField<32, 20, 3> exid;
        BoolField<32, 2> ide;  // IDE
        BoolField<32, 1> rtr;  // RTR
    };

    union Can_rdt1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_rdt1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 16> time;
        BitField<32, 15, 8> fmi;
        BitField<32, 3, 0> dlc;
    };

    union Can_rdl1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_rdl1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> data3;
        BitField<32, 23, 16> data2;
        BitField<32, 15, 8> data1;
        BitField<32, 7, 0> data0;
    };

    union Can_rdh1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_rdh1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> data7;
        BitField<32, 23, 16> data6;
        BitField<32, 15, 8> data5;
        BitField<32, 7, 0> data4;
    };

    union Can_fmr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_fmr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 13, 8> can2sb;
        BoolField<32, 0> finit;  // FINIT
    };

    union Can_fm1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_fm1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fbm0;  // Filter mode
        BoolField<32, 1> fbm1;  // Filter mode
        BoolField<32, 2> fbm2;  // Filter mode
        BoolField<32, 3> fbm3;  // Filter mode
        BoolField<32, 4> fbm4;  // Filter mode
        BoolField<32, 5> fbm5;  // Filter mode
        BoolField<32, 6> fbm6;  // Filter mode
        BoolField<32, 7> fbm7;  // Filter mode
        BoolField<32, 8> fbm8;  // Filter mode
        BoolField<32, 9> fbm9;  // Filter mode
        BoolField<32, 10> fbm10;  // Filter mode
        BoolField<32, 11> fbm11;  // Filter mode
        BoolField<32, 12> fbm12;  // Filter mode
        BoolField<32, 13> fbm13;  // Filter mode
        BoolField<32, 14> fbm14;  // Filter mode
        BoolField<32, 15> fbm15;  // Filter mode
        BoolField<32, 16> fbm16;  // Filter mode
        BoolField<32, 17> fbm17;  // Filter mode
        BoolField<32, 18> fbm18;  // Filter mode
        BoolField<32, 19> fbm19;  // Filter mode
        BoolField<32, 20> fbm20;  // Filter mode
        BoolField<32, 21> fbm21;  // Filter mode
        BoolField<32, 22> fbm22;  // Filter mode
        BoolField<32, 23> fbm23;  // Filter mode
        BoolField<32, 24> fbm24;  // Filter mode
        BoolField<32, 25> fbm25;  // Filter mode
        BoolField<32, 26> fbm26;  // Filter mode
        BoolField<32, 27> fbm27;  // Filter mode
    };

    union Can_fs1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_fs1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fsc0;  // Filter scale configuration
        BoolField<32, 1> fsc1;  // Filter scale configuration
        BoolField<32, 2> fsc2;  // Filter scale configuration
        BoolField<32, 3> fsc3;  // Filter scale configuration
        BoolField<32, 4> fsc4;  // Filter scale configuration
        BoolField<32, 5> fsc5;  // Filter scale configuration
        BoolField<32, 6> fsc6;  // Filter scale configuration
        BoolField<32, 7> fsc7;  // Filter scale configuration
        BoolField<32, 8> fsc8;  // Filter scale configuration
        BoolField<32, 9> fsc9;  // Filter scale configuration
        BoolField<32, 10> fsc10;  // Filter scale configuration
        BoolField<32, 11> fsc11;  // Filter scale configuration
        BoolField<32, 12> fsc12;  // Filter scale configuration
        BoolField<32, 13> fsc13;  // Filter scale configuration
        BoolField<32, 14> fsc14;  // Filter scale configuration
        BoolField<32, 15> fsc15;  // Filter scale configuration
        BoolField<32, 16> fsc16;  // Filter scale configuration
        BoolField<32, 17> fsc17;  // Filter scale configuration
        BoolField<32, 18> fsc18;  // Filter scale configuration
        BoolField<32, 19> fsc19;  // Filter scale configuration
        BoolField<32, 20> fsc20;  // Filter scale configuration
        BoolField<32, 21> fsc21;  // Filter scale configuration
        BoolField<32, 22> fsc22;  // Filter scale configuration
        BoolField<32, 23> fsc23;  // Filter scale configuration
        BoolField<32, 24> fsc24;  // Filter scale configuration
        BoolField<32, 25> fsc25;  // Filter scale configuration
        BoolField<32, 26> fsc26;  // Filter scale configuration
        BoolField<32, 27> fsc27;  // Filter scale configuration
    };

    union Can_ffa1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_ffa1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> ffa0;  // Filter FIFO assignment for filter 0
        BoolField<32, 1> ffa1;  // Filter FIFO assignment for filter 1
        BoolField<32, 2> ffa2;  // Filter FIFO assignment for filter 2
        BoolField<32, 3> ffa3;  // Filter FIFO assignment for filter 3
        BoolField<32, 4> ffa4;  // Filter FIFO assignment for filter 4
        BoolField<32, 5> ffa5;  // Filter FIFO assignment for filter 5
        BoolField<32, 6> ffa6;  // Filter FIFO assignment for filter 6
        BoolField<32, 7> ffa7;  // Filter FIFO assignment for filter 7
        BoolField<32, 8> ffa8;  // Filter FIFO assignment for filter 8
        BoolField<32, 9> ffa9;  // Filter FIFO assignment for filter 9
        BoolField<32, 10> ffa10;  // Filter FIFO assignment for filter 10
        BoolField<32, 11> ffa11;  // Filter FIFO assignment for filter 11
        BoolField<32, 12> ffa12;  // Filter FIFO assignment for filter 12
        BoolField<32, 13> ffa13;  // Filter FIFO assignment for filter 13
        BoolField<32, 14> ffa14;  // Filter FIFO assignment for filter 14
        BoolField<32, 15> ffa15;  // Filter FIFO assignment for filter 15
        BoolField<32, 16> ffa16;  // Filter FIFO assignment for filter 16
        BoolField<32, 17> ffa17;  // Filter FIFO assignment for filter 17
        BoolField<32, 18> ffa18;  // Filter FIFO assignment for filter 18
        BoolField<32, 19> ffa19;  // Filter FIFO assignment for filter 19
        BoolField<32, 20> ffa20;  // Filter FIFO assignment for filter 20
        BoolField<32, 21> ffa21;  // Filter FIFO assignment for filter 21
        BoolField<32, 22> ffa22;  // Filter FIFO assignment for filter 22
        BoolField<32, 23> ffa23;  // Filter FIFO assignment for filter 23
        BoolField<32, 24> ffa24;  // Filter FIFO assignment for filter 24
        BoolField<32, 25> ffa25;  // Filter FIFO assignment for filter 25
        BoolField<32, 26> ffa26;  // Filter FIFO assignment for filter 26
        BoolField<32, 27> ffa27;  // Filter FIFO assignment for filter 27
    };

    union Can_fa1r {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Can_fa1r() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fact0;  // Filter active
        BoolField<32, 1> fact1;  // Filter active
        BoolField<32, 2> fact2;  // Filter active
        BoolField<32, 3> fact3;  // Filter active
        BoolField<32, 4> fact4;  // Filter active
        BoolField<32, 5> fact5;  // Filter active
        BoolField<32, 6> fact6;  // Filter active
        BoolField<32, 7> fact7;  // Filter active
        BoolField<32, 8> fact8;  // Filter active
        BoolField<32, 9> fact9;  // Filter active
        BoolField<32, 10> fact10;  // Filter active
        BoolField<32, 11> fact11;  // Filter active
        BoolField<32, 12> fact12;  // Filter active
        BoolField<32, 13> fact13;  // Filter active
        BoolField<32, 14> fact14;  // Filter active
        BoolField<32, 15> fact15;  // Filter active
        BoolField<32, 16> fact16;  // Filter active
        BoolField<32, 17> fact17;  // Filter active
        BoolField<32, 18> fact18;  // Filter active
        BoolField<32, 19> fact19;  // Filter active
        BoolField<32, 20> fact20;  // Filter active
        BoolField<32, 21> fact21;  // Filter active
        BoolField<32, 22> fact22;  // Filter active
        BoolField<32, 23> fact23;  // Filter active
        BoolField<32, 24> fact24;  // Filter active
        BoolField<32, 25> fact25;  // Filter active
        BoolField<32, 26> fact26;  // Filter active
        BoolField<32, 27> fact27;  // Filter active
    };

    union F0r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F0r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F0r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F0r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F1r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F1r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F1r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F1r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F2r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F2r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F2r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F2r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F3r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F3r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F3r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F3r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F4r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F4r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F4r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F4r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F5r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F5r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F5r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F5r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F6r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F6r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F6r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F6r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F7r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F7r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F7r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F7r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F8r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F8r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F8r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F8r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F9r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F9r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F9r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F9r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F10r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F10r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F10r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F10r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F11r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F11r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F11r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F11r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F12r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F12r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F12r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F12r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F13r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F13r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F13r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F13r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F14r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F14r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F14r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F14r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F15r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F15r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F15r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F15r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F16r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F16r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F16r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F16r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F17r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F17r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F17r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F17r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F18r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F18r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F18r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F18r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F19r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F19r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F19r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F19r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F20r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F20r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F20r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F20r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F21r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F21r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F21r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F21r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F22r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F22r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F22r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F22r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F23r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F23r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F23r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F23r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F24r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F24r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F24r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F24r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F25r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F25r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F25r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F25r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F26r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F26r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F26r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F26r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F27r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F27r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    union F27r2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr F27r2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> fb0;  // Filter bits
        BoolField<32, 1> fb1;  // Filter bits
        BoolField<32, 2> fb2;  // Filter bits
        BoolField<32, 3> fb3;  // Filter bits
        BoolField<32, 4> fb4;  // Filter bits
        BoolField<32, 5> fb5;  // Filter bits
        BoolField<32, 6> fb6;  // Filter bits
        BoolField<32, 7> fb7;  // Filter bits
        BoolField<32, 8> fb8;  // Filter bits
        BoolField<32, 9> fb9;  // Filter bits
        BoolField<32, 10> fb10;  // Filter bits
        BoolField<32, 11> fb11;  // Filter bits
        BoolField<32, 12> fb12;  // Filter bits
        BoolField<32, 13> fb13;  // Filter bits
        BoolField<32, 14> fb14;  // Filter bits
        BoolField<32, 15> fb15;  // Filter bits
        BoolField<32, 16> fb16;  // Filter bits
        BoolField<32, 17> fb17;  // Filter bits
        BoolField<32, 18> fb18;  // Filter bits
        BoolField<32, 19> fb19;  // Filter bits
        BoolField<32, 20> fb20;  // Filter bits
        BoolField<32, 21> fb21;  // Filter bits
        BoolField<32, 22> fb22;  // Filter bits
        BoolField<32, 23> fb23;  // Filter bits
        BoolField<32, 24> fb24;  // Filter bits
        BoolField<32, 25> fb25;  // Filter bits
        BoolField<32, 26> fb26;  // Filter bits
        BoolField<32, 27> fb27;  // Filter bits
        BoolField<32, 28> fb28;  // Filter bits
        BoolField<32, 29> fb29;  // Filter bits
        BoolField<32, 30> fb30;  // Filter bits
        BoolField<32, 31> fb31;  // Filter bits
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Can_mcr can_mcr; // [+0x0] CAN_MCR
    Can_msr can_msr; // [+0x4] CAN_MSR
    Can_tsr can_tsr; // [+0x8] CAN_TSR
    Can_rf0r can_rf0r; // [+0xC] CAN_RF0R
    Can_rf1r can_rf1r; // [+0x10] CAN_RF1R
    Can_ier can_ier; // [+0x14] CAN_IER
    Can_esr can_esr; // [+0x18] CAN_ESR
    Can_btr can_btr; // [+0x1C] CAN_BTR
    uint32_t __padding_20_17C[88]; // [+0x20 - 0x17C] Padding for alignment
    Can_ti0r can_ti0r; // [+0x180] CAN_TI0R
    Can_tdt0r can_tdt0r; // [+0x184] CAN_TDT0R
    Can_tdl0r can_tdl0r; // [+0x188] CAN_TDL0R
    Can_tdh0r can_tdh0r; // [+0x18C] CAN_TDH0R
    Can_ti1r can_ti1r; // [+0x190] CAN_TI1R
    Can_tdt1r can_tdt1r; // [+0x194] CAN_TDT1R
    Can_tdl1r can_tdl1r; // [+0x198] CAN_TDL1R
    Can_tdh1r can_tdh1r; // [+0x19C] CAN_TDH1R
    Can_ti2r can_ti2r; // [+0x1A0] CAN_TI2R
    Can_tdt2r can_tdt2r; // [+0x1A4] CAN_TDT2R
    Can_tdl2r can_tdl2r; // [+0x1A8] CAN_TDL2R
    Can_tdh2r can_tdh2r; // [+0x1AC] CAN_TDH2R
    Can_ri0r can_ri0r; // [+0x1B0] CAN_RI0R
    Can_rdt0r can_rdt0r; // [+0x1B4] CAN_RDT0R
    Can_rdl0r can_rdl0r; // [+0x1B8] CAN_RDL0R
    Can_rdh0r can_rdh0r; // [+0x1BC] CAN_RDH0R
    Can_ri1r can_ri1r; // [+0x1C0] CAN_RI1R
    Can_rdt1r can_rdt1r; // [+0x1C4] CAN_RDT1R
    Can_rdl1r can_rdl1r; // [+0x1C8] CAN_RDL1R
    Can_rdh1r can_rdh1r; // [+0x1CC] CAN_RDH1R
    uint32_t __padding_1D0_1FC[12]; // [+0x1D0 - 0x1FC] Padding for alignment
    Can_fmr can_fmr; // [+0x200] CAN_FMR
    Can_fm1r can_fm1r; // [+0x204] CAN_FM1R
    uint32_t __padding_208_208[1]; // [+0x208 - 0x208] Padding for alignment
    Can_fs1r can_fs1r; // [+0x20C] CAN_FS1R
    uint32_t __padding_210_210[1]; // [+0x210 - 0x210] Padding for alignment
    Can_ffa1r can_ffa1r; // [+0x214] CAN_FFA1R
    uint32_t __padding_218_218[1]; // [+0x218 - 0x218] Padding for alignment
    Can_fa1r can_fa1r; // [+0x21C] CAN_FA1R
    uint32_t __padding_220_23C[8]; // [+0x220 - 0x23C] Padding for alignment
    F0r1 f0r1; // [+0x240] Filter bank 0 register 1
    F0r2 f0r2; // [+0x244] Filter bank 0 register 2
    F1r1 f1r1; // [+0x248] Filter bank 1 register 1
    F1r2 f1r2; // [+0x24C] Filter bank 1 register 2
    F2r1 f2r1; // [+0x250] Filter bank 2 register 1
    F2r2 f2r2; // [+0x254] Filter bank 2 register 2
    F3r1 f3r1; // [+0x258] Filter bank 3 register 1
    F3r2 f3r2; // [+0x25C] Filter bank 3 register 2
    F4r1 f4r1; // [+0x260] Filter bank 4 register 1
    F4r2 f4r2; // [+0x264] Filter bank 4 register 2
    F5r1 f5r1; // [+0x268] Filter bank 5 register 1
    F5r2 f5r2; // [+0x26C] Filter bank 5 register 2
    F6r1 f6r1; // [+0x270] Filter bank 6 register 1
    F6r2 f6r2; // [+0x274] Filter bank 6 register 2
    F7r1 f7r1; // [+0x278] Filter bank 7 register 1
    F7r2 f7r2; // [+0x27C] Filter bank 7 register 2
    F8r1 f8r1; // [+0x280] Filter bank 8 register 1
    F8r2 f8r2; // [+0x284] Filter bank 8 register 2
    F9r1 f9r1; // [+0x288] Filter bank 9 register 1
    F9r2 f9r2; // [+0x28C] Filter bank 9 register 2
    F10r1 f10r1; // [+0x290] Filter bank 10 register 1
    F10r2 f10r2; // [+0x294] Filter bank 10 register 2
    F11r1 f11r1; // [+0x298] Filter bank 11 register 1
    F11r2 f11r2; // [+0x29C] Filter bank 11 register 2
    F12r1 f12r1; // [+0x2A0] Filter bank 4 register 1
    F12r2 f12r2; // [+0x2A4] Filter bank 12 register 2
    F13r1 f13r1; // [+0x2A8] Filter bank 13 register 1
    F13r2 f13r2; // [+0x2AC] Filter bank 13 register 2
    F14r1 f14r1; // [+0x2B0] Filter bank 14 register 1
    F14r2 f14r2; // [+0x2B4] Filter bank 14 register 2
    F15r1 f15r1; // [+0x2B8] Filter bank 15 register 1
    F15r2 f15r2; // [+0x2BC] Filter bank 15 register 2
    F16r1 f16r1; // [+0x2C0] Filter bank 16 register 1
    F16r2 f16r2; // [+0x2C4] Filter bank 16 register 2
    F17r1 f17r1; // [+0x2C8] Filter bank 17 register 1
    F17r2 f17r2; // [+0x2CC] Filter bank 17 register 2
    F18r1 f18r1; // [+0x2D0] Filter bank 18 register 1
    F18r2 f18r2; // [+0x2D4] Filter bank 18 register 2
    F19r1 f19r1; // [+0x2D8] Filter bank 19 register 1
    F19r2 f19r2; // [+0x2DC] Filter bank 19 register 2
    F20r1 f20r1; // [+0x2E0] Filter bank 20 register 1
    F20r2 f20r2; // [+0x2E4] Filter bank 20 register 2
    F21r1 f21r1; // [+0x2E8] Filter bank 21 register 1
    F21r2 f21r2; // [+0x2EC] Filter bank 21 register 2
    F22r1 f22r1; // [+0x2F0] Filter bank 22 register 1
    F22r2 f22r2; // [+0x2F4] Filter bank 22 register 2
    F23r1 f23r1; // [+0x2F8] Filter bank 23 register 1
    F23r2 f23r2; // [+0x2FC] Filter bank 23 register 2
    F24r1 f24r1; // [+0x300] Filter bank 24 register 1
    F24r2 f24r2; // [+0x304] Filter bank 24 register 2
    F25r1 f25r1; // [+0x308] Filter bank 25 register 1
    F25r2 f25r2; // [+0x30C] Filter bank 25 register 2
    F26r1 f26r1; // [+0x310] Filter bank 26 register 1
    F26r2 f26r2; // [+0x314] Filter bank 26 register 2
    F27r1 f27r1; // [+0x318] Filter bank 27 register 1
    F27r2 f27r2; // [+0x31C] Filter bank 27 register 2

}; // Can registers


// Syscfg registers
struct Syscfg {
    ////////////////////////////////////////////////////////////////////////////
    union Cfgr1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cfgr1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 1, 0> mem_mode;
        BoolField<32, 8> adc_dma_rmp;  // ADC DMA remapping bit
        BoolField<32, 9> usart1_tx_dma_rmp;  // USART1_TX DMA remapping bit
        BoolField<32, 10> usart1_rx_dma_rmp;  // USART1_RX DMA request remapping bit
        BoolField<32, 11> tim16_dma_rmp;  // TIM16 DMA request remapping bit
        BoolField<32, 12> tim17_dma_rmp;  // TIM17 DMA request remapping bit
        BoolField<32, 16> i2c_pb6_fm;  // Fast Mode Plus (FM plus) driving capability activation bits.
        BoolField<32, 17> i2c_pb7_fm;  // Fast Mode Plus (FM+) driving capability activation bits.
        BoolField<32, 18> i2c_pb8_fm;  // Fast Mode Plus (FM+) driving capability activation bits.
        BoolField<32, 19> i2c_pb9_fm;  // Fast Mode Plus (FM+) driving capability activation bits.
        BoolField<32, 20> i2c1_fm_plus;  // FM+ driving capability activation for I2C1
        BoolField<32, 21> i2c2_fm_plus;  // FM+ driving capability activation for I2C2
        BoolField<32, 24> spi2_dma_rmp;  // SPI2 DMA request remapping bit
        BoolField<32, 25> usart2_dma_rmp;  // USART2 DMA request remapping bit
        BoolField<32, 26> usart3_dma_rmp;  // USART3 DMA request remapping bit
        BoolField<32, 27> i2c1_dma_rmp;  // I2C1 DMA request remapping bit
        BoolField<32, 28> tim1_dma_rmp;  // TIM1 DMA request remapping bit
        BoolField<32, 29> tim2_dma_rmp;  // TIM2 DMA request remapping bit
        BoolField<32, 30> tim3_dma_rmp;  // TIM3 DMA request remapping bit
    };

    union Exticr1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Exticr1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 12> exti3;
        BitField<32, 11, 8> exti2;
        BitField<32, 7, 4> exti1;
        BitField<32, 3, 0> exti0;
    };

    union Exticr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Exticr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 12> exti7;
        BitField<32, 11, 8> exti6;
        BitField<32, 7, 4> exti5;
        BitField<32, 3, 0> exti4;
    };

    union Exticr3 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Exticr3() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 12> exti11;
        BitField<32, 11, 8> exti10;
        BitField<32, 7, 4> exti9;
        BitField<32, 3, 0> exti8;
    };

    union Exticr4 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Exticr4() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 12> exti15;
        BitField<32, 11, 8> exti14;
        BitField<32, 7, 4> exti13;
        BitField<32, 3, 0> exti12;
    };

    union Cfgr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cfgr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 8> sram_pef;  // SRAM parity flag
        BoolField<32, 2> pvd_lock;  // PVD lock enable bit
        BoolField<32, 1> sram_parity_lock;  // SRAM parity lock bit
        BoolField<32, 0> locup_lock;  // Cortex-M0 LOCKUP bit enable bit
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cfgr1 cfgr1; // [+0x0] configuration register 1
    uint32_t __padding_4_4[1]; // [+0x4 - 0x4] Padding for alignment
    Exticr1 exticr1; // [+0x8] external interrupt configuration register 1
    Exticr2 exticr2; // [+0xC] external interrupt configuration register 2
    Exticr3 exticr3; // [+0x10] external interrupt configuration register 3
    Exticr4 exticr4; // [+0x14] external interrupt configuration register 4
    Cfgr2 cfgr2; // [+0x18] configuration register 2

}; // Syscfg registers


// Gpio registers
struct Gpio {
    ////////////////////////////////////////////////////////////////////////////
    union Moder {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Moder() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 30> moder15;
        BitField<32, 29, 28> moder14;
        BitField<32, 27, 26> moder13;
        BitField<32, 25, 24> moder12;
        BitField<32, 23, 22> moder11;
        BitField<32, 21, 20> moder10;
        BitField<32, 19, 18> moder9;
        BitField<32, 17, 16> moder8;
        BitField<32, 15, 14> moder7;
        BitField<32, 13, 12> moder6;
        BitField<32, 11, 10> moder5;
        BitField<32, 9, 8> moder4;
        BitField<32, 7, 6> moder3;
        BitField<32, 5, 4> moder2;
        BitField<32, 3, 2> moder1;
        BitField<32, 1, 0> moder0;
    };

    union Otyper {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Otyper() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 15> ot15;  // Port x configuration bit 15
        BoolField<32, 14> ot14;  // Port x configuration bit 14
        BoolField<32, 13> ot13;  // Port x configuration bit 13
        BoolField<32, 12> ot12;  // Port x configuration bit 12
        BoolField<32, 11> ot11;  // Port x configuration bit 11
        BoolField<32, 10> ot10;  // Port x configuration bit 10
        BoolField<32, 9> ot9;  // Port x configuration bit 9
        BoolField<32, 8> ot8;  // Port x configuration bit 8
        BoolField<32, 7> ot7;  // Port x configuration bit 7
        BoolField<32, 6> ot6;  // Port x configuration bit 6
        BoolField<32, 5> ot5;  // Port x configuration bit 5
        BoolField<32, 4> ot4;  // Port x configuration bit 4
        BoolField<32, 3> ot3;  // Port x configuration bit 3
        BoolField<32, 2> ot2;  // Port x configuration bit 2
        BoolField<32, 1> ot1;  // Port x configuration bit 1
        BoolField<32, 0> ot0;  // Port x configuration bit 0
    };

    union Ospeedr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ospeedr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 30> ospeedr15;
        BitField<32, 29, 28> ospeedr14;
        BitField<32, 27, 26> ospeedr13;
        BitField<32, 25, 24> ospeedr12;
        BitField<32, 23, 22> ospeedr11;
        BitField<32, 21, 20> ospeedr10;
        BitField<32, 19, 18> ospeedr9;
        BitField<32, 17, 16> ospeedr8;
        BitField<32, 15, 14> ospeedr7;
        BitField<32, 13, 12> ospeedr6;
        BitField<32, 11, 10> ospeedr5;
        BitField<32, 9, 8> ospeedr4;
        BitField<32, 7, 6> ospeedr3;
        BitField<32, 5, 4> ospeedr2;
        BitField<32, 3, 2> ospeedr1;
        BitField<32, 1, 0> ospeedr0;
    };

    union Pupdr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Pupdr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 30> pupdr15;
        BitField<32, 29, 28> pupdr14;
        BitField<32, 27, 26> pupdr13;
        BitField<32, 25, 24> pupdr12;
        BitField<32, 23, 22> pupdr11;
        BitField<32, 21, 20> pupdr10;
        BitField<32, 19, 18> pupdr9;
        BitField<32, 17, 16> pupdr8;
        BitField<32, 15, 14> pupdr7;
        BitField<32, 13, 12> pupdr6;
        BitField<32, 11, 10> pupdr5;
        BitField<32, 9, 8> pupdr4;
        BitField<32, 7, 6> pupdr3;
        BitField<32, 5, 4> pupdr2;
        BitField<32, 3, 2> pupdr1;
        BitField<32, 1, 0> pupdr0;
    };

    union Idr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Idr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 15> idr15;  // Port input data (y = 0..15)
        BoolField<32, 14> idr14;  // Port input data (y = 0..15)
        BoolField<32, 13> idr13;  // Port input data (y = 0..15)
        BoolField<32, 12> idr12;  // Port input data (y = 0..15)
        BoolField<32, 11> idr11;  // Port input data (y = 0..15)
        BoolField<32, 10> idr10;  // Port input data (y = 0..15)
        BoolField<32, 9> idr9;  // Port input data (y = 0..15)
        BoolField<32, 8> idr8;  // Port input data (y = 0..15)
        BoolField<32, 7> idr7;  // Port input data (y = 0..15)
        BoolField<32, 6> idr6;  // Port input data (y = 0..15)
        BoolField<32, 5> idr5;  // Port input data (y = 0..15)
        BoolField<32, 4> idr4;  // Port input data (y = 0..15)
        BoolField<32, 3> idr3;  // Port input data (y = 0..15)
        BoolField<32, 2> idr2;  // Port input data (y = 0..15)
        BoolField<32, 1> idr1;  // Port input data (y = 0..15)
        BoolField<32, 0> idr0;  // Port input data (y = 0..15)
    };

    union Odr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Odr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 15> odr15;  // Port output data (y = 0..15)
        BoolField<32, 14> odr14;  // Port output data (y = 0..15)
        BoolField<32, 13> odr13;  // Port output data (y = 0..15)
        BoolField<32, 12> odr12;  // Port output data (y = 0..15)
        BoolField<32, 11> odr11;  // Port output data (y = 0..15)
        BoolField<32, 10> odr10;  // Port output data (y = 0..15)
        BoolField<32, 9> odr9;  // Port output data (y = 0..15)
        BoolField<32, 8> odr8;  // Port output data (y = 0..15)
        BoolField<32, 7> odr7;  // Port output data (y = 0..15)
        BoolField<32, 6> odr6;  // Port output data (y = 0..15)
        BoolField<32, 5> odr5;  // Port output data (y = 0..15)
        BoolField<32, 4> odr4;  // Port output data (y = 0..15)
        BoolField<32, 3> odr3;  // Port output data (y = 0..15)
        BoolField<32, 2> odr2;  // Port output data (y = 0..15)
        BoolField<32, 1> odr1;  // Port output data (y = 0..15)
        BoolField<32, 0> odr0;  // Port output data (y = 0..15)
    };

    union Bsrr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Bsrr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 31> br15;  // Port x reset bit y (y = 0..15)
        BoolField<32, 30> br14;  // Port x reset bit y (y = 0..15)
        BoolField<32, 29> br13;  // Port x reset bit y (y = 0..15)
        BoolField<32, 28> br12;  // Port x reset bit y (y = 0..15)
        BoolField<32, 27> br11;  // Port x reset bit y (y = 0..15)
        BoolField<32, 26> br10;  // Port x reset bit y (y = 0..15)
        BoolField<32, 25> br9;  // Port x reset bit y (y = 0..15)
        BoolField<32, 24> br8;  // Port x reset bit y (y = 0..15)
        BoolField<32, 23> br7;  // Port x reset bit y (y = 0..15)
        BoolField<32, 22> br6;  // Port x reset bit y (y = 0..15)
        BoolField<32, 21> br5;  // Port x reset bit y (y = 0..15)
        BoolField<32, 20> br4;  // Port x reset bit y (y = 0..15)
        BoolField<32, 19> br3;  // Port x reset bit y (y = 0..15)
        BoolField<32, 18> br2;  // Port x reset bit y (y = 0..15)
        BoolField<32, 17> br1;  // Port x reset bit y (y = 0..15)
        BoolField<32, 16> br0;  // Port x set bit y (y= 0..15)
        BoolField<32, 15> bs15;  // Port x set bit y (y= 0..15)
        BoolField<32, 14> bs14;  // Port x set bit y (y= 0..15)
        BoolField<32, 13> bs13;  // Port x set bit y (y= 0..15)
        BoolField<32, 12> bs12;  // Port x set bit y (y= 0..15)
        BoolField<32, 11> bs11;  // Port x set bit y (y= 0..15)
        BoolField<32, 10> bs10;  // Port x set bit y (y= 0..15)
        BoolField<32, 9> bs9;  // Port x set bit y (y= 0..15)
        BoolField<32, 8> bs8;  // Port x set bit y (y= 0..15)
        BoolField<32, 7> bs7;  // Port x set bit y (y= 0..15)
        BoolField<32, 6> bs6;  // Port x set bit y (y= 0..15)
        BoolField<32, 5> bs5;  // Port x set bit y (y= 0..15)
        BoolField<32, 4> bs4;  // Port x set bit y (y= 0..15)
        BoolField<32, 3> bs3;  // Port x set bit y (y= 0..15)
        BoolField<32, 2> bs2;  // Port x set bit y (y= 0..15)
        BoolField<32, 1> bs1;  // Port x set bit y (y= 0..15)
        BoolField<32, 0> bs0;  // Port x set bit y (y= 0..15)
    };

    union Lckr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Lckr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 16> lckk;  // Port x lock bit y
        BoolField<32, 15> lck15;  // Port x lock bit y (y= 0..15)
        BoolField<32, 14> lck14;  // Port x lock bit y (y= 0..15)
        BoolField<32, 13> lck13;  // Port x lock bit y (y= 0..15)
        BoolField<32, 12> lck12;  // Port x lock bit y (y= 0..15)
        BoolField<32, 11> lck11;  // Port x lock bit y (y= 0..15)
        BoolField<32, 10> lck10;  // Port x lock bit y (y= 0..15)
        BoolField<32, 9> lck9;  // Port x lock bit y (y= 0..15)
        BoolField<32, 8> lck8;  // Port x lock bit y (y= 0..15)
        BoolField<32, 7> lck7;  // Port x lock bit y (y= 0..15)
        BoolField<32, 6> lck6;  // Port x lock bit y (y= 0..15)
        BoolField<32, 5> lck5;  // Port x lock bit y (y= 0..15)
        BoolField<32, 4> lck4;  // Port x lock bit y (y= 0..15)
        BoolField<32, 3> lck3;  // Port x lock bit y (y= 0..15)
        BoolField<32, 2> lck2;  // Port x lock bit y (y= 0..15)
        BoolField<32, 1> lck1;  // Port x lock bit y (y= 0..15)
        BoolField<32, 0> lck0;  // Port x lock bit y (y= 0..15)
    };

    union Afrl {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Afrl() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 28> afrl7;
        BitField<32, 27, 24> afrl6;
        BitField<32, 23, 20> afrl5;
        BitField<32, 19, 16> afrl4;
        BitField<32, 15, 12> afrl3;
        BitField<32, 11, 8> afrl2;
        BitField<32, 7, 4> afrl1;
        BitField<32, 3, 0> afrl0;
    };

    union Afrh {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Afrh() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 28> afrh15;
        BitField<32, 27, 24> afrh14;
        BitField<32, 23, 20> afrh13;
        BitField<32, 19, 16> afrh12;
        BitField<32, 15, 12> afrh11;
        BitField<32, 11, 8> afrh10;
        BitField<32, 7, 4> afrh9;
        BitField<32, 3, 0> afrh8;
    };

    union Brr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Brr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> br0;  // Port x Reset bit y
        BoolField<32, 1> br1;  // Port x Reset bit y
        BoolField<32, 2> br2;  // Port x Reset bit y
        BoolField<32, 3> br3;  // Port x Reset bit y
        BoolField<32, 4> br4;  // Port x Reset bit y
        BoolField<32, 5> br5;  // Port x Reset bit y
        BoolField<32, 6> br6;  // Port x Reset bit y
        BoolField<32, 7> br7;  // Port x Reset bit y
        BoolField<32, 8> br8;  // Port x Reset bit y
        BoolField<32, 9> br9;  // Port x Reset bit y
        BoolField<32, 10> br10;  // Port x Reset bit y
        BoolField<32, 11> br11;  // Port x Reset bit y
        BoolField<32, 12> br12;  // Port x Reset bit y
        BoolField<32, 13> br13;  // Port x Reset bit y
        BoolField<32, 14> br14;  // Port x Reset bit y
        BoolField<32, 15> br15;  // Port x Reset bit y
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Moder moder; // [+0x0] GPIO port mode register
    Otyper otyper; // [+0x4] GPIO port output type register
    Ospeedr ospeedr; // [+0x8] GPIO port output speed register
    Pupdr pupdr; // [+0xC] GPIO port pull-up/pull-down register
    Idr idr; // [+0x10] GPIO port input data register
    Odr odr; // [+0x14] GPIO port output data register
    Bsrr bsrr; // [+0x18] GPIO port bit set/reset register
    Lckr lckr; // [+0x1C] GPIO port configuration lock register
    Afrl afrl; // [+0x20] GPIO alternate function low register
    Afrh afrh; // [+0x24] GPIO alternate function high register
    Brr brr; // [+0x28] Port bit reset register

}; // Gpio registers


// Rcc registers
struct Rcc {
    ////////////////////////////////////////////////////////////////////////////
    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000083;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> hsion;  // Internal High Speed clock enable
        BoolField<32, 1> hsirdy;  // Internal High Speed clock ready flag
        BitField<32, 7, 3> hsitrim;
        BitField<32, 15, 8> hsical;
        BoolField<32, 16> hseon;  // External High Speed clock enable
        BoolField<32, 17> hserdy;  // External High Speed clock ready flag
        BoolField<32, 18> hsebyp;  // External High Speed clock Bypass
        BoolField<32, 19> csson;  // Clock Security System enable
        BoolField<32, 24> pllon;  // PLL enable
        BoolField<32, 25> pllrdy;  // PLL clock ready flag
    };

    union Cfgr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cfgr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 1, 0> sw;
        BitField<32, 3, 2> sws;
        BitField<32, 7, 4> hpre;
        BitField<32, 10, 8> ppre;
        BoolField<32, 14> adcpre;  // ADC prescaler
        BitField<32, 16, 15> pllsrc;
        BoolField<32, 17> pllxtpre;  // HSE divider for PLL entry
        BitField<32, 21, 18> pllmul;
        BitField<32, 26, 24> mco;
        BitField<32, 30, 28> mcopre;
        BoolField<32, 31> pllnodiv;  // PLL clock not divided for MCO
    };

    union Cir {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cir() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> lsirdyf;  // LSI Ready Interrupt flag
        BoolField<32, 1> lserdyf;  // LSE Ready Interrupt flag
        BoolField<32, 2> hsirdyf;  // HSI Ready Interrupt flag
        BoolField<32, 3> hserdyf;  // HSE Ready Interrupt flag
        BoolField<32, 4> pllrdyf;  // PLL Ready Interrupt flag
        BoolField<32, 5> hsi14rdyf;  // HSI14 ready interrupt flag
        BoolField<32, 6> hsi48rdyf;  // HSI48 ready interrupt flag
        BoolField<32, 7> cssf;  // Clock Security System Interrupt flag
        BoolField<32, 8> lsirdyie;  // LSI Ready Interrupt Enable
        BoolField<32, 9> lserdyie;  // LSE Ready Interrupt Enable
        BoolField<32, 10> hsirdyie;  // HSI Ready Interrupt Enable
        BoolField<32, 11> hserdyie;  // HSE Ready Interrupt Enable
        BoolField<32, 12> pllrdyie;  // PLL Ready Interrupt Enable
        BoolField<32, 13> hsi14rdye;  // HSI14 ready interrupt enable
        BoolField<32, 14> hsi48rdyie;  // HSI48 ready interrupt enable
        BoolField<32, 16> lsirdyc;  // LSI Ready Interrupt Clear
        BoolField<32, 17> lserdyc;  // LSE Ready Interrupt Clear
        BoolField<32, 18> hsirdyc;  // HSI Ready Interrupt Clear
        BoolField<32, 19> hserdyc;  // HSE Ready Interrupt Clear
        BoolField<32, 20> pllrdyc;  // PLL Ready Interrupt Clear
        BoolField<32, 21> hsi14rdyc;  // HSI 14 MHz Ready Interrupt Clear
        BoolField<32, 22> hsi48rdyc;  // HSI48 Ready Interrupt Clear
        BoolField<32, 23> cssc;  // Clock security system interrupt clear
    };

    union Apb2rstr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Apb2rstr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> syscfgrst;  // SYSCFG and COMP reset
        BoolField<32, 9> adcrst;  // ADC interface reset
        BoolField<32, 11> tim1rst;  // TIM1 timer reset
        BoolField<32, 12> spi1rst;  // SPI 1 reset
        BoolField<32, 14> usart1rst;  // USART1 reset
        BoolField<32, 16> tim15rst;  // TIM15 timer reset
        BoolField<32, 17> tim16rst;  // TIM16 timer reset
        BoolField<32, 18> tim17rst;  // TIM17 timer reset
        BoolField<32, 22> dbgmcurst;  // Debug MCU reset
    };

    union Apb1rstr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Apb1rstr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> tim2rst;  // Timer 2 reset
        BoolField<32, 1> tim3rst;  // Timer 3 reset
        BoolField<32, 4> tim6rst;  // Timer 6 reset
        BoolField<32, 5> tim7rst;  // TIM7 timer reset
        BoolField<32, 8> tim14rst;  // Timer 14 reset
        BoolField<32, 11> wwdgrst;  // Window watchdog reset
        BoolField<32, 14> spi2rst;  // SPI2 reset
        BoolField<32, 17> usart2rst;  // USART 2 reset
        BoolField<32, 18> usart3rst;  // USART3 reset
        BoolField<32, 19> usart4rst;  // USART4 reset
        BoolField<32, 21> i2c1rst;  // I2C1 reset
        BoolField<32, 22> i2c2rst;  // I2C2 reset
        BoolField<32, 23> usbrst;  // USB interface reset
        BoolField<32, 25> canrst;  // CAN interface reset
        BoolField<32, 27> crsrst;  // Clock Recovery System interface reset
        BoolField<32, 28> pwrrst;  // Power interface reset
        BoolField<32, 29> dacrst;  // DAC interface reset
        BoolField<32, 30> cecrst;  // HDMI CEC reset
    };

    union Ahbenr {
    public:
        constexpr static uint32_t kResetValue = 0x00000014;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ahbenr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> dmaen;  // DMA1 clock enable
        BoolField<32, 2> sramen;  // SRAM interface clock enable
        BoolField<32, 4> flitfen;  // FLITF clock enable
        BoolField<32, 6> crcen;  // CRC clock enable
        BoolField<32, 17> iopaen;  // I/O port A clock enable
        BoolField<32, 18> iopben;  // I/O port B clock enable
        BoolField<32, 19> iopcen;  // I/O port C clock enable
        BoolField<32, 20> iopden;  // I/O port D clock enable
        BoolField<32, 22> iopfen;  // I/O port F clock enable
        BoolField<32, 24> tscen;  // Touch sensing controller clock enable
    };

    union Apb2enr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Apb2enr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> syscfgen;  // SYSCFG clock enable
        BoolField<32, 9> adcen;  // ADC 1 interface clock enable
        BoolField<32, 11> tim1en;  // TIM1 Timer clock enable
        BoolField<32, 12> spi1en;  // SPI 1 clock enable
        BoolField<32, 14> usart1en;  // USART1 clock enable
        BoolField<32, 16> tim15en;  // TIM15 timer clock enable
        BoolField<32, 17> tim16en;  // TIM16 timer clock enable
        BoolField<32, 18> tim17en;  // TIM17 timer clock enable
        BoolField<32, 22> dbgmcuen;  // MCU debug module clock enable
    };

    union Apb1enr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Apb1enr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> tim2en;  // Timer 2 clock enable
        BoolField<32, 1> tim3en;  // Timer 3 clock enable
        BoolField<32, 4> tim6en;  // Timer 6 clock enable
        BoolField<32, 5> tim7en;  // TIM7 timer clock enable
        BoolField<32, 8> tim14en;  // Timer 14 clock enable
        BoolField<32, 11> wwdgen;  // Window watchdog clock enable
        BoolField<32, 14> spi2en;  // SPI 2 clock enable
        BoolField<32, 17> usart2en;  // USART 2 clock enable
        BoolField<32, 18> usart3en;  // USART3 clock enable
        BoolField<32, 19> usart4en;  // USART4 clock enable
        BoolField<32, 21> i2c1en;  // I2C 1 clock enable
        BoolField<32, 22> i2c2en;  // I2C 2 clock enable
        BoolField<32, 23> usbrst;  // USB interface clock enable
        BoolField<32, 25> canen;  // CAN interface clock enable
        BoolField<32, 27> crsen;  // Clock Recovery System interface clock enable
        BoolField<32, 28> pwren;  // Power interface clock enable
        BoolField<32, 29> dacen;  // DAC interface clock enable
        BoolField<32, 30> cecen;  // HDMI CEC interface clock enable
    };

    union Bdcr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Bdcr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> lseon;  // External Low Speed oscillator enable
        BoolField<32, 1> lserdy;  // External Low Speed oscillator ready
        BoolField<32, 2> lsebyp;  // External Low Speed oscillator bypass
        BitField<32, 4, 3> lsedrv;
        BitField<32, 9, 8> rtcsel;
        BoolField<32, 15> rtcen;  // RTC clock enable
        BoolField<32, 16> bdrst;  // Backup domain software reset
    };

    union Csr {
    public:
        constexpr static uint32_t kResetValue = 0x0C000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Csr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> lsion;  // Internal low speed oscillator enable
        BoolField<32, 1> lsirdy;  // Internal low speed oscillator ready
        BoolField<32, 24> rmvf;  // Remove reset flag
        BoolField<32, 25> oblrstf;  // Option byte loader reset flag
        BoolField<32, 26> pinrstf;  // PIN reset flag
        BoolField<32, 27> porrstf;  // POR/PDR reset flag
        BoolField<32, 28> sftrstf;  // Software reset flag
        BoolField<32, 29> iwdgrstf;  // Independent watchdog reset flag
        BoolField<32, 30> wwdgrstf;  // Window watchdog reset flag
        BoolField<32, 31> lpwrrstf;  // Low-power reset flag
    };

    union Ahbrstr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ahbrstr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 17> ioparst;  // I/O port A reset
        BoolField<32, 18> iopbrst;  // I/O port B reset
        BoolField<32, 19> iopcrst;  // I/O port C reset
        BoolField<32, 20> iopdrst;  // I/O port D reset
        BoolField<32, 22> iopfrst;  // I/O port F reset
        BoolField<32, 24> tscrst;  // Touch sensing controller reset
    };

    union Cfgr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cfgr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 3, 0> prediv;
    };

    union Cfgr3 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cfgr3() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 1, 0> usart1sw;
        BoolField<32, 4> i2c1sw;  // I2C1 clock source selection
        BoolField<32, 6> cecsw;  // HDMI CEC clock source selection
        BoolField<32, 7> usbsw;  // USB clock source selection
        BoolField<32, 8> adcsw;  // ADC clock source selection
        BitField<32, 17, 16> usart2sw;
    };

    union Cr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000080;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> hsi14on;  // HSI14 clock enable
        BoolField<32, 1> hsi14rdy;  // HR14 clock ready flag
        BoolField<32, 2> hsi14dis;  // HSI14 clock request from ADC disable
        BitField<32, 7, 3> hsi14trim;
        BitField<32, 15, 8> hsi14cal;
        BoolField<32, 16> hsi48on;  // HSI48 clock enable
        BoolField<32, 17> hsi48rdy;  // HSI48 clock ready flag
        BoolField<32, 24> hsi48cal;  // HSI48 factory clock calibration
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cr cr; // [+0x0] Clock control register
    Cfgr cfgr; // [+0x4] Clock configuration register (RCC_CFGR)
    Cir cir; // [+0x8] Clock interrupt register (RCC_CIR)
    Apb2rstr apb2rstr; // [+0xC] APB2 peripheral reset register (RCC_APB2RSTR)
    Apb1rstr apb1rstr; // [+0x10] APB1 peripheral reset register (RCC_APB1RSTR)
    Ahbenr ahbenr; // [+0x14] AHB Peripheral Clock enable register (RCC_AHBENR)
    Apb2enr apb2enr; // [+0x18] APB2 peripheral clock enable register (RCC_APB2ENR)
    Apb1enr apb1enr; // [+0x1C] APB1 peripheral clock enable register (RCC_APB1ENR)
    Bdcr bdcr; // [+0x20] Backup domain control register (RCC_BDCR)
    Csr csr; // [+0x24] Control/status register (RCC_CSR)
    Ahbrstr ahbrstr; // [+0x28] AHB peripheral reset register
    Cfgr2 cfgr2; // [+0x2C] Clock configuration register 2
    Cfgr3 cfgr3; // [+0x30] Clock configuration register 3
    Cr2 cr2; // [+0x34] Clock control register 2

}; // Rcc registers


// Iwdg registers
struct Iwdg {
    ////////////////////////////////////////////////////////////////////////////
    union Kr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Kr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> key;
    };

    union Pr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Pr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 2, 0> pr;
    };

    union Rlr {
    public:
        constexpr static uint32_t kResetValue = 0x00000FFF;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Rlr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 11, 0> rl;
    };

    union Sr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Sr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> pvu;  // Watchdog prescaler value update
        BoolField<32, 1> rvu;  // Watchdog counter reload value update
        BoolField<32, 2> wvu;  // Watchdog counter window value update
    };

    union Winr {
    public:
        constexpr static uint32_t kResetValue = 0x00000FFF;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Winr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 11, 0> win;
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Kr kr; // [+0x0] Key register
    Pr pr; // [+0x4] Prescaler register
    Rlr rlr; // [+0x8] Reload register
    Sr sr; // [+0xC] Status register
    Winr winr; // [+0x10] Window register

}; // Iwdg registers


// Cec registers
struct Cec {
    ////////////////////////////////////////////////////////////////////////////
    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 2> txeom;  // Tx End Of Message
        BoolField<32, 1> txsom;  // Tx start of message
        BoolField<32, 0> cecen;  // CEC Enable
    };

    union Cfgr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cfgr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 11> lbpegen;  // Generate Error-Bit on Long Bit Period Error
        BoolField<32, 10> bregen;  // Generate error-bit on bit rising error
        BoolField<32, 9> brestp;  // Rx-stop on bit rising error
        BoolField<32, 8> rxtol;  // Rx-Tolerance
        BitField<32, 7, 5> sft;
        BoolField<32, 4> lstn;  // Listen mode
        BitField<32, 3, 0> oar;
    };

    union Txdr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Txdr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 0> txd;
    };

    union Rxdr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Rxdr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 0> rxdr;
    };

    union Isr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Isr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 12> txacke;  // Tx-Missing acknowledge error
        BoolField<32, 11> txerr;  // Tx-Error
        BoolField<32, 10> txudr;  // Tx-Buffer Underrun
        BoolField<32, 9> txend;  // End of Transmission
        BoolField<32, 8> txbr;  // Tx-Byte Request
        BoolField<32, 7> arblst;  // Arbitration Lost
        BoolField<32, 6> rxacke;  // Rx-Missing Acknowledge
        BoolField<32, 5> lbpe;  // Rx-Long Bit Period Error
        BoolField<32, 4> sbpe;  // Rx-Short Bit period error
        BoolField<32, 3> bre;  // Rx-Bit rising error
        BoolField<32, 2> rxovr;  // Rx-Overrun
        BoolField<32, 1> rxend;  // End Of Reception
        BoolField<32, 0> rxbr;  // Rx-Byte Received
    };

    union Ier {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ier() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 12> txackie;  // Tx-Missing Acknowledge Error Interrupt Enable
        BoolField<32, 11> txerrie;  // Tx-Error Interrupt Enable
        BoolField<32, 10> txudrie;  // Tx-Underrun interrupt enable
        BoolField<32, 9> txendie;  // Tx-End of message interrupt enable
        BoolField<32, 8> txbrie;  // Tx-Byte Request Interrupt Enable
        BoolField<32, 7> arblstie;  // Arbitration Lost Interrupt Enable
        BoolField<32, 6> rxackie;  // Rx-Missing Acknowledge Error Interrupt Enable
        BoolField<32, 5> lbpeie;  // Long Bit Period Error Interrupt Enable
        BoolField<32, 4> sbpeie;  // Short Bit Period Error Interrupt Enable
        BoolField<32, 3> breie;  // Bit Rising Error Interrupt Enable
        BoolField<32, 2> rxovrie;  // Rx-Buffer Overrun Interrupt Enable
        BoolField<32, 1> rxendie;  // End Of Reception Interrupt Enable
        BoolField<32, 0> rxbrie;  // Rx-Byte Received Interrupt Enable
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cr cr; // [+0x0] control register
    Cfgr cfgr; // [+0x4] configuration register
    Txdr txdr; // [+0x8] Tx data register
    Rxdr rxdr; // [+0xC] Rx Data Register
    Isr isr; // [+0x10] Interrupt and Status Register
    Ier ier; // [+0x14] interrupt enable register

}; // Cec registers


// Rtc registers
struct Rtc {
    ////////////////////////////////////////////////////////////////////////////
    union Tr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Tr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 22> pm;  // AM/PM notation
        BitField<32, 21, 20> ht;
        BitField<32, 19, 16> hu;
        BitField<32, 14, 12> mnt;
        BitField<32, 11, 8> mnu;
        BitField<32, 6, 4> st;
        BitField<32, 3, 0> su;
    };

    union Dr {
    public:
        constexpr static uint32_t kResetValue = 0x00002101;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Dr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 23, 20> yt;
        BitField<32, 19, 16> yu;
        BitField<32, 15, 13> wdu;
        BoolField<32, 12> mt;  // Month tens in BCD format
        BitField<32, 11, 8> mu;
        BitField<32, 5, 4> dt;
        BitField<32, 3, 0> du;
    };

    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 3> tsedge;  // Time-stamp event active edge
        BoolField<32, 4> refckon;  // RTC_REFIN reference clock detection enable (50 or 60 Hz)
        BoolField<32, 5> bypshad;  // Bypass the shadow registers
        BoolField<32, 6> fmt;  // Hour format
        BoolField<32, 8> alrae;  // Alarm A enable
        BoolField<32, 11> tse;  // timestamp enable
        BoolField<32, 12> alraie;  // Alarm A interrupt enable
        BoolField<32, 15> tsie;  // Time-stamp interrupt enable
        BoolField<32, 16> add1h;  // Add 1 hour (summer time change)
        BoolField<32, 17> sub1h;  // Subtract 1 hour (winter time change)
        BoolField<32, 18> bkp;  // Backup
        BoolField<32, 19> cosel;  // Calibration output selection
        BoolField<32, 20> pol;  // Output polarity
        BitField<32, 22, 21> osel;
        BoolField<32, 23> coe;  // Calibration output enable
    };

    union Isr {
    public:
        constexpr static uint32_t kResetValue = 0x00000007;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Isr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> alrawf;  // Alarm A write flag
        BoolField<32, 3> shpf;  // Shift operation pending
        BoolField<32, 4> inits;  // Initialization status flag
        BoolField<32, 5> rsf;  // Registers synchronization flag
        BoolField<32, 6> initf;  // Initialization flag
        BoolField<32, 7> init;  // Initialization mode
        BoolField<32, 8> alraf;  // Alarm A flag
        BoolField<32, 11> tsf;  // Time-stamp flag
        BoolField<32, 12> tsovf;  // Time-stamp overflow flag
        BoolField<32, 13> tamp1f;  // RTC_TAMP1 detection flag
        BoolField<32, 14> tamp2f;  // RTC_TAMP2 detection flag
        BoolField<32, 16> recalpf;  // Recalibration pending Flag
    };

    union Prer {
    public:
        constexpr static uint32_t kResetValue = 0x007F00FF;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Prer() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 22, 16> prediv_a;
        BitField<32, 14, 0> prediv_s;
    };

    union Alrmar {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Alrmar() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 31> msk4;  // Alarm A date mask
        BoolField<32, 30> wdsel;  // Week day selection
        BitField<32, 29, 28> dt;
        BitField<32, 27, 24> du;
        BoolField<32, 23> msk3;  // Alarm A hours mask
        BoolField<32, 22> pm;  // AM/PM notation
        BitField<32, 21, 20> ht;
        BitField<32, 19, 16> hu;
        BoolField<32, 15> msk2;  // Alarm A minutes mask
        BitField<32, 14, 12> mnt;
        BitField<32, 11, 8> mnu;
        BoolField<32, 7> msk1;  // Alarm A seconds mask
        BitField<32, 6, 4> st;
        BitField<32, 3, 0> su;
    };

    union Wpr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Wpr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 0> key;
    };

    union Ssr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ssr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> ss;
    };

    union Shiftr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Shiftr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 31> add1s;  // Reserved
        BitField<32, 14, 0> subfs;
    };

    union Tstr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Tstr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 22> pm;  // AM/PM notation
        BitField<32, 21, 20> ht;
        BitField<32, 19, 16> hu;
        BitField<32, 14, 12> mnt;
        BitField<32, 11, 8> mnu;
        BitField<32, 6, 4> st;
        BitField<32, 3, 0> su;
    };

    union Tsdr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Tsdr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 13> wdu;
        BoolField<32, 12> mt;  // Month tens in BCD format
        BitField<32, 11, 8> mu;
        BitField<32, 5, 4> dt;
        BitField<32, 3, 0> du;
    };

    union Tsssr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Tsssr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> ss;
    };

    union Calr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Calr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 15> calp;  // Use an 8-second calibration cycle period
        BoolField<32, 14> calw8;  // Use a 16-second calibration cycle period
        BoolField<32, 13> calw16;  // Reserved
        BitField<32, 8, 0> calm;
    };

    union Tafcr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Tafcr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 23> pc15mode;  // PC15 mode
        BoolField<32, 22> pc15value;  // PC15 value
        BoolField<32, 21> pc14mode;  // PC14 mode
        BoolField<32, 20> pc14value;  // PC14 value
        BoolField<32, 19> pc13mode;  // PC13 mode
        BoolField<32, 18> pc13value;  // RTC_ALARM output type/PC13 value
        BoolField<32, 15> tamp_pudis;  // RTC_TAMPx pull-up disable
        BitField<32, 14, 13> tamp_prch;
        BitField<32, 12, 11> tampflt;
        BitField<32, 10, 8> tampfreq;
        BoolField<32, 7> tampts;  // Activate timestamp on tamper detection event
        BoolField<32, 4> tamp2_trg;  // Active level for RTC_TAMP2 input
        BoolField<32, 3> tamp2e;  // RTC_TAMP2 input detection enable
        BoolField<32, 2> tampie;  // Tamper interrupt enable
        BoolField<32, 1> tamp1trg;  // Active level for RTC_TAMP1 input
        BoolField<32, 0> tamp1e;  // RTC_TAMP1 input detection enable
    };

    union Alrmassr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Alrmassr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 27, 24> maskss;
        BitField<32, 14, 0> ss;
    };

    using Bkp0r = uint32_t;

    using Bkp1r = uint32_t;

    using Bkp2r = uint32_t;

    using Bkp3r = uint32_t;

    using Bkp4r = uint32_t;

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Tr tr; // [+0x0] time register
    Dr dr; // [+0x4] date register
    Cr cr; // [+0x8] control register
    Isr isr; // [+0xC] initialization and status register
    Prer prer; // [+0x10] prescaler register
    uint32_t __padding_14_18[2]; // [+0x14 - 0x18] Padding for alignment
    Alrmar alrmar; // [+0x1C] alarm A register
    uint32_t __padding_20_20[1]; // [+0x20 - 0x20] Padding for alignment
    Wpr wpr; // [+0x24] write protection register
    Ssr ssr; // [+0x28] sub second register
    Shiftr shiftr; // [+0x2C] shift control register
    Tstr tstr; // [+0x30] timestamp time register
    Tsdr tsdr; // [+0x34] timestamp date register
    Tsssr tsssr; // [+0x38] time-stamp sub second register
    Calr calr; // [+0x3C] calibration register
    Tafcr tafcr; // [+0x40] tamper and alternate function configuration register
    Alrmassr alrmassr; // [+0x44] alarm A sub second register
    uint32_t __padding_48_4C[2]; // [+0x48 - 0x4C] Padding for alignment
    Bkp0r bkp0r; // [+0x50] backup register
    Bkp1r bkp1r; // [+0x54] backup register
    Bkp2r bkp2r; // [+0x58] backup register
    Bkp3r bkp3r; // [+0x5C] backup register
    Bkp4r bkp4r; // [+0x60] backup register

}; // Rtc registers


// Dac registers
struct Dac {
    ////////////////////////////////////////////////////////////////////////////
    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> en1;  // DAC channel1 enable
        BoolField<32, 1> boff1;  // DAC channel1 output buffer disable
        BoolField<32, 2> ten1;  // DAC channel1 trigger enable
        BoolField<32, 3> tsel10;  // DAC channel1 trigger selection
        BoolField<32, 4> tsel11;  // DAC channel1 trigger selection
        BoolField<32, 5> tsel12;  // DAC channel1 trigger selection
        BoolField<32, 12> dmaen1;  // DAC channel1 DMA enable
        BoolField<32, 13> dmaudrie1;  // DAC channel1 DMA Underrun Interrupt enable
    };

    union Swtrigr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Swtrigr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> swtrig1;  // DAC channel1 software trigger
    };

    union Dhr12r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Dhr12r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 11, 0> dacc1dhr;
    };

    union Dhr12l1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Dhr12l1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 4> dacc1dhr;
    };

    union Dhr8r1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Dhr8r1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 0> dacc1dhr;
    };

    union Dor1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Dor1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 11, 0> dacc1dor;
    };

    union Sr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Sr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 29> dmaudr2;  // DAC channel2 DMA underrun flag
        BoolField<32, 13> dmaudr1;  // DAC channel1 DMA underrun flag
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cr cr; // [+0x0] control register
    Swtrigr swtrigr; // [+0x4] software trigger register
    Dhr12r1 dhr12r1; // [+0x8] channel1 12-bit right-aligned data holding register
    Dhr12l1 dhr12l1; // [+0xC] channel1 12-bit left aligned data holding register
    Dhr8r1 dhr8r1; // [+0x10] channel1 8-bit right aligned data holding register
    uint32_t __padding_14_28[6]; // [+0x14 - 0x28] Padding for alignment
    Dor1 dor1; // [+0x2C] channel1 data output register
    uint32_t __padding_30_30[1]; // [+0x30 - 0x30] Padding for alignment
    Sr sr; // [+0x34] status register

}; // Dac registers


// Spi registers
struct Spi {
    ////////////////////////////////////////////////////////////////////////////
    union Cr1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 15> bidimode;  // Bidirectional data mode enable
        BoolField<32, 14> bidioe;  // Output enable in bidirectional mode
        BoolField<32, 13> crcen;  // Hardware CRC calculation enable
        BoolField<32, 12> crcnext;  // CRC transfer next
        BoolField<32, 11> dff;  // Data frame format
        BoolField<32, 10> rxonly;  // Receive only
        BoolField<32, 9> ssm;  // Software slave management
        BoolField<32, 8> ssi;  // Internal slave select
        BoolField<32, 7> lsbfirst;  // Frame format
        BoolField<32, 6> spe;  // SPI enable
        BitField<32, 5, 3> br;
        BoolField<32, 2> mstr;  // Master selection
        BoolField<32, 1> cpol;  // Clock polarity
        BoolField<32, 0> cpha;  // Clock phase
    };

    union Cr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> rxdmaen;  // Rx buffer DMA enable
        BoolField<32, 1> txdmaen;  // Tx buffer DMA enable
        BoolField<32, 2> ssoe;  // SS output enable
        BoolField<32, 3> nssp;  // NSS pulse management
        BoolField<32, 4> frf;  // Frame format
        BoolField<32, 5> errie;  // Error interrupt enable
        BoolField<32, 6> rxneie;  // RX buffer not empty interrupt enable
        BoolField<32, 7> txeie;  // Tx buffer empty interrupt enable
        BitField<32, 11, 8> ds;
        BoolField<32, 12> frxth;  // FIFO reception threshold
        BoolField<32, 13> ldma_rx;  // Last DMA transfer for reception
        BoolField<32, 14> ldma_tx;  // Last DMA transfer for transmission
    };

    union Sr {
    public:
        constexpr static uint32_t kResetValue = 0x00000002;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Sr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> rxne;  // Receive buffer not empty
        BoolField<32, 1> txe;  // Transmit buffer empty
        BoolField<32, 2> chside;  // Channel side
        BoolField<32, 3> udr;  // Underrun flag
        BoolField<32, 4> crcerr;  // CRC error flag
        BoolField<32, 5> modf;  // Mode fault
        BoolField<32, 6> ovr;  // Overrun flag
        BoolField<32, 7> bsy;  // Busy flag
        BoolField<32, 8> tifrfe;  // TI frame format error
        BitField<32, 10, 9> frlvl;
        BitField<32, 12, 11> ftlvl;
    };

    union Dr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Dr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> dr;
    };

    union Crcpr {
    public:
        constexpr static uint32_t kResetValue = 0x00000007;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Crcpr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> crcpoly;
    };

    union Rxcrcr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Rxcrcr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> rxcrc;
    };

    union Txcrcr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Txcrcr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> txcrc;
    };

    union I2scfgr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr I2scfgr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 11> i2smod;  // I2S mode selection
        BoolField<32, 10> i2se;  // I2S Enable
        BitField<32, 9, 8> i2scfg;
        BoolField<32, 7> pcmsync;  // PCM frame synchronization
        BitField<32, 5, 4> i2sstd;
        BoolField<32, 3> ckpol;  // Steady state clock polarity
        BitField<32, 2, 1> datlen;
        BoolField<32, 0> chlen;  // Channel length (number of bits per audio channel)
    };

    union I2spr {
    public:
        constexpr static uint32_t kResetValue = 0x00000010;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr I2spr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 9> mckoe;  // Master clock output enable
        BoolField<32, 8> odd;  // Odd factor for the prescaler
        BitField<32, 7, 0> i2sdiv;
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cr1 cr1; // [+0x0] control register 1
    Cr2 cr2; // [+0x4] control register 2
    Sr sr; // [+0x8] status register
    Dr dr; // [+0xC] data register
    Crcpr crcpr; // [+0x10] CRC polynomial register
    Rxcrcr rxcrcr; // [+0x14] RX CRC register
    Txcrcr txcrcr; // [+0x18] TX CRC register
    I2scfgr i2scfgr; // [+0x1C] I2S configuration register
    I2spr i2spr; // [+0x20] I2S prescaler register

}; // Spi registers


// Exti registers
struct Exti {
    ////////////////////////////////////////////////////////////////////////////
    union Imr {
    public:
        constexpr static uint32_t kResetValue = 0x0F940000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Imr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> mr0;  // Interrupt Mask on line 0
        BoolField<32, 1> mr1;  // Interrupt Mask on line 1
        BoolField<32, 2> mr2;  // Interrupt Mask on line 2
        BoolField<32, 3> mr3;  // Interrupt Mask on line 3
        BoolField<32, 4> mr4;  // Interrupt Mask on line 4
        BoolField<32, 5> mr5;  // Interrupt Mask on line 5
        BoolField<32, 6> mr6;  // Interrupt Mask on line 6
        BoolField<32, 7> mr7;  // Interrupt Mask on line 7
        BoolField<32, 8> mr8;  // Interrupt Mask on line 8
        BoolField<32, 9> mr9;  // Interrupt Mask on line 9
        BoolField<32, 10> mr10;  // Interrupt Mask on line 10
        BoolField<32, 11> mr11;  // Interrupt Mask on line 11
        BoolField<32, 12> mr12;  // Interrupt Mask on line 12
        BoolField<32, 13> mr13;  // Interrupt Mask on line 13
        BoolField<32, 14> mr14;  // Interrupt Mask on line 14
        BoolField<32, 15> mr15;  // Interrupt Mask on line 15
        BoolField<32, 16> mr16;  // Interrupt Mask on line 16
        BoolField<32, 17> mr17;  // Interrupt Mask on line 17
        BoolField<32, 18> mr18;  // Interrupt Mask on line 18
        BoolField<32, 19> mr19;  // Interrupt Mask on line 19
        BoolField<32, 20> mr20;  // Interrupt Mask on line 20
        BoolField<32, 21> mr21;  // Interrupt Mask on line 21
        BoolField<32, 22> mr22;  // Interrupt Mask on line 22
        BoolField<32, 23> mr23;  // Interrupt Mask on line 23
        BoolField<32, 24> mr24;  // Interrupt Mask on line 24
        BoolField<32, 25> mr25;  // Interrupt Mask on line 25
        BoolField<32, 26> mr26;  // Interrupt Mask on line 26
        BoolField<32, 27> mr27;  // Interrupt Mask on line 27
    };

    union Emr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Emr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> mr0;  // Event Mask on line 0
        BoolField<32, 1> mr1;  // Event Mask on line 1
        BoolField<32, 2> mr2;  // Event Mask on line 2
        BoolField<32, 3> mr3;  // Event Mask on line 3
        BoolField<32, 4> mr4;  // Event Mask on line 4
        BoolField<32, 5> mr5;  // Event Mask on line 5
        BoolField<32, 6> mr6;  // Event Mask on line 6
        BoolField<32, 7> mr7;  // Event Mask on line 7
        BoolField<32, 8> mr8;  // Event Mask on line 8
        BoolField<32, 9> mr9;  // Event Mask on line 9
        BoolField<32, 10> mr10;  // Event Mask on line 10
        BoolField<32, 11> mr11;  // Event Mask on line 11
        BoolField<32, 12> mr12;  // Event Mask on line 12
        BoolField<32, 13> mr13;  // Event Mask on line 13
        BoolField<32, 14> mr14;  // Event Mask on line 14
        BoolField<32, 15> mr15;  // Event Mask on line 15
        BoolField<32, 16> mr16;  // Event Mask on line 16
        BoolField<32, 17> mr17;  // Event Mask on line 17
        BoolField<32, 18> mr18;  // Event Mask on line 18
        BoolField<32, 19> mr19;  // Event Mask on line 19
        BoolField<32, 20> mr20;  // Event Mask on line 20
        BoolField<32, 21> mr21;  // Event Mask on line 21
        BoolField<32, 22> mr22;  // Event Mask on line 22
        BoolField<32, 23> mr23;  // Event Mask on line 23
        BoolField<32, 24> mr24;  // Event Mask on line 24
        BoolField<32, 25> mr25;  // Event Mask on line 25
        BoolField<32, 26> mr26;  // Event Mask on line 26
        BoolField<32, 27> mr27;  // Event Mask on line 27
    };

    union Rtsr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Rtsr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> tr0;  // Rising trigger event configuration of line 0
        BoolField<32, 1> tr1;  // Rising trigger event configuration of line 1
        BoolField<32, 2> tr2;  // Rising trigger event configuration of line 2
        BoolField<32, 3> tr3;  // Rising trigger event configuration of line 3
        BoolField<32, 4> tr4;  // Rising trigger event configuration of line 4
        BoolField<32, 5> tr5;  // Rising trigger event configuration of line 5
        BoolField<32, 6> tr6;  // Rising trigger event configuration of line 6
        BoolField<32, 7> tr7;  // Rising trigger event configuration of line 7
        BoolField<32, 8> tr8;  // Rising trigger event configuration of line 8
        BoolField<32, 9> tr9;  // Rising trigger event configuration of line 9
        BoolField<32, 10> tr10;  // Rising trigger event configuration of line 10
        BoolField<32, 11> tr11;  // Rising trigger event configuration of line 11
        BoolField<32, 12> tr12;  // Rising trigger event configuration of line 12
        BoolField<32, 13> tr13;  // Rising trigger event configuration of line 13
        BoolField<32, 14> tr14;  // Rising trigger event configuration of line 14
        BoolField<32, 15> tr15;  // Rising trigger event configuration of line 15
        BoolField<32, 16> tr16;  // Rising trigger event configuration of line 16
        BoolField<32, 17> tr17;  // Rising trigger event configuration of line 17
        BoolField<32, 19> tr19;  // Rising trigger event configuration of line 19
    };

    union Ftsr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ftsr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> tr0;  // Falling trigger event configuration of line 0
        BoolField<32, 1> tr1;  // Falling trigger event configuration of line 1
        BoolField<32, 2> tr2;  // Falling trigger event configuration of line 2
        BoolField<32, 3> tr3;  // Falling trigger event configuration of line 3
        BoolField<32, 4> tr4;  // Falling trigger event configuration of line 4
        BoolField<32, 5> tr5;  // Falling trigger event configuration of line 5
        BoolField<32, 6> tr6;  // Falling trigger event configuration of line 6
        BoolField<32, 7> tr7;  // Falling trigger event configuration of line 7
        BoolField<32, 8> tr8;  // Falling trigger event configuration of line 8
        BoolField<32, 9> tr9;  // Falling trigger event configuration of line 9
        BoolField<32, 10> tr10;  // Falling trigger event configuration of line 10
        BoolField<32, 11> tr11;  // Falling trigger event configuration of line 11
        BoolField<32, 12> tr12;  // Falling trigger event configuration of line 12
        BoolField<32, 13> tr13;  // Falling trigger event configuration of line 13
        BoolField<32, 14> tr14;  // Falling trigger event configuration of line 14
        BoolField<32, 15> tr15;  // Falling trigger event configuration of line 15
        BoolField<32, 16> tr16;  // Falling trigger event configuration of line 16
        BoolField<32, 17> tr17;  // Falling trigger event configuration of line 17
        BoolField<32, 19> tr19;  // Falling trigger event configuration of line 19
    };

    union Swier {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Swier() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> swier0;  // Software Interrupt on line 0
        BoolField<32, 1> swier1;  // Software Interrupt on line 1
        BoolField<32, 2> swier2;  // Software Interrupt on line 2
        BoolField<32, 3> swier3;  // Software Interrupt on line 3
        BoolField<32, 4> swier4;  // Software Interrupt on line 4
        BoolField<32, 5> swier5;  // Software Interrupt on line 5
        BoolField<32, 6> swier6;  // Software Interrupt on line 6
        BoolField<32, 7> swier7;  // Software Interrupt on line 7
        BoolField<32, 8> swier8;  // Software Interrupt on line 8
        BoolField<32, 9> swier9;  // Software Interrupt on line 9
        BoolField<32, 10> swier10;  // Software Interrupt on line 10
        BoolField<32, 11> swier11;  // Software Interrupt on line 11
        BoolField<32, 12> swier12;  // Software Interrupt on line 12
        BoolField<32, 13> swier13;  // Software Interrupt on line 13
        BoolField<32, 14> swier14;  // Software Interrupt on line 14
        BoolField<32, 15> swier15;  // Software Interrupt on line 15
        BoolField<32, 16> swier16;  // Software Interrupt on line 16
        BoolField<32, 17> swier17;  // Software Interrupt on line 17
        BoolField<32, 19> swier19;  // Software Interrupt on line 19
    };

    union Pr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Pr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> pr0;  // Pending bit 0
        BoolField<32, 1> pr1;  // Pending bit 1
        BoolField<32, 2> pr2;  // Pending bit 2
        BoolField<32, 3> pr3;  // Pending bit 3
        BoolField<32, 4> pr4;  // Pending bit 4
        BoolField<32, 5> pr5;  // Pending bit 5
        BoolField<32, 6> pr6;  // Pending bit 6
        BoolField<32, 7> pr7;  // Pending bit 7
        BoolField<32, 8> pr8;  // Pending bit 8
        BoolField<32, 9> pr9;  // Pending bit 9
        BoolField<32, 10> pr10;  // Pending bit 10
        BoolField<32, 11> pr11;  // Pending bit 11
        BoolField<32, 12> pr12;  // Pending bit 12
        BoolField<32, 13> pr13;  // Pending bit 13
        BoolField<32, 14> pr14;  // Pending bit 14
        BoolField<32, 15> pr15;  // Pending bit 15
        BoolField<32, 16> pr16;  // Pending bit 16
        BoolField<32, 17> pr17;  // Pending bit 17
        BoolField<32, 19> pr19;  // Pending bit 19
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Imr imr; // [+0x0] Interrupt mask register (EXTI_IMR)
    Emr emr; // [+0x4] Event mask register (EXTI_EMR)
    Rtsr rtsr; // [+0x8] Rising Trigger selection register (EXTI_RTSR)
    Ftsr ftsr; // [+0xC] Falling Trigger selection register (EXTI_FTSR)
    Swier swier; // [+0x10] Software interrupt event register (EXTI_SWIER)
    Pr pr; // [+0x14] Pending register (EXTI_PR)

}; // Exti registers


// Dbgmcu registers
struct Dbgmcu {
    ////////////////////////////////////////////////////////////////////////////
    union Idcode {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Idcode() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 11, 0> dev_id;
        BitField<32, 15, 12> div_id;
        BitField<32, 31, 16> rev_id;
    };

    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 1> dbg_stop;  // Debug Stop Mode
        BoolField<32, 2> dbg_standby;  // Debug Standby Mode
    };

    union Apblfz {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Apblfz() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> dbg_timer2_stop;  // Debug Timer 2 stopped when Core is halted
        BoolField<32, 1> dbg_timer3_stop;  // Debug Timer 3 stopped when Core is halted
        BoolField<32, 4> dbg_timer6_stop;  // Debug Timer 6 stopped when Core is halted
        BoolField<32, 8> dbg_timer14_stop;  // Debug Timer 14 stopped when Core is halted
        BoolField<32, 10> dbg_rtc_stop;  // Debug RTC stopped when Core is halted
        BoolField<32, 11> dbg_wwdg_stop;  // Debug Window Wachdog stopped when Core is halted
        BoolField<32, 12> dbg_iwdg_stop;  // Debug Independent Wachdog stopped when Core is halted
        BoolField<32, 21> i2c1_smbus_timeout;  // SMBUS timeout mode stopped when Core is halted
    };

    union Apbhfz {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Apbhfz() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 11> dbg_timer1_stop;  // Debug Timer 1 stopped when Core is halted
        BoolField<32, 16> dbg_timer15_sto;  // Debug Timer 15 stopped when Core is halted
        BoolField<32, 17> dbg_timer16_sto;  // Debug Timer 16 stopped when Core is halted
        BoolField<32, 18> dbg_timer17_sto;  // Debug Timer 17 stopped when Core is halted
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Idcode idcode; // [+0x0] MCU Device ID Code Register
    Cr cr; // [+0x4] Debug MCU Configuration Register
    Apblfz apblfz; // [+0x8] APB Low Freeze Register
    Apbhfz apbhfz; // [+0xC] APB High Freeze Register

}; // Dbgmcu registers


// Usart registers
struct Usart {
    ////////////////////////////////////////////////////////////////////////////
    union Cr1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> ue;  // USART enable
        BoolField<32, 1> uesm;  // USART enable in Stop mode
        BoolField<32, 2> re;  // Receiver enable
        BoolField<32, 3> te;  // Transmitter enable
        BoolField<32, 4> idleie;  // IDLE interrupt enable
        BoolField<32, 5> rxneie;  // RXNE interrupt enable
        BoolField<32, 6> tcie;  // Transmission complete interrupt enable
        BoolField<32, 7> txeie;  // interrupt enable
        BoolField<32, 8> peie;  // PE interrupt enable
        BoolField<32, 9> ps;  // Parity selection
        BoolField<32, 10> pce;  // Parity control enable
        BoolField<32, 11> wake;  // Receiver wakeup method
        BoolField<32, 12> m;  // Word length
        BoolField<32, 13> mme;  // Mute mode enable
        BoolField<32, 14> cmie;  // Character match interrupt enable
        BoolField<32, 15> over8;  // Oversampling mode
        BitField<32, 20, 16> dedt;
        BitField<32, 25, 21> deat;
        BoolField<32, 26> rtoie;  // Receiver timeout interrupt enable
        BoolField<32, 27> eobie;  // End of Block interrupt enable
        BoolField<32, 28> m1;  // Word length
    };

    union Cr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 28> add4;
        BitField<32, 27, 24> add0;
        BoolField<32, 23> rtoen;  // Receiver timeout enable
        BitField<32, 22, 21> abrmod;
        BoolField<32, 20> abren;  // Auto baud rate enable
        BoolField<32, 19> msbfirst;  // Most significant bit first
        BoolField<32, 18> datainv;  // Binary data inversion
        BoolField<32, 17> txinv;  // TX pin active level inversion
        BoolField<32, 16> rxinv;  // RX pin active level inversion
        BoolField<32, 15> swap;  // Swap TX/RX pins
        BoolField<32, 14> linen;  // LIN mode enable
        BitField<32, 13, 12> stop;
        BoolField<32, 11> clken;  // Clock enable
        BoolField<32, 10> cpol;  // Clock polarity
        BoolField<32, 9> cpha;  // Clock phase
        BoolField<32, 8> lbcl;  // Last bit clock pulse
        BoolField<32, 6> lbdie;  // LIN break detection interrupt enable
        BoolField<32, 5> lbdl;  // LIN break detection length
        BoolField<32, 4> addm7;  // 7-bit Address Detection/4-bit Address Detection
    };

    union Cr3 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr3() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 22> wufie;  // Wakeup from Stop mode interrupt enable
        BitField<32, 21, 20> wus;
        BitField<32, 19, 17> scarcnt;
        BoolField<32, 15> dep;  // Driver enable polarity selection
        BoolField<32, 14> dem;  // Driver enable mode
        BoolField<32, 13> ddre;  // DMA Disable on Reception Error
        BoolField<32, 12> ovrdis;  // Overrun Disable
        BoolField<32, 11> onebit;  // One sample bit method enable
        BoolField<32, 10> ctsie;  // CTS interrupt enable
        BoolField<32, 9> ctse;  // CTS enable
        BoolField<32, 8> rtse;  // RTS enable
        BoolField<32, 7> dmat;  // DMA enable transmitter
        BoolField<32, 6> dmar;  // DMA enable receiver
        BoolField<32, 5> scen;  // Smartcard mode enable
        BoolField<32, 4> nack;  // Smartcard NACK enable
        BoolField<32, 3> hdsel;  // Half-duplex selection
        BoolField<32, 2> irlp;  // IrDA low-power
        BoolField<32, 1> iren;  // IrDA mode enable
        BoolField<32, 0> eie;  // Error interrupt enable
    };

    union Brr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Brr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 4> div_mantissa;
        BitField<32, 3, 0> div_fraction;
    };

    union Gtpr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Gtpr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 8> gt;
        BitField<32, 7, 0> psc;
    };

    union Rtor {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Rtor() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 31, 24> blen;
        BitField<32, 23, 0> rto;
    };

    union Rqr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Rqr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 4> txfrq;  // Transmit data flush request
        BoolField<32, 3> rxfrq;  // Receive data flush request
        BoolField<32, 2> mmrq;  // Mute mode request
        BoolField<32, 1> sbkrq;  // Send break request
        BoolField<32, 0> abrrq;  // Auto baud rate request
    };

    union Isr {
    public:
        constexpr static uint32_t kResetValue = 0x000000C0;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Isr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 22> reack;  // Receive enable acknowledge flag
        BoolField<32, 21> teack;  // Transmit enable acknowledge flag
        BoolField<32, 20> wuf;  // Wakeup from Stop mode flag
        BoolField<32, 19> rwu;  // Receiver wakeup from Mute mode
        BoolField<32, 18> sbkf;  // Send break flag
        BoolField<32, 17> cmf;  // character match flag
        BoolField<32, 16> busy;  // Busy flag
        BoolField<32, 15> abrf;  // Auto baud rate flag
        BoolField<32, 14> abre;  // Auto baud rate error
        BoolField<32, 12> eobf;  // End of block flag
        BoolField<32, 11> rtof;  // Receiver timeout
        BoolField<32, 10> cts;  // CTS flag
        BoolField<32, 9> ctsif;  // CTS interrupt flag
        BoolField<32, 8> lbdf;  // LIN break detection flag
        BoolField<32, 7> txe;  // Transmit data register empty
        BoolField<32, 6> tc;  // Transmission complete
        BoolField<32, 5> rxne;  // Read data register not empty
        BoolField<32, 4> idle;  // Idle line detected
        BoolField<32, 3> ore;  // Overrun error
        BoolField<32, 2> nf;  // Noise detected flag
        BoolField<32, 1> fe;  // Framing error
        BoolField<32, 0> pe;  // Parity error
    };

    union Icr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Icr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 20> wucf;  // Wakeup from Stop mode clear flag
        BoolField<32, 17> cmcf;  // Character match clear flag
        BoolField<32, 12> eobcf;  // End of timeout clear flag
        BoolField<32, 11> rtocf;  // Receiver timeout clear flag
        BoolField<32, 9> ctscf;  // CTS clear flag
        BoolField<32, 8> lbdcf;  // LIN break detection clear flag
        BoolField<32, 6> tccf;  // Transmission complete clear flag
        BoolField<32, 4> idlecf;  // Idle line detected clear flag
        BoolField<32, 3> orecf;  // Overrun error clear flag
        BoolField<32, 2> ncf;  // Noise detected clear flag
        BoolField<32, 1> fecf;  // Framing error clear flag
        BoolField<32, 0> pecf;  // Parity error clear flag
    };

    union Rdr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Rdr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 8, 0> rdr;
    };

    union Tdr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Tdr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 8, 0> tdr;
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cr1 cr1; // [+0x0] Control register 1
    Cr2 cr2; // [+0x4] Control register 2
    Cr3 cr3; // [+0x8] Control register 3
    Brr brr; // [+0xC] Baud rate register
    Gtpr gtpr; // [+0x10] Guard time and prescaler register
    Rtor rtor; // [+0x14] Receiver timeout register
    Rqr rqr; // [+0x18] Request register
    Isr isr; // [+0x1C] Interrupt & status register
    Icr icr; // [+0x20] Interrupt flag clear register
    Rdr rdr; // [+0x24] Receive data register
    Tdr tdr; // [+0x28] Transmit data register

}; // Usart registers


// Comp registers
struct Comp {
    ////////////////////////////////////////////////////////////////////////////
    union Csr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Csr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> comp1en;  // Comparator 1 enable
        BoolField<32, 1> comp1_inp_dac;  // COMP1_INP_DAC
        BitField<32, 3, 2> comp1mode;
        BitField<32, 6, 4> comp1insel;
        BitField<32, 10, 8> comp1outsel;
        BoolField<32, 11> comp1pol;  // Comparator 1 output polarity
        BitField<32, 13, 12> comp1hyst;
        BoolField<32, 14> comp1out;  // Comparator 1 output
        BoolField<32, 15> comp1lock;  // Comparator 1 lock
        BoolField<32, 16> comp2en;  // Comparator 2 enable
        BitField<32, 19, 18> comp2mode;
        BitField<32, 22, 20> comp2insel;
        BoolField<32, 23> wndwen;  // Window mode enable
        BitField<32, 26, 24> comp2outsel;
        BoolField<32, 27> comp2pol;  // Comparator 2 output polarity
        BitField<32, 29, 28> comp2hyst;
        BoolField<32, 30> comp2out;  // Comparator 2 output
        BoolField<32, 31> comp2lock;  // Comparator 2 lock
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Csr csr; // [+0x0] control and status register

}; // Comp registers


// Adc registers
struct Adc {
    ////////////////////////////////////////////////////////////////////////////
    union Isr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Isr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 7> awd;  // Analog watchdog flag
        BoolField<32, 4> ovr;  // ADC overrun
        BoolField<32, 3> eos;  // End of sequence flag
        BoolField<32, 2> eoc;  // End of conversion flag
        BoolField<32, 1> eosmp;  // End of sampling flag
        BoolField<32, 0> adrdy;  // ADC ready
    };

    union Ier {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ier() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 7> awdie;  // Analog watchdog interrupt enable
        BoolField<32, 4> ovrie;  // Overrun interrupt enable
        BoolField<32, 3> eosie;  // End of conversion sequence interrupt enable
        BoolField<32, 2> eocie;  // End of conversion interrupt enable
        BoolField<32, 1> eosmpie;  // End of sampling flag interrupt enable
        BoolField<32, 0> adrdyie;  // ADC ready interrupt enable
    };

    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 31> adcal;  // ADC calibration
        BoolField<32, 4> adstp;  // ADC stop conversion command
        BoolField<32, 2> adstart;  // ADC start conversion command
        BoolField<32, 1> addis;  // ADC disable command
        BoolField<32, 0> aden;  // ADC enable command
    };

    union Cfgr1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cfgr1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 30, 26> awdch;
        BoolField<32, 23> awden;  // Analog watchdog enable
        BoolField<32, 22> awdsgl;  // Enable the watchdog on a single channel or on all channels
        BoolField<32, 16> discen;  // Discontinuous mode
        BoolField<32, 15> autoff;  // Auto-off mode
        BoolField<32, 14> autdly;  // Auto-delayed conversion mode
        BoolField<32, 13> cont;  // Single / continuous conversion mode
        BoolField<32, 12> ovrmod;  // Overrun management mode
        BitField<32, 11, 10> exten;
        BitField<32, 8, 6> extsel;
        BoolField<32, 5> align;  // Data alignment
        BitField<32, 4, 3> res;
        BoolField<32, 2> scandir;  // Scan sequence direction
        BoolField<32, 1> dmacfg;  // Direct memery access configuration
        BoolField<32, 0> dmaen;  // Direct memory access enable
    };

    union Cfgr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00008000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cfgr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 31> jitoff_d4;  // JITOFF_D4
        BoolField<32, 30> jitoff_d2;  // JITOFF_D2
    };

    union Smpr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Smpr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 2, 0> smpr;
    };

    union Tr {
    public:
        constexpr static uint32_t kResetValue = 0x00000FFF;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Tr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 27, 16> ht;
        BitField<32, 11, 0> lt;
    };

    union Chselr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Chselr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 18> chsel18;  // Channel-x selection
        BoolField<32, 17> chsel17;  // Channel-x selection
        BoolField<32, 16> chsel16;  // Channel-x selection
        BoolField<32, 15> chsel15;  // Channel-x selection
        BoolField<32, 14> chsel14;  // Channel-x selection
        BoolField<32, 13> chsel13;  // Channel-x selection
        BoolField<32, 12> chsel12;  // Channel-x selection
        BoolField<32, 11> chsel11;  // Channel-x selection
        BoolField<32, 10> chsel10;  // Channel-x selection
        BoolField<32, 9> chsel9;  // Channel-x selection
        BoolField<32, 8> chsel8;  // Channel-x selection
        BoolField<32, 7> chsel7;  // Channel-x selection
        BoolField<32, 6> chsel6;  // Channel-x selection
        BoolField<32, 5> chsel5;  // Channel-x selection
        BoolField<32, 4> chsel4;  // Channel-x selection
        BoolField<32, 3> chsel3;  // Channel-x selection
        BoolField<32, 2> chsel2;  // Channel-x selection
        BoolField<32, 1> chsel1;  // Channel-x selection
        BoolField<32, 0> chsel0;  // Channel-x selection
    };

    union Dr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Dr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> data;
    };

    union Ccr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ccr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 24> vbaten;  // VBAT enable
        BoolField<32, 23> tsen;  // Temperature sensor enable
        BoolField<32, 22> vrefen;  // Temperature sensor and VREFINT enable
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Isr isr; // [+0x0] interrupt and status register
    Ier ier; // [+0x4] interrupt enable register
    Cr cr; // [+0x8] control register
    Cfgr1 cfgr1; // [+0xC] configuration register 1
    Cfgr2 cfgr2; // [+0x10] configuration register 2
    Smpr smpr; // [+0x14] sampling time register
    uint32_t __padding_18_1C[2]; // [+0x18 - 0x1C] Padding for alignment
    Tr tr; // [+0x20] watchdog threshold register
    uint32_t __padding_24_24[1]; // [+0x24 - 0x24] Padding for alignment
    Chselr chselr; // [+0x28] channel selection register
    uint32_t __padding_2C_3C[5]; // [+0x2C - 0x3C] Padding for alignment
    Dr dr; // [+0x40] data register
    uint32_t __padding_44_304[177]; // [+0x44 - 0x304] Padding for alignment
    Ccr ccr; // [+0x308] common configuration register

}; // Adc registers


// Pwr registers
struct Pwr {
    ////////////////////////////////////////////////////////////////////////////
    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 9> fpds;  // Flash power down in Stop mode
        BoolField<32, 8> dbp;  // Disable backup domain write protection
        BitField<32, 7, 5> pls;
        BoolField<32, 4> pvde;  // Power voltage detector enable
        BoolField<32, 3> csbf;  // Clear standby flag
        BoolField<32, 2> cwuf;  // Clear wakeup flag
        BoolField<32, 1> pdds;  // Power down deepsleep
        BoolField<32, 0> lpds;  // Low-power deep sleep
    };

    union Csr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Csr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 9> bre;  // Backup regulator enable
        BoolField<32, 8> ewup;  // Enable WKUP pin
        BoolField<32, 3> brr;  // Backup regulator ready
        BoolField<32, 2> pvdo;  // PVD output
        BoolField<32, 1> sbf;  // Standby flag
        BoolField<32, 0> wuf;  // Wakeup flag
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cr cr; // [+0x0] power control register
    Csr csr; // [+0x4] power control/status register

}; // Pwr registers


// Tim registers
struct Tim {
    ////////////////////////////////////////////////////////////////////////////
    union Cr1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 7> arpe;  // Auto-reload preload enable
        BoolField<32, 3> opm;  // One-pulse mode
        BoolField<32, 2> urs;  // Update request source
        BoolField<32, 1> udis;  // Update disable
        BoolField<32, 0> cen;  // Counter enable
    };

    union Cr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 6, 4> mms;
    };

    union Dier {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Dier() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 8> ude;  // Update DMA request enable
        BoolField<32, 0> uie;  // Update interrupt enable
    };

    union Sr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Sr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> uif;  // Update interrupt flag
    };

    union Egr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Egr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> ug;  // Update generation
    };

    union Cnt {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cnt() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> cnt;
    };

    union Psc {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Psc() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> psc;
    };

    union Arr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Arr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 15, 0> arr;
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cr1 cr1; // [+0x0] control register 1
    Cr2 cr2; // [+0x4] control register 2
    uint32_t __padding_8_8[1]; // [+0x8 - 0x8] Padding for alignment
    Dier dier; // [+0xC] DMA/Interrupt enable register
    Sr sr; // [+0x10] status register
    Egr egr; // [+0x14] event generation register
    uint32_t __padding_18_20[3]; // [+0x18 - 0x20] Padding for alignment
    Cnt cnt; // [+0x24] counter
    Psc psc; // [+0x28] prescaler
    Arr arr; // [+0x2C] auto-reload register

}; // Tim registers


// Nvic registers
struct Nvic {
    ////////////////////////////////////////////////////////////////////////////
    using Iser = uint32_t;

    using Icer = uint32_t;

    using Ispr = uint32_t;

    using Icpr = uint32_t;

    union Ipr0 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ipr0() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 6> pri_00;
        BitField<32, 15, 14> pri_01;
        BitField<32, 23, 22> pri_02;
        BitField<32, 31, 30> pri_03;
    };

    union Ipr1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ipr1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 6> pri_40;
        BitField<32, 15, 14> pri_41;
        BitField<32, 23, 22> pri_42;
        BitField<32, 31, 30> pri_43;
    };

    union Ipr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ipr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 6> pri_80;
        BitField<32, 15, 14> pri_81;
        BitField<32, 23, 22> pri_82;
        BitField<32, 31, 30> pri_83;
    };

    union Ipr3 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ipr3() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 6> pri_120;
        BitField<32, 15, 14> pri_121;
        BitField<32, 23, 22> pri_122;
        BitField<32, 31, 30> pri_123;
    };

    union Ipr4 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ipr4() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 6> pri_160;
        BitField<32, 15, 14> pri_161;
        BitField<32, 23, 22> pri_162;
        BitField<32, 31, 30> pri_163;
    };

    union Ipr5 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ipr5() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 6> pri_200;
        BitField<32, 15, 14> pri_201;
        BitField<32, 23, 22> pri_202;
        BitField<32, 31, 30> pri_203;
    };

    union Ipr6 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ipr6() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 6> pri_240;
        BitField<32, 15, 14> pri_241;
        BitField<32, 23, 22> pri_242;
        BitField<32, 31, 30> pri_243;
    };

    union Ipr7 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Ipr7() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 6> pri_280;
        BitField<32, 15, 14> pri_281;
        BitField<32, 23, 22> pri_282;
        BitField<32, 31, 30> pri_283;
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Iser iser; // [+0x0] Interrupt Set Enable Register
    uint32_t __padding_4_7C[31]; // [+0x4 - 0x7C] Padding for alignment
    Icer icer; // [+0x80] Interrupt Clear Enable Register
    uint32_t __padding_84_FC[31]; // [+0x84 - 0xFC] Padding for alignment
    Ispr ispr; // [+0x100] Interrupt Set-Pending Register
    uint32_t __padding_104_17C[31]; // [+0x104 - 0x17C] Padding for alignment
    Icpr icpr; // [+0x180] Interrupt Clear-Pending Register
    uint32_t __padding_184_2FC[95]; // [+0x184 - 0x2FC] Padding for alignment
    Ipr0 ipr0; // [+0x300] Interrupt Priority Register 0
    Ipr1 ipr1; // [+0x304] Interrupt Priority Register 1
    Ipr2 ipr2; // [+0x308] Interrupt Priority Register 2
    Ipr3 ipr3; // [+0x30C] Interrupt Priority Register 3
    Ipr4 ipr4; // [+0x310] Interrupt Priority Register 4
    Ipr5 ipr5; // [+0x314] Interrupt Priority Register 5
    Ipr6 ipr6; // [+0x318] Interrupt Priority Register 6
    Ipr7 ipr7; // [+0x31C] Interrupt Priority Register 7

}; // Nvic registers


// I2c registers
struct I2c {
    ////////////////////////////////////////////////////////////////////////////
    union Cr1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> pe;  // Peripheral enable
        BoolField<32, 1> txie;  // TX Interrupt enable
        BoolField<32, 2> rxie;  // RX Interrupt enable
        BoolField<32, 3> addrie;  // Address match interrupt enable (slave only)
        BoolField<32, 4> nackie;  // Not acknowledge received interrupt enable
        BoolField<32, 5> stopie;  // STOP detection Interrupt enable
        BoolField<32, 6> tcie;  // Transfer Complete interrupt enable
        BoolField<32, 7> errie;  // Error interrupts enable
        BitField<32, 11, 8> dnf;
        BoolField<32, 12> anfoff;  // Analog noise filter OFF
        BoolField<32, 13> swrst;  // Software reset
        BoolField<32, 14> txdmaen;  // DMA transmission requests enable
        BoolField<32, 15> rxdmaen;  // DMA reception requests enable
        BoolField<32, 16> sbc;  // Slave byte control
        BoolField<32, 17> nostretch;  // Clock stretching disable
        BoolField<32, 18> wupen;  // Wakeup from STOP enable
        BoolField<32, 19> gcen;  // General call enable
        BoolField<32, 20> smbhen;  // SMBus Host address enable
        BoolField<32, 21> smbden;  // SMBus Device Default address enable
        BoolField<32, 22> alerten;  // SMBUS alert enable
        BoolField<32, 23> pecen;  // PEC enable
    };

    union Cr2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 26> pecbyte;  // Packet error checking byte
        BoolField<32, 25> autoend;  // Automatic end mode (master mode)
        BoolField<32, 24> reload;  // NBYTES reload mode
        BitField<32, 23, 16> nbytes;
        BoolField<32, 15> nack;  // NACK generation (slave mode)
        BoolField<32, 14> stop;  // Stop generation (master mode)
        BoolField<32, 13> start;  // Start generation
        BoolField<32, 12> head10r;  // 10-bit address header only read direction (master receiver mode)
        BoolField<32, 11> add10;  // 10-bit addressing mode (master mode)
        BoolField<32, 10> rd_wrn;  // Transfer direction (master mode)
        BitField<32, 9, 8> sadd8;
        BitField<32, 7, 1> sadd1;
        BoolField<32, 0> sadd0;  // Slave address bit 0 (master mode)
    };

    union Oar1 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Oar1() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> oa1_0;  // Interface address
        BitField<32, 7, 1> oa1_1;
        BitField<32, 9, 8> oa1_8;
        BoolField<32, 10> oa1mode;  // Own Address 1 10-bit mode
        BoolField<32, 15> oa1en;  // Own Address 1 enable
    };

    union Oar2 {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Oar2() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 1> oa2;
        BitField<32, 10, 8> oa2msk;
        BoolField<32, 15> oa2en;  // Own Address 2 enable
    };

    union Timingr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Timingr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 0> scll;
        BitField<32, 15, 8> sclh;
        BitField<32, 19, 16> sdadel;
        BitField<32, 23, 20> scldel;
        BitField<32, 31, 28> presc;
    };

    union Timeoutr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Timeoutr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 11, 0> timeouta;
        BoolField<32, 12> tidle;  // Idle clock timeout detection
        BoolField<32, 15> timouten;  // Clock timeout enable
        BitField<32, 27, 16> timeoutb;
        BoolField<32, 31> texten;  // Extended clock timeout enable
    };

    union Isr {
    public:
        constexpr static uint32_t kResetValue = 0x00000001;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Isr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 23, 17> addcode;
        BoolField<32, 16> dir;  // Transfer direction (Slave mode)
        BoolField<32, 15> busy;  // Bus busy
        BoolField<32, 13> alert;  // SMBus alert
        BoolField<32, 12> timeout;  // Timeout or t_low detection flag
        BoolField<32, 11> pecerr;  // PEC Error in reception
        BoolField<32, 10> ovr;  // Overrun/Underrun (slave mode)
        BoolField<32, 9> arlo;  // Arbitration lost
        BoolField<32, 8> berr;  // Bus error
        BoolField<32, 7> tcr;  // Transfer Complete Reload
        BoolField<32, 6> tc;  // Transfer Complete (master mode)
        BoolField<32, 5> stopf;  // Stop detection flag
        BoolField<32, 4> nackf;  // Not acknowledge received flag
        BoolField<32, 3> addr;  // Address matched (slave mode)
        BoolField<32, 2> rxne;  // Receive data register not empty (receivers)
        BoolField<32, 1> txis;  // Transmit interrupt status (transmitters)
        BoolField<32, 0> txe;  // Transmit data register empty (transmitters)
    };

    union Icr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Icr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 13> alertcf;  // Alert flag clear
        BoolField<32, 12> timoutcf;  // Timeout detection flag clear
        BoolField<32, 11> peccf;  // PEC Error flag clear
        BoolField<32, 10> ovrcf;  // Overrun/Underrun flag clear
        BoolField<32, 9> arlocf;  // Arbitration lost flag clear
        BoolField<32, 8> berrcf;  // Bus error flag clear
        BoolField<32, 5> stopcf;  // Stop detection flag clear
        BoolField<32, 4> nackcf;  // Not Acknowledge flag clear
        BoolField<32, 3> addrcf;  // Address Matched flag clear
    };

    union Pecr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Pecr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 0> pec;
    };

    union Rxdr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Rxdr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 0> rxdata;
    };

    union Txdr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Txdr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BitField<32, 7, 0> txdata;
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cr1 cr1; // [+0x0] Control register 1
    Cr2 cr2; // [+0x4] Control register 2
    Oar1 oar1; // [+0x8] Own address register 1
    Oar2 oar2; // [+0xC] Own address register 2
    Timingr timingr; // [+0x10] Timing register
    Timeoutr timeoutr; // [+0x14] Status register 1
    Isr isr; // [+0x18] Interrupt and Status register
    Icr icr; // [+0x1C] Interrupt clear register
    Pecr pecr; // [+0x20] PEC register
    Rxdr rxdr; // [+0x24] Receive data register
    Txdr txdr; // [+0x28] Transmit data register

}; // I2c registers


// Wwdg registers
struct Wwdg {
    ////////////////////////////////////////////////////////////////////////////
    union Cr {
    public:
        constexpr static uint32_t kResetValue = 0x0000007F;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 7> wdga;  // Activation bit
        BitField<32, 6, 0> t;
    };

    union Cfr {
    public:
        constexpr static uint32_t kResetValue = 0x0000007F;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Cfr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 9> ewi;  // Early wakeup interrupt
        BitField<32, 8, 7> wdgtb;
        BitField<32, 6, 0> w;
    };

    union Sr {
    public:
        constexpr static uint32_t kResetValue = 0x00000000;
        uint32_t inline operator= (uint32_t v) volatile { return (u32 = v); }
        constexpr inline operator uint32_t() const volatile { return u32; }
        constexpr Sr() : u32(kResetValue) {}

        // Fields
        uint32_t u32; // Raw access to entire register

        BoolField<32, 0> ewif;  // Early wakeup interrupt flag
    };

    ////////////////////////////////////////////////////////////////////////////
    // DO NOT change the order of these fields
    // These are arranged to match the underlying memory layout of the registers

    Cr cr; // [+0x0] Control register
    Cfr cfr; // [+0x4] Configuration register
    Sr sr; // [+0x8] Status register

}; // Wwdg registers


// Analog-to-digital converter
constexpr uintptr_t kAdcAddress = 0x40012400;
Adc volatile &adc = *reinterpret_cast<Adc volatile *>(kAdcAddress);

// Controller area network
constexpr uintptr_t kCanAddress = 0x40006400;
Can volatile &can = *reinterpret_cast<Can volatile *>(kCanAddress);

// HDMI-CEC controller
constexpr uintptr_t kCecAddress = 0x40007800;
Cec volatile &cec = *reinterpret_cast<Cec volatile *>(kCecAddress);

// Comparator
constexpr uintptr_t kCompAddress = 0x4001001C;
Comp volatile &comp = *reinterpret_cast<Comp volatile *>(kCompAddress);

// cyclic redundancy check calculation unit
constexpr uintptr_t kCrcAddress = 0x40023000;
Crc volatile &crc = *reinterpret_cast<Crc volatile *>(kCrcAddress);

// Clock recovery system
constexpr uintptr_t kCrsAddress = 0x40006C00;
Crs volatile &crs = *reinterpret_cast<Crs volatile *>(kCrsAddress);

// Digital-to-analog converter
constexpr uintptr_t kDacAddress = 0x40007400;
Dac volatile &dac = *reinterpret_cast<Dac volatile *>(kDacAddress);

// Debug support
constexpr uintptr_t kDbgmcuAddress = 0x40015800;
Dbgmcu volatile &dbgmcu = *reinterpret_cast<Dbgmcu volatile *>(kDbgmcuAddress);

// DMA controller
constexpr uintptr_t kDmaAddress = 0x40020000;
Dma volatile &dma = *reinterpret_cast<Dma volatile *>(kDmaAddress);

// External interrupt/event controller
constexpr uintptr_t kExtiAddress = 0x40010400;
Exti volatile &exti = *reinterpret_cast<Exti volatile *>(kExtiAddress);

// Flash
constexpr uintptr_t kFlashAddress = 0x40022000;
Flash volatile &flash = *reinterpret_cast<Flash volatile *>(kFlashAddress);

// General-purpose I/Os
constexpr uintptr_t kGpioaAddress = 0x48000000;
Gpio volatile &gpioa = *reinterpret_cast<Gpio volatile *>(kGpioaAddress);

// General-purpose I/Os
constexpr uintptr_t kGpiobAddress = 0x48000400;
Gpio volatile &gpiob = *reinterpret_cast<Gpio volatile *>(kGpiobAddress);

// General-purpose I/Os
constexpr uintptr_t kGpiocAddress = 0x48000800;
Gpio volatile &gpioc = *reinterpret_cast<Gpio volatile *>(kGpiocAddress);

// General-purpose I/Os
constexpr uintptr_t kGpiodAddress = 0x48000C00;
Gpio volatile &gpiod = *reinterpret_cast<Gpio volatile *>(kGpiodAddress);

// General-purpose I/Os
constexpr uintptr_t kGpioeAddress = 0x48001000;
Gpio volatile &gpioe = *reinterpret_cast<Gpio volatile *>(kGpioeAddress);

// General-purpose I/Os
constexpr uintptr_t kGpiofAddress = 0x48001400;
Gpio volatile &gpiof = *reinterpret_cast<Gpio volatile *>(kGpiofAddress);

// Inter-integrated circuit
constexpr uintptr_t kI2c1Address = 0x40005400;
I2c volatile &i2c1 = *reinterpret_cast<I2c volatile *>(kI2c1Address);

// Inter-integrated circuit
constexpr uintptr_t kI2c2Address = 0x40005800;
I2c volatile &i2c2 = *reinterpret_cast<I2c volatile *>(kI2c2Address);

// Independent watchdog
constexpr uintptr_t kIwdgAddress = 0x40003000;
Iwdg volatile &iwdg = *reinterpret_cast<Iwdg volatile *>(kIwdgAddress);

// Nested Vectored Interrupt Controller
constexpr uintptr_t kNvicAddress = 0xE000E100;
Nvic volatile &nvic = *reinterpret_cast<Nvic volatile *>(kNvicAddress);

// Power control
constexpr uintptr_t kPwrAddress = 0x40007000;
Pwr volatile &pwr = *reinterpret_cast<Pwr volatile *>(kPwrAddress);

// Reset and clock control
constexpr uintptr_t kRccAddress = 0x40021000;
Rcc volatile &rcc = *reinterpret_cast<Rcc volatile *>(kRccAddress);

// Real-time clock
constexpr uintptr_t kRtcAddress = 0x40002800;
Rtc volatile &rtc = *reinterpret_cast<Rtc volatile *>(kRtcAddress);

// Serial peripheral interface
constexpr uintptr_t kSpi1Address = 0x40013000;
Spi volatile &spi1 = *reinterpret_cast<Spi volatile *>(kSpi1Address);

// Serial peripheral interface
constexpr uintptr_t kSpi2Address = 0x40003800;
Spi volatile &spi2 = *reinterpret_cast<Spi volatile *>(kSpi2Address);

// System configuration controller
constexpr uintptr_t kSyscfgAddress = 0x40010000;
Syscfg volatile &syscfg = *reinterpret_cast<Syscfg volatile *>(kSyscfgAddress);

// Advanced-timers
constexpr uintptr_t kTim1Address = 0x40012C00;
Tim volatile &tim1 = *reinterpret_cast<Tim volatile *>(kTim1Address);

// General-purpose-timers
constexpr uintptr_t kTim14Address = 0x40002000;
Tim volatile &tim14 = *reinterpret_cast<Tim volatile *>(kTim14Address);

// General-purpose-timers
constexpr uintptr_t kTim15Address = 0x40014000;
Tim volatile &tim15 = *reinterpret_cast<Tim volatile *>(kTim15Address);

// General-purpose-timers
constexpr uintptr_t kTim16Address = 0x40014400;
Tim volatile &tim16 = *reinterpret_cast<Tim volatile *>(kTim16Address);

// General-purpose-timers
constexpr uintptr_t kTim17Address = 0x40014800;
Tim volatile &tim17 = *reinterpret_cast<Tim volatile *>(kTim17Address);

// General-purpose-timers
constexpr uintptr_t kTim2Address = 0x40000000;
Tim volatile &tim2 = *reinterpret_cast<Tim volatile *>(kTim2Address);

// General-purpose-timers
constexpr uintptr_t kTim3Address = 0x40000400;
Tim volatile &tim3 = *reinterpret_cast<Tim volatile *>(kTim3Address);

// Basic-timers
constexpr uintptr_t kTim6Address = 0x40001000;
Tim volatile &tim6 = *reinterpret_cast<Tim volatile *>(kTim6Address);

// Basic-timers
constexpr uintptr_t kTim7Address = 0x40001400;
Tim volatile &tim7 = *reinterpret_cast<Tim volatile *>(kTim7Address);

// Touch sensing controller
constexpr uintptr_t kTscAddress = 0x40024000;
Tsc volatile &tsc = *reinterpret_cast<Tsc volatile *>(kTscAddress);

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kUsart1Address = 0x40013800;
Usart volatile &usart1 = *reinterpret_cast<Usart volatile *>(kUsart1Address);

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kUsart2Address = 0x40004400;
Usart volatile &usart2 = *reinterpret_cast<Usart volatile *>(kUsart2Address);

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kUsart3Address = 0x40004800;
Usart volatile &usart3 = *reinterpret_cast<Usart volatile *>(kUsart3Address);

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kUsart4Address = 0x40004C00;
Usart volatile &usart4 = *reinterpret_cast<Usart volatile *>(kUsart4Address);

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kUsart6Address = 0x40011400;
Usart volatile &usart6 = *reinterpret_cast<Usart volatile *>(kUsart6Address);

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kUsart7Address = 0x40011800;
Usart volatile &usart7 = *reinterpret_cast<Usart volatile *>(kUsart7Address);

// Universal synchronous asynchronous receiver transmitter
constexpr uintptr_t kUsart8Address = 0x40011C00;
Usart volatile &usart8 = *reinterpret_cast<Usart volatile *>(kUsart8Address);

// Universal serial bus full-speed device interface
constexpr uintptr_t kUsbAddress = 0x40005C00;
Usb volatile &usb = *reinterpret_cast<Usb volatile *>(kUsbAddress);

// Window watchdog
constexpr uintptr_t kWwdgAddress = 0x40002C00;
Wwdg volatile &wwdg = *reinterpret_cast<Wwdg volatile *>(kWwdgAddress);


} // namespace Stm32f091x

#endif // _STM32F091x_H_
