FLAGS = -lncurses ${FLAGS}
INCLUDE = -I /INCLUDE

all: move.o visuals.o new_game.o snake

move.cpp:
	g++ ${FLAGS} -c $< ${INCLUDE}

apple.cpp:
	g++ ${FLAGS} -c $< ${INCLUDE}

visuals.cpp:
	g++ ${FLAGS} -c $< ${INCLUDE}

new_game.cpp:
	g++ ${FLAGS} -c $< ${INCLUDE}

move.o: move.cpp move.hpp
	g++ ${FLAGS} -c $< ${INCLUDE}

apple.o: apple.cpp apple.hpp
	g++ ${FLAGS} -c $< ${INCLUDE}

visuals.o: visuals.cpp visuals.hpp
	g++ ${FLAGS} -c $< ${INCLUDE}

new_game.o: new_game.cpp new_game.hpp
	g++ ${FLAGS} -c $< ${INCLUDE}

snake: move.o apple.o visuals.o new_game.o 
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f snake *.o

.PHONY: clean