//Team 9
//Noise Gating wav files
//04/25/2021
//NoiseGate.h

#ifndef NOISEGATE_H
#define NOISEGATE_H

#include<iostream>
#include"IProcessor.h"

class Noise : public IProcessor
{

    public:
    int noiseGate();
    void processBuffer(unsigned char* buffer, int bufferSize);
    void shortProcessBuffer(short* shortBuffer, int bufferSize);
};

#endif