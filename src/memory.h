#ifndef MEMORY_H
#define MEMORY_H

// Libraries
#include <string.h>
#include <stdint.h>
#include <fstream>

/*  ---------------------------
     Interrupt Enable Register      | 0xFFFF
     Internal CPU RAM               | 0xFF80 - 0xFFFE
     I/O Registers                  | 0xFF00 - 0xFF7F
     Empty but unusable for I/O     | 0xFEA0 - 0xFEFF
     Sprite Attrib Memory (OAM)     | 0xFE00 - 0xFE9F
     Echo of Work RAM               | 0xE000 - 0xFDFF :check:
     4kB Work RAM, switchable (1-7) | 0xD000 - 0xDFFF :check:
     4kB Work RAM                   | 0xC000 - 0xCFFF :check:
     8kB External RAM (catridge)    | 0xA000 - 0xBFFF :check:
     8kB Video RAM                  | 0x8000 - 0x9FFF :check:
     16kB switchable ROM bank       | 0x4000 - 0x7FFF :check:
     16kB ROM bank #0               | 0x0000 - 0x3FFF :check:
    --------------------------- */

enum IO_Registers {
    /* IO */
    JOYP    = 0xFF00,  // Joypad input
    SB      = 0xFF01,  // Serial transfer data
    SC      = 0xFF02,  // Serial transfer control
 
    /* Timer */
    DIV     = 0xFF04,   // Divider
    TIMA    = 0xFF05,   // Timer counter
    TMA     = 0xFF06,   // Timer modulo
    TAC     = 0xFF07,   // Timer control
 
    /* Audio */
    NR10    = 0xFF10,  // Channel 1
    NR11    = 0xFF11,  // Channel 1
    NR12    = 0xFF12,  // Channel 1
    NR13    = 0xFF13,  // Channel 1
    NR20    = 0xFF00,  // Channel 2??
    NR21    = 0xFF00,  // Channel 2??
    NR22    = 0xFF00,  // Channel 2??
    NR23    = 0xFF00,  // Channel 2??
    NR30    = 0xFF1A,  // Channel 3
    NR31    = 0xFF1B,  // Channel 3
    NR32    = 0xFF1C,  // Channel 3
    NR33    = 0xFF1D,  // Channel 3
    NR34    = 0xFF1E,  // Channel 3
    WAVE    = 0xFF30,  // Wave pattern RAM (Channel 3)
    NR41    = 0xFF20,  // Channel 4
    NR42    = 0xFF21,  // Channel 4
    NR43    = 0xFF22,  // Channel 4
    NR44    = 0xFF23,  // Channel 4
    NR50    = 0xFF24,  // Master
    NR51    = 0xFF25,  // Master
    NR52    = 0xFF26,  // Master

    /* LCD */
    LCDC    = 0xFF40,   // LCD & PPU Control
    STAT    = 0xFF41,   // LCD status
    SCY     = 0xFF42,   // Viewport Y position
    SCX     = 0xFF43,   // Viewport X position
    LY      = 0xFF44,   // LCD Y coordinate
    LYC     = 0xFF45,   // LY compare
    BGP     = 0xFF47,   // BG palette data
    OBP0    = 0xFF48,   // OBJ palette 0 data
    OBP1    = 0xFF49,   // OBJ palette 1 data
    WY      = 0xFF4A,   // Window Y position
    WX      = 0xFF4B,   // Window X position
    BROM    = 0xFF50    // Boot ROM
};

class Memory {
private:
    uint8_t* memory[0xFFFF + 1];
    uint8_t prot_memory[0xFFFF + 1];
    uint8_t wram[0x2000];
    uint8_t vram[0x2000];
    uint8_t OAM[0x9F + 1];
    uint8_t restrio[0x5F + 1];
    uint8_t ioregs[0xFF + 1];

    uint8_t BOOTSTRAP[0xFF + 1];
    
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
    void Mapper(const uint16_t loc, uint8_t* array, const size_t size);
    void Prepare();

    // Checks
    void LoadBootstrap();
};

#endif