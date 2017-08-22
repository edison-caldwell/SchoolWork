#MAKEFILE FOR ASSIGNMENT 3

CC=c++

all: ass3

ass3: stopwatch.o client.o
	$(CC) stopwatch.o client.o -o ass3 

stopwatch.o: stopwatch.cpp
	$(CC) -c stopwatch.cpp

client.o: client.cpp
	$(CC) -c client.cpp

clean:
	rm *.o ass3
