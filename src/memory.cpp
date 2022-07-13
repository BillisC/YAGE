#include "memory.h"

// Constructor
void Memory::Init() {
    Clear();
}

void Memory::Clear() {
    memset(memory, 0, 0xFFFF);
}


// Write Operations
void Memory::Write(const uint16_t loc, uint8_t* buffer, const uint8_t size) {
    memcpy(memory + loc, buffer, size);
}

void Memory::Write8(const uint16_t loc, const uint8_t byte) {
    memory[loc] = byte;
    //if(loc >= 0xE000 && loc <= 0xFE00) memory[loc - 0x2000] = byte;  // Nintendo prohibited
    if (loc >= 0xC000 && loc <= 0xDE00) memory[loc + 0x2000] = byte;
}


// Read Operations
void Memory::CopyMem(uint8_t* buffer) {
    memcpy(buffer, memory, 0xFFFF);
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