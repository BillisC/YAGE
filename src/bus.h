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
    Cartridge* cartridge;
    //Sound sound;
    //Video video;
    //Interrupts intr;

public:
    Gameboy() {}

    int Load(const std::string file_name) {
        delete cartridge;
        cartridge = new Cartridge(this);

        if(cartridge->Init(file_name) == 0) rom_loaded = true;
        else rom_loaded = false;

        return rom_loaded;
    }

    void Reset() {
        if(!rom_loaded) return;

        // Reinitialize memory
        memory.Reset();
        // Reinitialize CPU
        cpu.Reset();
    }
};


#endif