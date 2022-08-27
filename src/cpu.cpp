#include "cpu.h"

CPU::CPU() {
    Preload();
    Init();
}

void CPU::Init() {
    // Initial register values
    registers.AF.solo.A = 0x01; registers.AF.solo.F = 0xB0;
    registers.BC.solo.B = 0x00; registers.BC.solo.C = 0x13;
    registers.DE.solo.D = 0x00; registers.DE.solo.E = 0xD8;
    registers.HL.solo.H = 0x01; registers.HL.solo.L = 0x4D;
    registers.SP = 0xFFFE;
    registers.PC = 0x100;

    // Initialize memory
    memory.Init();

    SPEED_SW = 1;

}

int CPU::LoadCatridge(const std::string file_name) {
    /* Open the ROM */
    std::fstream rom;
    rom.open(file_name, std::ios::in | std::ios::binary);
    if (!rom.is_open()) {
        printf("\nFailed to load file");
        return -1;
    }

    /* Get the ROM's size */
    rom.seekg(0, std::ios::end);
    size_t file_size = rom.tellg();
    rom.seekg(0, std::ios::beg);
    printf("\nROM Size: %d\n", file_size);

    /* Buffer catridge data */
    uint8_t buffer[file_size];
    rom.read(reinterpret_cast<char*>(buffer), file_size);
    
    /* Copy catridge header in struct as is */
    memcpy(&cartridge, buffer + 0x134, 0x1B);
    printf("Title: %s\n", cartridge.title);
    printf("Checksum: %02x\n", cartridge.checksum_global[0]);

    /* Copy catridge in memory */
    // BAD memory.Write(0x0, buffer, file_size);

    /* Close the ROM */
    rom.close();
    return 0;
}

void CPU::MemoryDump() {
    std::fstream dump;
    dump.open("debug/memory_dump.bin", std::ios::out | std::ios::binary);
    if (dump) {
        uint8_t buffer[0xFFFF + 1];
        memory.Read(0x0, buffer, 0xFFFF + 1);

        dump.write(reinterpret_cast<char*>(buffer), 0xFFFF + 1);
        dump.close();
    }
    else {
        printf("I/O ERROR: Memory dump file issue\n");
    }
}

void CPU::Fetch() {
    bool chk = memory.Read8(registers.PC) == 0xCB;
    registers.PC += chk;

    uint16_t opcode = memory.Read16(registers.PC);
    registers.PC += 2;

    if (!chk) ((*this).*(InstructionTable[opcode].ipr))();
    else ((*this).*(CB_InstructionTable[opcode].ipr))();
}