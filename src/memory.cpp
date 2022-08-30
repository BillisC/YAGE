#include "memory.h"

// Constructor
void Memory::Reset() {
    memset(memory, 0, 0xFFFF);
    Mapper(0x4000, bus->cartridge->mbc->GetRomBank(), 0x4000);
    Mapper(0xA000, bus->cartridge->mbc->GetRomBank(), 0x2000); 
}

// Write Operations
void Memory::Write8(const uint16_t loc, const uint8_t byte) {
    if ((loc & 0x0000) || (loc & 0x1000)) {
        bus->cartridge->mbc->SetRamAccess(byte);
    }
    else if ((loc & 0x2000) || (loc & 0x3000)) {
        bus->cartridge->mbc->SetRomBank(byte); 
        Mapper(0x4000, bus->cartridge->mbc->GetRomBank(), 0x4000); 
    }
    else if ((loc & 0x4000) || (loc & 0x5000)) {
        bus->cartridge->mbc->SetRamBank(byte);
        Mapper(0xA000, bus->cartridge->mbc->GetRamBank(), 0x2000);
    }
    else if ((loc & 0x6000) || (loc & 0x7000)) {
        bus->cartridge->mbc->SetBankMode(byte);
    }
    else if ((loc & 0xA000) || (loc & 0xB000)) {
        if (bus->cartridge->mbc->GetRamAccess() == 0x0A) {
            **(memory + loc) = byte;
        }
    }
    else if (loc & 0xC000 || loc & 0xD000) {
        **(memory + loc) = byte;
    }

}

// Read Operations
void Memory::Read(const uint16_t loc, uint8_t* buffer, const size_t size) {
    memcpy(buffer, *(memory + loc), size);
}

uint8_t Memory::Read8(const uint16_t loc) {
    return **(memory + loc);
}

uint16_t Memory::Read16(const uint16_t loc) {
    return (Read8(loc + 1) << 8) | Read8(loc);
}

// Mapping
void Memory::Mapper(const uint16_t loc,  uint8_t *array, const size_t size) {
    for (int i = 0; i < size; i++) {
        *(memory + i + loc) = array + i;
    }
}

// Checks
bool Memory::VerifyLogo() {
    uint8_t logo[0x30] = {
        0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
        0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
        0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
    };

    if (memcmp(logo, *(memory + 0x104), 0x18) != 0) return false;
    return true;
}