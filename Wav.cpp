
/*
    Currently, this only reads in PCM 8-bit mono wavfiles
    This needs further modification to read in stereo files
*/

#include <string>
#include <fstream>
#include <iostream>
#include "Wav.h"



void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        if(waveHeader.bit_depth == 8)
        {
            buffer = new unsigned char[waveHeader.data_bytes];
            file.read((char*)buffer, waveHeader.data_bytes);            
        }else if(waveHeader.bit_depth == 16)
        {
            buffer = new unsigned char[waveHeader.data_bytes];
            file.read((char*)buffer, waveHeader.data_bytes); 
            short* shortBuffer = reinterpret_cast<short*>(buffer);
        }
        file.close();
    }
}


unsigned char *Wav::getBuffer(){
    //Buffer for 8 mono/stereo
    return buffer;
}

short *Wav::getShortBuffer(){
    //Buffer for 16 mono/stereo 
    // THIS COULD BE WRONG AND PROBABLY NEEDS TO BE CHANGED.
    return shortBuffer;
}

void Wav::writeFile(const std::string &outFileName) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));
    outFile.write((char*)buffer, waveHeader.data_bytes);
    outFile.close();
}

Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
}

int Wav::getBufferSize() const {
    //Size of the buffer
    return waveHeader.data_bytes;
}

int Wav::getBufferBytes() const {
    //Tells us sample alignment 
    return waveHeader.sample_alignment;
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