CC = g++

all:Code2HTML

Code2HTML: Code2HTML.o
	$(CC) Code2HTML.o -o Code2HTML
	
Code2HTML.o: Code2HTML.cpp
	$(CC) -c Code2HTML.cpp
	
clean:
	rm *.o Code2HTML
