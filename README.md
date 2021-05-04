# group-project-pt9-abigail-aidan-kenneth
group-project-pt9-abigail-aidan-kenneth created by GitHub Classroom

Project Goals:
Our goals are to read the audio files provided and give the user variety by letting them choose which audio files to modify or display details of those audio files

Main:
  This is where the menu is made and the user has options to:
  -Process Audio (Makes edits to audio files provided)
  -Modify Meta Data (Modifies or overwrites existing or non-existing meta data)
  -Create a CSV file (Creates a .txt file with both technical and meta data of each audio file provided)
  -Exit (Leave program)

WaveHeader:
  This holds all the technical information of the wave audio file, this file is meant to store variables from the read in audio file.

MetaData:
  This holds all of the meta information in the wave audio file, this also stores variables from the read in audio file.

Wav:
  This reads in the audio file selected using templates, checks if it's 8 or 16 bit mono or stereo and has the ability to make audio files as well.
  -Composed of waveHeader/metaData information.
  -Holds an overload for the << operator so that all of information can be written down in a .txt file for CSV file creation.

CSV:
  Inherits from the Wav class to access overloaded << operator.
  -Gives option to name CSV file and then write a file based on the audio that was read in.

IProcessor:
 Processing audio interface.
 -Creates abstract functions for inherited classes to use. 

Echo:
 Inherits from IProcessor.
 -Modifies audio so that it may simulate an echo.

NoiseGate:
 Inherits from IProcessor.
 -Noise gates audio that has been read in.

Normalization:
 Inherits from IProcessor.
 -Normalizes the audio that has been read in.

