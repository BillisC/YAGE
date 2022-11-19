#include "gameboy.h"

// Constructor
void Memory::Reset() {
    gb->debug.Log("Resetting Memory");
    memset(memory, 0, 0xFFFF);
}

// Write Operations
void Memory::Write8(const uint16_t loc, const uint8_t byte) {
    /* RAM Access */
    if ((loc >= 0x0000) && (loc <= 0x1FFF)) {
        printf("RAM access\n");
        gb->cartridge.mbc->SetRamAccess(byte);
    }
    /* ROM Bank */
    else if ((loc >= 0x2000) && (loc <= 0x3FFF)) {
        printf("ROM bank\n");
        gb->cartridge.mbc->SetRomBank(byte);
        Mapper(0x4000, gb->cartridge.mbc->GetRomBank(), 0x4000);
    }
    /* RAM Bank */
    else if ((loc >= 0x4000) && (loc <= 0x5FFF)) {
        printf("RAM bank\n");
        gb->cartridge.mbc->SetRamBank(byte);
        Mapper(0xA000, gb->cartridge.mbc->GetRamBank(), 0x2000);
    }
    /* Bank Mode */
    else if ((loc >= 0x6000) && (loc <= 0x7FFF)) {
        printf("Bank mode\n");
        gb->cartridge.mbc->SetBankMode(byte);
    }
    /* Write to video RAM */
    else if ((loc >= 0x8000) && (loc <= 0x9FFF)) {
        printf("video ram\n");
        **(memory + loc) = byte;
    }
    /* Write to cartridge RAM */
    else if ((loc >= 0xA000) && (loc <= 0xBFFF)) {
        printf("cartridge ram\n");
        if (gb->cartridge.mbc->GetRamAccess() == 0x0A) {
            **(memory + loc) = byte;
        }
    }
    /* Write to Work + Echo RAM */
    else if ((loc >= 0xC000) && (loc <= 0xFDFF)) {
        printf("work ram\n");
        **(memory + loc) = byte;
    }
    /* IO Register Writes */
    else if ((loc >= 0xFF00) && (loc <= 0xFFFF)) {
        printf("io write\n");
        switch (loc) {
            case IO_Registers::BROM:
                if (byte) Mapper(0x0000, gb->cartridge.mbc->GetRomBank(), 0xFF + 1);
                break;
        }
        **(memory + loc) = byte;
        printf("loc: 0x%x val: 0x%x true: 0x%x\n", loc, byte, **(memory + loc));
    }
}

// Read Operations
void Memory::Read(const uint16_t loc, uint8_t* buffer, const size_t size) {
    for (size_t i = 0x0; i < size; i++) {
        buffer[i] = **(memory + loc + i);
    }
}

uint8_t Memory::Read8(const uint16_t loc) {
    /* OAM bugged IO */
    if (loc >= 0xFEA0 && loc <= 0xFEFF) {
        printf("Illegal read at loc 0x%X\n", loc);
        return 0x00;
    }
    /* Normal read */
    else {
        printf("Requested read at loc 0x%X\n", loc);
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
    else gb->debug.Log("Attempted to map nullptr array!");
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

    /* Restricted IO area [0xFEA0-0xFEFF] */
    memset(restrio, 0x0, (0x5F + 1) * sizeof(uint8_t));
    Mapper(0xFF00, restrio, 0x5F + 1);

    /* The rest upper part [0xFF00-0xFFFF] */
    memset(ioregs, 0x0, (0xFF + 1) * sizeof(uint8_t));
    Mapper(0xFF00, ioregs, 0xFF + 1);

    /* Bootstrap [0x0000-0x00FF] */
    LoadBootstrap();
}

void Memory::LoadBootstrap() {
    gb->debug.Log("Loading Bootstrap");
    std::fstream boot("DMG_ROM.bin", std::ios::in | std::ios::binary);

    /* Buffer catridge data */
    boot.read(reinterpret_cast<char*>(BOOTSTRAP), 0xFF + 1);
    if (boot.fail()) {
        gb->debug.Log("DMG_ROM.bin read failed!");
    }
    boot.close();

    Mapper(0x0000, BOOTSTRAP, 0xFF + 1);
}