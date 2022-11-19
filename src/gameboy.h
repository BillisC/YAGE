#ifndef BUS_H
#define BUS_H

// Libraries
#include <string>

// Components
#include "cpu.h"
#include "memory.h"
#include "cartridge.h"
#include "debugger.h"

class Gameboy {
    bool rom_loaded{ false };

public:
    Debugger debug{ this };
    CPU cpu{ this };
    Memory memory{ this };
    Cartridge cartridge{ this };
    //Sound sound;
    //Video video;
    //Interrupts intr;

public:
    Gameboy() {}

    int Load(const std::string rom_name);
    void Reset();
};


#endif