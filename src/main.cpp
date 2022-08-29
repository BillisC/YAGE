#include <chrono>

#include "cpu.h"

int main() {
    bool active = false;

    // Setup Environment
    Bus* gb_system = new Bus();

    if (gb_system->LoadCatridge("roms/cpu_instrs.gb") != 0) {
        printf("Initialization Failure!\n");

        return -1;
    }

    gb_system->MemoryDump();

    // Actual Loop
    std::chrono::time_point<std::chrono::system_clock> last = std::chrono::system_clock::now();
    while (active) {
        if (std::chrono::duration<double, std::nano>(std::chrono::system_clock::now() - last).count() > 238.41) {
            gb_system->Fetch();

            last = std::chrono::system_clock::now();
        }
    }

    delete gb_system;

    return 0;
}