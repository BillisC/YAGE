#ifndef MBC_H
#define MBC_H

#include <stdint.h>

/* Memory Bank Controllers */
class MBC_TEMPLATE {
protected:
    struct Registers {
        uint8_t RAM_ENABLE : 4;
        uint8_t RAM_BANK : 2;
        uint8_t ROM_BANK : 5;
        uint8_t BANK_MODE : 1;
    } registers;

    uint8_t** rom_banks{ nullptr };
    uint8_t** ram_banks{ nullptr };

    uint8_t rom_banks_count, ram_banks_count;

public:
    virtual ~MBC_TEMPLATE() {}

    virtual int Init(const uint8_t romsize, const uint8_t ramsize, uint8_t* file) = 0;

    virtual uint8_t* GetRomBank() = 0;
    virtual uint8_t* GetRomBank(uint8_t bank) = 0;
    virtual uint8_t* GetRamBank() = 0;
    virtual uint8_t GetRamAccess() = 0;
    virtual bool GetBankMode() = 0;

    virtual void SetRomBank(uint8_t bank) = 0;
    virtual void SetRamBank(uint8_t bank) = 0;
    virtual void SetRamAccess(uint8_t val) = 0;
    virtual void SetBankMode(uint8_t mode) = 0;
};


/* NO MBC */
class NO_MBC : public MBC_TEMPLATE {
public:
    NO_MBC() {}
    ~NO_MBC() {
        Deallocator2D(1, 0x8000, rom_banks);
        if (ram_banks_count) Deallocator2D(ram_banks_count, 0x2000, ram_banks);
    }

    uint8_t* GetRomBank() { return nullptr; }
    uint8_t* GetRomBank(uint8_t bank) { return nullptr; }
    uint8_t* GetRamBank() { return nullptr; }
    bool GetBankMode() { return 0; }
    uint8_t GetRamAccess() { return 0; }

    void SetRomBank(uint8_t bank) {}
    void SetRamBank(uint8_t bank) {}
    void SetRamAccess(uint8_t val) {}
    void SetBankMode(uint8_t mode) {}

    int Init(const uint8_t romsize, const uint8_t ramsize, uint8_t* file) {
        // Initialize ROM space
        rom_banks_count = 1;
        rom_banks = Allocator2D(rom_banks_count, 0x8000);
        memcpy(rom_banks[0], file + 0x150, 0x8000);
        if (rom_banks == nullptr) return 1;

        // Initialize RAM space
        switch (ramsize) {
            case 0x2: ram_banks_count = 1; break;
            default: ram_banks_count = 0;
        };
        if (ram_banks_count != 0) {
            ram_banks = Allocator2D(ram_banks_count, 0x2000);
            if (rom_banks == nullptr) return 1;
        }

        return 0;
    }
};

#endif