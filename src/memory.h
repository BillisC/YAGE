#ifndef MEMORY_H
#define MEMORY_H

// Libraries
#include <string.h>
#include <stdint.h>

/*  ---------------------------
     Interrupt Enable Register      | 0xFFFF
     Internal CPU RAM               | 0xFF80 - 0xFFFE
     I/O Registers                  | 0xFF00 - 0xFF7F
     Empty but unusable for I/O     | 0xFEA0 - 0xFEFF
     Sprite Attrib Memory (OAM)     | 0xFE00 - 0xFE9F
     Echo of Work RAM               | 0xE000 - 0xFDFF
     4kB Work RAM, switchable (1-7) | 0xD000 - 0xDFFF
     4kB Work RAM                   | 0xC000 - 0xCFFF
     8kB External RAM (catridge)    | 0xA000 - 0xBFFF
     8kB Video RAM                  | 0x8000 - 0x9FFF
     16kB switchable ROM bank       | 0x4000 - 0x7FFF
     16kB ROM bank #0               | 0x0000 - 0x3FFF
    --------------------------- */

class Memory {
private:
    uint8_t* memory[0xFFFF + 1];
    Gameboy* gb;

public:
    Memory(Gameboy* mbus): gb(mbus) { Reset(); }
    ~Memory() { Reset(); }

    void Reset();

    // Write operations
    void Write8(const uint16_t loc, const uint8_t byte);

    // Read operations
    void Read(const uint16_t loc, uint8_t* buffer, const size_t size);
    uint8_t Read8(const uint16_t loc);
    uint16_t Read16(const uint16_t loc);

    // Mapper
    void Mapper(const uint16_t loc,  uint8_t *array, const size_t size);
    void Prepare();

    // Checks
    bool VerifyLogo();
};

#endif