#ifndef CATRIDGE_H
#define CATRIDGE_H

// Libraries
#include <fstream>

#include "bus.h"

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
    NO_MBC* mbc;

private:
    Bus* bus;
    uint8_t* filebuf;

public:
    Cartridge(Bus* bus) {
        this->bus = bus;
    }

    int InitCartridge(const std::string file_name) {
        LoadFile(file_name);
        InitHeader();
        InitMBC();

        mbc->prep_rom(header.rom_size);
        mbc->prep_ram(header.ram_size);
    }

private:
    int LoadFile(const std::string file_name);
    void InitHeader();
    void InitMBC();
};


/* Memory Bank Controllers */
class NO_MBC {
protected:
    uint8_t** rom_banks{ nullptr };
    uint8_t** ram_banks{ nullptr };

    uint8_t rom_banks_count{ 0 };
    uint8_t ram_banks_count{ 0 };

protected:
    void ROM_INIT() {
        rom_banks = new uint8_t * [rom_banks_count];
        for (int i = 0; i < rom_banks_count; i++) {
            rom_banks[i] = new uint8_t[0x4000];
            memset(rom_banks[i], 0, 0x4000);
        }
    }

    void RAM_INIT() {
        ram_banks = new uint8_t * [ram_banks_count];
        for (int i = 0; i < ram_banks_count; i++) {
            ram_banks[i] = new uint8_t[0x2000];
            memset(ram_banks[i], 0, 0x2000);
        }
    }

public:
    NO_MBC() {}

    void prep_rom(const uint8_t rom_size) {
        rom_banks_count = 2;
        ROM_INIT();
    }

    void prep_ram(const uint8_t ram_size) {
        switch (ram_size) {
            case 0x2: ram_banks_count = 1; break;
            default: ram_banks_count = 0;
        }
        if (ram_banks_count) RAM_INIT();
    }
};

class MBC1 : public NO_MBC {
protected:
    struct Registers {
        uint8_t RAM_ENABLE{ 0x00 };
        uint8_t ROM_BANK_NUMBER{ 0x01 };
        uint8_t ROM_BANK_MODE{ 0x00 };
        uint8_t RAM_BANK_NUMBER{ 0x00 };
    } registers;

public:
    MBC1() {}

    void prep_rom(const uint8_t rom_size) {
        rom_banks_count = (32 << rom_size) / 16;
        ROM_INIT();
    }

    void prep_ram(const uint8_t ram_size) {
        switch (ram_size) {
            case 0x2: ram_banks_count = 1; break;
            case 0x3: ram_banks_count = 4; break;
            case 0x4: ram_banks_count = 16; break;
            case 0x5: ram_banks_count = 8; break;
            default: ram_banks_count = 0;
        }
        if (ram_banks_count) RAM_INIT();
    }

};

class MBC2 : public MBC1 {
protected:
    void RAM_INIT() {
        ram_banks = new uint8_t * [1];
        ram_banks[0] = new uint8_t[512];
        memset(ram_banks[0], 0, 512);
    }

public:
    MBC2() {}

    void prep_ram(const uint8_t ram_size) {
        RAM_INIT();
    }
};

#endif