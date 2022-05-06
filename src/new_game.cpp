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

void start_game( bool load ){

    init_pair(11, COLOR_RED, COLOR_MAGENTA);                    // genApple
    init_pair(12, COLOR_RED, COLOR_CYAN);                       // showHead
    init_pair(14, COLOR_CYAN, COLOR_GREEN);                     // moveChoice (snake body)
    init_pair(15, COLOR_BLACK, COLOR_YELLOW);                   // drawBorder

    int height=23, width=80, starty=1, startx=0;                // standardized window size to 80x24
    WINDOW * gamewin = newwin(height, width, starty, startx);
    
    SaveAndLoad * sl = new SaveAndLoad("./log/state.txt", "./log/leaderboard.txt");  // initialized new class member: saveload
    std::ifstream stateFile( (sl->get_state_file()).c_str() );

    Snake * player;
    if ( load && !sl->is_empty(stateFile) ) {                   // if in load mode and state file is not empty
        player = new Snake(gamewin, *sl);                       // initialized new class member with state.txt: player
        showBody(gamewin, player->get_snake(), player->get_sBody());
    } else {
        player = new Snake(gamewin);
    }

    drawBorder(gamewin);

    do {                                                        // print snake before getting the choice
        apple(* player, gamewin);
        mvwprintw(stdscr, 0, 0, "Your Score: \t %d", player->get_score());
        usleep( (player->get_speed())*1000 );                   // unistd.h
    } while ( player->Move() == true );                         // MAIN PROGRAM LOOP

    
    if ( player->exitFlag ) {                                   // exit key is pressed, save the game to state.txt
        sl->saveState(player->get_mvCount(), player->get_previous(), player->get_yApple(), player->get_xApple(), player->get_appleState(), player->get_snakeLen(), player->get_snake());
    } else {                                                    // game is over, store game and required key confirm to exit
        sl->saveScore(player->get_score());                     // save score to file
        mvwprintw(stdscr, 0, 0, "Press ENTER to quit ...");
        sl->delState();
        while ( getch() != KEY_KEYBOARD_ENTER );
    }

    delete player;                                              // free the memory of the address in pointer
    delete sl;

    player = 0, sl = 0;                                         // stray pointer -> null pointer

    endwin(); 
}