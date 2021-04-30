#ifndef METADATA_H
#define METADATA_H


typedef struct meta_data {

    //Top
    char list[4];
    int sizeOfChunk;
    char info[4];
    //Middle
    char ID[4];
    int subchunk_size;


} meta_data;

#endif