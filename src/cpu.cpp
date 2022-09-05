#include "gameboy.h"

void CPU::Reset() {
    gb->debug.Log("Resetting CPU");

    // Initial register values
    registers.AF.solo.A = 0x01; registers.AF.solo.F = 0xB0;
    registers.BC.solo.B = 0x00; registers.BC.solo.C = 0x13;
    registers.DE.solo.D = 0x00; registers.DE.solo.E = 0xD8;
    registers.HL.solo.H = 0x01; registers.HL.solo.L = 0x4D;
    registers.SP = 0xFFFE;
    registers.PC = 0x100;
}

void CPU::Fetch() {
    bool chk = (gb->memory.Read8(registers.PC) == 0xCB);
    registers.PC += chk;

    uint8_t opcode = gb->memory.Read8(registers.PC++);

    if (!chk) {
        gb->debug.Log("Code: " + std::to_string(opcode) + " | Name: " + std::string(InstructionTable[opcode].name));
        ((*this).*(InstructionTable[opcode].ipr))();
    }
    else {
        gb->debug.Log("Code: CB " + std::to_string(opcode) + " | Name: " + std::string(InstructionTable[opcode].name));
        ((*this).*(CB_InstructionTable[opcode].ipr))();
    }
}