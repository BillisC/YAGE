#ifndef SYSTEM_H
#define SYSTEM_H

#include "memory.h"

struct flag_register{
    uint8_t pad : 4;
    uint8_t C   : 1;
    uint8_t H   : 1;
    uint8_t N   : 1;
    uint8_t Z   : 1;
};

struct gameboy_system{
    uint8_t A, B, C, D, E, F, H, L;
    flag_register flags;

    uint16_t PC{0x100}, SP{0xFFFE};

    Memory memoryH;
    //Sound soundH;
    //Video videoH;
    //Timers timerH;
    //Interrupts intrH;
    //S_Modes modeH;
};


#endif