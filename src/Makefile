FLAGS = -lncurses -std=c++11

all: move.o visuals.o snake.o snake

move.o: move.cpp move.h
	g++ -std=c++11 -c move.cpp

apple.o: apple.cpp apple.h
	g++ -std=c++11 -c apple.cpp

visuals.o: visuals.cpp visuals.h
	g++ -std=c++11 -c visuals.cpp

snake.o: snake.cpp
	g++ -std=c++11 -c snake.cpp

snake: move.o apple.o visuals.o snake.o 
	g++ $(FLAGS) $^ -o snake

clean:
	rm -f snake *.o

.PHONY: clean