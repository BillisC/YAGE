#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <fstream>
#include <stdint.h>

class Debugger {
    Gameboy *gb;

public:
    Debugger(Gameboy *mgb): gb(mgb) {}

    void MemoryBuffer() {
        std::string buffer_name = "memory_buffer.bin";
        std::fstream buffer_file;
        
        buffer_file.open(buffer_name, std::ios::out | std::ios::binary);
        if (buffer_file.is_open()) {
            uint8_t* buffer = nullptr;
            //gb->memory.Read(0x0000, buffer, 0xFFFF + 1);
            buffer_file.write(reinterpret_cast<char *>(buffer), 0xFFFF+1);
            buffer_file.close();
        }
    }
};

#endif