#ifndef WAV_H
#define WAV_H

/*
    Currently, this only reads in PCM 8-bit mono wavfiles
    This needs further modification to read in stereo files
*/

#include "WaveHeader.h"
#include "MetaData.h"
class Wav {
public:
    void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
private:
    unsigned char* buffer = NULL;
    short* shortBuffer = NULL;
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

    friend std::ostream& operator <<(std::ostream& out, Wav& wav)
    {
        //Outputs all technical data into CSV file when << is used with wav objects
        out 
        << "Data size                  :" << wav.getBufferSize() << std::endl
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
