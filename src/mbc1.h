#ifndef MBC1_H
#define MBC1_H

#include <stdint.h>

/* MBC1 */
class MBC1 : public MBC_TEMPLATE {
public:
    MBC1() {}
    ~MBC1() { Deallocator2D(rom_banks_count, 0x4000, rom_banks); if(ram_banks_count) Deallocator2D(ram_banks_count, 0x2000, ram_banks); }

    uint8_t* GetRomBank() { return (registers.BANK_MODE == 0) ? rom_banks[(registers.RAM_BANK << 5) | registers.ROM_BANK] : rom_banks[registers.ROM_BANK]; }
    uint8_t* GetRamBank() { return (registers.BANK_MODE == 0) ? ram_banks[0] : ram_banks[registers.RAM_BANK]; }
    uint8_t GetRamAccess() { return registers.RAM_ENABLE; }
    bool GetBankMode() { return registers.BANK_MODE; }
    void SetRomBank(uint8_t bank) { registers.ROM_BANK = bank; registers.ROM_BANK |= (registers.ROM_BANK == 0); }
    void SetRamBank(uint8_t bank) { registers.RAM_BANK = bank; }
    void SetRamAccess(uint8_t val) { registers.RAM_ENABLE = val; }
    void SetBankMode(uint8_t mode) { registers.BANK_MODE = mode; }

    void Init(const uint8_t romsize, const uint8_t ramsize, uint8_t* file) {
        // Initialize ROM space
        rom_banks_count = (32 << romsize) / 16;
        rom_banks = Allocator2D(rom_banks_count, 0x4000);
        for(int i = 0; i < rom_banks_count; i++) memcpy(rom_banks[i], file + 150, 0x4000); 

        // Initialize RAM space
        switch (ramsize) {
            case 0x2: ram_banks_count = 1; break;
            case 0x3: ram_banks_count = 4; break;
            case 0x4: ram_banks_count = 16; break;
            case 0x5: ram_banks_count = 8; break;
            default: ram_banks_count = 0;
        };
        if (ram_banks_count) ram_banks = Allocator2D(ram_banks_count, 0x2000);

        // Initialize registers
        SetRomBank(0);
        SetRamBank(0);
        SetRamAccess(0);
        SetBankMode(0);
    }
};


#endif