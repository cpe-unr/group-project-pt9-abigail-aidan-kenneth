// Team 9
// CSV file creation
// 05/01/2021
// CSV.h


#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <string>
#include <fstream>
#include "Wav.h"

class CSV: public Wav
{
    public:
    CSV(std::string n, Wav wav, Wav wav2, Wav wav3, Wav wav4);
    ~CSV();
};

#endif
