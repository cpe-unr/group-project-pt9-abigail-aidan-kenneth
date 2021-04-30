#ifndef WAV_H
#define WAV_H

/*
    Currently, this only reads in PCM 8-bit mono wavfiles
    This needs further modification to read in stereo files
*/

#include "WaveHeader.h"

class Wav {
public:
    void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
private:
    unsigned char* buffer = NULL;
    short* shortBuffer = NULL;
    wav_header waveHeader;
public:
    virtual ~Wav();

public:
    unsigned char *getBuffer();
    short *getShortBuffer();
    int getBufferSize() const;
    int getBufferBytes() const;
    int getBitDepth() const;
};


#endif //WAV_H
