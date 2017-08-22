CC = g++ 

all: ass4

ass4: List.o stopwatch.o client.o
	$(CC) List.o stopwatch.o client.o -o ass4

List.o: List.cpp
	$(CC) -O -c List.cpp

stopwatch.o: stopwatch.cpp
	$(CC) -O -c stopwatch.cpp

client.o: client.cpp
	$(CC) -O -c client.cpp

clean:
	rm *.o ass4
