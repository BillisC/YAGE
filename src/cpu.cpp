#include "cpu.h"

CPU::CPU() {
    Preload();
    Init();
}

void CPU::Init() {
    // Initial register values
    registers.A = 0x01; registers.F = 0xB0;
    registers.B = 0x00; registers.C = 0x13;
    registers.D = 0x00; registers.E = 0xD8;
    registers.H = 0x01; registers.L = 0x4D;
    registers.SP = 0xFFFE;
    registers.PC = 0x100;

    // Initialize memory
    memory.Init();

    SPEED_SW = 1;

}

int CPU::LoadCatridge(const std::string file_name) {
    std::fstream rom;
    rom.open(file_name, std::ios::in | std::ios::binary);
    if (!rom.is_open()) {
        printf("\nFailed to load file");
        return -1;
    }

    // Get the file's size
    rom.seekg(0, std::ios::end);
    size_t file_size = rom.tellg();
    rom.seekg(0, std::ios::beg);
    printf("\nROM Size: %d\n", file_size);

    // Load the file in the memory
    uint8_t buffer[file_size];
    rom.read(reinterpret_cast<char*>(buffer), file_size);
    memory.Write(0x100, buffer, file_size);

    rom.close();
    return 0;
}

void CPU::MemoryDump() {
    std::fstream dump;
    dump.open("debug/memory_dump.bin", std::ios::out | std::ios::binary);
    if (dump) {
        uint8_t buffer[0xFFFF];
        memory.CopyMem(buffer);

        dump.write(reinterpret_cast<char*>(buffer), 0xFFFF);
        dump.close();
    }
    else {
        printf("I/O ERROR: Memory dump file issue");
    }
}

void CPU::Fetch() {
    uint16_t chk = *memory.GetHostAddress(registers.PC);
    registers.PC += (chk == 0xCB);

    uint16_t opcode = memory.Read16(registers.PC - 1);

    if (chk != 0xCB) ((*this).*(InstructionTable[opcode].ipr))();
    else ((*this).*(CB_InstructionTable[opcode].ipr))();

    registers.PC += InstructionTable[opcode].bytes;
}