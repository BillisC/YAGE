#ifndef TOOLS_H
#define TOOLS_H

#include "stdint.h"

inline uint8_t** Allocator2D(int rows, int columns) {
    uint8_t** tmp;

    tmp = new uint8_t * [rows];
    for (int i = 0; i < rows; i++) {
        tmp[i] = new uint8_t[columns];
    }

    return tmp;
}

inline void Deallocator2D(int rows, int columns, uint8_t **tmp) {
    for (int i = 0; i < rows; i++) {
        delete[] tmp[i];
    }

    delete[] tmp;
}

#endif