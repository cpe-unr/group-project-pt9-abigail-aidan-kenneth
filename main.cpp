/** @file */
#include <iostream>
#include "Wav.h"
#include "Processor.h"
#include "Echo.h"
#include "NoiseGate.h"
#include "Normalization.h"
#include "CSV.h"

using namespace std;
//Gives us the audio files to mess with
const string audiofile1 = "yes-8-bit-mono.wav";
const string audiofile2 = "yes-8-bit-stereo.wav";
const string audiofile3 = "yes-16-bit-mono.wav";
const string audiofile4 = "yes-16-bit-stereo.wav";

int main() {
    //For user interaction
    int choice;
    int choice2;
    //Instance of wav object for processing/reading
    Wav wav;

    do
    {   
        cout << endl << "++==Menu==++" << endl; //Gives user the option to choose what they want to do
        cout << "1. Audio Processing" << endl;
        cout << "2. Modify Metadata" << endl;
        cout << "3. Create CSV file" << endl;
        cout << "0. Exit" << endl;
        cin >> choice; //Gets that primary choice
        switch(choice)
        {
            case 1:
                do{
                cout << endl << "Choose which audio file you'd like to modify:" << endl;
                cout << "1. yes-8-bit-mono.wav" << endl;
                cout << "2. yes-8-bit-stereo.wav" << endl;
                cout << "3. yes-16-bit-mono.wav" << endl;
                cout << "4. yes-16-bit-stereo.wav" << endl;

                cin >> choice2; //Gets secondary choice for choosing which audio to modify and reads them in.
                    switch(choice2)
                    {
                    case 1:
                    {
                        wav.readFile(audiofile1);                        
                    }
                    break;
                    case 2:
                    {
                        wav.readFile(audiofile2);
                    }
                    break;
                    case 3:
                    {
                        wav.readFile(audiofile3);
                    }
                    break;
                    case 4:
                    {
                        wav.readFile(audiofile4);
                    }
                    break;
                    }
                }while(choice2 != 1,2,3,4,0);
                do{
                    cout << endl << "**==Process Audio==**" << endl; //Presents option for user to choose what audio process to carry out
                    cout <<"1. Normalization" << endl;
                    cout << "2. Noise Gating" << endl;
                    cout << "3. Echo" << endl;
                    cout << "4. Name Your File" << endl;
                    cout << "0. Back" << endl;
                    cin >> choice2; //Gets secondary choice for processing audio chosen above^^^
                 switch(choice2)
                    {
                        case 1: //Checks if it's 8 or 16 then does Normalization to chosen audio.
                            {
                                if(wav.getBitDepth() == 8)
                                {
                                    Processor *processor = new Normalize;
                                    processor->processBuffer(wav.getBuffer(),wav.getBufferSize());                                    
                                }else
                                {
                                    Processor *processor = new Normalize;
                                    processor->shortProcessBuffer(wav.getShortBuffer(),wav.getBufferSize());
                                }

                            }
                        break;
                        case 2: //Checks if it's 8 or 16 then does Noise gating to chosen audio.
                            {
                                if(wav.getBitDepth() == 8)
                                {
                                    Processor *processor = new Noise;
                                    processor->processBuffer(wav.getBuffer(),wav.getBufferSize());                                    
                                }else
                                {
                                    Processor *processor = new Noise;
                                    processor->shortProcessBuffer(wav.getShortBuffer(),wav.getBufferSize());
                                }

                            }
                        break;
                        case 3: //Checks if it's 8 or 16 then makes chosen audio Echo.
                            {
                                if(wav.getBitDepth() == 8)
                                {
                                    Processor *processor = new Echo(7000);
                                    processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
                                }else
                                {
                                    Processor *processor = new Echo(7000);
                                    processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
                                }
                            }
                        break;
                        case 4:
                            //*Prompts user for filename, the filename can't be the same as the base audio.
                            {

                                cout << endl << "Name your new audio file: ";
                                string s;
                                cin >> s;
                                s.append(".wav");
                                if(s == audiofile1)
                                {
                                    cout << "Please enter a unique file name." << endl;
                                    break;
                                }else{
                                    wav.writeFile(s);                                    
                                }

                            }
                        break;
                        case 0:
                            //*Returns you to the Menu.
                        break;           
                    }
                }while(choice2 != 0);
            break;
            case 2:
                //*Will modify metadata, if it exists it will over write it.
            break;
            case 3:
                //*CSV, displays technical/metadata, whether it's mono or stereo, 8 or 16 bit and any other interesting things in the audio.
                {
                    //Creates instances for the file to take in all available audio files.
                    Wav wav2;
                    Wav wav3;
                    Wav wav4;
                    //String for the name of the file
                    string n;
                    //Reads in audio files to pass into CSV constructor to write to the file we're creating
                    wav.readFile(audiofile1);
                    wav2.readFile(audiofile2);
                    wav3.readFile(audiofile3);
                    wav4.readFile(audiofile4);

                    cout << endl << "Name of CSV file: " << endl;
                    cin >> n; //File name
                    CSV csv(n,wav,wav2,wav3,wav4); //Creates object and puts all the wave files in to be read with overloader
                    cout << "CSV file '" << n << "' has been created." << endl; //Gives confirmation that the file was created

                    //*****Segmentation fault here??
                }

            break;
            case 0:
                //*Ends Program
            break;
        }

    } while (choice != 0);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}


/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}
