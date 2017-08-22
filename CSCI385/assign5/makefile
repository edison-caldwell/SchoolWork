CC = g++

all: ass5

ass5: Graph.o List.o Stack.o Queue.o Client.o
	$(CC) Graph.o List.o Stack.o Queue.o Client.o -o ass5

Graph.o: Graph.cpp
	$(CC) -c Graph.cpp

List.o: List.cpp
	$(CC) -c List.cpp

Stack.o: Stack.cpp
	$(CC) -c Stack.cpp
	
Queue.o: Queue.cpp
	$(CC) -c Queue.cpp

Client.o: Client.cpp
	$(CC) -c Client.cpp

clean: 
	rm *.o ass5
