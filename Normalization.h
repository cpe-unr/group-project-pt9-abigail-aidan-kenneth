//Team 9
//Normalizing wav files
//04/25/2021
//Normalization.h


#ifndef NORMALIZATION_H
#define NORMALIZATION_H

#include <iostream> 
#include "IProcessor.h"

class Normalize : public IProcessor
{
    public:

    Normalize();
    ~Normalize();

    void processBuffer(unsigned char* buffer, int bufferSize);
    void shortProcessBuffer(short* shortBuffer, int bufferSize);
};

#endif