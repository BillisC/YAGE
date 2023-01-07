#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>

/*
    Error Codes:
        - 1 ROM_LOAD_FAILED
        - 2 BOOTSTRAP_LOAD_FAILED
        - 3 MAPPED_NULLPTR_IN_MEM
        - 4 MBC_UNSUPPORTED
*/

class Debugger {
    Gameboy* gb;

public:
    Debugger(Gameboy* mgb) : gb(mgb) {}

    void MemoryBuffer();
    void Log(std::string txt);
    void ForceStop(const uint8_t error);
};

#endif