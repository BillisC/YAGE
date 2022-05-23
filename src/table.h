#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <stdint.h>

#include "instructions.h"

typedef void(*instr_ptr)();

struct instr_str{
    instr_ptr ptr;
    const char *name;
    uint8_t bytes;
    uint8_t cycles;
};

std::vector<instr_str> instr_table{
    { &NOP,             "NOP",              1,      4    },
    { &LD_BC_U16,       "LD BC, u16",       3,      12   },
    { &LD_ADDR_BC_A,    "LD (BC), A",       1,      8    },
    { &INC_BC,          "INC BC",           1,      8    },
    { &INC_B,           "INC B",            1,      4    },
    { &DEC_B,           "DEC B",            1,      4    },
    { &LD_B_U8,         "LD B, u8",         2,      8    },
    { &RLCA,            "RLCA",             1,      4    },
    { &LD_ADDR_U16_SP,  "LD (u16), SP",     3,      20   },
    { &ADD_HL_BC,       "ADD HL,BC",        1,      8    },
    { &LD_A_ADDR_BC,    "LD A, (BC)",       1,      8    },
    { &DEC_BC,          "DEC BC",           1,      8    },
    { &INC_C,           "INC C",            1,      4    },
    { &DEC_C,           "DEC C",            1,      4    },
    { &LD_C_U8,         "LD C, u8",         2,      8    },
    { &RRCA,            "RRCA",             1,      4    },
    { &STOP,            "STOP",             1,      4    },
    { &LD_DE_U16,       "LD DE, u16",       3,      12   },
    { &LD_ADDR_DE_A,    "LD (DE), A",       1,      8    },
    { &INC_DE,          "INC DE",           1,      8    },
    { &INC_D,           "INC D",            1,      4    },
    { &DEC_D,           "DEC D",            1,      4    },
    { &LD_D_U8,         "LD D, u8",         2,      8    },
    { &RLA,             "RLA",              1,      4    },
    { &JR_I8,           "JR i8",            2,      12   },
    { &ADD_HL_DE,       "ADD HL,DE",        1,      8    },
    { &LD_A_ADDR_DE,    "LD A, (DE)",       1,      8    },
    { &DEC_DE,          "DEC DE",           1,      8    },
    { &INC_E,           "INC E",            1,      4    },
    { &DEC_E,           "DEC E",            1,      4    },
    { &LD_E_U8,         "LD E, u8",         1,      8    },
    { &RRA,             "RRA",              1,      4    },
    { &JR_NZ_I8,        "JR NZ, i8",        2,      8+12 },
    { &LD_HL_U16,       "LD HL, u16",       3,      12   },
    { &LD_ADDR_HLp_A,   "LD (HL+), A",      1,      8    },
    { &INC_HL,          "INC HL",           1,      8    },
    { &INC_H,           "INC H",            1,      4    },
    { &DEC_H,           "DEC H",            1,      4    },
    { &LD_H_U8,         "LD H, u8",         2,      8    },
    { &DAA,             "DAA",              1,      4    },
    { &JR_Z_I8,         "JR Z, i8",         2,      8+12 },
    { &ADD_HL_HL,       "ADD HL, HL",       1,      8    },
    { &LD_A_ADDR_HLp,   "LD A, (HL+)",      1,      8    },
    { &DEC_HL,          "DEC HL",           1,      8    },
    { &INC_L,           "INC L",            1,      4    },
    { &DEC_L,           "DEC L",            1,      4    },
    { &LD_L_U8,         "LD L, u8",         2,      8    },
    { &CPL,             "CPL",              1,      4    },
    { &JR_NC_I8,        "JR NC, i8",        2,      8+12 },
    { &LD_SP_U16,       "LD SP, u16",       3,      12   },
    { &LD_ADDR_HLm_A,   "LD (HL-), A",      1,      8    },
    { &INC_SP,          "INC SP",           1,      8    },
    { &INC_ADDR_HL,     "INC (HL)",         1,      12   },
    { &DEC_ADDR_HL,     "DEC (HL)",         1,      12   },
    { &LD_ADDR_HL_U8,   "LD (HL), u8",      2,      12   },
    { &SCF,             "SCF",              1,      4    },
    { &JR_C_I8,         "JR C, i8",         2,      8+12 },
    { &ADD_HL_SP,       "ADD HL, SP",       1,      8    },
    { &LD_A_ADDR_HLm,   "LD A, (HL-)",      1,      8    },
    { &DEC_SP,          "DEC SP",           1,      8    },
    { &INC_A,           "INC A",            1,      4    },
    { &DEC_A,           "DEC A",            1,      4    },
    { &LD_A_U8,         "LD A, u8",         2,      8    },
    { &CCF,             "CCF",              1,      4    },

}

#endif