#include <random>

#include "apple.hpp"

// TODO: shall prevent the apple got generated on the snake body
std::array<int, 2> genApple(WINDOW * win){

    init_pair(11, COLOR_RED, COLOR_MAGENTA);
    std::string apple = "()";
    int yApple, xApple, ch;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> unif(1, 819);
    // printw("Min: %d Max: %d", generator.min(), generator.max());

    int applePos = unif(generator);
    do {
        yApple = applePos/40+1;
        xApple = ( (xApple=(applePos%39)*2-1)==-1 ? 77 : xApple ) ;     //xApple: (applePos%39)*2-1),  == -1 indicates: y-index = 77
        ch = mvwinch(win, yApple, xApple);
        // *******
        mvwprintw(stdscr, 0, 0, "yApple: %d xApple: %d ch: %c   ", yApple, xApple, ch);   // for debug
        wrefresh(stdscr);
        // *******
    } while ( ch == apple[0] || ch == '0' || ch == '[' );               // TODO: use class member sHead sBody
    // printw("applePos: %d x-y: %d %d", applePos, xApple, yApple);

    wattron(win, COLOR_PAIR(11));
    // wattron(win, A_BLINK);

    mvwprintw(win, yApple, xApple, apple.c_str());
    wattroff(win, COLOR_PAIR(11));
    // wattroff(win, A_BLINK);
    
    wrefresh(stdscr);
    wrefresh(win);

    return {yApple, xApple};
}