#ifndef CATRIDGE_H
#define CATRIDGE_H

// Libraries
#include <fstream>
#include <stdint.h>

#include "mbc.h"
#include "mbc1.h"

class Cartridge {
private:
    struct Header {
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
    } header;

public:
    MBC_TEMPLATE* mbc;

private:
    Gameboy* bus;
    uint8_t* filebuf;

public:
    Cartridge(Gameboy* mbus): bus(mbus) {}
    ~Cartridge() { delete mbc; }

    int Init(const std::string file_name) { LoadFile(file_name); }

private:
    int LoadFile(const std::string file_name);
    void InitHeader();
    void InitMBC();
};


#endif