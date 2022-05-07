#include "pause_menu.hpp"

/*
opposite key function

what it does:
creates a window for pause menu,
pause the game by trapping the main game loop in a while loop (until further action)

input:none

output: none
*/
void pause_menu(bool &exitFlag) {
    WINDOW* pause_menu_win = newwin(pause_menu_y, pause_menu_x, pause_menu_pos_y, pause_menu_pos_x);
    curs_set(0);

    char choice = 0;
    bool n_chosen = true;
    keypad(pause_menu_win, true);

    render_pause_menu(choice, pause_menu_win);

    while(n_chosen) // waiting for player's input at here
    {
        switch(wgetch(pause_menu_win))
        {
            case(KEY_UP):
            case('w'):
                if (choice > 0)
                    choice--;
                break;

            case(KEY_DOWN):
            case('s'):
                if (choice < pause_menu_option_number - 1)
                    choice++;
                break;
            
            case(KEY_KEYBOARD_ENTER): // hitting enter will confirm the choice chosen in the pause menu
                n_chosen = false;
                break;

            default:
                break;
        }
        render_pause_menu(choice, pause_menu_win);
    }

    if (choice == 1){
        exitFlag = true;
    }
    
    // end pause menu
    werase(pause_menu_win);
    wrefresh(pause_menu_win);
    delwin(pause_menu_win);
}


/* 
render_pause_menu function

what it does:
initialize the pause menu window + 
update the player's current choice on the pause menu

inputs: a WINDOW pointer for pause menu

outputs: none
*/
void render_pause_menu(char choice, WINDOW*& pause_menu_win){

    // draw the boarder
    werase(pause_menu_win);
    box(pause_menu_win, 0, 0);

    const char* options[pause_menu_option_number] = {"CONTINUE\0", "SAVE GAME AND EXIT\0"};

    for (char i = 0; i < pause_menu_option_number; i++){

        if (choice == i){
            wattron(pause_menu_win, A_STANDOUT);
            mvwaddstr(pause_menu_win, (i+1) * 3, 1, options[i]);
            wattroff(pause_menu_win, A_STANDOUT);
        }
        else{
            mvwaddstr(pause_menu_win, (i+1) * 3, 1, options[i]);
        }
    }

    // print this specific string separate from the main reandering loop
    wattron(pause_menu_win, A_BLINK);
    mvwaddstr(pause_menu_win, 1, (pause_menu_x-13)/2, "*GAME PAUSED*");
    wattroff(pause_menu_win, A_BLINK);

    wrefresh(pause_menu_win);
}