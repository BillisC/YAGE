#include "cpu.h"

void CPU::Reset() {
    // Initial register values
    registers.AF.solo.A = 0x01; registers.AF.solo.F = 0xB0;
    registers.BC.solo.B = 0x00; registers.BC.solo.C = 0x13;
    registers.DE.solo.D = 0x00; registers.DE.solo.E = 0xD8;
    registers.HL.solo.H = 0x01; registers.HL.solo.L = 0x4D;
    registers.SP = 0xFFFE;
    registers.PC = 0x100;
}

void CPU::Fetch() {
    bool chk = (bus->memory.Read8(registers.PC) == 0xCB);
    registers.PC += chk;

    uint8_t opcode = bus->memory.Read8(registers.PC++);

    if (!chk) ((*this).*(InstructionTable[opcode].ipr))();
    else ((*this).*(CB_InstructionTable[opcode].ipr))();
}