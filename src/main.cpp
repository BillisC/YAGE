#include <chrono>

#include "bus.h"

int main() {
    //bool active = false;

    // Setup Environment
    Gameboy* gb_system = new Gameboy;

    if (gb_system->Load("roms/cpu_instrs.gb") != 1) {
        printf("Initialization Failure!\n");

        return -1;
    }

    gb_system->Reset();
    gb_system->debug.MemoryBuffer();

    // Actual Loop
    //std::chrono::time_point<std::chrono::system_clock> last = std::chrono::system_clock::now();
    //while (active) {
    //    if (std::chrono::duration<double, std::nano>(std::chrono::system_clock::now() - last).count() > 238.41) {
    //        gb_system->Fetch();
    //
    //        last = std::chrono::system_clock::now();
    //    }
    //}

    delete gb_system;

    return 0;
}