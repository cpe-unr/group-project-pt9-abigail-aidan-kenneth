/** @file */
#include <iostream>
#include "Wav.h"
#include "Processor.h"
#include "Echo.h"
#include "NoiseGate.h"

using namespace std;

const string audiofile1 = "yes-8-bit-mono.wav";
const string audiofile2 = "yes-8-bit-stereo.wav";
const string audiofile3 = "yes-16-bit-mono.wav";
const string audiofile4 = "yes-16-bit-stereo.wav";

int main() {

    int choice;
    int choice2;

    Wav wav;

    do
    {
        cout << endl << "++==Menu==++" << endl;
        cout << "1. Audio Processing" << endl;
        cout << "2. Modify Metadata" << endl;
        cout << "3. List of audio files" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
                do{
                cout << endl << "Choose which audio file you'd like to modify:" << endl;
                cout << "1. yes-8-bit-mono.wav" << endl;
                cout << "2. yes-8-bit-stereo.wav" << endl;
                cout << "3. yes-16-bit-mono.wav" << endl;
                cout << "4. yes-16-bit-stereo.wav" << endl;

                cin >> choice2;
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
                    cout << endl << "**==Process Audio==**" << endl;
                    cout <<"1. Normalization" << endl;
                    cout << "2. Noise Gating" << endl;
                    cout << "3. Echo" << endl;
                    cout << "4. Name Your File" << endl;
                    cout << "0. Back" << endl;
                    cin >> choice2;
                 switch(choice2)
                    {
                        case 1:
                            //*Makes or adds onto an object for normalizing audio*
                            cout << wav.getBitDepth() << endl;
                        break;
                        case 2:
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
                        case 3:
                            {
                                Processor *processor = new Echo(7000);
                                processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
                            }
                        break;
                        case 4:
                            //*Prompts user for filename, the filename can't be the same as the base audio.
                            {
                                string end = ".wav";
                                cout << endl << "Name your new audio file: ";
                                string s;
                                cin >> s;
                                s.append(end);
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
                //*Lists audio files, displays metadata, whether it's mono or stereo, 8 or 16 bit and any other interesting things in the audio.
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