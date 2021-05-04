//Team 9
//Processor interface
//05/04/2021
//IProcessor.H

#ifndef PROCESSOR_H
#define PROCESSOR_H


#include <cstdint>
#include <cmath>

class IProcessor {
public:

    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
    virtual void shortProcessBuffer(short* shortBuffer, int bufferSize) = 0;
};


#endif
