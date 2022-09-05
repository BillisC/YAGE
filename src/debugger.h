#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>

class Debugger {
    Gameboy* gb;

public:
    Debugger(Gameboy* mgb) : gb(mgb) {}

    void MemoryBuffer();
    void Log(std::string txt);
};

#endif