#ifndef CATRIDGE_H
#define CATRIDGE_H

// Libraries
#include <fstream>
#include <stdint.h>

#include "tools.h"
#include "mbc.h"
#include "mbc1.h"

class Gameboy;

class Cartridge {
    struct Header {
        uint8_t title[16];
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
    } header;

    Gameboy* gb;

public:
    Cartridge(Gameboy* mbus) : gb(mbus) {}
    ~Cartridge() { Reset(); }

    // Initialization
    void Init(const std::string file_name);
    void Reset();

private:
    void InitHeader(uint8_t* filebuf);
    void InitMBC(uint8_t* filebuf);

public:
    MBC_TEMPLATE* mbc;

    // Cartridge info
    std::string GetMBCType();
    std::string GetTitle();
};


#endif