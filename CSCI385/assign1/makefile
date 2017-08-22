#MAKEFILE FOR ASSIGNMENT 1
CC=g++

all: ass1

ass1: List.o Milkyway.o client.o
	$(CC) List.o Milkyway.o client.o -o ass1

List.o: List.cpp
	$(CC) -c List.cpp

Milkyway.o: Milkyway.cpp
	$(CC) -c Milkyway.cpp

client.o: client.cpp
	$(CC) -c client.cpp

clean:
	rm *o ass1