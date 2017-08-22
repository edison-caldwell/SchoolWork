CC=g++
CFLAGS=`mysql_config --cflags -libs`

all: createGames popGames seeComment

createGames: createGames.cpp
	$(CC) createGames.cpp -o createGames

popGames: popGames.cpp
	$(CC) popGames.cpp -o popGames

seeComment: seeComment.cpp
	$(CC) seeComment.cpp -o seeComment

clean:
	rm createGames popGames seeComment
