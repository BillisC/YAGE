#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#define U16_BYTE (uint16_t)((gb_sys.memoryH.read_from_mem(gb_sys.PC+2) << 8) | gb_sys.memoryH.read_from_mem(gb_sys.PC+1))
#define U8_BYTE gb_sys.memoryH.read_from_mem(gb_sys.PC+1)
#define HL (uint16_t)((gb_sys.H << 8) | gb_sys.L)
#define BC (uint16_t)((gb_sys.B << 8) | gb_sys.C)
#define DE (uint16_t)((gb_sys.D << 8) | gb_sys.E)

void hlp(){
    uint16_t hlp = HL + 1;
    gb_sys.H = hlp >> 8; 
    gb_sys.L = (uint8_t)hlp;
}
void hlm(){
    uint16_t hlm = HL - 1;
    gb_sys.H = hlm >> 8; 
    gb_sys.L = (uint8_t)hlm;
}

// Nope
void NOP(){}

// LOAD INSTRUCTIONS
void LD_B_U8(){ gb_sys.B = U8_BYTE; }
void LD_C_U8(){ gb_sys.C = U8_BYTE; }
void LD_D_U8(){ gb_sys.D = U8_BYTE; }
void LD_E_U8(){ gb_sys.E = U8_BYTE; }
void LD_H_U8(){ gb_sys.H = U8_BYTE; }
void LD_L_U8(){ gb_sys.L = U8_BYTE; }
void LD_A_U8(){ gb_sys.A = U8_BYTE; }
void LD_SP_U16(){ gb_sys.SP = U16_BYTE; }
void LD_A_ADDR_BC(){ gb_sys.A = gb_sys.memoryH.read_from_mem(BC); }
void LD_A_ADDR_DE(){ gb_sys.A = gb_sys.memoryH.read_from_mem(DE); }
void LD_A_ADDR_HLp(){ 
    gb_sys.A = gb_sys.memoryH.read_from_mem(HL);
    hlp();
}
void LD_A_ADDR_HLm(){ 
    gb_sys.A = gb_sys.memoryH.read_from_mem(HL); 
    hlm();
}
void LD_BC_U16(){ 
    gb_sys.B = gb_sys.memoryH.read_from_mem(gb_sys.PC+2); 
    gb_sys.C = gb_sys.memoryH.read_from_mem(gb_sys.PC+1); 
}
void LD_DE_U16(){ 
    gb_sys.D = gb_sys.memoryH.read_from_mem(gb_sys.PC+2); 
    gb_sys.E = gb_sys.memoryH.read_from_mem(gb_sys.PC+1); 
}
void LD_HL_U16(){ 
    gb_sys.H = gb_sys.memoryH.read_from_mem(gb_sys.PC+2); 
    gb_sys.L = gb_sys.memoryH.read_from_mem(gb_sys.PC+1); 
}
void LD_ADDR_BC_A(){ gb_sys.memoryH.write_2_mem(BC, gb_sys.A); }
void LD_ADDR_DE_A(){ gb_sys.memoryH.write_2_mem(DE, gb_sys.A); }
void LD_ADDR_HLp_A(){ 
    gb_sys.memoryH.write_2_mem(HL, gb_sys.A); 
    hlp();
}
void LD_ADDR_HLm_A(){ 
    gb_sys.memoryH.write_2_mem(HL, gb_sys.A); 
    hlm();
}
void LD_ADDR_HL_U8(){ gb_sys.memoryH.write_2_mem(HL, U8_BYTE); }
void LD_ADDR_U16_SP(){ gb_sys.memoryH.write_2_mem(U16_BYTE, gb_sys.SP); }
void LD_B_B(){ gb_sys.B = gb_sys.B; } // Optimizable
void LD_B_C(){ gb_sys.B = gb_sys.C; }
void LD_B_D(){ gb_sys.B = gb_sys.D; }
void LD_B_E(){ gb_sys.B = gb_sys.E; }
void LD_B_H(){ gb_sys.B = gb_sys.H; }
void LD_B_L(){ gb_sys.B = gb_sys.L; }
void LD_B_ADDR_HL(){ gb_sys.B = gb_sys.memoryH.read_from_mem(HL); }
void LD_B_A(){ gb_sys.B = gb_sys.A; }
void LD_C_B(){ gb_sys.C = gb_sys.B; }
void LD_C_C(){ gb_sys.C = gb_sys.C; } // Optimizable
void LD_C_D(){ gb_sys.C = gb_sys.D; }
void LD_C_E(){ gb_sys.C = gb_sys.E; }
void LD_C_H(){ gb_sys.C = gb_sys.H; }
void LD_C_L(){ gb_sys.C = gb_sys.L; }
void LD_C_ADDR_HL(){ gb_sys.C = gb_sys.memoryH.read_from_mem(HL); }
void LD_C_A(){ gb_sys.C = gb_sys.A; }
void LD_D_B(){ gb_sys.D = gb_sys.B; }
void LD_D_C(){ gb_sys.D = gb_sys.C; }
void LD_D_D(){ gb_sys.D = gb_sys.D; } // Optimizable
void LD_D_E(){ gb_sys.D = gb_sys.E; }
void LD_D_H(){ gb_sys.D = gb_sys.H; }
void LD_D_L(){ gb_sys.D = gb_sys.L; }
void LD_D_ADDR_HL(){ gb_sys.D = gb_sys.memoryH.read_from_mem(HL); }
void LD_D_A(){ gb_sys.D = gb_sys.A; }     
void LD_E_B(){ gb_sys.E = gb_sys.B; }
void LD_E_C(){ gb_sys.E = gb_sys.C; }
void LD_E_D(){ gb_sys.E = gb_sys.D; }
void LD_E_E(){ gb_sys.E = gb_sys.E; } // Optimizable
void LD_E_H(){ gb_sys.E = gb_sys.H; }
void LD_E_L(){ gb_sys.E = gb_sys.L; }
void LD_E_ADDR_HL(){ gb_sys.E = gb_sys.memoryH.read_from_mem(HL); }
void LD_E_A(){ gb_sys.E = gb_sys.A; }
void LD_H_B(){ gb_sys.H = gb_sys.B; }
void LD_H_C(){ gb_sys.H = gb_sys.C; }
void LD_H_D(){ gb_sys.H = gb_sys.D; }
void LD_H_E(){ gb_sys.H = gb_sys.E; }
void LD_H_H(){ gb_sys.H = gb_sys.H; } // Optimizable
void LD_H_L(){ gb_sys.H = gb_sys.L; }
void LD_H_ADDR_HL(){ gb_sys.H = gb_sys.memoryH.read_from_mem(HL); }
void LD_H_A(){ gb_sys.H = gb_sys.A; }
void LD_L_B(){ gb_sys.L = gb_sys.B; }
void LD_L_C(){ gb_sys.L = gb_sys.C; }
void LD_L_D(){ gb_sys.L = gb_sys.D; }
void LD_L_E(){ gb_sys.L = gb_sys.E; }
void LD_L_H(){ gb_sys.L = gb_sys.H; }
void LD_L_L(){ gb_sys.L = gb_sys.L; } // Optimizable
void LD_L_ADDR_HL(){ gb_sys.L = gb_sys.memoryH.read_from_mem(HL); }
void LD_L_A(){ gb_sys.L = gb_sys.A; }
void LD_ADDR_HL_B(){ gb_sys.memoryH.write_2_mem(HL, gb_sys.B); }
void LD_ADDR_HL_C(){ gb_sys.memoryH.write_2_mem(HL, gb_sys.C); }
void LD_ADDR_HL_D(){ gb_sys.memoryH.write_2_mem(HL, gb_sys.D); }
void LD_ADDR_HL_E(){ gb_sys.memoryH.write_2_mem(HL, gb_sys.E); }
void LD_ADDR_HL_H(){ gb_sys.memoryH.write_2_mem(HL, gb_sys.H); }
void LD_ADDR_HL_L(){ gb_sys.memoryH.write_2_mem(HL, gb_sys.L); }
void LD_ADDR_HL_A(){ gb_sys.memoryH.write_2_mem(HL, gb_sys.A); }
void LD_A_B(){ gb_sys.A = gb_sys.B; }
void LD_A_C(){ gb_sys.A = gb_sys.C; }
void LD_A_D(){ gb_sys.A = gb_sys.D; }
void LD_A_E(){ gb_sys.A = gb_sys.E; }
void LD_A_H(){ gb_sys.A = gb_sys.H; }
void LD_A_L(){ gb_sys.A = gb_sys.L; }
void LD_A_ADDR_HL(){ gb_sys.A = gb_sys.memoryH.read_from_mem(HL); }
void LD_A_A(){ gb_sys.A = gb_sys.A; } // Optimizable

// ALU INSTRUCTIONS
void ADD(uint8_t num){
    uint16_t res = gb_sys.A + num;    
    gb_sys.flags.Z = (res == 0);
    gb_sys.flags.N = 0;
    gb_sys.flags.C = ((res & 0x100) != 0);
    gb_sys.flags.H = ((gb_sys.A & 0xf) + (num & 0xf) > 0xf);

    gb_sys.A = (uint8_t)res;
}
void ADD(uint16_t num){
    uint32_t res = HL + num;
    gb_sys.flags.N = 0;
    gb_sys.flags.C = ((res & 0x100000000) != 0);
    gb_sys.flags.H = ((HL & 0xfff) + (num & 0xfff) > 0xfff);

    gb_sys.H = (res >> 8);
    gb_sys.L = res;
}

void ADC(uint8_t num){
    ADD((uint8_t)(num+gb_sys.flags.C));
}

void INC(uint8_t &reg){
    uint16_t res = gb_sys.A + 1;
    gb_sys.flags.Z = (res == 0);
    gb_sys.flags.N = 0;
    gb_sys.flags.H = ((res & 0x0F) == 0);

    reg++;
}
void INC(uint8_t &hreg, uint8_t &lreg){
    uint16_t res = ((hreg << 8) | lreg) + 1;
    hreg = res >> 8;
    lreg = (uint8_t)res;
}

void DEC(uint8_t &reg){
    uint16_t res = gb_sys.A - 1;
    gb_sys.flags.Z = (res == 0);
    gb_sys.flags.N = 1;
    gb_sys.flags.H = ((res & 0x0F) == 0x0F);

    reg--;
}
void DEC(uint8_t &hreg, uint8_t &lreg){
    uint16_t res = ((hreg << 8) | lreg) - 1;
    hreg = res >> 8;
    lreg = (uint8_t)res;
}

void INC_B(){ INC(gb_sys.B); }
void DEC_B(){ DEC(gb_sys.B); }
void INC_C(){ INC(gb_sys.C); }
void DEC_C(){ DEC(gb_sys.C); }
void INC_D(){ INC(gb_sys.D); }
void DEC_D(){ DEC(gb_sys.D); }
void INC_E(){ INC(gb_sys.E); }
void DEC_E(){ DEC(gb_sys.E); }
void INC_H(){ INC(gb_sys.H); }
void DEC_H(){ DEC(gb_sys.H); }
void INC_L(){ INC(gb_sys.L); }
void DEC_L(){ DEC(gb_sys.L); }
void INC_A(){ INC(gb_sys.A); }
void DEC_A(){ DEC(gb_sys.A); }
void INC_BC(){ INC(gb_sys.B, gb_sys.C); }
void DEC_BC(){ DEC(gb_sys.B, gb_sys.C); }
void INC_DE(){ INC(gb_sys.D, gb_sys.E); }
void DEC_DE(){ DEC(gb_sys.D, gb_sys.E); }
void INC_HL(){ INC(gb_sys.H, gb_sys.L); }
void DEC_HL(){ DEC(gb_sys.H, gb_sys.L); }
void INC_SP(){ gb_sys.SP++; }
void DEC_SP(){ gb_sys.SP--; }
void ADD_HL_BC(){ ADD(BC); }
void ADD_HL_DE(){ ADD(DE); }
void ADD_HL_HL(){ ADD(HL); } // Optimizable
void ADD_HL_SP(){}
void INC_ADDR_HL(){}
void DEC_ADDR_HL(){}

// JUMP
void JR_I8(){}
void JR_NZ_I8(){}
void JR_Z_I8(){}
void JR_NC_I8(){}
void JR_C_I8(){}

// MISC
void RLCA(){}
void RRCA(){}
void STOP(){}
void HALT(){}       
void RLA(){}
void RRA(){}
void DAA(){}
void CPL(){}
void SCF(){}
void CCF(){}


#endif