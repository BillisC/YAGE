#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <string.h>

/*   Interrupt Enable Register
    --------------------------- FFFF
     Internal RAM
    --------------------------- FF80
     Empty but unusable for I/O
    --------------------------- FF4C
     I/O ports
    --------------------------- FF00
     Empty but unusable for I/O
    --------------------------- FEA0
     Sprite Attrib Memory (OAM)
    --------------------------- FE00
     Echo of 8kB Internal RAM
    --------------------------- E000
     8kB Internal RAM
    --------------------------- C000
     8kB switchable RAM bank
    --------------------------- A000
     8kB Video RAM
    --------------------------- 8000 --
     16kB switchable ROM bank         |
    --------------------------- 4000  |= 32kB Cartrigbe
     16kB ROM bank #0                 |
    --------------------------- 0000 -- */

class Memory{
private:
    uint8_t memory[0xFFFF];

public:
    Memory(){};

    void Init();
    void Clear();

    // Write operations
    void Write8Mem( const uint16_t loc, const uint8_t byte );
    void WriteMem( const uint16_t loc, uint8_t *buffer, const uint8_t size );

    // Read operations
    void CopyMem( uint8_t *buffer );
    uint8_t Read8Mem( const uint16_t loc );
    uint16_t Read16Mem( const uint16_t loc );
    uint8_t *GetHostAddressMem( const uint16_t loc ); // Allows the use of pointers and adds control over the address space of memory
};

#endif