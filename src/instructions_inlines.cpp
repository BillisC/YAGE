#include "cpu.h"

// MISC
void CPU::set_flag(Flags flag, bool val) {
    switch(val) {
        case 0: RES(flag, &registers.AF.solo.F); break;
        case 1: SET(flag, &registers.AF.solo.F); break;
    }
}
bool CPU::get_flag(Flags flag) {
    return ((registers.AF.solo.F >> flag) & 0x01);
}

// -- ALU --
void CPU::ADD(uint8_t val) {
    uint16_t res = registers.AF.solo.A + val;

    set_flag(CARRY, (res & 0x100) != 0);
    set_flag(HALF, (((registers.AF.solo.A & 0xf) + (val & 0xf)) & 0x10) != 0);
    set_flag(NEG, 0);
    set_flag(ZERO, (res == 0));

    registers.AF.solo.A = (uint8_t)res;
}
void CPU::ADD16(uint16_t *dst, uint16_t val) {
    uint32_t res = *dst + val;
    
    set_flag(CARRY, (res & 0x100000000) != 0);
    set_flag(HALF, (((*dst & 0xfff) + (val & 0xfff)) & 0x1000) != 0);
    set_flag(NEG, 0);

    *dst = (uint16_t)res;
}
void CPU::ADC(uint8_t val) {
    uint16_t res = registers.AF.solo.A + val;

    set_flag(CARRY, (res & 0x100) != 0);
    set_flag(HALF, (((registers.AF.solo.A & 0xf) + (val & 0xf) + (get_flag(CARRY) & 0xf)) & 0x10) != 0);
    set_flag(NEG, 0);
    set_flag(ZERO, (res == 0));

    registers.AF.solo.A = (uint8_t)res;
}
void CPU::SUB(uint8_t val) {
    uint16_t res = registers.AF.solo.A - val;
    
    set_flag(CARRY, (res & 0x100) != 0);
    set_flag(HALF, (((registers.AF.solo.A & 0xf) - (val & 0xf)) & 0x10) != 0);
    set_flag(NEG, 1);
    set_flag(ZERO, (res == 0));

    registers.AF.solo.A = (uint8_t)res;
}
void CPU::SBC(uint8_t val) {
    uint16_t res = registers.AF.solo.A - val;
    
    set_flag(CARRY, (res & 0x100) != 0);
    set_flag(HALF, (((registers.AF.solo.A & 0xf) - (val & 0xf) - (get_flag(CARRY) & 0xf)) & 0x10) != 0);
    set_flag(NEG, 1);
    set_flag(ZERO, (res == 0));

    registers.AF.solo.A = (uint8_t)res;
}

void CPU::INC(uint8_t* dst) {
    uint16_t res = *dst + 1;
    
    set_flag(HALF, (((*dst & 0xf) + 1) & 0x10) != 0);
    set_flag(NEG, 0);
    set_flag(ZERO, (res == 0));

    (*dst)++;
}
void CPU::DEC(uint8_t* dst) {
    uint16_t res = *dst - 1;
    
    set_flag(HALF, (((*dst & 0xf) - 1) & 0x10) != 0);
    set_flag(NEG, 0);
    set_flag(ZERO, (res == 0));

    (*dst)--;
}

void CPU::AND(uint8_t val) {
    registers.AF.solo.A &= val;

    set_flag(CARRY, 0);
    set_flag(HALF, 1);
    set_flag(NEG, 0);
    set_flag(ZERO, (registers.AF.solo.A == 0));
}
void CPU::XOR(uint8_t val) {
    registers.AF.solo.A ^= val;

    set_flag(CARRY, 0);
    set_flag(HALF, 0);
    set_flag(NEG, 0);
    set_flag(ZERO, (registers.AF.solo.A == 0));
}
void CPU::OR(uint8_t val) {
    registers.AF.solo.A |= val;

    set_flag(CARRY, 0);
    set_flag(HALF, 0);
    set_flag(NEG, 0);
    set_flag(ZERO, (registers.AF.solo.A == 0));
}
void CPU::CP(uint8_t val) {
    set_flag(CARRY, (((registers.AF.solo.A - val) & 0x100) != 0));
    set_flag(HALF, (((registers.AF.solo.A & 0xf) - (val & 0xf)) & 0x10));
    set_flag(NEG, 1);
    set_flag(ZERO, (registers.AF.solo.A == 0));
}

// -- BRANCH --
void CPU::JR(int8_t val) {
    registers.PC += val;
}
void CPU::JP(uint16_t val) {
    registers.PC = val;
}
void CPU::PUSH(uint16_t reg) {
    bus->memory.Write8(registers.SP--, (uint8_t)(reg >> 8));
    bus->memory.Write8(registers.SP--, (uint8_t)reg);
}
void CPU::POP(uint16_t* reg) {
    *reg = bus->memory.Read8(++registers.SP) | (bus->memory.Read8(++registers.SP) << 8);
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
    set_flag(CARRY, (*dst & 0x80) >> 7);
    *dst <<= 1; *dst |= get_flag(CARRY);
    set_flag(NEG, 0);
    set_flag(HALF, 0);
    set_flag(ZERO, (*dst == 0));
}
void CPU::RRC(uint8_t* dst) {
    set_flag(CARRY, (*dst & 0x01));
    *dst >>= 1; *dst |= (get_flag(CARRY) << 7);
    set_flag(NEG, 0);
    set_flag(HALF, 0);
    set_flag(ZERO, (*dst == 0));
}

void CPU::RL(uint8_t* dst) {
    bool tmp = get_flag(CARRY);
    set_flag(CARRY, ((*dst & 0x80) >> 7));
    *dst <<= 1; *dst |= tmp;
    set_flag(NEG, 0);
    set_flag(HALF, 0);
    set_flag(ZERO, (*dst == 0));
}
void CPU::RR(uint8_t* dst) {
    bool tmp = get_flag(CARRY);
    set_flag(CARRY, (*dst & 0x10));
    *dst >>= 1; *dst |= (tmp << 7);
    set_flag(HALF, 0);
    set_flag(NEG, 0);
    set_flag(ZERO, (*dst == 0));
}

void CPU::SLA(uint8_t* dst) {
    set_flag(CARRY, ((*dst & 0x80) >> 7));
    *dst <<= 1;
    set_flag(HALF, 0);
    set_flag(NEG, 0);
    set_flag(ZERO, (*dst == 0));
}
void CPU::SRA(uint8_t* dst) {
    uint8_t tmp = (*dst & 0x80);
    set_flag(CARRY, (*dst & 0x01));
    *dst >>= 1; *dst |= tmp;
    set_flag(HALF, 0);
    set_flag(NEG, 0);
    set_flag(ZERO, (*dst == 0));
}
void CPU::SRL(uint8_t* dst) {
    set_flag(CARRY, (*dst & 0x01));
    *dst >>= 1;
    set_flag(HALF, 0);
    set_flag(NEG, 0);
    set_flag(ZERO, (*dst == 0));
}

// -- BIT OPERATIONS --
void CPU::SWAP(uint8_t* dst) {
    *dst = (((*dst & 0x0F) << 4) | ((*dst & 0xF0) >> 4));

    set_flag(CARRY, 0);
    set_flag(HALF, 0);
    set_flag(NEG, 0);
    set_flag(ZERO, (*dst == 0));
}
void CPU::BIT(uint8_t bit, uint8_t dst) {
    set_flag(HALF, 1);
    set_flag(NEG, 0);
    set_flag(ZERO, (((dst & (0x01 << bit)) >> bit) == 0));
}
void CPU::RES(uint8_t bit, uint8_t* dst) {
    *dst = (*dst & ((0x01 << bit) ^ 0xFF));
}
void CPU::SET(uint8_t bit, uint8_t* dst) {
    *dst = (*dst | (0x01 << bit));
}