#include <random>

#include "apple.hpp"

// TODO: shall prevent the apple got generated on the snake body
void genApple(WINDOW * win){
    std::string apple = "()";

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> unif(1, 819);
    // printw("Min: %d Max: %d", generator.min(), generator.max());
    int applePos = unif(generator);
    int yApple = applePos/40+1;
    int xApple = ( (xApple=(applePos%39)*2-1)==-1 ? 77 : xApple ) ;     //xApple: (applePos%39)*2-1),  == -1 indicates: y-index = 77
    // printw("applePos: %d x-y: %d %d", applePos, xApple, yApple);

    mvwprintw(win, yApple, xApple, apple.c_str());
    wrefresh(win);
}