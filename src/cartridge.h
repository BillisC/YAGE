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

    MBC_NUL mbc;
};

/* Memory Bank Controllers */

class MBC_NUL {
protected:
    uint8_t rom_banks_count{ 0 };
    uint8_t* rom_bank_0{ nullptr };
    uint8_t** rom_banks{ nullptr };

    uint8_t ram_banks_count{ 0 };
    uint8_t** ram_banks{ nullptr };

protected:
    /* 
        In order to avoid the limitation of the 16bit memory bus ROMs may have 
        multiple ROM banks. Every ROM bank consists of 16kb worth of data. If 
        there is no MBC at all the system allocates a 32kb address space for it.
    */
    void AllocateROM(const uint8_t& rom_size) {
        rom_bank_0 = new uint8_t[0x4000];
        rom_banks_count = (32 << rom_size) / 16;

        rom_banks = new uint8_t * [rom_banks_count];
        for (int i = 0; i < rom_banks_count; i++) {
            rom_banks[i] = new uint8_t[0x4000];
            memset(rom_banks[i], 0, 0x4000);
        }
    }

    void DeallocateROM() {
        /* Deallocate ROM bank #0 */
        delete[] rom_bank_0;
        rom_bank_0 = nullptr;

        /* Deallocate all ROM banks */
        for (int i = 0; i < rom_banks_count; i++) {
            delete[] rom_banks[i];
        }
        delete[] rom_banks;
        rom_banks = nullptr;
    }

    /* 
        Cartridges may include an additional RAM circuit which can split in 8kb 
        banks. Unlike most MBCs MBC2 is considered to be a special case because 
        the memory bus is 4bit and the size is always 512 x 4. 
    */
    void AllocateRAM(const uint8_t& ram_size) {
        if (ram_size == 0x00 || ram_size == 0x01) return;
        else if (ram_size == 0x02) ram_banks_count = 1;
        else if (ram_size == 0x03) ram_banks_count = 4;
        else if (ram_size == 0x04) ram_banks_count = 16;
        else if (ram_size == 0x05) ram_banks_count = 8;

        ram_banks = new uint8_t * [ram_banks_count];
        for (int i = 0; i < ram_banks_count; i++) {
            ram_banks[i] = new uint8_t[0x2000];
            memset(ram_banks[i], 0, 0x2000);
        }
    }

    void DeallocateRAM() {
        /* Deallocate RAM banks */
        for (int i = 0; i < ram_banks_count; i++) {
            delete[] ram_banks[i];
        }
        delete[] ram_banks;
        ram_banks = nullptr;
    }

public:
    MBC_NUL() {
        /* NO MBC */
        rom_banks = 0;
        rom_bank_0 = new uint8_t[0x8000];
    }
    
    virtual ~MBC_NUL() {
        DeallocateROM();
        DeallocateRAM();
    }
};

class MBC1 : public MBC_NUL {
public:
    MBC1(const uint8_t& rom_size, const uint8_t& ram_size) {        
        AllocateROM(rom_size);
        AllocateRAM(ram_size);
    }
};

class MBC2 : public MBC_NUL {
private:
    uint8_t* ram_bank;

private:
    void AllocateRAM(const uint8_t& ram_size) {
        if (ram_size != 0x00) return;
        
        // Only the lower 4 bits should be accessed
        ram_bank = new uint8_t[512];
        memset(ram_bank, 0, 512);
    }

public:
    MBC2(const uint8_t& rom_size, const uint8_t& ram_size) {
        AllocateROM(rom_size);
        AllocateRAM(ram_size);
    }
    
    ~MBC2() {
        DeallocateROM();
        delete[] ram_bank;
    }
};

class MBC3 : public MBC1 {
    
};


#endif