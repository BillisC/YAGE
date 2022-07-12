#include "cpu.h"

// nop
void CPU::NOP() {}

// -- LOAD --
void CPU::LD_B_U8() { LD(&registers.B, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_C_U8() { LD(&registers.C, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_D_U8() { LD(&registers.D, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_E_U8() { LD(&registers.E, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_H_U8() { LD(&registers.H, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_L_U8() { LD(&registers.L, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_A_U8() { LD(&registers.A, memory.GetHostAddress(registers.PC + 1)); }

void CPU::LD_SP_U16() { LD16(&registers.SP, memory.Read16(registers.PC)); }
void CPU::LD_SP_HL() { LD16(&registers.SP, registers.Pair(registers.H, registers.L)); }

void CPU::LD_A_ADDR_BC() { LD(&registers.A, memory.GetHostAddress(registers.Pair(registers.B, registers.C))); }
void CPU::LD_A_ADDR_DE() { LD(&registers.A, memory.GetHostAddress(registers.Pair(registers.D, registers.E))); }
void CPU::LD_A_ADDR_HLp() {
    LD(&registers.A, memory.GetHostAddress(registers.Pair(registers.H, registers.L)));
    uint16_t hlp = registers.Pair(registers.H, registers.L) + 1; registers.H = hlp >> 8; registers.L = (uint8_t)hlp;
}
void CPU::LD_A_ADDR_HLm() {
    LD(&registers.A, memory.GetHostAddress(registers.Pair(registers.H, registers.L)));
    uint16_t hlm = registers.Pair(registers.H, registers.L) - 1; registers.H = hlm >> 8; registers.L = (uint8_t)hlm;
}
void CPU::LD_A_ADDR_U16() { LD(&registers.A, memory.GetHostAddress(memory.Read16(registers.PC))); }

void CPU::LD_BC_U16() { LD16(&registers.B, &registers.C); }
void CPU::LD_DE_U16() { LD16(&registers.D, &registers.E); }
void CPU::LD_HL_U16() { LD16(&registers.H, &registers.L); }
void CPU::LD_HL_SPpI8() {
    uint16_t val = registers.SP + (int8_t)memory.Read8(registers.PC);
    registers.H = val << 8; registers.L = (uint8_t)val;
}

void CPU::LD_B_B() { LD(&registers.B, &registers.B); }  // Optimizable
void CPU::LD_B_C() { LD(&registers.B, &registers.C); }
void CPU::LD_B_D() { LD(&registers.B, &registers.D); }
void CPU::LD_B_E() { LD(&registers.B, &registers.E); }
void CPU::LD_B_H() { LD(&registers.B, &registers.H); }
void CPU::LD_B_L() { LD(&registers.B, &registers.L); }
void CPU::LD_B_A() { LD(&registers.B, &registers.A); }

void CPU::LD_C_B() { LD(&registers.C, &registers.B); }
void CPU::LD_C_C() { LD(&registers.C, &registers.C); }  // Optimizable
void CPU::LD_C_D() { LD(&registers.C, &registers.D); }
void CPU::LD_C_E() { LD(&registers.C, &registers.E); }
void CPU::LD_C_H() { LD(&registers.C, &registers.H); }
void CPU::LD_C_L() { LD(&registers.C, &registers.L); }
void CPU::LD_C_A() { LD(&registers.C, &registers.A); }

void CPU::LD_D_B() { LD(&registers.D, &registers.B); }
void CPU::LD_D_C() { LD(&registers.D, &registers.C); }
void CPU::LD_D_D() { LD(&registers.D, &registers.D); }  // Optimizable
void CPU::LD_D_E() { LD(&registers.D, &registers.E); }
void CPU::LD_D_H() { LD(&registers.D, &registers.H); }
void CPU::LD_D_L() { LD(&registers.D, &registers.L); }
void CPU::LD_D_A() { LD(&registers.D, &registers.A); }

void CPU::LD_E_B() { LD(&registers.E, &registers.B); }
void CPU::LD_E_C() { LD(&registers.E, &registers.C); }
void CPU::LD_E_D() { LD(&registers.E, &registers.D); }
void CPU::LD_E_E() { LD(&registers.E, &registers.E); }  // Optimizable
void CPU::LD_E_H() { LD(&registers.E, &registers.H); }
void CPU::LD_E_L() { LD(&registers.E, &registers.L); }
void CPU::LD_E_A() { LD(&registers.E, &registers.A); }

void CPU::LD_H_B() { LD(&registers.H, &registers.B); }
void CPU::LD_H_C() { LD(&registers.H, &registers.C); }
void CPU::LD_H_D() { LD(&registers.H, &registers.D); }
void CPU::LD_H_E() { LD(&registers.H, &registers.E); }
void CPU::LD_H_H() { LD(&registers.H, &registers.H); }  // Optimizable
void CPU::LD_H_L() { LD(&registers.H, &registers.L); }
void CPU::LD_H_A() { LD(&registers.H, &registers.A); }

void CPU::LD_L_B() { LD(&registers.L, &registers.B); }
void CPU::LD_L_C() { LD(&registers.L, &registers.C); }
void CPU::LD_L_D() { LD(&registers.L, &registers.D); }
void CPU::LD_L_E() { LD(&registers.L, &registers.E); }
void CPU::LD_L_H() { LD(&registers.L, &registers.H); }
void CPU::LD_L_L() { LD(&registers.L, &registers.L); }  // Optimizable
void CPU::LD_L_A() { LD(&registers.L, &registers.A); }

void CPU::LD_B_ADDR_HL() { LD(&registers.B, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::LD_C_ADDR_HL() { LD(&registers.C, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::LD_D_ADDR_HL() { LD(&registers.D, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::LD_E_ADDR_HL() { LD(&registers.E, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::LD_H_ADDR_HL() { LD(&registers.H, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::LD_L_ADDR_HL() { LD(&registers.L, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::LD_A_ADDR_HL() { LD(&registers.A, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::LD_ADDR_HL_B() { memory.Write8(registers.Pair(registers.H, registers.L), registers.B); }
void CPU::LD_ADDR_HL_C() { memory.Write8(registers.Pair(registers.H, registers.L), registers.C); }
void CPU::LD_ADDR_HL_D() { memory.Write8(registers.Pair(registers.H, registers.L), registers.D); }
void CPU::LD_ADDR_HL_E() { memory.Write8(registers.Pair(registers.H, registers.L), registers.E); }
void CPU::LD_ADDR_HL_H() { memory.Write8(registers.Pair(registers.H, registers.L), registers.H); }
void CPU::LD_ADDR_HL_L() { memory.Write8(registers.Pair(registers.H, registers.L), registers.L); }
void CPU::LD_ADDR_HL_A() { memory.Write8(registers.Pair(registers.H, registers.L), registers.A); }
void CPU::LD_ADDR_BC_A() { memory.Write8(registers.Pair(registers.B, registers.C), registers.A); }
void CPU::LD_ADDR_DE_A() { memory.Write8(registers.Pair(registers.D, registers.E), registers.A); }
void CPU::LD_ADDR_HLp_A() {
    memory.Write8(registers.Pair(registers.H, registers.L), registers.A);
    uint16_t hlp = registers.Pair(registers.H, registers.L) + 1; registers.H = hlp >> 8; registers.L = hlp;
}
void CPU::LD_ADDR_HLm_A() {
    memory.Write8(registers.Pair(registers.H, registers.L), registers.A);
    uint16_t hlm = registers.Pair(registers.H, registers.L) - 1; registers.H = hlm >> 8; registers.L = (uint8_t)hlm;
}
void CPU::LD_ADDR_U16_A() { memory.Write8(memory.Read16(registers.PC), registers.A); }
void CPU::LD_ADDR_U16_SP() { memory.Write8(memory.Read16(registers.PC), registers.SP); }
void CPU::LD_ADDR_HL_U8() { memory.Write8(registers.Pair(registers.H, registers.L), memory.Read8(registers.PC)); }

void CPU::LD_A_B() { LD(&registers.A, &registers.B); }
void CPU::LD_A_C() { LD(&registers.A, &registers.C); }
void CPU::LD_A_D() { LD(&registers.A, &registers.D); }
void CPU::LD_A_E() { LD(&registers.A, &registers.E); }
void CPU::LD_A_H() { LD(&registers.A, &registers.H); }
void CPU::LD_A_L() { LD(&registers.A, &registers.L); }
void CPU::LD_A_A() { LD(&registers.A, &registers.A); }  // Optimizable

void CPU::LD_OFF_U8_A() { memory.Write8(0xFF00 + memory.Read8(registers.PC), registers.A); }
void CPU::LD_A_OFF_U8() { LD(&registers.A, memory.GetHostAddress(0xFF00 + memory.Read8(registers.PC))); }
void CPU::LD_A_OFF_C() { LD(&registers.A, memory.GetHostAddress(0xFF00 + registers.C)); }
void CPU::LD_OFF_C_A() { memory.Write8(0xFF00 + registers.C, registers.A); }


// -- ALU -- 
void CPU::INC_B() { INC(&registers.B); }
void CPU::DEC_B() { DEC(&registers.B); }
void CPU::INC_C() { INC(&registers.C); }
void CPU::DEC_C() { DEC(&registers.C); }
void CPU::INC_D() { INC(&registers.D); }
void CPU::DEC_D() { DEC(&registers.D); }
void CPU::INC_E() { INC(&registers.E); }
void CPU::DEC_E() { DEC(&registers.E); }
void CPU::INC_H() { INC(&registers.H); }
void CPU::DEC_H() { DEC(&registers.H); }
void CPU::INC_L() { INC(&registers.L); }
void CPU::DEC_L() { DEC(&registers.L); }
void CPU::INC_A() { INC(&registers.A); }
void CPU::DEC_A() { DEC(&registers.A); }

void CPU::INC_BC() { INC16(&registers.B, &registers.C); }
void CPU::DEC_BC() { DEC16(&registers.B, &registers.C); }
void CPU::INC_DE() { INC16(&registers.D, &registers.E); }
void CPU::DEC_DE() { DEC16(&registers.D, &registers.E); }
void CPU::INC_HL() { INC16(&registers.H, &registers.L); }
void CPU::DEC_HL() { DEC16(&registers.H, &registers.L); }
void CPU::INC_SP() { registers.SP++; }
void CPU::DEC_SP() { registers.SP--; }

void CPU::INC_ADDR_HL() { INC(memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::DEC_ADDR_HL() { DEC(memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::ADD_A_B() { ADD(&registers.A, &registers.B); }
void CPU::ADD_A_C() { ADD(&registers.A, &registers.C); }
void CPU::ADD_A_D() { ADD(&registers.A, &registers.D); }
void CPU::ADD_A_E() { ADD(&registers.A, &registers.E); }
void CPU::ADD_A_H() { ADD(&registers.A, &registers.H); }
void CPU::ADD_A_L() { ADD(&registers.A, &registers.L); }
void CPU::ADD_A_A() { ADD(&registers.A, &registers.A); }  // Optimizable
void CPU::ADD_A_U8() { ADD(&registers.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::ADD_A_ADDR_HL() { ADD(&registers.A, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::ADC_A_B() { ADC(&registers.A, &registers.B); }
void CPU::ADC_A_C() { ADC(&registers.A, &registers.C); }
void CPU::ADC_A_D() { ADC(&registers.A, &registers.D); }
void CPU::ADC_A_E() { ADC(&registers.A, &registers.E); }
void CPU::ADC_A_H() { ADC(&registers.A, &registers.H); }
void CPU::ADC_A_L() { ADC(&registers.A, &registers.L); }
void CPU::ADC_A_A() { ADC(&registers.A, &registers.A); }  // Optimizable
void CPU::ADC_A_U8() { ADC(&registers.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::ADC_A_ADDR_HL() { ADC(&registers.A, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::ADD_HL_BC() { ADD(registers.Pair(registers.H, registers.L), registers.Pair(registers.B, registers.C)); }
void CPU::ADD_HL_DE() { ADD(registers.Pair(registers.H, registers.L), registers.Pair(registers.D, registers.E)); }
void CPU::ADD_HL_HL() { ADD(registers.Pair(registers.H, registers.L), registers.Pair(registers.H, registers.L)); }  // Optimizable
void CPU::ADD_HL_SP() { ADD(registers.Pair(registers.H, registers.L), registers.SP); }
void CPU::ADD_SP_I8() {
    uint32_t res = registers.SP + (int8_t)memory.Read8(registers.PC);
    flags.Z ^= flags.Z;
    flags.N ^= flags.N;
    flags.C = ((res & 0x100000000) != 0);
    flags.H = (((registers.SP & 0xfff) + ((int8_t)memory.Read8(registers.PC) & 0xfff)) & 0x1000) != 0;

    registers.SP = (uint16_t)res;
}

void CPU::SUB_A_B() { SUB(&registers.A, &registers.B); }
void CPU::SUB_A_C() { SUB(&registers.A, &registers.C); }
void CPU::SUB_A_D() { SUB(&registers.A, &registers.D); }
void CPU::SUB_A_E() { SUB(&registers.A, &registers.E); }
void CPU::SUB_A_H() { SUB(&registers.A, &registers.H); }
void CPU::SUB_A_L() { SUB(&registers.A, &registers.L); }
void CPU::SUB_A_A() { SUB(&registers.A, &registers.A); }
void CPU::SUB_A_U8() { SUB(&registers.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::SUB_A_ADDR_HL() { SUB(&registers.A, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::SBC_A_B() { SBC(&registers.A, &registers.B); }
void CPU::SBC_A_C() { SBC(&registers.A, &registers.C); }
void CPU::SBC_A_D() { SBC(&registers.A, &registers.D); }
void CPU::SBC_A_E() { SBC(&registers.A, &registers.E); }
void CPU::SBC_A_H() { SBC(&registers.A, &registers.H); }
void CPU::SBC_A_L() { SBC(&registers.A, &registers.L); }
void CPU::SBC_A_A() { SBC(&registers.A, &registers.A); }  // Optimizable
void CPU::SBC_A_U8() { SBC(&registers.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::SBC_A_ADDR_HL() { SBC(&registers.A, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::AND_A_B() { AND(&registers.A, &registers.B); }
void CPU::AND_A_C() { AND(&registers.A, &registers.C); }
void CPU::AND_A_D() { AND(&registers.A, &registers.D); }
void CPU::AND_A_E() { AND(&registers.A, &registers.E); }
void CPU::AND_A_H() { AND(&registers.A, &registers.H); }
void CPU::AND_A_L() { AND(&registers.A, &registers.L); }
void CPU::AND_A_A() { AND(&registers.A, &registers.A); }  // Optimizable
void CPU::AND_A_U8() { AND(&registers.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::AND_A_ADDR_HL() { AND(&registers.A, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::XOR_A_B() { XOR(&registers.A, &registers.B); }
void CPU::XOR_A_C() { XOR(&registers.A, &registers.C); }
void CPU::XOR_A_D() { XOR(&registers.A, &registers.D); }
void CPU::XOR_A_E() { XOR(&registers.A, &registers.E); }
void CPU::XOR_A_H() { XOR(&registers.A, &registers.H); }
void CPU::XOR_A_L() { XOR(&registers.A, &registers.L); }
void CPU::XOR_A_A() { XOR(&registers.A, &registers.A); }  // Optimizable
void CPU::XOR_A_U8() { XOR(&registers.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::XOR_A_ADDR_HL() { XOR(&registers.A, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::OR_A_B() { OR(&registers.A, &registers.B); }
void CPU::OR_A_C() { OR(&registers.A, &registers.C); }
void CPU::OR_A_D() { OR(&registers.A, &registers.D); }
void CPU::OR_A_E() { OR(&registers.A, &registers.E); }
void CPU::OR_A_H() { OR(&registers.A, &registers.H); }
void CPU::OR_A_L() { OR(&registers.A, &registers.L); }
void CPU::OR_A_A() { OR(&registers.A, &registers.A); }  // Optimizable
void CPU::OR_A_U8() { OR(&registers.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::OR_A_ADDR_HL() { OR(&registers.A, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::CP_A_B() { CP(&registers.A, &registers.B); }
void CPU::CP_A_C() { CP(&registers.A, &registers.C); }
void CPU::CP_A_D() { CP(&registers.A, &registers.D); }
void CPU::CP_A_E() { CP(&registers.A, &registers.E); }
void CPU::CP_A_H() { CP(&registers.A, &registers.H); }
void CPU::CP_A_L() { CP(&registers.A, &registers.L); }
void CPU::CP_A_A() { CP(&registers.A, &registers.A); }
void CPU::CP_A_U8() { CP(&registers.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::CP_A_ADDR_HL() { CP(&registers.A, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }


// -- BRANCH --
void CPU::JR_I8() { JR((int8_t)memory.Read8(registers.PC)); }
void CPU::JR_C_I8() { if (flags.C) JR((int8_t)memory.Read8(registers.PC)); }
void CPU::JR_Z_I8() { if (flags.Z) JR((int8_t)memory.Read8(registers.PC)); }
void CPU::JR_NC_I8() { if (!flags.C) JR((int8_t)memory.Read8(registers.PC)); }
void CPU::JR_NZ_I8() { if (!flags.Z) JR((int8_t)memory.Read8(registers.PC)); }

void CPU::JP_U16() { JP(memory.Read16(registers.PC)); }
void CPU::JP_Z_U16() { if (flags.Z) JP(memory.Read16(registers.PC)); }
void CPU::JP_C_U16() { if (flags.C) JP(memory.Read16(registers.PC)); }
void CPU::JP_NZ_U16() { if (!flags.Z) JP(memory.Read16(registers.PC)); }
void CPU::JP_NC_U16() { if (!flags.C) JP(memory.Read16(registers.PC)); }
void CPU::JP_HL() { JP(registers.Pair(registers.H, registers.L)); }

void CPU::PUSH_BC() { PUSH(&registers.B, &registers.C); }
void CPU::PUSH_DE() { PUSH(&registers.D, &registers.E); }
void CPU::PUSH_HL() { PUSH(&registers.H, &registers.L); }
void CPU::PUSH_AF() { PUSH(&registers.A, &registers.F); }

void CPU::POP_BC() { POP(&registers.B, &registers.C); }
void CPU::POP_DE() { POP(&registers.D, &registers.E); }
void CPU::POP_HL() { POP(&registers.H, &registers.L); }
void CPU::POP_AF() { POP(&registers.A, &registers.F); }

void CPU::CALL_U16() { CALL(memory.Read16(registers.PC)); }
void CPU::CALL_Z_U16() { if (flags.Z) CALL(memory.Read16(registers.PC)); }
void CPU::CALL_C_U16() { if (flags.C) CALL(memory.Read16(registers.PC)); }
void CPU::CALL_NZ_U16() { if (!flags.Z) CALL(memory.Read16(registers.PC)); }
void CPU::CALL_NC_U16() { if (!flags.C) CALL(memory.Read16(registers.PC)); }

void CPU::RETI() { flags.IME = true; RET(); }
void CPU::RET_Z() { if (flags.Z) RET(); }
void CPU::RET_C() { if (flags.C) RET(); }
void CPU::RET_NZ() { if (!flags.Z) RET(); }
void CPU::RET_NC() { if (!flags.C) RET(); }

// -- SHIFT & ROTATE --
void CPU::RLC_B() { RLC(&registers.B); }
void CPU::RLC_C() { RLC(&registers.C); }
void CPU::RLC_D() { RLC(&registers.D); }
void CPU::RLC_E() { RLC(&registers.E); }
void CPU::RLC_H() { RLC(&registers.H); }
void CPU::RLC_L() { RLC(&registers.L); }
void CPU::RLC_A() { RLC(&registers.A); }
void CPU::RLC_ADDR_HL() { RLC(memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::RRC_B() { RRC(&registers.B); }
void CPU::RRC_C() { RRC(&registers.C); }
void CPU::RRC_D() { RRC(&registers.D); }
void CPU::RRC_E() { RRC(&registers.E); }
void CPU::RRC_H() { RRC(&registers.H); }
void CPU::RRC_L() { RRC(&registers.L); }
void CPU::RRC_A() { RRC(&registers.A); }
void CPU::RRC_ADDR_HL() { RRC(memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::RL_B() { RL(&registers.B); }
void CPU::RL_C() { RL(&registers.C); }
void CPU::RL_D() { RL(&registers.D); }
void CPU::RL_E() { RL(&registers.E); }
void CPU::RL_H() { RL(&registers.H); }
void CPU::RL_L() { RL(&registers.L); }
void CPU::RL_A() { RL(&registers.A); }
void CPU::RL_ADDR_HL() { RL(memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::RR_B() { RR(&registers.B); }
void CPU::RR_C() { RR(&registers.C); }
void CPU::RR_D() { RR(&registers.D); }
void CPU::RR_E() { RR(&registers.E); }
void CPU::RR_H() { RR(&registers.H); }
void CPU::RR_L() { RR(&registers.L); }
void CPU::RR_A() { RR(&registers.A); }
void CPU::RR_ADDR_HL() { RR(memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::SLA_B() { SLA(&registers.B); }
void CPU::SLA_C() { SLA(&registers.C); }
void CPU::SLA_D() { SLA(&registers.D); }
void CPU::SLA_E() { SLA(&registers.E); }
void CPU::SLA_H() { SLA(&registers.H); }
void CPU::SLA_L() { SLA(&registers.L); }
void CPU::SLA_A() { SLA(&registers.A); }
void CPU::SLA_ADDR_HL() { SLA(memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::SRA_B() { SRA(&registers.B); }
void CPU::SRA_C() { SRA(&registers.C); }
void CPU::SRA_D() { SRA(&registers.D); }
void CPU::SRA_E() { SRA(&registers.E); }
void CPU::SRA_H() { SRA(&registers.H); }
void CPU::SRA_L() { SRA(&registers.L); }
void CPU::SRA_A() { SRA(&registers.A); }
void CPU::SRA_ADDR_HL() { SRA(memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::SRL_B() { SRL(&registers.B); }
void CPU::SRL_C() { SRL(&registers.C); }
void CPU::SRL_D() { SRL(&registers.D); }
void CPU::SRL_E() { SRL(&registers.E); }
void CPU::SRL_H() { SRL(&registers.H); }
void CPU::SRL_L() { SRL(&registers.L); }
void CPU::SRL_A() { SRL(&registers.A); }
void CPU::SRL_ADDR_HL() { SRL(memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }


// -- BIT OPERATIONS --
void CPU::SWAP_B() { SWAP(&registers.B); }
void CPU::SWAP_C() { SWAP(&registers.C); }
void CPU::SWAP_D() { SWAP(&registers.D); }
void CPU::SWAP_E() { SWAP(&registers.E); }
void CPU::SWAP_H() { SWAP(&registers.H); }
void CPU::SWAP_L() { SWAP(&registers.L); }
void CPU::SWAP_A() { SWAP(&registers.A); }
void CPU::SWAP_ADDR_HL() { SWAP(memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::BIT_0_B() { BIT(0, &registers.B); }
void CPU::BIT_0_C() { BIT(0, &registers.C); }
void CPU::BIT_0_D() { BIT(0, &registers.D); }
void CPU::BIT_0_E() { BIT(0, &registers.E); }
void CPU::BIT_0_H() { BIT(0, &registers.H); }
void CPU::BIT_0_L() { BIT(0, &registers.L); }
void CPU::BIT_0_A() { BIT(0, &registers.A); }
void CPU::BIT_1_B() { BIT(1, &registers.B); }
void CPU::BIT_1_C() { BIT(1, &registers.C); }
void CPU::BIT_1_D() { BIT(1, &registers.D); }
void CPU::BIT_1_E() { BIT(1, &registers.E); }
void CPU::BIT_1_H() { BIT(1, &registers.H); }
void CPU::BIT_1_L() { BIT(1, &registers.L); }
void CPU::BIT_1_A() { BIT(1, &registers.A); }
void CPU::BIT_2_B() { BIT(2, &registers.B); }
void CPU::BIT_2_C() { BIT(2, &registers.C); }
void CPU::BIT_2_D() { BIT(2, &registers.D); }
void CPU::BIT_2_E() { BIT(2, &registers.E); }
void CPU::BIT_2_H() { BIT(2, &registers.H); }
void CPU::BIT_2_L() { BIT(2, &registers.L); }
void CPU::BIT_2_A() { BIT(2, &registers.A); }
void CPU::BIT_3_B() { BIT(3, &registers.B); }
void CPU::BIT_3_C() { BIT(3, &registers.C); }
void CPU::BIT_3_D() { BIT(3, &registers.D); }
void CPU::BIT_3_E() { BIT(3, &registers.E); }
void CPU::BIT_3_H() { BIT(3, &registers.H); }
void CPU::BIT_3_L() { BIT(3, &registers.L); }
void CPU::BIT_3_A() { BIT(3, &registers.A); }
void CPU::BIT_4_B() { BIT(4, &registers.B); }
void CPU::BIT_4_C() { BIT(4, &registers.C); }
void CPU::BIT_4_D() { BIT(4, &registers.D); }
void CPU::BIT_4_E() { BIT(4, &registers.E); }
void CPU::BIT_4_H() { BIT(4, &registers.H); }
void CPU::BIT_4_L() { BIT(4, &registers.L); }
void CPU::BIT_4_A() { BIT(4, &registers.A); }
void CPU::BIT_5_B() { BIT(5, &registers.B); }
void CPU::BIT_5_C() { BIT(5, &registers.C); }
void CPU::BIT_5_D() { BIT(5, &registers.D); }
void CPU::BIT_5_E() { BIT(5, &registers.E); }
void CPU::BIT_5_H() { BIT(5, &registers.H); }
void CPU::BIT_5_L() { BIT(5, &registers.L); }
void CPU::BIT_5_A() { BIT(5, &registers.A); }
void CPU::BIT_6_B() { BIT(6, &registers.B); }
void CPU::BIT_6_C() { BIT(6, &registers.C); }
void CPU::BIT_6_D() { BIT(6, &registers.D); }
void CPU::BIT_6_E() { BIT(6, &registers.E); }
void CPU::BIT_6_H() { BIT(6, &registers.H); }
void CPU::BIT_6_L() { BIT(6, &registers.L); }
void CPU::BIT_6_A() { BIT(6, &registers.A); }
void CPU::BIT_7_B() { BIT(7, &registers.B); }
void CPU::BIT_7_C() { BIT(7, &registers.C); }
void CPU::BIT_7_D() { BIT(7, &registers.D); }
void CPU::BIT_7_E() { BIT(7, &registers.E); }
void CPU::BIT_7_H() { BIT(7, &registers.H); }
void CPU::BIT_7_L() { BIT(7, &registers.L); }
void CPU::BIT_7_A() { BIT(7, &registers.A); }
void CPU::BIT_0_ADDR_HL() { BIT(0, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::BIT_1_ADDR_HL() { BIT(1, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::BIT_2_ADDR_HL() { BIT(2, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::BIT_3_ADDR_HL() { BIT(3, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::BIT_4_ADDR_HL() { BIT(4, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::BIT_5_ADDR_HL() { BIT(5, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::BIT_6_ADDR_HL() { BIT(6, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::BIT_7_ADDR_HL() { BIT(7, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::RES_0_B() { RES(0, &registers.B); }
void CPU::RES_0_C() { RES(0, &registers.C); }
void CPU::RES_0_D() { RES(0, &registers.D); }
void CPU::RES_0_E() { RES(0, &registers.E); }
void CPU::RES_0_H() { RES(0, &registers.H); }
void CPU::RES_0_L() { RES(0, &registers.L); }
void CPU::RES_0_A() { RES(0, &registers.A); }
void CPU::RES_1_B() { RES(1, &registers.B); }
void CPU::RES_1_C() { RES(1, &registers.C); }
void CPU::RES_1_D() { RES(1, &registers.D); }
void CPU::RES_1_E() { RES(1, &registers.E); }
void CPU::RES_1_H() { RES(1, &registers.H); }
void CPU::RES_1_L() { RES(1, &registers.L); }
void CPU::RES_1_A() { RES(1, &registers.A); }
void CPU::RES_2_B() { RES(2, &registers.B); }
void CPU::RES_2_C() { RES(2, &registers.C); }
void CPU::RES_2_D() { RES(2, &registers.D); }
void CPU::RES_2_E() { RES(2, &registers.E); }
void CPU::RES_2_H() { RES(2, &registers.H); }
void CPU::RES_2_L() { RES(2, &registers.L); }
void CPU::RES_2_A() { RES(2, &registers.A); }
void CPU::RES_3_B() { RES(3, &registers.B); }
void CPU::RES_3_C() { RES(3, &registers.C); }
void CPU::RES_3_D() { RES(3, &registers.D); }
void CPU::RES_3_E() { RES(3, &registers.E); }
void CPU::RES_3_H() { RES(3, &registers.H); }
void CPU::RES_3_L() { RES(3, &registers.L); }
void CPU::RES_3_A() { RES(3, &registers.A); }
void CPU::RES_4_B() { RES(4, &registers.B); }
void CPU::RES_4_C() { RES(4, &registers.C); }
void CPU::RES_4_D() { RES(4, &registers.D); }
void CPU::RES_4_E() { RES(4, &registers.E); }
void CPU::RES_4_H() { RES(4, &registers.H); }
void CPU::RES_4_L() { RES(4, &registers.L); }
void CPU::RES_4_A() { RES(4, &registers.A); }
void CPU::RES_5_B() { RES(5, &registers.B); }
void CPU::RES_5_C() { RES(5, &registers.C); }
void CPU::RES_5_D() { RES(5, &registers.D); }
void CPU::RES_5_E() { RES(5, &registers.E); }
void CPU::RES_5_H() { RES(5, &registers.H); }
void CPU::RES_5_L() { RES(5, &registers.L); }
void CPU::RES_5_A() { RES(5, &registers.A); }
void CPU::RES_6_B() { RES(6, &registers.B); }
void CPU::RES_6_C() { RES(6, &registers.C); }
void CPU::RES_6_D() { RES(6, &registers.D); }
void CPU::RES_6_E() { RES(6, &registers.E); }
void CPU::RES_6_H() { RES(6, &registers.H); }
void CPU::RES_6_L() { RES(6, &registers.L); }
void CPU::RES_6_A() { RES(6, &registers.A); }
void CPU::RES_7_B() { RES(7, &registers.B); }
void CPU::RES_7_C() { RES(7, &registers.C); }
void CPU::RES_7_D() { RES(7, &registers.D); }
void CPU::RES_7_E() { RES(7, &registers.E); }
void CPU::RES_7_H() { RES(7, &registers.H); }
void CPU::RES_7_L() { RES(7, &registers.L); }
void CPU::RES_7_A() { RES(7, &registers.A); }
void CPU::RES_0_ADDR_HL() { RES(0, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::RES_1_ADDR_HL() { RES(1, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::RES_2_ADDR_HL() { RES(2, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::RES_3_ADDR_HL() { RES(3, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::RES_4_ADDR_HL() { RES(4, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::RES_5_ADDR_HL() { RES(5, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::RES_6_ADDR_HL() { RES(6, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::RES_7_ADDR_HL() { RES(7, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }

void CPU::SET_0_B() { SET(0, &registers.B); }
void CPU::SET_0_C() { SET(0, &registers.C); }
void CPU::SET_0_D() { SET(0, &registers.D); }
void CPU::SET_0_E() { SET(0, &registers.E); }
void CPU::SET_0_H() { SET(0, &registers.H); }
void CPU::SET_0_L() { SET(0, &registers.L); }
void CPU::SET_0_A() { SET(0, &registers.A); }
void CPU::SET_1_B() { SET(1, &registers.B); }
void CPU::SET_1_C() { SET(1, &registers.C); }
void CPU::SET_1_D() { SET(1, &registers.D); }
void CPU::SET_1_E() { SET(1, &registers.E); }
void CPU::SET_1_H() { SET(1, &registers.H); }
void CPU::SET_1_L() { SET(1, &registers.L); }
void CPU::SET_1_A() { SET(1, &registers.A); }
void CPU::SET_2_B() { SET(2, &registers.B); }
void CPU::SET_2_C() { SET(2, &registers.C); }
void CPU::SET_2_D() { SET(2, &registers.D); }
void CPU::SET_2_E() { SET(2, &registers.E); }
void CPU::SET_2_H() { SET(2, &registers.H); }
void CPU::SET_2_L() { SET(2, &registers.L); }
void CPU::SET_2_A() { SET(2, &registers.A); }
void CPU::SET_3_B() { SET(3, &registers.B); }
void CPU::SET_3_C() { SET(3, &registers.C); }
void CPU::SET_3_D() { SET(3, &registers.D); }
void CPU::SET_3_E() { SET(3, &registers.E); }
void CPU::SET_3_H() { SET(3, &registers.H); }
void CPU::SET_3_L() { SET(3, &registers.L); }
void CPU::SET_3_A() { SET(3, &registers.A); }
void CPU::SET_4_B() { SET(4, &registers.B); }
void CPU::SET_4_C() { SET(4, &registers.C); }
void CPU::SET_4_D() { SET(4, &registers.D); }
void CPU::SET_4_E() { SET(4, &registers.E); }
void CPU::SET_4_H() { SET(4, &registers.H); }
void CPU::SET_4_L() { SET(4, &registers.L); }
void CPU::SET_4_A() { SET(4, &registers.A); }
void CPU::SET_5_B() { SET(5, &registers.B); }
void CPU::SET_5_C() { SET(5, &registers.C); }
void CPU::SET_5_D() { SET(5, &registers.D); }
void CPU::SET_5_E() { SET(5, &registers.E); }
void CPU::SET_5_H() { SET(5, &registers.H); }
void CPU::SET_5_L() { SET(5, &registers.L); }
void CPU::SET_5_A() { SET(5, &registers.A); }
void CPU::SET_6_B() { SET(6, &registers.B); }
void CPU::SET_6_C() { SET(6, &registers.C); }
void CPU::SET_6_D() { SET(6, &registers.D); }
void CPU::SET_6_E() { SET(6, &registers.E); }
void CPU::SET_6_H() { SET(6, &registers.H); }
void CPU::SET_6_L() { SET(6, &registers.L); }
void CPU::SET_6_A() { SET(6, &registers.A); }
void CPU::SET_7_B() { SET(7, &registers.B); }
void CPU::SET_7_C() { SET(7, &registers.C); }
void CPU::SET_7_D() { SET(7, &registers.D); }
void CPU::SET_7_E() { SET(7, &registers.E); }
void CPU::SET_7_H() { SET(7, &registers.H); }
void CPU::SET_7_L() { SET(7, &registers.L); }
void CPU::SET_7_A() { SET(7, &registers.A); }
void CPU::SET_0_ADDR_HL() { SET(0, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::SET_1_ADDR_HL() { SET(1, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::SET_2_ADDR_HL() { SET(2, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::SET_3_ADDR_HL() { SET(3, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::SET_4_ADDR_HL() { SET(4, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::SET_5_ADDR_HL() { SET(5, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::SET_6_ADDR_HL() { SET(6, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }
void CPU::SET_7_ADDR_HL() { SET(7, memory.GetHostAddress(registers.Pair(registers.H, registers.L))); }


// -- SYSTEM --
void CPU::STOP() { /* standby */ }
void CPU::HALT() { /* Wait for interrupt */ }
void CPU::DAA() { /* decimal adjust A */ }
void CPU::CPL() {
    registers.A ^= 0xFF;
    flags.N = 1;
    flags.H = 1;
}
void CPU::SCF() {
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.C = 1;
}
void CPU::CCF() {
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.C = flags.C ^ 1;
}
void CPU::DI() { flags.IME = 0; }
void CPU::EI() { flags.IME = 1; }


// -- RST --
void CPU::RST_00H() { CALL(0x00); }
void CPU::RST_08H() { CALL(0x08); }
void CPU::RST_10H() { CALL(0x10); }
void CPU::RST_18H() { CALL(0x18); }
void CPU::RST_20H() { CALL(0x20); }
void CPU::RST_28H() { CALL(0x28); }
void CPU::RST_30H() { CALL(0x30); }
void CPU::RST_38H() { CALL(0x38); }