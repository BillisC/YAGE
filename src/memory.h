#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <string.h>

/*  --------------------------- 0xFFFF
     Interrupt Enable Register  
    --------------------------- 0xFFFE
     Internal CPU RAM
    --------------------------- 0xFF7F
     I/O Registers
    --------------------------- 0xFEFF
     Empty but unusable for I/O
    --------------------------- 0xFE9F
     Sprite Attrib Memory (OAM)
    --------------------------- 0xFDFF
     Echo of Work RAM
    --------------------------- 0xDFFF
     4kB Work RAM, switchable (1-7)
    --------------------------- 0xCFFF
     4kB Work RAM
    --------------------------- 0xBFFF
     8kB External RAM (catridge)
    --------------------------- 0x9FFF
     8kB Video RAM
    --------------------------- 0x7FFF
     16kB switchable ROM bank         
    --------------------------- 0x3FFF 
     16kB ROM bank #0                   
    --------------------------- 0x0000 -- */

class Memory {
private:
    uint8_t **memory[0xFFFF + 1];

public:
    Memory() {};

    void Init();
    void Clear();

    // Write operations
    void Write(const uint16_t loc, uint8_t* buffer, const size_t size);
    void Write8(const uint16_t loc, const uint8_t byte);

    // Read operations
    void Read(const uint16_t loc, uint8_t* buffer, const size_t size);
    uint8_t Read8(const uint16_t loc);
    uint16_t Read16(const uint16_t loc);
    uint8_t* GetHostAddress(const uint16_t loc); // Allows the use of pointers and adds control over the address space of memory

    // Checks
    bool VerifyLogo();
};

#endif