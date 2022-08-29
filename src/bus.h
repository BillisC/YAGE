#ifndef BUS_H
#define BUS_H

// Libraries
#include <stdint.h>

// Components
#include "cpu.h"
#include "memory.h"
#include "cartridge.h"

class Bus {
public:
    CPU cpu{ this };
    Memory memory{ this };
    Cartridge* cartridge;
    //Sound sound;
    //Video video;
    //Interrupts intr;

public:
    Bus() {
        cartridge = new Cartridge(this);
    }

    void Reset() {
        // Reinitialize memory
        memory.Reset();
        // Reinitialize CPU
        cpu.Reset();
    }
};


#endif