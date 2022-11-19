#include "gameboy.h"

void Debugger::MemoryBuffer() {
    Log("Memory Copy Requested");
    std::string buffer_name = "debug/memory_buffer.bin";
    std::fstream buffer_file(buffer_name, std::ios::out | std::ios::binary);

    if (buffer_file.is_open()) {
        uint8_t* buffer = new uint8_t[0x10000];
        gb->memory.Read(0x0000, buffer, 0x10000);

        buffer_file.write(reinterpret_cast<char*>(buffer), 0x10000);
        if (buffer_file.fail()) Log("Memory Copy Failed!");

        delete[] buffer;
        buffer_file.close();
    }
}

void Debugger::Log(std::string txt) {
    std::cout << "DEBUG: " << txt << "\n";
}