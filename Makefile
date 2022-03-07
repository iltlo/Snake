FLAGS = -pedantic-errors -std=c++11
LIB = -lcurses
vpath %.cpp src
vpath %.hpp include
INCLUDE = -I ./include

all: main

# snake.cpp:
# 	g++ ${FLAGS} -c $< ${INCLUDE}

# apple.cpp:
# 	g++ ${FLAGS} -c $< ${INCLUDE}

# visuals.cpp:
# 	g++ ${FLAGS} -c $< ${INCLUDE}

# new_game.cpp:
# 	g++ ${FLAGS} -c $< ${INCLUDE}

# start_menu.cpp:
# 	g++ ${FLAGS} -c $< ${INCLUDE}

# main.cpp:
# 	g++ ${FLAGS} -c $< ${INCLUDE}

#######################################

snake.o: snake.cpp snake.hpp visuals.hpp
	g++ ${FLAGS} -c $< ${INCLUDE}

visuals.o: visuals.cpp visuals.hpp
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

clean:
	rm *.o -f main

.PHONY: clean