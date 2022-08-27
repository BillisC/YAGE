#ifndef CATRIDGE_H
#define CATRIDGE_H

#include <stdint.h>

struct Cartridge {
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

    //MBC mbc;
};

/* Memory Bank Controllers */

class MBC {
    uint8_t** rom_banks{ nullptr };
    uint8_t** ram_banks{ nullptr };

    uint8_t rom_banks_count, ram_banks_count;
    uint8_t mbc_type;

private:
    void ROM_INIT() {
        rom_banks = new uint8_t * [rom_banks_count];
        for (int i = 0; i < rom_banks_count; i++) {
            rom_banks[i] = new uint8_t[0x4000];
            memset(rom_banks[i], 0, 0x4000);
        }
    }

    void RAM_INIT() {
        if (mbc_type == 0x5 || mbc_type == 0x6) {
            ram_banks = new uint8_t * [1];
            ram_banks[0] = new uint8_t[0x1E00];
            memset(ram_banks[0], 0, 0x1E00);
        }
        else {
            ram_banks = new uint8_t * [ram_banks_count];
            for (int i = 0; i < ram_banks_count; i++) {
                ram_banks[i] = new uint8_t[0x2000];
                memset(ram_banks[i], 0, 0x2000);
            }
        }
    }

public:
    MBC(const uint8_t rom_size, const uint8_t ram_size, const uint8_t mbc_type) {
        this->mbc_type = mbc_type;
        rom_banks_count = (32 << rom_size) / 16;
        ROM_INIT();

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

#endif