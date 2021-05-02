#ifndef METADATA_H
#define METADATA_H

#include <iostream>
#include <vector>

typedef struct meta_data {

    //Top
    char list[4];
    int sizeOfChunk;
    char info[20];

} meta_data;

#endif