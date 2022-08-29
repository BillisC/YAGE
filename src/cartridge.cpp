#include "cartridge.h"

int Cartridge::LoadFile(const std::string file_name) {
    /* Open the ROM */
    std::fstream rom;
    rom.open(file_name, std::ios::in | std::ios::binary);
    if (!rom.is_open()) {
        printf("\nFailed to load file");
    }

    /* Get the ROM's size */
    rom.seekg(0, std::ios::end);
    size_t file_size = rom.tellg();
    rom.seekg(0, std::ios::beg);
    printf("\nROM Size: %d\n", file_size);

    /* Buffer catridge data */
    delete[] filebuf;
    filebuf = new uint8_t[file_size];
    rom.read(reinterpret_cast<char*>(filebuf), file_size);
    rom.close();
}

void Cartridge::InitHeader() {
    memcpy(&header, filebuf + 0x134, 0x1B);
    printf("Title: %s\n", header.title);
    printf("Checksum: %02x\n", header.checksum_global[0]);
}

void Cartridge::InitMBC() {
    switch (header.catridge_type) {
        case 0x00: mbc = new NO_MBC; break;

        case 0x01:
        case 0x02:
        case 0x03: mbc = new MBC1; break;

        case 0x05:
        case 0x06: mbc = new MBC2; break;

        case 0x08:
        case 0x09: mbc = new NO_MBC;
    };
}