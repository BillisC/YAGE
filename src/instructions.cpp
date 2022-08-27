#include "cpu.h"

// nop
void CPU::NOP() {}

// -- LOAD --
void CPU::LD_B_U8() { LD(&registers.BC.solo.B, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_C_U8() { LD(&registers.BC.solo.C, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_D_U8() { LD(&registers.DE.solo.D, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_E_U8() { LD(&registers.DE.solo.E, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_H_U8() { LD(&registers.HL.solo.H, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_L_U8() { LD(&registers.HL.solo.L, memory.GetHostAddress(registers.PC + 1)); }
void CPU::LD_A_U8() { LD(&registers.AF.solo.A, memory.GetHostAddress(registers.PC + 1)); }

void CPU::LD_SP_U16() { LD16(&registers.SP, memory.Read16(registers.PC)); }
void CPU::LD_SP_HL() { LD16(&registers.SP, registers.HL.pair); }

void CPU::LD_A_ADDR_BC() { LD(&registers.AF.solo.A, memory.GetHostAddress(registers.BC.pair)); }
void CPU::LD_A_ADDR_DE() { LD(&registers.AF.solo.A, memory.GetHostAddress(registers.DE.pair)); }
void CPU::LD_A_ADDR_HLp() {
    LD(&registers.AF.solo.A, memory.GetHostAddress(registers.HL.pair));
    registers.HL.pair++;
}
void CPU::LD_A_ADDR_HLm() {
    LD(&registers.AF.solo.A, memory.GetHostAddress(registers.HL.pair));
    registers.HL.pair--;
}
void CPU::LD_A_ADDR_U16() { LD(&registers.AF.solo.A, memory.GetHostAddress(memory.Read16(registers.PC))); }

void CPU::LD_BC_U16() { LD16(&registers.BC.pair); }
void CPU::LD_DE_U16() { LD16(&registers.DE.pair); }
void CPU::LD_HL_U16() { LD16(&registers.HL.pair); }
void CPU::LD_HL_SPpI8() {
    registers.HL.pair = registers.SP + (int8_t)memory.Read8(registers.PC);
}

void CPU::LD_B_B() { LD(&registers.BC.solo.B, &registers.BC.solo.B); }  // Optimizable
void CPU::LD_B_C() { LD(&registers.BC.solo.B, &registers.BC.solo.C); }
void CPU::LD_B_D() { LD(&registers.BC.solo.B, &registers.DE.solo.D); }
void CPU::LD_B_E() { LD(&registers.BC.solo.B, &registers.DE.solo.E); }
void CPU::LD_B_H() { LD(&registers.BC.solo.B, &registers.HL.solo.H); }
void CPU::LD_B_L() { LD(&registers.BC.solo.B, &registers.HL.solo.L); }
void CPU::LD_B_A() { LD(&registers.BC.solo.B, &registers.AF.solo.A); }

void CPU::LD_C_B() { LD(&registers.BC.solo.C, &registers.BC.solo.B); }
void CPU::LD_C_C() { LD(&registers.BC.solo.C, &registers.BC.solo.C); }  // Optimizable
void CPU::LD_C_D() { LD(&registers.BC.solo.C, &registers.DE.solo.D); }
void CPU::LD_C_E() { LD(&registers.BC.solo.C, &registers.DE.solo.E); }
void CPU::LD_C_H() { LD(&registers.BC.solo.C, &registers.HL.solo.H); }
void CPU::LD_C_L() { LD(&registers.BC.solo.C, &registers.HL.solo.L); }
void CPU::LD_C_A() { LD(&registers.BC.solo.C, &registers.AF.solo.A); }

void CPU::LD_D_B() { LD(&registers.DE.solo.D, &registers.BC.solo.B); }
void CPU::LD_D_C() { LD(&registers.DE.solo.D, &registers.BC.solo.C); }
void CPU::LD_D_D() { LD(&registers.DE.solo.D, &registers.DE.solo.D); }  // Optimizable
void CPU::LD_D_E() { LD(&registers.DE.solo.D, &registers.DE.solo.E); }
void CPU::LD_D_H() { LD(&registers.DE.solo.D, &registers.HL.solo.H); }
void CPU::LD_D_L() { LD(&registers.DE.solo.D, &registers.HL.solo.L); }
void CPU::LD_D_A() { LD(&registers.DE.solo.D, &registers.AF.solo.A); }

void CPU::LD_E_B() { LD(&registers.DE.solo.E, &registers.BC.solo.B); }
void CPU::LD_E_C() { LD(&registers.DE.solo.E, &registers.BC.solo.C); }
void CPU::LD_E_D() { LD(&registers.DE.solo.E, &registers.DE.solo.D); }
void CPU::LD_E_E() { LD(&registers.DE.solo.E, &registers.DE.solo.E); }  // Optimizable
void CPU::LD_E_H() { LD(&registers.DE.solo.E, &registers.HL.solo.H); }
void CPU::LD_E_L() { LD(&registers.DE.solo.E, &registers.HL.solo.L); }
void CPU::LD_E_A() { LD(&registers.DE.solo.E, &registers.AF.solo.A); }

void CPU::LD_H_B() { LD(&registers.HL.solo.H, &registers.BC.solo.B); }
void CPU::LD_H_C() { LD(&registers.HL.solo.H, &registers.BC.solo.C); }
void CPU::LD_H_D() { LD(&registers.HL.solo.H, &registers.DE.solo.D); }
void CPU::LD_H_E() { LD(&registers.HL.solo.H, &registers.DE.solo.E); }
void CPU::LD_H_H() { LD(&registers.HL.solo.H, &registers.HL.solo.H); }  // Optimizable
void CPU::LD_H_L() { LD(&registers.HL.solo.H, &registers.HL.solo.L); }
void CPU::LD_H_A() { LD(&registers.HL.solo.H, &registers.AF.solo.A); }

void CPU::LD_L_B() { LD(&registers.HL.solo.L, &registers.BC.solo.B); }
void CPU::LD_L_C() { LD(&registers.HL.solo.L, &registers.BC.solo.C); }
void CPU::LD_L_D() { LD(&registers.HL.solo.L, &registers.DE.solo.D); }
void CPU::LD_L_E() { LD(&registers.HL.solo.L, &registers.DE.solo.E); }
void CPU::LD_L_H() { LD(&registers.HL.solo.L, &registers.HL.solo.H); }
void CPU::LD_L_L() { LD(&registers.HL.solo.L, &registers.HL.solo.L); }  // Optimizable
void CPU::LD_L_A() { LD(&registers.HL.solo.L, &registers.AF.solo.A); }

void CPU::LD_B_ADDR_HL() { LD(&registers.BC.solo.B, memory.GetHostAddress(registers.HL.pair)); }
void CPU::LD_C_ADDR_HL() { LD(&registers.BC.solo.C, memory.GetHostAddress(registers.HL.pair)); }
void CPU::LD_D_ADDR_HL() { LD(&registers.DE.solo.D, memory.GetHostAddress(registers.HL.pair)); }
void CPU::LD_E_ADDR_HL() { LD(&registers.DE.solo.E, memory.GetHostAddress(registers.HL.pair)); }
void CPU::LD_H_ADDR_HL() { LD(&registers.HL.solo.H, memory.GetHostAddress(registers.HL.pair)); }
void CPU::LD_L_ADDR_HL() { LD(&registers.HL.solo.L, memory.GetHostAddress(registers.HL.pair)); }
void CPU::LD_A_ADDR_HL() { LD(&registers.AF.solo.A, memory.GetHostAddress(registers.HL.pair)); }

void CPU::LD_ADDR_HL_B() { memory.Write8(registers.HL.pair, registers.BC.solo.B); }
void CPU::LD_ADDR_HL_C() { memory.Write8(registers.HL.pair, registers.BC.solo.C); }
void CPU::LD_ADDR_HL_D() { memory.Write8(registers.HL.pair, registers.DE.solo.D); }
void CPU::LD_ADDR_HL_E() { memory.Write8(registers.HL.pair, registers.DE.solo.E); }
void CPU::LD_ADDR_HL_H() { memory.Write8(registers.HL.pair, registers.HL.solo.H); }
void CPU::LD_ADDR_HL_L() { memory.Write8(registers.HL.pair, registers.HL.solo.L); }
void CPU::LD_ADDR_HL_A() { memory.Write8(registers.HL.pair, registers.AF.solo.A); }
void CPU::LD_ADDR_BC_A() { memory.Write8(registers.BC.pair, registers.AF.solo.A); }
void CPU::LD_ADDR_DE_A() { memory.Write8(registers.DE.pair, registers.AF.solo.A); }
void CPU::LD_ADDR_HLp_A() {
    memory.Write8(registers.HL.pair, registers.AF.solo.A);
    registers.HL.pair++;
}
void CPU::LD_ADDR_HLm_A() {
    memory.Write8(registers.HL.pair, registers.AF.solo.A);
    registers.HL.pair--;
}
void CPU::LD_ADDR_U16_A() { memory.Write8(memory.Read16(registers.PC), registers.AF.solo.A); }
void CPU::LD_ADDR_U16_SP() { memory.Write8(memory.Read16(registers.PC), registers.SP); }
void CPU::LD_ADDR_HL_U8() { memory.Write8(registers.HL.pair, memory.Read8(registers.PC)); }

void CPU::LD_A_B() { LD(&registers.AF.solo.A, &registers.BC.solo.B); }
void CPU::LD_A_C() { LD(&registers.AF.solo.A, &registers.BC.solo.C); }
void CPU::LD_A_D() { LD(&registers.AF.solo.A, &registers.DE.solo.D); }
void CPU::LD_A_E() { LD(&registers.AF.solo.A, &registers.DE.solo.E); }
void CPU::LD_A_H() { LD(&registers.AF.solo.A, &registers.HL.solo.H); }
void CPU::LD_A_L() { LD(&registers.AF.solo.A, &registers.HL.solo.L); }
void CPU::LD_A_A() { LD(&registers.AF.solo.A, &registers.AF.solo.A); }  // Optimizable

void CPU::LD_OFF_U8_A() { memory.Write8(0xFF00 + memory.Read8(registers.PC), registers.AF.solo.A); }
void CPU::LD_A_OFF_U8() { LD(&registers.AF.solo.A, memory.GetHostAddress(0xFF00 + memory.Read8(registers.PC))); }
void CPU::LD_A_OFF_C() { LD(&registers.AF.solo.A, memory.GetHostAddress(0xFF00 + registers.BC.solo.C)); }
void CPU::LD_OFF_C_A() { memory.Write8(0xFF00 + registers.BC.solo.C, registers.AF.solo.A); }


// -- ALU -- 
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

void CPU::INC_BC() { INC16(&registers.BC.solo.B, &registers.BC.solo.C); }
void CPU::DEC_BC() { DEC16(&registers.BC.solo.B, &registers.BC.solo.C); }
void CPU::INC_DE() { INC16(&registers.DE.solo.D, &registers.DE.solo.E); }
void CPU::DEC_DE() { DEC16(&registers.DE.solo.D, &registers.DE.solo.E); }
void CPU::INC_HL() { INC16(&registers.HL.solo.H, &registers.HL.solo.L); }
void CPU::DEC_HL() { DEC16(&registers.HL.solo.H, &registers.HL.solo.L); }
void CPU::INC_SP() { registers.SP++; }
void CPU::DEC_SP() { registers.SP--; }

void CPU::INC_ADDR_HL() { INC(memory.GetHostAddress(registers.HL.pair)); }
void CPU::DEC_ADDR_HL() { DEC(memory.GetHostAddress(registers.HL.pair)); }

void CPU::ADD_A_B() { ADD(&registers.AF.solo.A, &registers.BC.solo.B); }
void CPU::ADD_A_C() { ADD(&registers.AF.solo.A, &registers.BC.solo.C); }
void CPU::ADD_A_D() { ADD(&registers.AF.solo.A, &registers.DE.solo.D); }
void CPU::ADD_A_E() { ADD(&registers.AF.solo.A, &registers.DE.solo.E); }
void CPU::ADD_A_H() { ADD(&registers.AF.solo.A, &registers.HL.solo.H); }
void CPU::ADD_A_L() { ADD(&registers.AF.solo.A, &registers.HL.solo.L); }
void CPU::ADD_A_A() { ADD(&registers.AF.solo.A, &registers.AF.solo.A); }  // Optimizable
void CPU::ADD_A_U8() { ADD(&registers.AF.solo.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::ADD_A_ADDR_HL() { ADD(&registers.AF.solo.A, memory.GetHostAddress(registers.HL.pair)); }

void CPU::ADC_A_B() { ADC(&registers.AF.solo.A, &registers.BC.solo.B); }
void CPU::ADC_A_C() { ADC(&registers.AF.solo.A, &registers.BC.solo.C); }
void CPU::ADC_A_D() { ADC(&registers.AF.solo.A, &registers.DE.solo.D); }
void CPU::ADC_A_E() { ADC(&registers.AF.solo.A, &registers.DE.solo.E); }
void CPU::ADC_A_H() { ADC(&registers.AF.solo.A, &registers.HL.solo.H); }
void CPU::ADC_A_L() { ADC(&registers.AF.solo.A, &registers.HL.solo.L); }
void CPU::ADC_A_A() { ADC(&registers.AF.solo.A, &registers.AF.solo.A); }  // Optimizable
void CPU::ADC_A_U8() { ADC(&registers.AF.solo.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::ADC_A_ADDR_HL() { ADC(&registers.AF.solo.A, memory.GetHostAddress(registers.HL.pair)); }

void CPU::ADD_HL_BC() { ADD(registers.HL.pair, registers.BC.pair); }
void CPU::ADD_HL_DE() { ADD(registers.HL.pair, registers.DE.pair); }
void CPU::ADD_HL_HL() { ADD(registers.HL.pair, registers.HL.pair); }  // Optimizable
void CPU::ADD_HL_SP() { ADD(registers.HL.pair, registers.SP); }
void CPU::ADD_SP_I8() {
    uint32_t res = registers.SP + (int8_t)memory.Read8(registers.PC);
    flags.Z ^= flags.Z;
    flags.N ^= flags.N;
    flags.C = ((res & 0x100000000) != 0);
    flags.H = (((registers.SP & 0xfff) + ((int8_t)memory.Read8(registers.PC) & 0xfff)) & 0x1000) != 0;

    registers.SP = (uint16_t)res;
}

void CPU::SUB_A_B() { SUB(&registers.AF.solo.A, &registers.BC.solo.B); }
void CPU::SUB_A_C() { SUB(&registers.AF.solo.A, &registers.BC.solo.C); }
void CPU::SUB_A_D() { SUB(&registers.AF.solo.A, &registers.DE.solo.D); }
void CPU::SUB_A_E() { SUB(&registers.AF.solo.A, &registers.DE.solo.E); }
void CPU::SUB_A_H() { SUB(&registers.AF.solo.A, &registers.HL.solo.H); }
void CPU::SUB_A_L() { SUB(&registers.AF.solo.A, &registers.HL.solo.L); }
void CPU::SUB_A_A() { SUB(&registers.AF.solo.A, &registers.AF.solo.A); }
void CPU::SUB_A_U8() { SUB(&registers.AF.solo.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::SUB_A_ADDR_HL() { SUB(&registers.AF.solo.A, memory.GetHostAddress(registers.HL.pair)); }

void CPU::SBC_A_B() { SBC(&registers.AF.solo.A, &registers.BC.solo.B); }
void CPU::SBC_A_C() { SBC(&registers.AF.solo.A, &registers.BC.solo.C); }
void CPU::SBC_A_D() { SBC(&registers.AF.solo.A, &registers.DE.solo.D); }
void CPU::SBC_A_E() { SBC(&registers.AF.solo.A, &registers.DE.solo.E); }
void CPU::SBC_A_H() { SBC(&registers.AF.solo.A, &registers.HL.solo.H); }
void CPU::SBC_A_L() { SBC(&registers.AF.solo.A, &registers.HL.solo.L); }
void CPU::SBC_A_A() { SBC(&registers.AF.solo.A, &registers.AF.solo.A); }  // Optimizable
void CPU::SBC_A_U8() { SBC(&registers.AF.solo.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::SBC_A_ADDR_HL() { SBC(&registers.AF.solo.A, memory.GetHostAddress(registers.HL.pair)); }

void CPU::AND_A_B() { AND(&registers.AF.solo.A, &registers.BC.solo.B); }
void CPU::AND_A_C() { AND(&registers.AF.solo.A, &registers.BC.solo.C); }
void CPU::AND_A_D() { AND(&registers.AF.solo.A, &registers.DE.solo.D); }
void CPU::AND_A_E() { AND(&registers.AF.solo.A, &registers.DE.solo.E); }
void CPU::AND_A_H() { AND(&registers.AF.solo.A, &registers.HL.solo.H); }
void CPU::AND_A_L() { AND(&registers.AF.solo.A, &registers.HL.solo.L); }
void CPU::AND_A_A() { AND(&registers.AF.solo.A, &registers.AF.solo.A); }  // Optimizable
void CPU::AND_A_U8() { AND(&registers.AF.solo.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::AND_A_ADDR_HL() { AND(&registers.AF.solo.A, memory.GetHostAddress(registers.HL.pair)); }

void CPU::XOR_A_B() { XOR(&registers.AF.solo.A, &registers.BC.solo.B); }
void CPU::XOR_A_C() { XOR(&registers.AF.solo.A, &registers.BC.solo.C); }
void CPU::XOR_A_D() { XOR(&registers.AF.solo.A, &registers.DE.solo.D); }
void CPU::XOR_A_E() { XOR(&registers.AF.solo.A, &registers.DE.solo.E); }
void CPU::XOR_A_H() { XOR(&registers.AF.solo.A, &registers.HL.solo.H); }
void CPU::XOR_A_L() { XOR(&registers.AF.solo.A, &registers.HL.solo.L); }
void CPU::XOR_A_A() { XOR(&registers.AF.solo.A, &registers.AF.solo.A); }  // Optimizable
void CPU::XOR_A_U8() { XOR(&registers.AF.solo.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::XOR_A_ADDR_HL() { XOR(&registers.AF.solo.A, memory.GetHostAddress(registers.HL.pair)); }

void CPU::OR_A_B() { OR(&registers.AF.solo.A, &registers.BC.solo.B); }
void CPU::OR_A_C() { OR(&registers.AF.solo.A, &registers.BC.solo.C); }
void CPU::OR_A_D() { OR(&registers.AF.solo.A, &registers.DE.solo.D); }
void CPU::OR_A_E() { OR(&registers.AF.solo.A, &registers.DE.solo.E); }
void CPU::OR_A_H() { OR(&registers.AF.solo.A, &registers.HL.solo.H); }
void CPU::OR_A_L() { OR(&registers.AF.solo.A, &registers.HL.solo.L); }
void CPU::OR_A_A() { OR(&registers.AF.solo.A, &registers.AF.solo.A); }  // Optimizable
void CPU::OR_A_U8() { OR(&registers.AF.solo.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::OR_A_ADDR_HL() { OR(&registers.AF.solo.A, memory.GetHostAddress(registers.HL.pair)); }

void CPU::CP_A_B() { CP(&registers.AF.solo.A, &registers.BC.solo.B); }
void CPU::CP_A_C() { CP(&registers.AF.solo.A, &registers.BC.solo.C); }
void CPU::CP_A_D() { CP(&registers.AF.solo.A, &registers.DE.solo.D); }
void CPU::CP_A_E() { CP(&registers.AF.solo.A, &registers.DE.solo.E); }
void CPU::CP_A_H() { CP(&registers.AF.solo.A, &registers.HL.solo.H); }
void CPU::CP_A_L() { CP(&registers.AF.solo.A, &registers.HL.solo.L); }
void CPU::CP_A_A() { CP(&registers.AF.solo.A, &registers.AF.solo.A); }
void CPU::CP_A_U8() { CP(&registers.AF.solo.A, memory.GetHostAddress(registers.PC + 1)); }
void CPU::CP_A_ADDR_HL() { CP(&registers.AF.solo.A, memory.GetHostAddress(registers.HL.pair)); }


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
void CPU::JP_HL() { JP(registers.HL.pair); }

void CPU::PUSH_BC() { PUSH(&registers.BC.solo.B, &registers.BC.solo.C); }
void CPU::PUSH_DE() { PUSH(&registers.DE.solo.D, &registers.DE.solo.E); }
void CPU::PUSH_HL() { PUSH(&registers.HL.solo.H, &registers.HL.solo.L); }
void CPU::PUSH_AF() { PUSH(&registers.AF.solo.A, &registers.AF.solo.F); }

void CPU::POP_BC() { POP(&registers.BC.solo.B, &registers.BC.solo.C); }
void CPU::POP_DE() { POP(&registers.DE.solo.D, &registers.DE.solo.E); }
void CPU::POP_HL() { POP(&registers.HL.solo.H, &registers.HL.solo.L); }
void CPU::POP_AF() { POP(&registers.AF.solo.A, &registers.AF.solo.F); }

void CPU::CALL_U16() { CALL(memory.Read16(registers.PC)); }
void CPU::CALL_Z_U16() { if (flags.Z) CALL(memory.Read16(registers.PC)); }
void CPU::CALL_C_U16() { if (flags.C) CALL(memory.Read16(registers.PC)); }
void CPU::CALL_NZ_U16() { if (!flags.Z) CALL(memory.Read16(registers.PC)); }
void CPU::CALL_NC_U16() { if (!flags.C) CALL(memory.Read16(registers.PC)); }

void CPU::RET() {
    registers.PC = (*memory.GetHostAddress(registers.SP + 1) << 8) | *memory.GetHostAddress(registers.SP);
    registers.SP += 2;
}
void CPU::RETI() { flags.IME = true; RET(); }
void CPU::RET_Z() { if (flags.Z) RET(); }
void CPU::RET_C() { if (flags.C) RET(); }
void CPU::RET_NZ() { if (!flags.Z) RET(); }
void CPU::RET_NC() { if (!flags.C) RET(); }

// -- SHIFT & ROTATE --
void CPU::RLC_B() { RLC(&registers.BC.solo.B); }
void CPU::RLC_C() { RLC(&registers.BC.solo.C); }
void CPU::RLC_D() { RLC(&registers.DE.solo.D); }
void CPU::RLC_E() { RLC(&registers.DE.solo.E); }
void CPU::RLC_H() { RLC(&registers.HL.solo.H); }
void CPU::RLC_L() { RLC(&registers.HL.solo.L); }
void CPU::RLC_A() { RLC(&registers.AF.solo.A); }
void CPU::RLC_ADDR_HL() { RLC(memory.GetHostAddress(registers.HL.pair)); }
void CPU::RRC_B() { RRC(&registers.BC.solo.B); }
void CPU::RRC_C() { RRC(&registers.BC.solo.C); }
void CPU::RRC_D() { RRC(&registers.DE.solo.D); }
void CPU::RRC_E() { RRC(&registers.DE.solo.E); }
void CPU::RRC_H() { RRC(&registers.HL.solo.H); }
void CPU::RRC_L() { RRC(&registers.HL.solo.L); }
void CPU::RRC_A() { RRC(&registers.AF.solo.A); }
void CPU::RRC_ADDR_HL() { RRC(memory.GetHostAddress(registers.HL.pair)); }

void CPU::RL_B() { RL(&registers.BC.solo.B); }
void CPU::RL_C() { RL(&registers.BC.solo.C); }
void CPU::RL_D() { RL(&registers.DE.solo.D); }
void CPU::RL_E() { RL(&registers.DE.solo.E); }
void CPU::RL_H() { RL(&registers.HL.solo.H); }
void CPU::RL_L() { RL(&registers.HL.solo.L); }
void CPU::RL_A() { RL(&registers.AF.solo.A); }
void CPU::RL_ADDR_HL() { RL(memory.GetHostAddress(registers.HL.pair)); }
void CPU::RR_B() { RR(&registers.BC.solo.B); }
void CPU::RR_C() { RR(&registers.BC.solo.C); }
void CPU::RR_D() { RR(&registers.DE.solo.D); }
void CPU::RR_E() { RR(&registers.DE.solo.E); }
void CPU::RR_H() { RR(&registers.HL.solo.H); }
void CPU::RR_L() { RR(&registers.HL.solo.L); }
void CPU::RR_A() { RR(&registers.AF.solo.A); }
void CPU::RR_ADDR_HL() { RR(memory.GetHostAddress(registers.HL.pair)); }

void CPU::SLA_B() { SLA(&registers.BC.solo.B); }
void CPU::SLA_C() { SLA(&registers.BC.solo.C); }
void CPU::SLA_D() { SLA(&registers.DE.solo.D); }
void CPU::SLA_E() { SLA(&registers.DE.solo.E); }
void CPU::SLA_H() { SLA(&registers.HL.solo.H); }
void CPU::SLA_L() { SLA(&registers.HL.solo.L); }
void CPU::SLA_A() { SLA(&registers.AF.solo.A); }
void CPU::SLA_ADDR_HL() { SLA(memory.GetHostAddress(registers.HL.pair)); }
void CPU::SRA_B() { SRA(&registers.BC.solo.B); }
void CPU::SRA_C() { SRA(&registers.BC.solo.C); }
void CPU::SRA_D() { SRA(&registers.DE.solo.D); }
void CPU::SRA_E() { SRA(&registers.DE.solo.E); }
void CPU::SRA_H() { SRA(&registers.HL.solo.H); }
void CPU::SRA_L() { SRA(&registers.HL.solo.L); }
void CPU::SRA_A() { SRA(&registers.AF.solo.A); }
void CPU::SRA_ADDR_HL() { SRA(memory.GetHostAddress(registers.HL.pair)); }
void CPU::SRL_B() { SRL(&registers.BC.solo.B); }
void CPU::SRL_C() { SRL(&registers.BC.solo.C); }
void CPU::SRL_D() { SRL(&registers.DE.solo.D); }
void CPU::SRL_E() { SRL(&registers.DE.solo.E); }
void CPU::SRL_H() { SRL(&registers.HL.solo.H); }
void CPU::SRL_L() { SRL(&registers.HL.solo.L); }
void CPU::SRL_A() { SRL(&registers.AF.solo.A); }
void CPU::SRL_ADDR_HL() { SRL(memory.GetHostAddress(registers.HL.pair)); }

void CPU::RLCA() {
    flags.C = ((registers.AF.solo.A & 0x80) >> 7);
    registers.AF.solo.A <<= 1;
    registers.AF.solo.A |= flags.C;
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.Z = (registers.AF.solo.A == 0);
}
void CPU::RRCA() {
    flags.C = (registers.AF.solo.A & 0x01);
    registers.AF.solo.A >>= 1;
    registers.AF.solo.A |= (flags.C << 7);
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.Z = (registers.AF.solo.A == 0);
}
void CPU::RLA() {
    bool tmp = flags.C;
    flags.C = ((registers.AF.solo.A & 0x80) >> 7);
    registers.AF.solo.A <<= 1;
    registers.AF.solo.A |= tmp;
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.Z ^= flags.Z;
}
void CPU::RRA() {
    bool tmp = flags.C;
    flags.C = (registers.AF.solo.A & 0x10);
    registers.AF.solo.A >>= 1;
    registers.AF.solo.A |= (tmp << 7);
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.Z ^= flags.Z;
}

// -- BIT OPERATIONS --
void CPU::SWAP_B() { SWAP(&registers.BC.solo.B); }
void CPU::SWAP_C() { SWAP(&registers.BC.solo.C); }
void CPU::SWAP_D() { SWAP(&registers.DE.solo.D); }
void CPU::SWAP_E() { SWAP(&registers.DE.solo.E); }
void CPU::SWAP_H() { SWAP(&registers.HL.solo.H); }
void CPU::SWAP_L() { SWAP(&registers.HL.solo.L); }
void CPU::SWAP_A() { SWAP(&registers.AF.solo.A); }
void CPU::SWAP_ADDR_HL() { SWAP(memory.GetHostAddress(registers.HL.pair)); }

void CPU::BIT_0_B() { BIT(0, &registers.BC.solo.B); }
void CPU::BIT_0_C() { BIT(0, &registers.BC.solo.C); }
void CPU::BIT_0_D() { BIT(0, &registers.DE.solo.D); }
void CPU::BIT_0_E() { BIT(0, &registers.DE.solo.E); }
void CPU::BIT_0_H() { BIT(0, &registers.HL.solo.H); }
void CPU::BIT_0_L() { BIT(0, &registers.HL.solo.L); }
void CPU::BIT_0_A() { BIT(0, &registers.AF.solo.A); }
void CPU::BIT_1_B() { BIT(1, &registers.BC.solo.B); }
void CPU::BIT_1_C() { BIT(1, &registers.BC.solo.C); }
void CPU::BIT_1_D() { BIT(1, &registers.DE.solo.D); }
void CPU::BIT_1_E() { BIT(1, &registers.DE.solo.E); }
void CPU::BIT_1_H() { BIT(1, &registers.HL.solo.H); }
void CPU::BIT_1_L() { BIT(1, &registers.HL.solo.L); }
void CPU::BIT_1_A() { BIT(1, &registers.AF.solo.A); }
void CPU::BIT_2_B() { BIT(2, &registers.BC.solo.B); }
void CPU::BIT_2_C() { BIT(2, &registers.BC.solo.C); }
void CPU::BIT_2_D() { BIT(2, &registers.DE.solo.D); }
void CPU::BIT_2_E() { BIT(2, &registers.DE.solo.E); }
void CPU::BIT_2_H() { BIT(2, &registers.HL.solo.H); }
void CPU::BIT_2_L() { BIT(2, &registers.HL.solo.L); }
void CPU::BIT_2_A() { BIT(2, &registers.AF.solo.A); }
void CPU::BIT_3_B() { BIT(3, &registers.BC.solo.B); }
void CPU::BIT_3_C() { BIT(3, &registers.BC.solo.C); }
void CPU::BIT_3_D() { BIT(3, &registers.DE.solo.D); }
void CPU::BIT_3_E() { BIT(3, &registers.DE.solo.E); }
void CPU::BIT_3_H() { BIT(3, &registers.HL.solo.H); }
void CPU::BIT_3_L() { BIT(3, &registers.HL.solo.L); }
void CPU::BIT_3_A() { BIT(3, &registers.AF.solo.A); }
void CPU::BIT_4_B() { BIT(4, &registers.BC.solo.B); }
void CPU::BIT_4_C() { BIT(4, &registers.BC.solo.C); }
void CPU::BIT_4_D() { BIT(4, &registers.DE.solo.D); }
void CPU::BIT_4_E() { BIT(4, &registers.DE.solo.E); }
void CPU::BIT_4_H() { BIT(4, &registers.HL.solo.H); }
void CPU::BIT_4_L() { BIT(4, &registers.HL.solo.L); }
void CPU::BIT_4_A() { BIT(4, &registers.AF.solo.A); }
void CPU::BIT_5_B() { BIT(5, &registers.BC.solo.B); }
void CPU::BIT_5_C() { BIT(5, &registers.BC.solo.C); }
void CPU::BIT_5_D() { BIT(5, &registers.DE.solo.D); }
void CPU::BIT_5_E() { BIT(5, &registers.DE.solo.E); }
void CPU::BIT_5_H() { BIT(5, &registers.HL.solo.H); }
void CPU::BIT_5_L() { BIT(5, &registers.HL.solo.L); }
void CPU::BIT_5_A() { BIT(5, &registers.AF.solo.A); }
void CPU::BIT_6_B() { BIT(6, &registers.BC.solo.B); }
void CPU::BIT_6_C() { BIT(6, &registers.BC.solo.C); }
void CPU::BIT_6_D() { BIT(6, &registers.DE.solo.D); }
void CPU::BIT_6_E() { BIT(6, &registers.DE.solo.E); }
void CPU::BIT_6_H() { BIT(6, &registers.HL.solo.H); }
void CPU::BIT_6_L() { BIT(6, &registers.HL.solo.L); }
void CPU::BIT_6_A() { BIT(6, &registers.AF.solo.A); }
void CPU::BIT_7_B() { BIT(7, &registers.BC.solo.B); }
void CPU::BIT_7_C() { BIT(7, &registers.BC.solo.C); }
void CPU::BIT_7_D() { BIT(7, &registers.DE.solo.D); }
void CPU::BIT_7_E() { BIT(7, &registers.DE.solo.E); }
void CPU::BIT_7_H() { BIT(7, &registers.HL.solo.H); }
void CPU::BIT_7_L() { BIT(7, &registers.HL.solo.L); }
void CPU::BIT_7_A() { BIT(7, &registers.AF.solo.A); }
void CPU::BIT_0_ADDR_HL() { BIT(0, memory.GetHostAddress(registers.HL.pair)); }
void CPU::BIT_1_ADDR_HL() { BIT(1, memory.GetHostAddress(registers.HL.pair)); }
void CPU::BIT_2_ADDR_HL() { BIT(2, memory.GetHostAddress(registers.HL.pair)); }
void CPU::BIT_3_ADDR_HL() { BIT(3, memory.GetHostAddress(registers.HL.pair)); }
void CPU::BIT_4_ADDR_HL() { BIT(4, memory.GetHostAddress(registers.HL.pair)); }
void CPU::BIT_5_ADDR_HL() { BIT(5, memory.GetHostAddress(registers.HL.pair)); }
void CPU::BIT_6_ADDR_HL() { BIT(6, memory.GetHostAddress(registers.HL.pair)); }
void CPU::BIT_7_ADDR_HL() { BIT(7, memory.GetHostAddress(registers.HL.pair)); }

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
void CPU::RES_0_ADDR_HL() { RES(0, memory.GetHostAddress(registers.HL.pair)); }
void CPU::RES_1_ADDR_HL() { RES(1, memory.GetHostAddress(registers.HL.pair)); }
void CPU::RES_2_ADDR_HL() { RES(2, memory.GetHostAddress(registers.HL.pair)); }
void CPU::RES_3_ADDR_HL() { RES(3, memory.GetHostAddress(registers.HL.pair)); }
void CPU::RES_4_ADDR_HL() { RES(4, memory.GetHostAddress(registers.HL.pair)); }
void CPU::RES_5_ADDR_HL() { RES(5, memory.GetHostAddress(registers.HL.pair)); }
void CPU::RES_6_ADDR_HL() { RES(6, memory.GetHostAddress(registers.HL.pair)); }
void CPU::RES_7_ADDR_HL() { RES(7, memory.GetHostAddress(registers.HL.pair)); }

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
void CPU::SET_0_ADDR_HL() { SET(0, memory.GetHostAddress(registers.HL.pair)); }
void CPU::SET_1_ADDR_HL() { SET(1, memory.GetHostAddress(registers.HL.pair)); }
void CPU::SET_2_ADDR_HL() { SET(2, memory.GetHostAddress(registers.HL.pair)); }
void CPU::SET_3_ADDR_HL() { SET(3, memory.GetHostAddress(registers.HL.pair)); }
void CPU::SET_4_ADDR_HL() { SET(4, memory.GetHostAddress(registers.HL.pair)); }
void CPU::SET_5_ADDR_HL() { SET(5, memory.GetHostAddress(registers.HL.pair)); }
void CPU::SET_6_ADDR_HL() { SET(6, memory.GetHostAddress(registers.HL.pair)); }
void CPU::SET_7_ADDR_HL() { SET(7, memory.GetHostAddress(registers.HL.pair)); }


// -- SYSTEM --
void CPU::STOP() { /* standby */ }
void CPU::HALT() { /* Wait for interrupt */ }
void CPU::DAA() { /* decimal adjust A */ }
void CPU::CPL() {
    registers.AF.solo.A ^= 0xFF;
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