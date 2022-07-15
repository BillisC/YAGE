#ifndef CATRIDGE_H
#define CATRIDGE_H

#include <stdint.h>

struct Catridge {
    char title[16];
    uint8_t cgb_flag;
    uint8_t licensee[2];
    uint8_t sgb_flag;
    uint8_t catridge_type;
    uint8_t rom_size;
    uint8_t ram_size;
    uint8_t destination_code;
    uint8_t licensee_old;
    uint8_t version;
    uint8_t checksum_header;
    uint8_t checksum_global[2];
};

class NO_MBC {
    uint8_t *rom_bank_0{nullptr};    // Must exist
    uint8_t **switchable_rom_bank{nullptr};

    uint8_t *ram_bank_0{nullptr};    // Should exist
    uint8_t **switchable_ram_banks{nullptr};

    NO_MBC(uint8_t ram_size){
        rom_bank_0 = new uint8_t[0x7FFF + 1];
        
        if(ram_size == 0x00)
        ram_bank_0 = new uint8_t[]
    }
};


#endif