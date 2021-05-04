// Team 9
// CSV file creation
// 05/01/2021
// CSV.cpp

#include "CSV.h"

using namespace std;

CSV::CSV(string n, Wav wav, Wav wav2, Wav wav3, Wav wav4)
{
    //appends file named with .txt
    n.append(".txt");

    std::ofstream outfile (n);
    //Writes into file using overload<< in Wav.h file
    outfile << "File name                  :yes-8-bit-mono.wav " << endl << wav << endl << endl;
    outfile << "File name                  :yes-8-bit-stereo.wav " << endl << wav2 << endl << endl;
    outfile << "File name                  :yes-16-bit-mono.wav " << endl << wav3 << endl << endl;
    outfile << "File name                  :yes-16-bit-stereo.wav " << endl << wav4 << endl << endl;
    

    outfile.close();
}

CSV::~CSV()
{

}