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

struct RIFF_Chunk
{
    char RIFF[4];
    int ChunkSize;
    char WAVE[4];
};

struct Data_Chunk
{
    char label[4]; 
    int size; 
    char* data;
};

struct Meta_Chunk
{
    char label[4];
    int MetaChunkSize;
    char* chunk_info;
};



#endif
