#include "gameboy.h"

int main() {
    // Setup Environment
    Gameboy *gb = new Gameboy;

    gb->Load("roms/cpu_instrs.gb");

    gb->debug.MemoryBuffer();
    gb->debug.Log("------------------");

    while (true) {
        gb->cpu.Fetch();
        gb->cpu.Execute();
    }

    return 0;
}