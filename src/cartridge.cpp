#include "gameboy.h"

// Initialization
void Cartridge::Init(const std::string file_name) {
    /* Open the ROM */
    std::fstream rom(file_name, std::ios::in | std::ios::binary);
    if (!rom.is_open()) {
        gb->debug.Log("Unable to open ROM file!");
        gb->debug.ForceStop(1);
    }

    /* Get the ROM's size */
    rom.seekg(0, std::ios::end);
    size_t file_size = rom.tellg();
    gb->debug.Log("File size: " + std::to_string(file_size));
    rom.seekg(0, std::ios::beg);

    /* Buffer catridge data */
    uint8_t* filebuf = new uint8_t[file_size];
    rom.read(reinterpret_cast<char*>(filebuf), file_size);
    if (rom.fail()) {
        delete[] filebuf;
        gb->debug.Log("Unable to read ROM file!");
        gb->debug.ForceStop(1);
    }
    rom.close();

    /* Initialize Cartridge */
    InitHeader(filebuf);
    InitMBC(filebuf);

    delete[] filebuf;
}

void Cartridge::Reset() {
    gb->debug.Log("Resetting Cartridge");
    delete mbc;
}

void Cartridge::InitHeader(uint8_t* filebuf) {
    for (int i = 0; i < 16; i++) header.title[i] = filebuf[i + 0x134];
    header.cgb_flag = filebuf[0x143];
    for (int i = 0; i < 2; i++) header.licensee[i] = filebuf[0x144 + i];
    header.sgb_flag = filebuf[0x146];
    header.catridge_type = filebuf[0x147];
    header.rom_size = filebuf[0x148];
    header.ram_size = filebuf[0x149];
    header.destination_code = filebuf[0x14A];
    header.licensee_old = filebuf[0x14B];
    header.version = filebuf[0x14C];
    header.checksum_header = filebuf[0x14D];
    for (int i = 0; i < 2; i++) header.checksum_global[i] = filebuf[0x14E + i];

    gb->debug.Log("Title: " + GetTitle());
    gb->debug.Log("ROM Size: " + std::to_string(32 * (1 << header.rom_size)) + "kb");
}

void Cartridge::InitMBC(uint8_t* filebuf) {
    switch (header.catridge_type) {
        case 0x00: mbc = new NO_MBC; break;

        case 0x01:
        case 0x02:
        case 0x03: mbc = new MBC1; break;

        case 0x05:
        case 0x06: break;

        case 0x08:
        case 0x09: mbc = new NO_MBC; break;
    };
    gb->debug.Log("MBC Type: " + GetMBCType());
    
    if (GetMBCType() == "UNIMPLEMENTED" || !mbc->Init(header.rom_size, header.ram_size, filebuf)) {
        gb->debug.Log("MBC Initialization failed!");
        gb->debug.ForceStop(4);
    }
}

// Cartridge info
std::string Cartridge::GetMBCType() {
    switch (header.catridge_type) {
        case 0x00: return "ROM";
        case 0x01: return "MBC1";
        case 0x02: return "MBC1+RAM";
        case 0x03: return "MBC1+RAM+BATTERY";
        case 0x08: return "ROM+RAM";
        case 0x09: return "ROM+RAM+BATTERY";
        default: return "UNIMPLEMENTED";
    };
}

std::string Cartridge::GetTitle() {
    std::string t = (char*)header.title;
    return t;
}