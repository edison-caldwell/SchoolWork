CC="g++"

all: stopwatch.o cracker searcher

stopwatch.o: stopwatch.cpp
	$(CC) -c stopwatch.cpp

cracker: cracker.cpp
	$(CC) stopwatch.o cracker.cpp -o cracker -lcrypt

searcher: searcher.cpp 
	$(CC) searcher.cpp -o searcher

clean: 
	rm cracker searcher stopwatch.o


