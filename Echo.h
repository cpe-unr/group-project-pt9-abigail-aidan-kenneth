//Team 9
//Making wav files Echo
//04/25/2021
//Echo.h

#ifndef ECHO_H
#define ECHO_H

#include <iostream> 
#include "IProcessor.h"

class Echo : public IProcessor
{
private:
    int delay;
public:
    Echo();
    Echo(int newDelay);
    ~Echo();
    int getDelay();
    void processBuffer(unsigned char* buffer, int bufferSize);
    void shortProcessBuffer(short* shortBuffer, int bufferSize);
};

#endif