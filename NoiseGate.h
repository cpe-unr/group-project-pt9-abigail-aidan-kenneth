//Kenneth Peterson
//Messing with wav files(Programming assignment 3)
//03/23/2021
//NoiseGate.h

#ifndef NOISEGATE_H
#define NOISEGATE_H

#include<iostream>
#include"Processor.h"

class Noise : public Processor
{

    public:
    int noiseGate();
    void processBuffer(unsigned char* buffer, int bufferSize);
    void shortProcessBuffer(short* shortBuffer, int bufferSize);
};

#endif