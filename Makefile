audio: main.o wav.o
	g++ -std=c++11 main.o wav.o -o audio

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

wav.o: Wav.cpp Wav.h
	g++ -std=c++11 -c Wav.cpp 

clean:
	rm *.o audio
