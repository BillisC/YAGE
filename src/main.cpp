#include <chrono>

#include "gameboy.h"

int main() {
    bool active = true;

    // Setup Environment
    Gameboy *gb = new Gameboy;

    if (gb->Load("roms/cpu_instrs.gb") != 1) {
        return -1;
    }

    gb->debug.MemoryBuffer();
    gb->debug.Log("------------------");

    //std::chrono::time_point<std::chrono::system_clock> last = std::chrono::system_clock::now();
    while (active) {
        gb->cpu.Fetch();
        //std::cin.get();

        //last = std::chrono::system_clock::now();
    }

    return 0;
}