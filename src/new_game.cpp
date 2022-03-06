#include <ncurses.h>
#include <unistd.h>

#include "move.hpp"
#include "visuals.hpp"
#include "new_game.hpp"

void new_game(){

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);                               // get screen size

    // initialize a play window
    printw("Your std win size: %dx%d, please adjust your window to 80x24.", xMax, yMax);
    getch();
    move(0,0);
    clrtoeol();
    // int height=yMax-1, width=((xMax)%2==0 ? xMax-2 : xMax-1), starty=1, startx=1;        // dimension of play window
    int height=23, width=80, starty=1, startx=0;                // standardized window size to 80x24
    WINDOW * gamewin = newwin(height, width, starty, startx);
    Snake * player = new Snake(gamewin, 1, 1);                  // initialized new class member: player

    drawBorder(gamewin);                                        // requires further decoration
    do {                                                        // print snake before getting the choice
        showHead(gamewin, player->get_yPos(), player->get_xPos(), player->get_sHead());
        usleep( (player->get_speed())*1000 );
    } while (player->Move() != 'q');                            // MAIN PROGRAM LOOP

    getch();
    endwin(); 
}