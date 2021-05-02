//Team 9: Kenneth Peterson
//Normalizing Audio
//04/30/2021
//Normalization.cpp

#include "Normalization.h"


void Normalize::processBuffer(unsigned char* buffer, int bufferSize)
{
    int x = 0;

    for(int i = 0; i < bufferSize; i++)
    {
        if(buffer[i] >= 124 && buffer[i] <= 144)
        {
            x = 144/buffer[i];

            buffer[i] = buffer[i]*x;
        }
    }
}
void Normalize::shortProcessBuffer(short* shortBuffer, int bufferSize)
{
    int x = 0;

    for(int i = 0; i < bufferSize; i++)
    {
        if(shortBuffer[i] >= -32767 && shortBuffer[i] <= 32767)
        {
            x = 32767/shortBuffer[i];

            shortBuffer[i] = shortBuffer[i]*x;
        }
    }
}

Normalize::Normalize()
{

}

Normalize::~Normalize()
{
    
}
