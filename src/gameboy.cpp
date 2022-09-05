#include "gameboy.h"

int Gameboy::Load(const std::string file_name) {
    if(cartridge.Init(file_name) == 0) {
        memory.Prepare();
        rom_loaded = true;
        debug.Log("File Loaded");
    }
    else rom_loaded = false;
    
    return rom_loaded;
}

void Gameboy::Reset() {
    debug.Log("Resetting Gameboy");

    // Reinitialize CPU
    cpu.Reset();
    // Reinitialize memory
    memory.Reset();
    // Reinitialize Cartridge
    cartridge.Reset();
}