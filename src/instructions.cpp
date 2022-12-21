#include "gameboy.h"

// nop
void CPU::NOP() {}

// -- LOAD --
void CPU::LD_B_U8() { registers.BC.solo.B = gb->memory.Read8(registers.PC++); }
void CPU::LD_C_U8() { registers.BC.solo.C = gb->memory.Read8(registers.PC++); }
void CPU::LD_D_U8() { registers.DE.solo.D = gb->memory.Read8(registers.PC++); }
void CPU::LD_E_U8() { registers.DE.solo.E = gb->memory.Read8(registers.PC++); }
void CPU::LD_H_U8() { registers.HL.solo.H = gb->memory.Read8(registers.PC++); }
void CPU::LD_L_U8() { registers.HL.solo.L = gb->memory.Read8(registers.PC++); }
void CPU::LD_A_U8() { registers.AF.solo.A = gb->memory.Read8(registers.PC++); }

void CPU::LD_SP_U16() { registers.SP = gb->memory.Read16(registers.PC); }
void CPU::LD_SP_HL() { registers.SP = registers.HL.pair; }

void CPU::LD_A_ADDR_BC() { registers.AF.solo.A = gb->memory.Read8(registers.BC.pair); }
void CPU::LD_A_ADDR_DE() { registers.AF.solo.A = gb->memory.Read8(registers.DE.pair); }
void CPU::LD_A_ADDR_HLp() { registers.AF.solo.A = gb->memory.Read8(registers.HL.pair++); }
void CPU::LD_A_ADDR_HLm() { registers.AF.solo.A = gb->memory.Read8(registers.HL.pair--); }
void CPU::LD_A_ADDR_U16() { registers.AF.solo.A = gb->memory.Read8(gb->memory.Read16(registers.PC)); registers.PC += 2; }

void CPU::LD_BC_U16() { registers.BC.pair = gb->memory.Read16(registers.PC); registers.PC += 2; }
void CPU::LD_DE_U16() { registers.DE.pair = gb->memory.Read16(registers.PC); registers.PC += 2; }
void CPU::LD_HL_U16() { registers.HL.pair = gb->memory.Read16(registers.PC); registers.PC += 2; }
void CPU::LD_HL_SPpI8() { registers.HL.pair = registers.SP + (int8_t)gb->memory.Read8(registers.PC++); }

void CPU::LD_B_B() { registers.BC.solo.B = registers.BC.solo.B; }
void CPU::LD_B_C() { registers.BC.solo.B = registers.BC.solo.C; }
void CPU::LD_B_D() { registers.BC.solo.B = registers.DE.solo.D; }
void CPU::LD_B_E() { registers.BC.solo.B = registers.DE.solo.E; }
void CPU::LD_B_H() { registers.BC.solo.B = registers.HL.solo.H; }
void CPU::LD_B_L() { registers.BC.solo.B = registers.HL.solo.L; }
void CPU::LD_B_A() { registers.BC.solo.B = registers.AF.solo.A; }

void CPU::LD_C_B() { registers.BC.solo.C = registers.BC.solo.B; }
void CPU::LD_C_C() { registers.BC.solo.C = registers.BC.solo.C; }
void CPU::LD_C_D() { registers.BC.solo.C = registers.DE.solo.D; }
void CPU::LD_C_E() { registers.BC.solo.C = registers.DE.solo.E; }
void CPU::LD_C_H() { registers.BC.solo.C = registers.HL.solo.H; }
void CPU::LD_C_L() { registers.BC.solo.C = registers.HL.solo.L; }
void CPU::LD_C_A() { registers.BC.solo.C = registers.AF.solo.A; }

void CPU::LD_D_B() { registers.DE.solo.D = registers.BC.solo.B; }
void CPU::LD_D_C() { registers.DE.solo.D = registers.BC.solo.C; }
void CPU::LD_D_D() { registers.DE.solo.D = registers.DE.solo.D; }
void CPU::LD_D_E() { registers.DE.solo.D = registers.DE.solo.E; }
void CPU::LD_D_H() { registers.DE.solo.D = registers.HL.solo.H; }
void CPU::LD_D_L() { registers.DE.solo.D = registers.HL.solo.L; }
void CPU::LD_D_A() { registers.DE.solo.D = registers.AF.solo.A; }

void CPU::LD_E_B() { registers.DE.solo.E = registers.BC.solo.B; }
void CPU::LD_E_C() { registers.DE.solo.E = registers.BC.solo.C; }
void CPU::LD_E_D() { registers.DE.solo.E = registers.DE.solo.D; }
void CPU::LD_E_E() { registers.DE.solo.E = registers.DE.solo.E; }
void CPU::LD_E_H() { registers.DE.solo.E = registers.HL.solo.H; }
void CPU::LD_E_L() { registers.DE.solo.E = registers.HL.solo.L; }
void CPU::LD_E_A() { registers.DE.solo.E = registers.AF.solo.A; }

void CPU::LD_H_B() { registers.HL.solo.H = registers.BC.solo.B; }
void CPU::LD_H_C() { registers.HL.solo.H = registers.BC.solo.C; }
void CPU::LD_H_D() { registers.HL.solo.H = registers.DE.solo.D; }
void CPU::LD_H_E() { registers.HL.solo.H = registers.DE.solo.E; }
void CPU::LD_H_H() { registers.HL.solo.H = registers.HL.solo.H; }
void CPU::LD_H_L() { registers.HL.solo.H = registers.HL.solo.L; }
void CPU::LD_H_A() { registers.HL.solo.H = registers.AF.solo.A; }

void CPU::LD_L_B() { registers.HL.solo.L = registers.BC.solo.B; }
void CPU::LD_L_C() { registers.HL.solo.L = registers.BC.solo.C; }
void CPU::LD_L_D() { registers.HL.solo.L = registers.DE.solo.D; }
void CPU::LD_L_E() { registers.HL.solo.L = registers.DE.solo.E; }
void CPU::LD_L_H() { registers.HL.solo.L = registers.HL.solo.H; }
void CPU::LD_L_L() { registers.HL.solo.L = registers.HL.solo.L; }
void CPU::LD_L_A() { registers.HL.solo.L = registers.AF.solo.A; }

void CPU::LD_B_ADDR_HL() { registers.BC.solo.B = gb->memory.Read8(registers.HL.pair); }
void CPU::LD_C_ADDR_HL() { registers.BC.solo.C = gb->memory.Read8(registers.HL.pair); }
void CPU::LD_D_ADDR_HL() { registers.DE.solo.D = gb->memory.Read8(registers.HL.pair); }
void CPU::LD_E_ADDR_HL() { registers.DE.solo.E = gb->memory.Read8(registers.HL.pair); }
void CPU::LD_H_ADDR_HL() { registers.HL.solo.H = gb->memory.Read8(registers.HL.pair); }
void CPU::LD_L_ADDR_HL() { registers.HL.solo.L = gb->memory.Read8(registers.HL.pair); }
void CPU::LD_A_ADDR_HL() { registers.AF.solo.A = gb->memory.Read8(registers.HL.pair); }

void CPU::LD_ADDR_HL_B() { gb->memory.Write8(registers.HL.pair, registers.BC.solo.B); }
void CPU::LD_ADDR_HL_C() { gb->memory.Write8(registers.HL.pair, registers.BC.solo.C); }
void CPU::LD_ADDR_HL_D() { gb->memory.Write8(registers.HL.pair, registers.DE.solo.D); }
void CPU::LD_ADDR_HL_E() { gb->memory.Write8(registers.HL.pair, registers.DE.solo.E); }
void CPU::LD_ADDR_HL_H() { gb->memory.Write8(registers.HL.pair, registers.HL.solo.H); }
void CPU::LD_ADDR_HL_L() { gb->memory.Write8(registers.HL.pair, registers.HL.solo.L); }
void CPU::LD_ADDR_HL_A() { gb->memory.Write8(registers.HL.pair, registers.AF.solo.A); }
void CPU::LD_ADDR_BC_A() { gb->memory.Write8(registers.BC.pair, registers.AF.solo.A); }
void CPU::LD_ADDR_DE_A() { gb->memory.Write8(registers.DE.pair, registers.AF.solo.A); }
void CPU::LD_ADDR_HLp_A() { gb->memory.Write8(registers.HL.pair++, registers.AF.solo.A); }
void CPU::LD_ADDR_HLm_A() { gb->memory.Write8(registers.HL.pair--, registers.AF.solo.A); }
void CPU::LD_ADDR_U16_A() { gb->memory.Write8(gb->memory.Read16(registers.PC), registers.AF.solo.A); registers.PC += 2; }
void CPU::LD_ADDR_U16_SP() { gb->memory.Write8(gb->memory.Read16(registers.PC), registers.SP); registers.PC += 2; }
void CPU::LD_ADDR_HL_U8() { gb->memory.Write8(registers.HL.pair, gb->memory.Read8(registers.PC++)); }

void CPU::LD_A_B() { registers.AF.solo.A = registers.BC.solo.B; }
void CPU::LD_A_C() { registers.AF.solo.A = registers.BC.solo.C; }
void CPU::LD_A_D() { registers.AF.solo.A = registers.DE.solo.D; }
void CPU::LD_A_E() { registers.AF.solo.A = registers.DE.solo.E; }
void CPU::LD_A_H() { registers.AF.solo.A = registers.HL.solo.H; }
void CPU::LD_A_L() { registers.AF.solo.A = registers.HL.solo.L; }
void CPU::LD_A_A() { registers.AF.solo.A = registers.AF.solo.A; }

void CPU::LD_OFF_U8_A() { gb->memory.Write8(0xFF00 + gb->memory.Read8(registers.PC++), registers.AF.solo.A); }
void CPU::LD_A_OFF_U8() { registers.AF.solo.A = gb->memory.Read8(0xFF00 + gb->memory.Read8(registers.PC++)); }
void CPU::LD_A_OFF_C() { registers.AF.solo.A = gb->memory.Read8(0xFF00 + registers.BC.solo.C); }
void CPU::LD_OFF_C_A() { gb->memory.Write8(0xFF00 + registers.BC.solo.C, registers.AF.solo.A); }

// -- ALU -- 
void CPU::DAA() {
    if (!get_flag(NEG)) {
        if (get_flag(CARRY) || (registers.AF.solo.A > 0x99)) { 
            registers.AF.solo.A += 0x60; set_flag(CARRY, 1); 
        }
        if (get_flag(HALF) || ((registers.AF.solo.A & 0x0F) > 0x09)) { 
            registers.AF.solo.A += 0x06; 
        }
    } 
    else {
        if (get_flag(CARRY)) { 
            registers.AF.solo.A -= 0x60; 
        }
        if (get_flag(HALF)) { 
            registers.AF.solo.A -= 0x06; 
        }
    }

    set_flag(ZERO, (registers.AF.solo.A == 0));
    set_flag(HALF, 0);
}

void CPU::INC_B() { INC(&registers.BC.solo.B); }
void CPU::DEC_B() { DEC(&registers.BC.solo.B); }
void CPU::INC_C() { INC(&registers.BC.solo.C); }
void CPU::DEC_C() { DEC(&registers.BC.solo.C); }
void CPU::INC_D() { INC(&registers.DE.solo.D); }
void CPU::DEC_D() { DEC(&registers.DE.solo.D); }
void CPU::INC_E() { INC(&registers.DE.solo.E); }
void CPU::DEC_E() { DEC(&registers.DE.solo.E); }
void CPU::INC_H() { INC(&registers.HL.solo.H); }
void CPU::DEC_H() { DEC(&registers.HL.solo.H); }
void CPU::INC_L() { INC(&registers.HL.solo.L); }
void CPU::DEC_L() { DEC(&registers.HL.solo.L); }
void CPU::INC_A() { INC(&registers.AF.solo.A); }
void CPU::DEC_A() { DEC(&registers.AF.solo.A); }

void CPU::INC_BC() { registers.BC.pair++; }
void CPU::DEC_BC() { registers.BC.pair--; }
void CPU::INC_DE() { registers.DE.pair++; }
void CPU::DEC_DE() { registers.DE.pair--; }
void CPU::INC_HL() { registers.HL.pair++; }
void CPU::DEC_HL() { registers.HL.pair--; }
void CPU::INC_SP() { registers.SP++; }
void CPU::DEC_SP() { registers.SP--; }

void CPU::INC_ADDR_HL() { gb->memory.Write8(registers.HL.pair, gb->memory.Read8(registers.HL.pair) + 1); }
void CPU::DEC_ADDR_HL() { gb->memory.Write8(registers.HL.pair, gb->memory.Read8(registers.HL.pair) - 1); }

void CPU::ADD_A_B() { ADD(registers.BC.solo.B); }
void CPU::ADD_A_C() { ADD(registers.BC.solo.C); }
void CPU::ADD_A_D() { ADD(registers.DE.solo.D); }
void CPU::ADD_A_E() { ADD(registers.DE.solo.E); }
void CPU::ADD_A_H() { ADD(registers.HL.solo.H); }
void CPU::ADD_A_L() { ADD(registers.HL.solo.L); }
void CPU::ADD_A_A() { ADD(registers.AF.solo.A); }
void CPU::ADD_A_U8() { ADD(gb->memory.Read8(registers.PC++)); }
void CPU::ADD_A_ADDR_HL() { ADD(gb->memory.Read8(registers.HL.pair)); }

void CPU::ADC_A_B() { ADC(registers.BC.solo.B); }
void CPU::ADC_A_C() { ADC(registers.BC.solo.C); }
void CPU::ADC_A_D() { ADC(registers.DE.solo.D); }
void CPU::ADC_A_E() { ADC(registers.DE.solo.E); }
void CPU::ADC_A_H() { ADC(registers.HL.solo.H); }
void CPU::ADC_A_L() { ADC(registers.HL.solo.L); }
void CPU::ADC_A_A() { ADC(registers.AF.solo.A); }
void CPU::ADC_A_U8() { ADC(gb->memory.Read8(registers.PC++)); }
void CPU::ADC_A_ADDR_HL() { ADC(gb->memory.Read8(registers.HL.pair)); }

void CPU::ADD_HL_BC() { ADD16(&registers.HL.pair, registers.BC.pair); }
void CPU::ADD_HL_DE() { ADD16(&registers.HL.pair, registers.DE.pair); }
void CPU::ADD_HL_HL() { ADD16(&registers.HL.pair, registers.HL.pair); }
void CPU::ADD_HL_SP() { ADD16(&registers.HL.pair, registers.SP); }
void CPU::ADD_SP_I8() {
    uint32_t res = registers.SP + (int8_t)gb->memory.Read8(registers.PC);
    
    set_flag(CARRY, ((res & 0x100000000) != 0));
    set_flag(HALF, (((registers.SP & 0xfff) + ((int8_t)gb->memory.Read8(registers.PC++) & 0xfff)) & 0x1000) != 0);
    set_flag(NEG, 0);
    set_flag(ZERO, 0);

    registers.SP = (uint16_t)res;
}

void CPU::SUB_A_B() { SUB(registers.BC.solo.B); }
void CPU::SUB_A_C() { SUB(registers.BC.solo.C); }
void CPU::SUB_A_D() { SUB(registers.DE.solo.D); }
void CPU::SUB_A_E() { SUB(registers.DE.solo.E); }
void CPU::SUB_A_H() { SUB(registers.HL.solo.H); }
void CPU::SUB_A_L() { SUB(registers.HL.solo.L); }
void CPU::SUB_A_A() { SUB(registers.AF.solo.A); }
void CPU::SUB_A_U8() { SUB(gb->memory.Read8(registers.PC++)); }
void CPU::SUB_A_ADDR_HL() { SUB(gb->memory.Read8(registers.HL.pair)); }

void CPU::SBC_A_B() { SBC(registers.BC.solo.B); }
void CPU::SBC_A_C() { SBC(registers.BC.solo.C); }
void CPU::SBC_A_D() { SBC(registers.DE.solo.D); }
void CPU::SBC_A_E() { SBC(registers.DE.solo.E); }
void CPU::SBC_A_H() { SBC(registers.HL.solo.H); }
void CPU::SBC_A_L() { SBC(registers.HL.solo.L); }
void CPU::SBC_A_A() { SBC(registers.AF.solo.A); }
void CPU::SBC_A_U8() { SBC(gb->memory.Read8(registers.PC++)); }
void CPU::SBC_A_ADDR_HL() { SBC(gb->memory.Read8(registers.HL.pair)); }

void CPU::AND_A_B() { AND(registers.BC.solo.B); }
void CPU::AND_A_C() { AND(registers.BC.solo.C); }
void CPU::AND_A_D() { AND(registers.DE.solo.D); }
void CPU::AND_A_E() { AND(registers.DE.solo.E); }
void CPU::AND_A_H() { AND(registers.HL.solo.H); }
void CPU::AND_A_L() { AND(registers.HL.solo.L); }
void CPU::AND_A_A() { AND(registers.AF.solo.A); }
void CPU::AND_A_U8() { AND(gb->memory.Read8(registers.PC++)); }
void CPU::AND_A_ADDR_HL() { AND(gb->memory.Read8(registers.HL.pair)); }

void CPU::XOR_A_B() { XOR(registers.BC.solo.B); }
void CPU::XOR_A_C() { XOR(registers.BC.solo.C); }
void CPU::XOR_A_D() { XOR(registers.DE.solo.D); }
void CPU::XOR_A_E() { XOR(registers.DE.solo.E); }
void CPU::XOR_A_H() { XOR(registers.HL.solo.H); }
void CPU::XOR_A_L() { XOR(registers.HL.solo.L); }
void CPU::XOR_A_A() { XOR(registers.AF.solo.A); }
void CPU::XOR_A_U8() { XOR(gb->memory.Read8(registers.PC++)); }
void CPU::XOR_A_ADDR_HL() { XOR(gb->memory.Read8(registers.HL.pair)); }

void CPU::OR_A_B() { OR(registers.BC.solo.B); }
void CPU::OR_A_C() { OR(registers.BC.solo.C); }
void CPU::OR_A_D() { OR(registers.DE.solo.D); }
void CPU::OR_A_E() { OR(registers.DE.solo.E); }
void CPU::OR_A_H() { OR(registers.HL.solo.H); }
void CPU::OR_A_L() { OR(registers.HL.solo.L); }
void CPU::OR_A_A() { OR(registers.AF.solo.A); }
void CPU::OR_A_U8() { OR(gb->memory.Read8(registers.PC++)); }
void CPU::OR_A_ADDR_HL() { OR(gb->memory.Read8(registers.HL.pair)); }

void CPU::CP_A_B() { CP(registers.BC.solo.B); }
void CPU::CP_A_C() { CP(registers.BC.solo.C); }
void CPU::CP_A_D() { CP(registers.DE.solo.D); }
void CPU::CP_A_E() { CP(registers.DE.solo.E); }
void CPU::CP_A_H() { CP(registers.HL.solo.H); }
void CPU::CP_A_L() { CP(registers.HL.solo.L); }
void CPU::CP_A_A() { CP(registers.AF.solo.A); }
void CPU::CP_A_U8() { CP(gb->memory.Read8(registers.PC++)); }
void CPU::CP_A_ADDR_HL() { CP(gb->memory.Read8(registers.HL.pair)); }

// -- BRANCH --
void CPU::JR_I8() { 
    int8_t dst = (int8_t)gb->memory.Read8(registers.PC++);
    JR(dst); 
}
void CPU::JR_C_I8() { 
    int8_t dst = (int8_t)gb->memory.Read8(registers.PC++); 
    if (get_flag(CARRY)) JR(dst); 
}
void CPU::JR_Z_I8() { 
    int8_t dst = (int8_t)gb->memory.Read8(registers.PC++); 
    if (get_flag(ZERO)) JR(dst); 
}
void CPU::JR_NC_I8() { 
    int8_t dst = (int8_t)gb->memory.Read8(registers.PC++); 
    if (!get_flag(CARRY)) JR(dst); 
}
void CPU::JR_NZ_I8() { 
    int8_t dst = (int8_t)gb->memory.Read8(registers.PC++); 
    if (!get_flag(ZERO)) JR(dst); 
}

void CPU::JP_U16() {
    uint16_t dst = gb->memory.Read16(registers.PC); 
    registers.PC += 2;
    JP(dst); 
}
void CPU::JP_Z_U16() { 
    uint16_t dst = gb->memory.Read16(registers.PC); 
    registers.PC += 2;
    if (get_flag(ZERO)) JP(dst); 
}
void CPU::JP_C_U16() { 
    uint16_t dst = gb->memory.Read16(registers.PC); 
    registers.PC += 2;
    if (get_flag(CARRY)) JP(dst); 
}
void CPU::JP_NZ_U16() { 
    uint16_t dst = gb->memory.Read16(registers.PC); 
    registers.PC += 2;
    if (!get_flag(ZERO)) JP(dst); 
}
void CPU::JP_NC_U16() { 
    uint16_t dst = gb->memory.Read16(registers.PC); 
    registers.PC += 2;
    if (!get_flag(CARRY)) JP(dst); 
}
void CPU::JP_HL() { JP(registers.HL.pair); }

void CPU::PUSH_BC() { PUSH(registers.BC.pair); }
void CPU::PUSH_DE() { PUSH(registers.DE.pair); }
void CPU::PUSH_HL() { PUSH(registers.HL.pair); }
void CPU::PUSH_AF() { PUSH(registers.AF.pair); }

void CPU::POP_BC() { POP(&registers.BC.pair); }
void CPU::POP_DE() { POP(&registers.DE.pair); }
void CPU::POP_HL() { POP(&registers.HL.pair); }
void CPU::POP_AF() { POP(&registers.AF.pair); }

void CPU::CALL_U16() { CALL(gb->memory.Read16(registers.PC)); }
void CPU::CALL_Z_U16() { if (get_flag(ZERO)) CALL(gb->memory.Read16(registers.PC)); }
void CPU::CALL_C_U16() { if (get_flag(CARRY)) CALL(gb->memory.Read16(registers.PC)); }
void CPU::CALL_NZ_U16() { if (!get_flag(ZERO)) CALL(gb->memory.Read16(registers.PC)); }
void CPU::CALL_NC_U16() { if (!get_flag(CARRY)) CALL(gb->memory.Read16(registers.PC)); }

void CPU::RET() { POP(&registers.PC); }
void CPU::RETI() { /*flags.IME = true; RET();*/ }
void CPU::RET_Z() { if (get_flag(ZERO)) RET(); }
void CPU::RET_C() { if (get_flag(CARRY)) RET(); }
void CPU::RET_NZ() { if (!get_flag(ZERO)) RET(); }
void CPU::RET_NC() { if (!get_flag(CARRY)) RET(); }

// -- SHIFT & ROTATE --
void CPU::RLC_B() { RLC(&registers.BC.solo.B); }
void CPU::RLC_C() { RLC(&registers.BC.solo.C); }
void CPU::RLC_D() { RLC(&registers.DE.solo.D); }
void CPU::RLC_E() { RLC(&registers.DE.solo.E); }
void CPU::RLC_H() { RLC(&registers.HL.solo.H); }
void CPU::RLC_L() { RLC(&registers.HL.solo.L); }
void CPU::RLC_A() { RLC(&registers.AF.solo.A); }
void CPU::RLC_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RLC(&dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::RRC_B() { RRC(&registers.BC.solo.B); }
void CPU::RRC_C() { RRC(&registers.BC.solo.C); }
void CPU::RRC_D() { RRC(&registers.DE.solo.D); }
void CPU::RRC_E() { RRC(&registers.DE.solo.E); }
void CPU::RRC_H() { RRC(&registers.HL.solo.H); }
void CPU::RRC_L() { RRC(&registers.HL.solo.L); }
void CPU::RRC_A() { RRC(&registers.AF.solo.A); }
void CPU::RRC_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RRC(&dst);
    gb->memory.Write8(registers.HL.pair, dst);
}

void CPU::RL_B() { RL(&registers.BC.solo.B); }
void CPU::RL_C() { RL(&registers.BC.solo.C); }
void CPU::RL_D() { RL(&registers.DE.solo.D); }
void CPU::RL_E() { RL(&registers.DE.solo.E); }
void CPU::RL_H() { RL(&registers.HL.solo.H); }
void CPU::RL_L() { RL(&registers.HL.solo.L); }
void CPU::RL_A() { RL(&registers.AF.solo.A); }
void CPU::RL_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RL(&dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::RR_B() { RR(&registers.BC.solo.B); }
void CPU::RR_C() { RR(&registers.BC.solo.C); }
void CPU::RR_D() { RR(&registers.DE.solo.D); }
void CPU::RR_E() { RR(&registers.DE.solo.E); }
void CPU::RR_H() { RR(&registers.HL.solo.H); }
void CPU::RR_L() { RR(&registers.HL.solo.L); }
void CPU::RR_A() { RR(&registers.AF.solo.A); }
void CPU::RR_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RR(&dst);
    gb->memory.Write8(registers.HL.pair, dst);
}

void CPU::SLA_B() { SLA(&registers.BC.solo.B); }
void CPU::SLA_C() { SLA(&registers.BC.solo.C); }
void CPU::SLA_D() { SLA(&registers.DE.solo.D); }
void CPU::SLA_E() { SLA(&registers.DE.solo.E); }
void CPU::SLA_H() { SLA(&registers.HL.solo.H); }
void CPU::SLA_L() { SLA(&registers.HL.solo.L); }
void CPU::SLA_A() { SLA(&registers.AF.solo.A); }
void CPU::SLA_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SLA(&dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::SRA_B() { SRA(&registers.BC.solo.B); }
void CPU::SRA_C() { SRA(&registers.BC.solo.C); }
void CPU::SRA_D() { SRA(&registers.DE.solo.D); }
void CPU::SRA_E() { SRA(&registers.DE.solo.E); }
void CPU::SRA_H() { SRA(&registers.HL.solo.H); }
void CPU::SRA_L() { SRA(&registers.HL.solo.L); }
void CPU::SRA_A() { SRA(&registers.AF.solo.A); }
void CPU::SRA_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SRA(&dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::SRL_B() { SRL(&registers.BC.solo.B); }
void CPU::SRL_C() { SRL(&registers.BC.solo.C); }
void CPU::SRL_D() { SRL(&registers.DE.solo.D); }
void CPU::SRL_E() { SRL(&registers.DE.solo.E); }
void CPU::SRL_H() { SRL(&registers.HL.solo.H); }
void CPU::SRL_L() { SRL(&registers.HL.solo.L); }
void CPU::SRL_A() { SRL(&registers.AF.solo.A); }
void CPU::SRL_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SRL(&dst);
    gb->memory.Write8(registers.HL.pair, dst);
}

void CPU::RLCA() {
    set_flag(CARRY, ((registers.AF.solo.A & 0x80) >> 7));
    registers.AF.solo.A <<= 1;
    registers.AF.solo.A |= get_flag(CARRY);
    set_flag(NEG, 0);
    set_flag(HALF, 0);
    set_flag(ZERO, 0);
}
void CPU::RRCA() {
    set_flag(CARRY, (registers.AF.solo.A & 0x01));
    registers.AF.solo.A >>= 1;
    registers.AF.solo.A |= (get_flag(CARRY) << 7);
    set_flag(NEG, 0);
    set_flag(HALF, 0);
    set_flag(ZERO, 0);
}
void CPU::RLA() {
    bool tmp = get_flag(CARRY);
    set_flag(CARRY, ((registers.AF.solo.A & 0x80) >> 7));
    registers.AF.solo.A <<= 1;
    registers.AF.solo.A |= tmp;
    set_flag(NEG, 0);
    set_flag(HALF, 0);
    set_flag(ZERO, 0);
}
void CPU::RRA() {
    bool tmp = get_flag(CARRY);
    set_flag(CARRY, (registers.AF.solo.A & 0x10));
    registers.AF.solo.A >>= 1;
    registers.AF.solo.A |= (tmp << 7);
    set_flag(NEG, 0);
    set_flag(HALF, 0);
    set_flag(ZERO, 0);
}

// -- BIT OPERATIONS --
void CPU::SWAP_B() { SWAP(&registers.BC.solo.B); }
void CPU::SWAP_C() { SWAP(&registers.BC.solo.C); }
void CPU::SWAP_D() { SWAP(&registers.DE.solo.D); }
void CPU::SWAP_E() { SWAP(&registers.DE.solo.E); }
void CPU::SWAP_H() { SWAP(&registers.HL.solo.H); }
void CPU::SWAP_L() { SWAP(&registers.HL.solo.L); }
void CPU::SWAP_A() { SWAP(&registers.AF.solo.A); }
void CPU::SWAP_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SWAP(&dst);
    gb->memory.Write8(registers.HL.pair, dst);
}

void CPU::BIT_0_B() { BIT(0, registers.BC.solo.B); }
void CPU::BIT_0_C() { BIT(0, registers.BC.solo.C); }
void CPU::BIT_0_D() { BIT(0, registers.DE.solo.D); }
void CPU::BIT_0_E() { BIT(0, registers.DE.solo.E); }
void CPU::BIT_0_H() { BIT(0, registers.HL.solo.H); }
void CPU::BIT_0_L() { BIT(0, registers.HL.solo.L); }
void CPU::BIT_0_A() { BIT(0, registers.AF.solo.A); }
void CPU::BIT_1_B() { BIT(1, registers.BC.solo.B); }
void CPU::BIT_1_C() { BIT(1, registers.BC.solo.C); }
void CPU::BIT_1_D() { BIT(1, registers.DE.solo.D); }
void CPU::BIT_1_E() { BIT(1, registers.DE.solo.E); }
void CPU::BIT_1_H() { BIT(1, registers.HL.solo.H); }
void CPU::BIT_1_L() { BIT(1, registers.HL.solo.L); }
void CPU::BIT_1_A() { BIT(1, registers.AF.solo.A); }
void CPU::BIT_2_B() { BIT(2, registers.BC.solo.B); }
void CPU::BIT_2_C() { BIT(2, registers.BC.solo.C); }
void CPU::BIT_2_D() { BIT(2, registers.DE.solo.D); }
void CPU::BIT_2_E() { BIT(2, registers.DE.solo.E); }
void CPU::BIT_2_H() { BIT(2, registers.HL.solo.H); }
void CPU::BIT_2_L() { BIT(2, registers.HL.solo.L); }
void CPU::BIT_2_A() { BIT(2, registers.AF.solo.A); }
void CPU::BIT_3_B() { BIT(3, registers.BC.solo.B); }
void CPU::BIT_3_C() { BIT(3, registers.BC.solo.C); }
void CPU::BIT_3_D() { BIT(3, registers.DE.solo.D); }
void CPU::BIT_3_E() { BIT(3, registers.DE.solo.E); }
void CPU::BIT_3_H() { BIT(3, registers.HL.solo.H); }
void CPU::BIT_3_L() { BIT(3, registers.HL.solo.L); }
void CPU::BIT_3_A() { BIT(3, registers.AF.solo.A); }
void CPU::BIT_4_B() { BIT(4, registers.BC.solo.B); }
void CPU::BIT_4_C() { BIT(4, registers.BC.solo.C); }
void CPU::BIT_4_D() { BIT(4, registers.DE.solo.D); }
void CPU::BIT_4_E() { BIT(4, registers.DE.solo.E); }
void CPU::BIT_4_H() { BIT(4, registers.HL.solo.H); }
void CPU::BIT_4_L() { BIT(4, registers.HL.solo.L); }
void CPU::BIT_4_A() { BIT(4, registers.AF.solo.A); }
void CPU::BIT_5_B() { BIT(5, registers.BC.solo.B); }
void CPU::BIT_5_C() { BIT(5, registers.BC.solo.C); }
void CPU::BIT_5_D() { BIT(5, registers.DE.solo.D); }
void CPU::BIT_5_E() { BIT(5, registers.DE.solo.E); }
void CPU::BIT_5_H() { BIT(5, registers.HL.solo.H); }
void CPU::BIT_5_L() { BIT(5, registers.HL.solo.L); }
void CPU::BIT_5_A() { BIT(5, registers.AF.solo.A); }
void CPU::BIT_6_B() { BIT(6, registers.BC.solo.B); }
void CPU::BIT_6_C() { BIT(6, registers.BC.solo.C); }
void CPU::BIT_6_D() { BIT(6, registers.DE.solo.D); }
void CPU::BIT_6_E() { BIT(6, registers.DE.solo.E); }
void CPU::BIT_6_H() { BIT(6, registers.HL.solo.H); }
void CPU::BIT_6_L() { BIT(6, registers.HL.solo.L); }
void CPU::BIT_6_A() { BIT(6, registers.AF.solo.A); }
void CPU::BIT_7_B() { BIT(7, registers.BC.solo.B); }
void CPU::BIT_7_C() { BIT(7, registers.BC.solo.C); }
void CPU::BIT_7_D() { BIT(7, registers.DE.solo.D); }
void CPU::BIT_7_E() { BIT(7, registers.DE.solo.E); }
void CPU::BIT_7_H() { BIT(7, registers.HL.solo.H); }
void CPU::BIT_7_L() { BIT(7, registers.HL.solo.L); }
void CPU::BIT_7_A() { BIT(7, registers.AF.solo.A); }
void CPU::BIT_0_ADDR_HL() { BIT(0, gb->memory.Read8(registers.HL.pair)); }
void CPU::BIT_1_ADDR_HL() { BIT(1, gb->memory.Read8(registers.HL.pair)); }
void CPU::BIT_2_ADDR_HL() { BIT(2, gb->memory.Read8(registers.HL.pair)); }
void CPU::BIT_3_ADDR_HL() { BIT(3, gb->memory.Read8(registers.HL.pair)); }
void CPU::BIT_4_ADDR_HL() { BIT(4, gb->memory.Read8(registers.HL.pair)); }
void CPU::BIT_5_ADDR_HL() { BIT(5, gb->memory.Read8(registers.HL.pair)); }
void CPU::BIT_6_ADDR_HL() { BIT(6, gb->memory.Read8(registers.HL.pair)); }
void CPU::BIT_7_ADDR_HL() { BIT(7, gb->memory.Read8(registers.HL.pair)); }

void CPU::RES_0_B() { RES(0, &registers.BC.solo.B); }
void CPU::RES_0_C() { RES(0, &registers.BC.solo.C); }
void CPU::RES_0_D() { RES(0, &registers.DE.solo.D); }
void CPU::RES_0_E() { RES(0, &registers.DE.solo.E); }
void CPU::RES_0_H() { RES(0, &registers.HL.solo.H); }
void CPU::RES_0_L() { RES(0, &registers.HL.solo.L); }
void CPU::RES_0_A() { RES(0, &registers.AF.solo.A); }
void CPU::RES_1_B() { RES(1, &registers.BC.solo.B); }
void CPU::RES_1_C() { RES(1, &registers.BC.solo.C); }
void CPU::RES_1_D() { RES(1, &registers.DE.solo.D); }
void CPU::RES_1_E() { RES(1, &registers.DE.solo.E); }
void CPU::RES_1_H() { RES(1, &registers.HL.solo.H); }
void CPU::RES_1_L() { RES(1, &registers.HL.solo.L); }
void CPU::RES_1_A() { RES(1, &registers.AF.solo.A); }
void CPU::RES_2_B() { RES(2, &registers.BC.solo.B); }
void CPU::RES_2_C() { RES(2, &registers.BC.solo.C); }
void CPU::RES_2_D() { RES(2, &registers.DE.solo.D); }
void CPU::RES_2_E() { RES(2, &registers.DE.solo.E); }
void CPU::RES_2_H() { RES(2, &registers.HL.solo.H); }
void CPU::RES_2_L() { RES(2, &registers.HL.solo.L); }
void CPU::RES_2_A() { RES(2, &registers.AF.solo.A); }
void CPU::RES_3_B() { RES(3, &registers.BC.solo.B); }
void CPU::RES_3_C() { RES(3, &registers.BC.solo.C); }
void CPU::RES_3_D() { RES(3, &registers.DE.solo.D); }
void CPU::RES_3_E() { RES(3, &registers.DE.solo.E); }
void CPU::RES_3_H() { RES(3, &registers.HL.solo.H); }
void CPU::RES_3_L() { RES(3, &registers.HL.solo.L); }
void CPU::RES_3_A() { RES(3, &registers.AF.solo.A); }
void CPU::RES_4_B() { RES(4, &registers.BC.solo.B); }
void CPU::RES_4_C() { RES(4, &registers.BC.solo.C); }
void CPU::RES_4_D() { RES(4, &registers.DE.solo.D); }
void CPU::RES_4_E() { RES(4, &registers.DE.solo.E); }
void CPU::RES_4_H() { RES(4, &registers.HL.solo.H); }
void CPU::RES_4_L() { RES(4, &registers.HL.solo.L); }
void CPU::RES_4_A() { RES(4, &registers.AF.solo.A); }
void CPU::RES_5_B() { RES(5, &registers.BC.solo.B); }
void CPU::RES_5_C() { RES(5, &registers.BC.solo.C); }
void CPU::RES_5_D() { RES(5, &registers.DE.solo.D); }
void CPU::RES_5_E() { RES(5, &registers.DE.solo.E); }
void CPU::RES_5_H() { RES(5, &registers.HL.solo.H); }
void CPU::RES_5_L() { RES(5, &registers.HL.solo.L); }
void CPU::RES_5_A() { RES(5, &registers.AF.solo.A); }
void CPU::RES_6_B() { RES(6, &registers.BC.solo.B); }
void CPU::RES_6_C() { RES(6, &registers.BC.solo.C); }
void CPU::RES_6_D() { RES(6, &registers.DE.solo.D); }
void CPU::RES_6_E() { RES(6, &registers.DE.solo.E); }
void CPU::RES_6_H() { RES(6, &registers.HL.solo.H); }
void CPU::RES_6_L() { RES(6, &registers.HL.solo.L); }
void CPU::RES_6_A() { RES(6, &registers.AF.solo.A); }
void CPU::RES_7_B() { RES(7, &registers.BC.solo.B); }
void CPU::RES_7_C() { RES(7, &registers.BC.solo.C); }
void CPU::RES_7_D() { RES(7, &registers.DE.solo.D); }
void CPU::RES_7_E() { RES(7, &registers.DE.solo.E); }
void CPU::RES_7_H() { RES(7, &registers.HL.solo.H); }
void CPU::RES_7_L() { RES(7, &registers.HL.solo.L); }
void CPU::RES_7_A() { RES(7, &registers.AF.solo.A); }
void CPU::RES_0_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RES(0, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::RES_1_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RES(1, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::RES_2_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RES(2, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::RES_3_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RES(3, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::RES_4_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RES(4, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::RES_5_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RES(5, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::RES_6_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RES(6, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::RES_7_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    RES(7, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}

void CPU::SET_0_B() { SET(0, &registers.BC.solo.B); }
void CPU::SET_0_C() { SET(0, &registers.BC.solo.C); }
void CPU::SET_0_D() { SET(0, &registers.DE.solo.D); }
void CPU::SET_0_E() { SET(0, &registers.DE.solo.E); }
void CPU::SET_0_H() { SET(0, &registers.HL.solo.H); }
void CPU::SET_0_L() { SET(0, &registers.HL.solo.L); }
void CPU::SET_0_A() { SET(0, &registers.AF.solo.A); }
void CPU::SET_1_B() { SET(1, &registers.BC.solo.B); }
void CPU::SET_1_C() { SET(1, &registers.BC.solo.C); }
void CPU::SET_1_D() { SET(1, &registers.DE.solo.D); }
void CPU::SET_1_E() { SET(1, &registers.DE.solo.E); }
void CPU::SET_1_H() { SET(1, &registers.HL.solo.H); }
void CPU::SET_1_L() { SET(1, &registers.HL.solo.L); }
void CPU::SET_1_A() { SET(1, &registers.AF.solo.A); }
void CPU::SET_2_B() { SET(2, &registers.BC.solo.B); }
void CPU::SET_2_C() { SET(2, &registers.BC.solo.C); }
void CPU::SET_2_D() { SET(2, &registers.DE.solo.D); }
void CPU::SET_2_E() { SET(2, &registers.DE.solo.E); }
void CPU::SET_2_H() { SET(2, &registers.HL.solo.H); }
void CPU::SET_2_L() { SET(2, &registers.HL.solo.L); }
void CPU::SET_2_A() { SET(2, &registers.AF.solo.A); }
void CPU::SET_3_B() { SET(3, &registers.BC.solo.B); }
void CPU::SET_3_C() { SET(3, &registers.BC.solo.C); }
void CPU::SET_3_D() { SET(3, &registers.DE.solo.D); }
void CPU::SET_3_E() { SET(3, &registers.DE.solo.E); }
void CPU::SET_3_H() { SET(3, &registers.HL.solo.H); }
void CPU::SET_3_L() { SET(3, &registers.HL.solo.L); }
void CPU::SET_3_A() { SET(3, &registers.AF.solo.A); }
void CPU::SET_4_B() { SET(4, &registers.BC.solo.B); }
void CPU::SET_4_C() { SET(4, &registers.BC.solo.C); }
void CPU::SET_4_D() { SET(4, &registers.DE.solo.D); }
void CPU::SET_4_E() { SET(4, &registers.DE.solo.E); }
void CPU::SET_4_H() { SET(4, &registers.HL.solo.H); }
void CPU::SET_4_L() { SET(4, &registers.HL.solo.L); }
void CPU::SET_4_A() { SET(4, &registers.AF.solo.A); }
void CPU::SET_5_B() { SET(5, &registers.BC.solo.B); }
void CPU::SET_5_C() { SET(5, &registers.BC.solo.C); }
void CPU::SET_5_D() { SET(5, &registers.DE.solo.D); }
void CPU::SET_5_E() { SET(5, &registers.DE.solo.E); }
void CPU::SET_5_H() { SET(5, &registers.HL.solo.H); }
void CPU::SET_5_L() { SET(5, &registers.HL.solo.L); }
void CPU::SET_5_A() { SET(5, &registers.AF.solo.A); }
void CPU::SET_6_B() { SET(6, &registers.BC.solo.B); }
void CPU::SET_6_C() { SET(6, &registers.BC.solo.C); }
void CPU::SET_6_D() { SET(6, &registers.DE.solo.D); }
void CPU::SET_6_E() { SET(6, &registers.DE.solo.E); }
void CPU::SET_6_H() { SET(6, &registers.HL.solo.H); }
void CPU::SET_6_L() { SET(6, &registers.HL.solo.L); }
void CPU::SET_6_A() { SET(6, &registers.AF.solo.A); }
void CPU::SET_7_B() { SET(7, &registers.BC.solo.B); }
void CPU::SET_7_C() { SET(7, &registers.BC.solo.C); }
void CPU::SET_7_D() { SET(7, &registers.DE.solo.D); }
void CPU::SET_7_E() { SET(7, &registers.DE.solo.E); }
void CPU::SET_7_H() { SET(7, &registers.HL.solo.H); }
void CPU::SET_7_L() { SET(7, &registers.HL.solo.L); }
void CPU::SET_7_A() { SET(7, &registers.AF.solo.A); }
void CPU::SET_0_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SET(0, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::SET_1_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SET(1, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::SET_2_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SET(2, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::SET_3_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SET(3, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::SET_4_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SET(4, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::SET_5_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SET(5, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::SET_6_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SET(6, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}
void CPU::SET_7_ADDR_HL() {
    uint8_t dst = gb->memory.Read8(registers.HL.pair);
    SET(7, &dst);
    gb->memory.Write8(registers.HL.pair, dst);
}

// -- SYSTEM --
void CPU::STOP() { /* standby */ }
void CPU::HALT() { /* Wait for interrupt */ }
void CPU::CPL() {
    registers.AF.solo.A ^= 0xFF;
    set_flag(HALF, 1);
    set_flag(NEG, 1);
}
void CPU::SCF() {
    set_flag(CARRY, 1);
    set_flag(HALF, 0);
    set_flag(NEG, 0);
}
void CPU::CCF() {
    set_flag(CARRY, get_flag(CARRY) ^ 1);
    set_flag(HALF, 0);
    set_flag(NEG, 0);
}
void CPU::DI() { /*flags.IME = 0;*/ }
void CPU::EI() { /*flags.IME = 1;*/ }

// -- RST --
void CPU::RST_00H() { RST(0x00); }
void CPU::RST_08H() { RST(0x08); }
void CPU::RST_10H() { RST(0x10); }
void CPU::RST_18H() { RST(0x18); }
void CPU::RST_20H() { RST(0x20); }
void CPU::RST_28H() { RST(0x28); }
void CPU::RST_30H() { RST(0x30); }
void CPU::RST_38H() { RST(0x38); }