// Team 9
// Reading wav files(using templates)
// 04/26/2021
// Wav.cpp

/*
    Currently, this only reads in PCM 8-bit mono wavfiles
    This needs further modification to read in stereo files
*/

#include <string>
#include <fstream>
#include <iostream>
#include "Wav.h"

unsigned char *Wav::getBuffer(){
    //Buffer for 8 mono/stereo
    return buffer;
}

short *Wav::getShortBuffer(){
    //Buffer for 16 mono/stereo 
    // THIS COULD BE WRONG AND PROBABLY NEEDS TO BE CHANGED.
    return shortBuffer;
}

Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
    if(shortBuffer != NULL)
        delete[] shortBuffer;
}

int Wav::getBufferSize() const {
    //Size of the buffer
    return waveHeader.data_bytes;
}

int Wav::getBufferBytes() const {
    //Tells us sample alignment 
    return waveHeader.byte_rate;
}

int Wav::getSampleRate() const
{
    //Tells us audio's sample rate
    return waveHeader.sample_rate;
}

int Wav::getBitDepth() const
{
    //Tells us if the audio is 8 or 16 bit
    return waveHeader.bit_depth;
}

int Wav::getChannels() const
{
    //Tells us number of channels Mono(one) or Stereo(Two)
    return waveHeader.num_channels;
}

int Wav::getAudioFormat() const
{
    //Tells us about the audio format PCM or IEEE
    return waveHeader.audio_format;
}

int Wav::getDataSize() const
{
    return waveHeader.wav_size;
}