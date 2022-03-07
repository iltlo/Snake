#include "new_game.hpp"

/*
new game function

what it does: 
will be called when player opt for new game
`new` keyword is used to allocate memory for Snake class object
call for the main game loop

inputs: none

outputs: game window
*/

void new_game(){

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);                               // get screen size

    // initialize a play window
    move(0,0);
    clrtoeol();
    // int height=yMax-1, width=((xMax)%2==0 ? xMax-2 : xMax-1), starty=1, startx=1;        // dimension of play window
    int height=23, width=80, starty=1, startx=0;                // standardized window size to 80x24
    WINDOW * gamewin = newwin(height, width, starty, startx);
    
    Snake * player = new Snake(gamewin);                  // initialized new class member: player

    // *******
    // wprintw(stdscr, "%d %d",(chtype)(unsigned char)((player->get_sHead())[0]),(chtype)(unsigned char)(player->get_sBody()[0]) );     //for debug
    // wgetch(stdscr);
    // *******

    drawBorder(gamewin);                                        // requires further decoration
    do {                                                        // print snake before getting the choice
        showHead(gamewin, player->get_yPos(), player->get_xPos(), player->get_sHead());
        apple(* player, gamewin);
        usleep( (player->get_speed())*1000 );                   // unistd.h
    } while (player->Move() != 'q');                            // MAIN PROGRAM LOOP

    delete player;                                              // free the memory of the address in player pointer
    player = 0;                                                 // stray pointer -> null pointer

    getch();
    endwin(); 
}