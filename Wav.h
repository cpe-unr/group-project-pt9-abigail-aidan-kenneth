// Team 9
// Reading wav files(using templates)
// 04/26/2021
// Wav.h

#ifndef WAV_H
#define WAV_H

/*
    Currently, this only reads in PCM 8-bit mono/stereo wavfiles
    This needs further modification to read in 16-bit mono/stereo files
*/

#include "WaveHeader.h"
//#include "MetaData.h"

class Wav {
public:
    template<typename T>
    void readFile(const std::string &fileName){
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
        if(file.is_open()){
                file.read((T)&waveHeader, sizeof(wav_header));
                buffer = new unsigned char[waveHeader.data_bytes];
                file.read((T)buffer, waveHeader.data_bytes);
            if(waveHeader.num_channels == 2 && waveHeader.bit_depth == 8)
            {   //Splits buffer into left and right channels if stereo
                leftBuffer = buffer;
                rightBuffer = buffer;
            }else if(waveHeader.bit_depth == 16)
            {
                short* shortBuffer = reinterpret_cast<short*>(buffer);            
            }
            if(waveHeader.num_channels == 4 && waveHeader.bit_depth == 16)
            {   //Splits 16-bit buffer into left and right channels if stereo
                leftShortBuffer = shortBuffer;
                rightShortBuffer = shortBuffer;
            }    
        file.close();
        }
    }
    template<typename T>
    void writeFile(const std::string &outFileName){
        std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
        outFile.write((T)&waveHeader,sizeof(wav_header));
        outFile.write((T)buffer, waveHeader.data_bytes);
        outFile.close();
    }

private:
    unsigned char* buffer = NULL;
    unsigned char* leftBuffer = NULL;
    unsigned char* rightBuffer = NULL;
    short* shortBuffer = NULL;
    short* leftShortBuffer = NULL;
    short* rightShortBuffer = NULL;
    wav_header waveHeader;
public:
    virtual ~Wav();

public:
    unsigned char *getBuffer();
    short *getShortBuffer();
    int getBufferSize() const;
    int getBufferBytes() const;
    int getSampleRate() const;
    int getBitDepth() const;
    int getChannels() const;
    int getAudioFormat() const;
    int getDataSize() const;

    friend std::ostream& operator <<(std::ostream& out, Wav& wav)
    {
        //Outputs all technical data into CSV file when << is used with wav objects
        out 
        << "Data size                  :" << wav.getDataSize() << std::endl
        << "Sampling Rate              :" << wav.getSampleRate() << std::endl
        << "Number of bits used        :" << wav.getBitDepth() << std::endl
        << "Number of channels         :" << wav.getChannels() << std::endl
        << "Number of bytes per second :" << wav.getBufferBytes() << std::endl
        << "Data length                :" << wav.getBufferSize() << std::endl
        << "Audio Format               :" << wav.getAudioFormat() << std::endl; 
        return out;
    }
};


#endif //WAV_H
