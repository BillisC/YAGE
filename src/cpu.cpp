#include "gameboy.h"

void CPU::Reset() {
    gb->debug.Log("Resetting CPU");

    // Initial register values
    registers.AF.solo.A = 0x01; registers.AF.solo.F = 0xB0;
    registers.BC.solo.B = 0x00; registers.BC.solo.C = 0x13;
    registers.DE.solo.D = 0x00; registers.DE.solo.E = 0xD8;
    registers.HL.solo.H = 0x01; registers.HL.solo.L = 0x4D;
    registers.SP = 0xFFFE;
    registers.PC = 0x0000;
}

void CPU::Fetch() {
    is_cb = (gb->memory.Read8(registers.PC) == 0xCB);
    registers.PC += is_cb;

    opcode = gb->memory.Read8(registers.PC++);
}

void CPU::Execute() {
    printf("\nB:0x%02X C:0x%02X D:0x%02X E:0x%02X H:0x%02X L:0x%02X A:0x%02X F:0x%02X | PC:0x%04X SP:0x%04X\n", 
                        registers.BC.solo.B, registers.BC.solo.C, 
                        registers.DE.solo.D, registers.DE.solo.E, 
                        registers.HL.solo.H, registers.HL.solo.L, 
                        registers.AF.solo.A, registers.AF.solo.F,
                        registers.PC, registers.SP);
    if (!is_cb) {
        printf("PC: 0x%X | Code: 0x%X | Name: %s\n", registers.PC - 1, opcode, InstructionTable[opcode].name);
        ((*this).*(InstructionTable[opcode].ipr))();
    }
    else {
        printf("PC: 0x%X | Code: 0xCB%X | Name: %s\n", registers.PC - 2, opcode, CB_InstructionTable[opcode].name);
        ((*this).*(CB_InstructionTable[opcode].ipr))();
        printf("\n");
    }
}

void CatchUp(const uint8_t cycles) { 
    
}