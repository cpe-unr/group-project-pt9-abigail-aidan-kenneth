audio: main.o wav.o processor.o echo.o noisegate.o normalization.o csv.o
	g++ -std=c++11 main.o wav.o processor.o echo.o noisegate.o normalization.o csv.o -o audio

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

wav.o: Wav.cpp Wav.h
	g++ -std=c++11 -c Wav.cpp 

processor.o: Processor.cpp Processor.h
	g++ -c -std=c++11 Processor.cpp

echo.o: Echo.cpp Echo.h
	g++ -c -std=c++11 Echo.cpp

noisegate.o: NoiseGate.cpp NoiseGate.h
	g++ -c -std=c++11 NoiseGate.cpp

normalization.o: Normalization.cpp Normalization.h
	g++ -c -std=c++11 Normalization.cpp

csv.o: CSV.cpp CSV.h
	g++ -c -std=c++11 CSV.cpp

MetaData.o: MetaData.cpp MetaData.h
	g++ -c -std=c++11 MetaData.cpp

clean:
	rm *.o audio
