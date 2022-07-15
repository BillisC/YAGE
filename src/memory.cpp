#include "memory.h"
#include "stdio.h"

// Constructor
void Memory::Init() {
    Clear();
}

void Memory::Clear() {
    memset(memory, 0, 0xFFFF);
}


// Write Operations
void Memory::Write(const uint16_t loc, uint8_t* buffer, const size_t size) {
    memcpy(memory + loc, buffer, size);
}

void Memory::Write8(const uint16_t loc, const uint8_t byte) {
    if (!(loc >= 0xE000 && loc <= 0xFE00)) {
        memory[loc] = byte;
        if (loc >= 0xC000 && loc <= 0xDE00) memory[loc + 0x2000] = byte;
    }
    else {
        /* memory[loc - 0x2000] = byte; */  // Nintendo prohibited
    }

}


// Read Operations
void Memory::Read(const uint16_t loc, uint8_t* buffer, const size_t size) {
    memcpy(buffer, memory + loc, size);
}

uint8_t Memory::Read8(const uint16_t loc) {
    return memory[loc + 1];
}

uint16_t Memory::Read16(const uint16_t loc) {
    return (memory[loc + 2] << 8) | memory[loc + 1];
}

uint8_t* Memory::GetHostAddress(const uint16_t loc) {
    return &memory[loc];
}


// Checks
bool Memory::VerifyLogo() {
    uint8_t logo[0x30] = {
        0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D, 0x00, 0x0B, 0x03, 0x73, 0x00, 0x83, 0x00, 0x0C, 0x00, 0x0D,
        0x00, 0x08, 0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E, 0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD, 0xD9, 0x99,
        0xBB, 0xBB, 0x67, 0x63, 0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC, 0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E
    };

    if (memcmp(logo, &memory[0x104], 0x18) != 0) return false;
    return true;
}