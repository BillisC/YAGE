#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

void NOP(){}

// LOAD INSTRUCTIONS
void LD_B_U8(){}
void LD_C_U8(){}
void LD_D_U8(){}
void LD_E_U8(){}
void LD_H_U8(){}
void LD_L_U8(){}
void LD_A_U8(){}
void LD_SP_U16(){}
void LD_A_ADDR_BC(){}
void LD_A_ADDR_DE(){}
void LD_A_ADDR_HLp(){}
void LD_A_ADDR_HLm(){}
void LD_BC_U16(){}
void LD_DE_U16(){}
void LD_HL_U16(){}
void LD_ADDR_BC_A(){}
void LD_ADDR_DE_A(){}
void LD_ADDR_HLp_A(){}
void LD_ADDR_HLm_A(){}
void LD_ADDR_HL_U8(){}
void LD_ADDR_U16_SP(){}

// ALU INSTRUCTIONS
void INC_B(){}
void DEC_B(){}
void INC_C(){}
void DEC_C(){}
void INC_D(){}
void DEC_D(){}
void INC_E(){}
void DEC_E(){}
void INC_H(){}
void DEC_H(){}
void INC_L(){}
void DEC_L(){}
void INC_A(){}
void DEC_A(){}
void INC_BC(){}
void DEC_BC(){}
void INC_DE(){}
void DEC_DE(){}
void INC_HL(){}
void DEC_HL(){}
void INC_SP(){}
void DEC_SP(){}
void ADD_HL_BC(){}
void ADD_HL_DE(){}
void ADD_HL_HL(){}
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
void RLA(){}
void RRA(){}
void DAA(){}
void CPL(){}
void SCF(){}
void CCF(){}


#endif