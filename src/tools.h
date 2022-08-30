#ifndef TOOLS_H
#define TOOLS_H

#include "stdint.h"

uint8_t** Allocator2D(int rows, int columns) {
    uint8_t **tmp;

    tmp = new uint8_t * [rows];
    for (int i = 0; i < rows; i++) {
        tmp[i] = new uint8_t[columns];
    }

    return tmp;
}

void Deallocator2D(int rows, int columns, uint8_t **tmp) {
    uint8_t **temp;

    for (int i = 0; i < rows; i++) {
        delete[] temp[i];
    }

    delete[] temp;
}

#endif