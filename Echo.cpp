//Team 9
//Making wav files Echo
//04/25/2021
//Echo.cpp

#include "Echo.h"
 
using namespace std;

void Echo::processBuffer(unsigned char* buffer, int bufferSize)
{ 
    for(int i = 0; i < bufferSize; i++)
    {
        buffer[i] = buffer[i]*0.5 + buffer[i-getDelay()]*0.5;
    }
}

void Echo::shortProcessBuffer(short* shortBuffer, int bufferSize)
{
    for(int i = 0; i < bufferSize/2; i++)
    {
        shortBuffer[i] = shortBuffer[i]*0.5 + shortBuffer[i-getDelay()]*0.5;
    }
}

Echo::Echo()
{
    delay = 0;
}
Echo::Echo(int newDelay)
{
    delay = newDelay;
}

Echo::~Echo()
{
}

int Echo::getDelay()
{
    return delay;
}