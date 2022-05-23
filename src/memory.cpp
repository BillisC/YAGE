#include "memory.h"

Memory::Memory(){}

void Memory::load_catridge(){
    
}

void Memory::write_2_mem(uint16_t loc, uint8_t byte){
    memory[loc] = byte;
    if(loc >= 0xE000 && loc <= 0xFE00) memory[loc - 0x2000] = byte;
    else if(loc >= 0xC000 && loc <= 0xDE00) memory[loc + 0x2000] = byte;
}
