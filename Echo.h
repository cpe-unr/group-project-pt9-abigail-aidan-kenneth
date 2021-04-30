//Kenneth Peterson
//Messing with wav files(Programming assignment 3)
//03/23/2021
//Echo.h

#ifndef ECHO_H
#define ECHO_H

#include <iostream> 
#include "Processor.h"

class Echo : public Processor
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