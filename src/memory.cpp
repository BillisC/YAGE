#include "gameboy.h"

// Constructor
void Memory::Reset() {
    gb->debug.Log("Resetting Memory");
    memset(memory, 0, 0xFFFF);
}

// Write Operations
void Memory::Write8(const uint16_t loc, const uint8_t byte) {
    switch (loc) {
        case 0x0000 ... 0x1FFF: 
            gb->cartridge.mbc->SetRamAccess(byte); 
            break;
        case 0x2000 ... 0x3FFF:
            gb->cartridge.mbc->SetRomBank(byte);
            Mapper(0x4000, gb->cartridge.mbc->GetRomBank(), 0x4000);
            break;
        case 0x4000 ... 0x5FFF:
            gb->cartridge.mbc->SetRamBank(byte);
            Mapper(0xA000, gb->cartridge.mbc->GetRamBank(), 0x2000);
            break;
        case 0x6000 ... 0x7FFF:
            gb->cartridge.mbc->SetBankMode(byte);
            break;
        case 0xA000 ... 0xBFFF:
            if (gb->cartridge.mbc->GetRamAccess() == 0x0A) **(memory + loc) = byte;
            break;
        case IO_Registers::BROM:
            if (byte) Mapper(0x0000, gb->cartridge.mbc->GetRomBank(), 0xFF + 1);
        default:
            **(memory + loc) = byte;
    }
}

// Read Operations
void Memory::Read(const uint16_t loc, uint8_t* const buffer, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        buffer[i] = **(memory + loc + i);
    }
}

uint8_t Memory::Read8(const uint16_t loc) {
    switch (loc) {
        case 0xFEA0 ... 0xFEFF:
            return 0;
        default:
            return **(memory + loc);
    }
}

uint16_t Memory::Read16(const uint16_t loc) {
    return (Read8(loc + 1) << 8) | Read8(loc);
}

// Mapping
void Memory::Mapper(const uint16_t loc, uint8_t* array, const size_t size) {
    if (array != nullptr) {
        for (size_t i = 0; i < size; i++) *(memory + i + loc) = array + i;
    }
    else {
        gb->debug.Log("Attempted to map nullptr array!");
        gb->debug.ForceStop(3);
    }
}

void Memory::Prepare() {
    /* Segmentation fault protection layer */
    memset(prot_memory, 0, (0xFFFF + 1) * sizeof(uint8_t));
    Mapper(0x0000, prot_memory, 0xFFFF + 1);

    /* Detect MBC type [0x0000-0x7FFF] */
    if (gb->cartridge.GetMBCType().find("ROM") != std::string::npos) {
        Mapper(0x0000, gb->cartridge.mbc->GetRomBank(), 0x8000);
    }
    else if (gb->cartridge.GetMBCType().find("MBC1") != std::string::npos) {
        Mapper(0x0000, gb->cartridge.mbc->GetRomBank(0), 0x4000);
        Mapper(0x4000, gb->cartridge.mbc->GetRomBank(), 0x4000);
    }

    /* Video RAM [0x8000-0x9FFF] */
    memset(vram, 0x0, 0x2000 * sizeof(uint8_t));
    Mapper(0x8000, vram, 0x2000);

    /* Detect RAM [0xA000-0xBFFF] */
    if (gb->cartridge.GetMBCType().find("RAM") != std::string::npos) {
        Mapper(0xA000, gb->cartridge.mbc->GetRamBank(), 0x2000);
    }

    /* Work RAM w/ Echo [0xC000-0xFDFF] */
    memset(wram, 0x0, 0x2000 * sizeof(uint8_t));
    Mapper(0xC000, wram, 0x2000);
    Mapper(0xE000, wram, 0x1E00);

    /* OAM [0xFE00-0xFE9F] */
    memset(OAM, 0x0, (0x9F + 1) * sizeof(uint8_t));
    Mapper(0xFE00, OAM, 0x9F + 1);

    /* The rest upper part [0xFF00-0xFFFF] */
    memset(ioregs, 0x0, (0xFF + 1) * sizeof(uint8_t));
    Mapper(0xFF00, ioregs, 0xFF + 1);

    /* Bootstrap [0x0000-0x00FF] */
    LoadBootstrap();
}

void Memory::LoadBootstrap() {
    gb->debug.Log("Loading Bootstrap");
    std::fstream boot("DMG_ROM.bin", std::ios::in | std::ios::binary);
    if (!boot.is_open()) {
        gb->debug.Log("Failed to open DMG_ROM.bin!");
        gb->debug.ForceStop(2);
    }

    /* Buffer catridge data */
    boot.read(reinterpret_cast<char*>(BOOTSTRAP), 0xFF + 1);
    if (boot.fail()) {
        boot.close();
        gb->debug.Log("DMG_ROM.bin read failed!");
        gb->debug.ForceStop(2);
    }
    boot.close();

    Mapper(0x0000, BOOTSTRAP, 0xFF + 1);
}