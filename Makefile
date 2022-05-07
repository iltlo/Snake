FLAGS = -pedantic-errors -std=c++11 -I ~/ncurses_files/include -I ~/ncurses_files/include/ncurses
LIB = -lncurses -L ~/ncurses_files/lib
vpath %.cpp src
vpath %.hpp include
INCLUDE = -I ./include

all: ncurses main
	@echo "Run the game with \`./main\`"

snake.o: snake.cpp snake.hpp visuals.hpp
	@g++ ${FLAGS} -c $< ${INCLUDE}

visuals.o: visuals.cpp visuals.hpp snake.hpp
	@g++ ${FLAGS} -c $< ${INCLUDE}

save_and_load.o: save_and_load.cpp save_and_load.hpp
	@g++ ${FLAGS} -c $< ${INCLUDE}

new_game.o: new_game.cpp new_game.hpp snake.hpp visuals.hpp save_and_load.hpp
	@g++ ${FLAGS} -c $< ${INCLUDE}

start_menu.o: start_menu.cpp start_menu.hpp
	@g++ ${FLAGS} -c $< ${INCLUDE}

main.o: main.cpp start_menu.hpp new_game.hpp
	@g++ ${FLAGS} -c $< ${INCLUDE}

pause_menu.o: pause_menu.cpp pause_menu.hpp
	@g++ ${FLAGS} -c $< ${INCLUDE}

#########################################

main: main.o start_menu.o new_game.o snake.o save_and_load.o visuals.o pause_menu.o
	@g++ $(FLAGS) $^ ${LIB} -o $@
	@echo "Compilation finished!"

ncurses: FORCE
	@chmod u+x get_ncurses.sh
	@./get_ncurses.sh
FORCE: 

clean:
	@rm -f *.o main
	@echo "Object files and executable cleaned!"
clear-score:
	@chmod u+x ./log/clear-score.sh
	@./log/clear-score.sh

.PHONY: clean clear-score