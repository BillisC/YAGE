#ifndef CPU_H
#define CPU_H

// Libraries
#include <vector>
#include <stdint.h>

enum Flags { CARRY = 4, HALF = 5, NEG = 6, ZERO = 7 };
struct Registers {
    union B_C {
        struct registers {
            uint8_t C;
            uint8_t B;
        } solo;
        uint16_t pair;
    } BC;
    union D_E {
        struct registers {
            uint8_t E;
            uint8_t D;
        } solo;
        uint16_t pair;
    } DE;
    union H_L {
        struct registers {
            uint8_t L;
            uint8_t H;
        } solo;
        uint16_t pair;
    } HL;
    union A_F {
        struct registers {
            uint8_t F;
            uint8_t A;
        } solo;
        uint16_t pair;
    } AF;

    uint16_t PC, SP;
};

class CPU {
    Registers registers;
    //Timers timer;
    //S_Modes mode;
    Gameboy* bus;

public:
    CPU(Gameboy* mbus) : bus(mbus) { Preload(); Reset(); }
    ~CPU() { Reset(); }

    void Preload();
    void Reset();
    void Fetch();

private:
    // Generic Functions
    void set_flag(Flags flag, bool val);
    bool get_flag(Flags flag);

    void ADD(const uint8_t val);
    void ADD16(uint16_t* dst, const uint16_t val);
    void ADC(const uint8_t val);
    void SUB(const uint8_t val);
    void SBC(const uint8_t val);

    void INC(uint8_t* dst);
    void DEC(uint8_t* dst);
    void INC16(uint8_t* hreg, uint8_t* lreg);
    void DEC16(uint8_t* hreg, uint8_t* lreg);

    void AND(uint8_t val);
    void XOR(uint8_t val);
    void OR(uint8_t val);
    void CP(uint8_t val);

    void JR(int8_t val);
    void JP(uint16_t val);
    void PUSH(uint16_t reg);
    void POP(uint16_t* reg);
    void CALL(uint16_t loc);
    void RST(uint8_t loc);

    void RLC(uint8_t* dst);
    void RRC(uint8_t* dst);
    void RL(uint8_t* dst);
    void RR(uint8_t* dst);
    void SLA(uint8_t* dst);
    void SRA(uint8_t* dst);
    void SRL(uint8_t* dst);

    void SWAP(uint8_t* dst);
    void BIT(uint8_t bit, uint8_t dst);
    void RES(uint8_t bit, uint8_t* dst);
    void SET(uint8_t bit, uint8_t* dst);

private:
    // Instructions
    typedef void(CPU::* InstructionPointer)();
    struct Instruction {
        InstructionPointer ipr;
        const char* name;
        uint8_t bytes;
        uint8_t cycles;
    };

    std::vector<Instruction> InstructionTable;
    std::vector<Instruction> CB_InstructionTable;

private:
    // nop
    void NOP();

    // LOAD
    void LD_SP_U16(); void LD_SP_HL(); void LD_HL_SPpI8(); void LD_ADDR_U16_SP();
    void LD_A_ADDR_BC(); void LD_A_ADDR_DE(); void LD_A_ADDR_HLp(); void LD_A_ADDR_HLm(); void LD_A_ADDR_U16();
    void LD_BC_U16(); void LD_DE_U16(); void LD_HL_U16();
    void LD_ADDR_BC_A(); void LD_ADDR_DE_A();
    void LD_ADDR_HL_U8(); void LD_ADDR_HLp_A(); void LD_ADDR_HLm_A(); void LD_ADDR_U16_A();
    void LD_B_U8(); void LD_C_U8(); void LD_D_U8(); void LD_E_U8(); void LD_H_U8(); void LD_L_U8(); void LD_A_U8();
    void LD_B_B(); void LD_B_C(); void LD_B_D(); void LD_B_E(); void LD_B_H(); void LD_B_L(); void LD_B_A(); void LD_C_B(); void LD_C_C(); void LD_C_D();
    void LD_C_E(); void LD_C_H(); void LD_C_L(); void LD_C_A(); void LD_D_B(); void LD_D_C(); void LD_D_D(); void LD_D_E(); void LD_D_H(); void LD_D_L();
    void LD_D_A(); void LD_E_B(); void LD_E_C(); void LD_E_D(); void LD_E_E(); void LD_E_H(); void LD_E_L(); void LD_E_A(); void LD_H_B(); void LD_H_C();
    void LD_H_D(); void LD_H_E(); void LD_H_H(); void LD_H_L(); void LD_H_A(); void LD_L_B(); void LD_L_C(); void LD_L_D(); void LD_L_E(); void LD_L_H();
    void LD_L_L(); void LD_L_A(); void LD_A_B(); void LD_A_C(); void LD_A_D(); void LD_A_E(); void LD_A_H(); void LD_A_L(); void LD_A_A();
    void LD_B_ADDR_HL(); void LD_C_ADDR_HL(); void LD_D_ADDR_HL(); void LD_E_ADDR_HL(); void LD_H_ADDR_HL(); void LD_L_ADDR_HL(); void LD_A_ADDR_HL();
    void LD_ADDR_HL_B(); void LD_ADDR_HL_C(); void LD_ADDR_HL_D(); void LD_ADDR_HL_E(); void LD_ADDR_HL_H(); void LD_ADDR_HL_L(); void LD_ADDR_HL_A();
    void LD_OFF_U8_A(); void LD_OFF_C_A(); void LD_A_OFF_U8(); void LD_A_OFF_C();

    // ALU
    void INC_B(); void DEC_B(); void INC_C(); void DEC_C(); void INC_D(); void DEC_D(); void INC_E(); void DEC_E(); void INC_H(); void DEC_H();
    void INC_L(); void DEC_L(); void INC_A(); void DEC_A(); void INC_BC(); void DEC_BC(); void INC_DE(); void DEC_DE(); void INC_HL(); void DEC_HL();
    void INC_SP(); void DEC_SP(); void INC_ADDR_HL(); void DEC_ADDR_HL(); void ADD_A_C(); void ADD_A_D(); void ADD_A_E(); void ADD_A_H(); void ADD_A_B();
    void ADD_A_L(); void ADD_A_A(); void ADD_A_U8(); void ADD_A_ADDR_HL(); void ADD_HL_DE(); void ADD_HL_HL(); void ADD_HL_SP(); void ADD_SP_I8();
    void ADC_A_L(); void ADC_A_A(); void ADC_A_U8(); void ADC_A_B(); void ADC_A_C(); void ADC_A_D(); void ADC_A_E(); void ADC_A_H();
    void ADC_A_ADDR_HL(); void ADD_HL_BC();
    void SUB_A_B(); void SUB_A_C(); void SUB_A_D(); void SUB_A_E(); void SUB_A_H(); void SUB_A_L(); void SUB_A_A(); void SUB_A_U8(); void SUB_A_ADDR_HL();
    void SBC_A_B(); void SBC_A_C(); void SBC_A_D(); void SBC_A_E(); void SBC_A_H(); void SBC_A_L(); void SBC_A_A(); void SBC_A_U8(); void SBC_A_ADDR_HL();
    void AND_A_B(); void AND_A_C(); void AND_A_D(); void AND_A_E(); void AND_A_H(); void AND_A_L(); void AND_A_A(); void AND_A_U8(); void AND_A_ADDR_HL();
    void XOR_A_B(); void XOR_A_C(); void XOR_A_D(); void XOR_A_E(); void XOR_A_H(); void XOR_A_L(); void XOR_A_A(); void XOR_A_U8(); void XOR_A_ADDR_HL();
    void OR_A_B(); void OR_A_C(); void OR_A_D(); void OR_A_E(); void OR_A_H(); void OR_A_L(); void OR_A_A(); void OR_A_U8(); void OR_A_ADDR_HL();
    void CP_A_B(); void CP_A_C(); void CP_A_D(); void CP_A_E(); void CP_A_H(); void CP_A_L(); void CP_A_A(); void CP_A_U8(); void CP_A_ADDR_HL();

    // BRANCH
    void JR_C_I8(); void JR_Z_I8(); void JR_NC_I8(); void JR_NZ_I8(); void JR_I8(); void JP_HL();
    void JP_Z_U16(); void JP_C_U16(); void JP_NZ_U16(); void JP_NC_U16(); void JP_U16();
    void PUSH_BC(); void PUSH_HL(); void PUSH_AF(); void PUSH_DE();
    void POP_BC(); void POP_DE(); void POP_HL(); void POP_AF();
    void CALL_U16(); void CALL_Z_U16(); void CALL_C_U16(); void CALL_NZ_U16(); void CALL_NC_U16();
    void RET(); void RETI(); void RET_Z(); void RET_NZ(); void RET_C(); void RET_NC();

    // SHIFT & ROTATE
    void RLCA(); void RRCA(); void RLA(); void RRA();
    void RLC_B(); void RLC_C(); void RLC_D(); void RLC_E(); void RLC_H(); void RLC_L(); void RLC_ADDR_HL(); void RLC_A();
    void RRC_B(); void RRC_C(); void RRC_D(); void RRC_E(); void RRC_H(); void RRC_L(); void RRC_ADDR_HL(); void RRC_A();
    void RL_B(); void RL_C(); void RL_D(); void RL_E(); void RL_H(); void RL_L(); void RL_ADDR_HL(); void RL_A();
    void RR_B(); void RR_C(); void RR_D(); void RR_E(); void RR_H(); void RR_L(); void RR_ADDR_HL(); void RR_A();

    // BIT OPERATIONS
    void SWAP_B(); void SWAP_C(); void SWAP_D(); void SWAP_E(); void SWAP_H(); void SWAP_L(); void SWAP_A(); void SWAP_ADDR_HL();
    void BIT_0_B(); void BIT_0_C(); void BIT_0_D(); void BIT_0_E(); void BIT_0_H(); void BIT_0_L(); void BIT_0_A(); void BIT_0_ADDR_HL();
    void BIT_1_B(); void BIT_1_C(); void BIT_1_D(); void BIT_1_E(); void BIT_1_H(); void BIT_1_L(); void BIT_1_A(); void BIT_1_ADDR_HL();
    void BIT_2_B(); void BIT_2_C(); void BIT_2_D(); void BIT_2_E(); void BIT_2_H(); void BIT_2_L(); void BIT_2_A(); void BIT_2_ADDR_HL();
    void BIT_3_B(); void BIT_3_C(); void BIT_3_D(); void BIT_3_E(); void BIT_3_H(); void BIT_3_L(); void BIT_3_A(); void BIT_3_ADDR_HL();
    void BIT_4_B(); void BIT_4_C(); void BIT_4_D(); void BIT_4_E(); void BIT_4_H(); void BIT_4_L(); void BIT_4_A(); void BIT_4_ADDR_HL();
    void BIT_5_B(); void BIT_5_C(); void BIT_5_D(); void BIT_5_E(); void BIT_5_H(); void BIT_5_L(); void BIT_5_A(); void BIT_5_ADDR_HL();
    void BIT_6_B(); void BIT_6_C(); void BIT_6_D(); void BIT_6_E(); void BIT_6_H(); void BIT_6_L(); void BIT_6_A(); void BIT_6_ADDR_HL();
    void BIT_7_B(); void BIT_7_C(); void BIT_7_D(); void BIT_7_E(); void BIT_7_H(); void BIT_7_L(); void BIT_7_A(); void BIT_7_ADDR_HL();
    void RES_0_B(); void RES_0_C(); void RES_0_D(); void RES_0_E(); void RES_0_H(); void RES_0_L(); void RES_0_A(); void RES_0_ADDR_HL();
    void RES_1_B(); void RES_1_C(); void RES_1_D(); void RES_1_E(); void RES_1_H(); void RES_1_L(); void RES_1_A(); void RES_1_ADDR_HL();
    void RES_2_B(); void RES_2_C(); void RES_2_D(); void RES_2_E(); void RES_2_H(); void RES_2_L(); void RES_2_A(); void RES_2_ADDR_HL();
    void RES_3_B(); void RES_3_C(); void RES_3_D(); void RES_3_E(); void RES_3_H(); void RES_3_L(); void RES_3_A(); void RES_3_ADDR_HL();
    void RES_4_B(); void RES_4_C(); void RES_4_D(); void RES_4_E(); void RES_4_H(); void RES_4_L(); void RES_4_A(); void RES_4_ADDR_HL();
    void RES_5_B(); void RES_5_C(); void RES_5_D(); void RES_5_E(); void RES_5_H(); void RES_5_L(); void RES_5_A(); void RES_5_ADDR_HL();
    void RES_6_B(); void RES_6_C(); void RES_6_D(); void RES_6_E(); void RES_6_H(); void RES_6_L(); void RES_6_A(); void RES_6_ADDR_HL();
    void RES_7_B(); void RES_7_C(); void RES_7_D(); void RES_7_E(); void RES_7_H(); void RES_7_L(); void RES_7_A(); void RES_7_ADDR_HL();
    void SET_0_B(); void SET_0_C(); void SET_0_D(); void SET_0_E(); void SET_0_H(); void SET_0_L(); void SET_0_A(); void SET_0_ADDR_HL();
    void SET_1_B(); void SET_1_C(); void SET_1_D(); void SET_1_E(); void SET_1_H(); void SET_1_L(); void SET_1_A(); void SET_1_ADDR_HL();
    void SET_2_B(); void SET_2_C(); void SET_2_D(); void SET_2_E(); void SET_2_H(); void SET_2_L(); void SET_2_A(); void SET_2_ADDR_HL();
    void SET_3_B(); void SET_3_C(); void SET_3_D(); void SET_3_E(); void SET_3_H(); void SET_3_L(); void SET_3_A(); void SET_3_ADDR_HL();
    void SET_4_B(); void SET_4_C(); void SET_4_D(); void SET_4_E(); void SET_4_H(); void SET_4_L(); void SET_4_A(); void SET_4_ADDR_HL();
    void SET_5_B(); void SET_5_C(); void SET_5_D(); void SET_5_E(); void SET_5_H(); void SET_5_L(); void SET_5_A(); void SET_5_ADDR_HL();
    void SET_6_B(); void SET_6_C(); void SET_6_D(); void SET_6_E(); void SET_6_H(); void SET_6_L(); void SET_6_A(); void SET_6_ADDR_HL();
    void SET_7_B(); void SET_7_C(); void SET_7_D(); void SET_7_E(); void SET_7_H(); void SET_7_L(); void SET_7_A(); void SET_7_ADDR_HL();
    void SLA_B(); void SLA_C(); void SLA_D(); void SLA_E(); void SLA_H(); void SLA_L(); void SLA_A(); void SLA_ADDR_HL();
    void SRA_B(); void SRA_C(); void SRA_D(); void SRA_E(); void SRA_H(); void SRA_L(); void SRA_A(); void SRA_ADDR_HL();
    void SRL_B(); void SRL_C(); void SRL_D(); void SRL_E(); void SRL_H(); void SRL_L(); void SRL_A(); void SRL_ADDR_HL();

    // SYSTEM
    void STOP(); void HALT(); void DAA(); void CPL(); void SCF(); void CCF(); void DI(); void EI();

    // RST
    void RST_00H(); void RST_08H(); void RST_10H(); void RST_18H(); void RST_20H(); void RST_28H(); void RST_30H(); void RST_38H();
};


#endif