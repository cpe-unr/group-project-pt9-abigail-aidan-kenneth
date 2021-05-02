#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <iostream> 
#include "Processor.h"

class Normalize : public Processor
{
    public:

    Normalize();
    ~Normalize();

    void processBuffer(unsigned char* buffer, int bufferSize);
    void shortProcessBuffer(short* shortBuffer, int bufferSize);
};

#endif