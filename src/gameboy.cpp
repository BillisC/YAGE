#include "gameboy.h"

void Gameboy::Load(const std::string rom_name) {
    cartridge.Init(rom_name);
    memory.Prepare();
    debug.Log("File Loaded");
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
