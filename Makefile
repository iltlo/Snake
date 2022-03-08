FLAGS = -pedantic-errors -std=c++11 -I ~/ncurses_files/include -I ~/ncurses_files/include/ncurses
LIB = -lncurses -L ~/ncurses_files/lib
vpath %.cpp src
vpath %.hpp include
INCLUDE = -I ./include

all: ncurses main

snake.o: snake.cpp snake.hpp visuals.hpp
	g++ ${FLAGS} -c $< ${INCLUDE}

visuals.o: visuals.cpp visuals.hpp snake.hpp
	g++ ${FLAGS} -c $< ${INCLUDE}

new_game.o: new_game.cpp new_game.hpp snake.hpp visuals.hpp
	g++ ${FLAGS} -c $< ${INCLUDE}

start_menu.o: start_menu.cpp start_menu.hpp
	g++ ${FLAGS} -c $< ${INCLUDE}

main.o: main.cpp start_menu.hpp new_game.hpp
	g++ ${FLAGS} -c $< ${INCLUDE}

#########################################

main: main.o start_menu.o new_game.o snake.o visuals.o
	g++ $(FLAGS) $^ ${LIB} -o $@

ncurses: FORCE
	@chmod u+x get_curses.sh
	@./get_curses.sh
FORCE: 

clean:
	rm -f *.o main

.PHONY: clean