//Kenneth Peterson
//Messing with wav files(Programming assignment 3)
//03/23/2021
//NoiseGate.cpp

#include "NoiseGate.h"

using namespace std;

void Noise::processBuffer(unsigned char* buffer, int bufferSize)
{
    for(int i = 0; i < bufferSize; i++)
    {
        if(buffer[i] >= 124 && buffer[i] <= 144)
        {
            buffer[i] = 128;
        }
    }
}

void Noise::shortProcessBuffer(short* shortBuffer, int bufferSize)
{
        for(int i = 0; i < bufferSize; i++)
    {
        if(shortBuffer[i] >= -32767 && shortBuffer[i] <= 32767)
        {
            shortBuffer[i] = 0;
        }
    }
}

int Noise::noiseGate()
{
    return 89;
}