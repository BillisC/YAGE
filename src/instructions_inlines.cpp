#include "cpu.h"


// -- LOAD -- Will be removed in future
void CPU::LD(uint8_t* dst, uint8_t src) {
    *dst = src;
}
void CPU::LD16(uint16_t* dst, uint16_t src) {
    *dst = src;
}

// -- ALU --
void CPU::ADD(uint8_t* dst, uint8_t val) {
    uint16_t res = *dst + val;

    flags.Z = (res == 0);
    flags.N ^= flags.N;
    flags.C = (res & 0x100) != 0;
    flags.H = (((*dst & 0xf) + (val & 0xf)) & 0x10) != 0;

    *dst = (uint8_t)res;
}
void CPU::ADD16(uint16_t *dst, uint16_t val) {
    uint32_t res = *dst + val;

    flags.N ^= flags.N;
    flags.C = (res & 0x100000000) != 0;
    flags.H = (((*dst & 0xfff) + (val & 0xfff)) & 0x1000) != 0;

    *dst = (uint16_t)res;
}
void CPU::ADC(uint8_t* dst, uint8_t val) {
    uint16_t res = *dst + val;

    flags.Z = (res == 0);
    flags.N ^= flags.N;
    flags.C = (res & 0x100) != 0;
    flags.H = (((*dst & 0xf) + (val & 0xf) + (flags.C & 0xf)) & 0x10) != 0;

    *dst = (uint8_t)res;
}
void CPU::SUB(uint8_t* dst, uint8_t val) {
    uint16_t res = *dst - val;
    flags.Z = (res == 0);
    flags.N = 1;
    flags.C = (res & 0x100) != 0;
    flags.H = (((*dst & 0xf) - (val & 0xf)) & 0x10) != 0;

    *dst = (uint8_t)res;
}
void CPU::SBC(uint8_t* dst, uint8_t val) {
    uint16_t res = *dst - val;
    flags.Z = (res == 0);
    flags.N = 1;
    flags.C = (res & 0x100) != 0;
    flags.H = (((*dst & 0xf) - (val & 0xf) - (flags.C & 0xf)) & 0x10) != 0;

    *dst = (uint8_t)res;
}

void CPU::INC(uint8_t* dst) {
    uint16_t res = *dst + 1;
    flags.Z = (res == 0);
    flags.N = 0;
    flags.H = (((*dst & 0xf) + 1) & 0x10) != 0;

    (*dst)++;
}
void CPU::DEC(uint8_t* dst) {
    uint16_t res = *dst - 1;

    flags.Z = (res == 0);
    flags.N = 0;
    flags.H = (((*dst & 0xf) - 1) & 0x10) != 0;

    (*dst)--;
}

void CPU::AND(uint8_t* dst, uint8_t val) {
    *dst &= val;
    flags.Z = (dst == 0);
    flags.N ^= flags.N;
    flags.H = 1;
    flags.C ^= flags.C;
}
void CPU::XOR(uint8_t* dst, uint8_t val) {
    *dst ^= val;
    flags.Z = (dst == 0);
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.C ^= flags.C;
}
void CPU::OR(uint8_t* dst, uint8_t val) {
    *dst |= val;
    flags.Z = (dst == 0);
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.C ^= flags.C;
}
void CPU::CP(uint8_t dst, uint8_t val) {
    flags.Z = (dst == 0);
    flags.N = 1;
    flags.H = (((dst & 0xf) - (val & 0xf)) & 0x10);
    flags.C = (((dst - val) & 0x100) != 0);
}


// -- BRANCH --
void CPU::JR(int8_t val) {
    registers.PC += val;
}
void CPU::JP(uint16_t val) {
    registers.PC = val;
}
void CPU::PUSH(uint16_t reg) {
    memory.Write8(registers.SP--, (uint8_t)(reg >> 8));
    memory.Write8(registers.SP--, (uint8_t)reg);
}
void CPU::POP(uint16_t* reg) {
    *reg = memory.Read8(++registers.SP) | (memory.Read8(++registers.SP) << 8);
}
void CPU::CALL(uint16_t loc) {
    registers.PC += 2;
    PUSH(registers.PC);
    registers.PC = loc;
}
void CPU::RST(uint8_t loc) {
    PUSH(registers.PC);
    registers.PC = loc;
}

// -- SHIFT & ROTATE --
void CPU::RLC(uint8_t* dst) {
    flags.C = (*dst & 0x80) >> 7;
    *dst <<= 1;
    *dst |= flags.C;
    flags.Z = (*dst == 0);
    flags.N ^= flags.N;
    flags.H ^= flags.H;
}
void CPU::RRC(uint8_t* dst) {
    flags.C = (*dst & 0x01);
    *dst >>= 1;
    *dst |= (flags.C << 7);
    flags.Z = (*dst == 0);
    flags.N ^= flags.N;
    flags.H ^= flags.H;
}

void CPU::RL(uint8_t* dst) {
    bool tmp = flags.C;
    flags.C = ((*dst & 0x80) >> 7);
    *dst <<= 1; *dst |= tmp;
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.Z = (*dst == 0);
}
void CPU::RR(uint8_t* dst) {
    bool tmp = flags.C;
    flags.C = (*dst & 0x10);
    *dst >>= 1; *dst |= (tmp << 7);
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.Z = (*dst == 0);
}

void CPU::SLA(uint8_t* dst) {
    flags.C = ((*dst & 0x80) >> 7);
    *dst <<= 1;
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.Z = (*dst == 0);
}
void CPU::SRA(uint8_t* dst) {
    uint8_t tmp = (*dst & 0x80);
    flags.C = (*dst & 0x01);
    *dst >>= 1;
    *dst |= tmp;
    flags.Z = (*dst == 0);
    flags.N ^= flags.N;
    flags.H ^= flags.H;
}
void CPU::SRL(uint8_t* dst) {
    flags.C = (*dst & 0x01);
    *dst >>= 1;
    flags.Z = (*dst == 0);
    flags.N ^= flags.N;
    flags.H ^= flags.H;
}


// -- BIT OPERATIONS --
void CPU::SWAP(uint8_t* dst) {
    *dst = (((*dst & 0x0F) << 4) | ((*dst & 0xF0) >> 4));

    flags.Z = (*dst == 0);
    flags.N ^= flags.N;
    flags.H ^= flags.H;
    flags.C ^= flags.C;
}
void CPU::BIT(uint8_t bit, uint8_t dst) {
    flags.Z = (((dst & (0x01 << bit)) >> bit) == 0);
    flags.N ^= flags.N;
    flags.H = 1;
}
void CPU::RES(uint8_t bit, uint8_t* dst) {
    *dst = (*dst & ((0x01 << bit) ^ 0xFF));
}
void CPU::SET(uint8_t bit, uint8_t* dst) {
    *dst = (*dst | (0x01 << bit));
}