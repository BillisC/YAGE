#include "gameboy.h"

int Gameboy::Load(const std::string rom_name) {
    bool all_good = true;
    
    if(cartridge.Init(rom_name) == 0) {
        memory.Prepare();
        debug.Log("File Loaded");
    }
    else all_good = false;
        
    return all_good;
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