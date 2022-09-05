#include <chrono>

#include "gameboy.h"

int main() {

    // Setup Environment
    Gameboy gb;

    if (gb.Load("roms/cpu_instrs.gb") != 1) {
        return -1;
    }

    gb.debug.MemoryBuffer();

    gb.debug.Log("------------------");

    //std::chrono::time_point<std::chrono::system_clock> last = std::chrono::system_clock::now();
    //while (active) {
    //    if (std::chrono::duration<double, std::nano>(std::chrono::system_clock::now() - last).count() > 238.41) {
    //        gb_system->Fetch();
    //
    //        last = std::chrono::system_clock::now();
    //    }
    //}

    return 0;
}