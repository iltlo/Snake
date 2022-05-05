#include "start_menu.hpp"

const std::string menu_pic = 
R"(                  &&&&&&&&&&&&&&&&&&&&&&&&                            )"
R"(            &&&&&(((((((((((((((((((((((&&&&&                         )"
R"(            &&&&&(((((((((((((((((((((((&&&&&                         )"
R"(            &&&&&((((((((((((((((((((((((((((&&&&&                    )"
R"(            &&&&&((((((((((((((((((((((((((((&&&&&                    )"
R"(        &&&&((((((&&&&&(((((((((((((&&&&&((((&&&&&                    )"
R"(        &&&&((((((&&&&&(((((((((((((&&&&&((((&&&&&                    )"
R"(        &&&&((((((&&&&&(((((((((((((&&&&&((((####%&&&&                )"
R"(        &&&&((((((&&&&&(((((((((((((&&&&&((((####%&&&&                )"
R"(        &&&&(****(((((((((((&((((((((((((****####%&&&&                )"
R"(        &&&&(****((((((((((((((((((((((((****&&&&%&&&&                )"
R"(            &&&&&###########################&                         )"
/*R"(                &&&&&&&&&&&&&&&&&&&&&&&&&&&&&                         )",*/
R"(                &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                      )"
R"(        &&&&&&&&&((((((((((&&&&((((((((((####&&&&  &&&                )"
R"(        &&&&&&&&&((((((((((&&&&((((((((((####&&&&&&##&                )"
R"(  &&&&&&((((((((((((((&&&&&((((((((((((((####&&&&&####&&&&&           )"
R"(  &&&&&&((((((((((((((&&&&&((((((((((((((####&&&&&####&&&&&           )"
R"(&&&&&((((((((((&&&&########################&&&&(((((####&&###&&&&&    )"
R"(&&&&&#####(((((((((&&&&&&&&&&&&&&&&&&&&&&&&(((((((((####&&&######%&&& )"
R"(&&&&&#####(((((((((&&&&&&&&&&&&&&&&&&&&&&&&(((((((((####&&&&####%&&&& )"
R"(&&&&&#####((((((((((((((((((((((((((((((((((((((((((####&&&&####%&&&& )"
R"(    &&&&&&####&####################################%&&&&&&&&####%&&&& )"
R"(    &&&&&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&&&&&&&&##&&&&&& )"
R"(          &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&        &&&&&&    )"
;

// '(' , '#' = green, '%' = dark green , '&' = black , '*' = red , others = blue (background_color)
// concatenating the raw string literals into one big array, 
// thus speeding up the loading time in game
// (due to reading adjacent memory address and putting them into the same cache line)
// also putting it as an initialized global constants to avoid repeated
// deletion and creation of string literals on stack whenever reloading start menu


/* 
start_menu function 

what it does:
switch the main game loop to the start menu page, 
create a terminal GUI for player to choose further action(s)

inputs: two WINDOW pointers for menu picture and option window respectively

outputs: player's choice on the option window in type char
*/

char start_menu(WINDOW*& menu_pic_win, WINDOW*& option_win)
{
    curs_set(0);

    char choice = 0;
    bool n_chosen = true;
    keypad(option_win, true);

    render_menu_pic(menu_pic_win);
    render_option(choice, option_win);

    while(n_chosen)
    {
        switch(wgetch(option_win)) // waiting for player's input at here
        {
            case(KEY_UP):
            case('w'):
                if (choice > 0)
                    choice--;
                break;

            case(KEY_DOWN):
            case('s'):
                if (choice < 3)
                    choice++;
                break;
            
            case(KEY_KEYBOARD_ENTER): // hitting enter will confirm the choice chosen in the option window
                n_chosen = false;
                break;

            case(KEY_R):
                render_menu_pic(menu_pic_win);
                render_option(choice, option_win);
                break;

            default:
                break;
        }
        render_option(choice, option_win);
    }

    return choice; // to the main loop
}



/* 
render_menu_pic function

what it does:
draw the predefined ascii text picture on the window provided for the menu picture

inputs: a WINDOW pointer for menu picture

outputs: none
*/

void render_menu_pic(WINDOW*& menu_pic_win){

    // as customized color are not available in most terminal, default color will be used
    // init_color(COLOR_LIGHT_GREEN, 0, 901, 0);
    // init_color(COLOR_DARK_GREEN, 0, 783, 0);
    // init_color(COLOR_PINK, 999, 713, 756);
    // init_pair(0, COLOR_DARK_GREEN, bg_color );
    // init_pair(1,  COLOR_LIGHT_GREEN , bg_color );
    // init_pair(2, COLOR_LIGHT_GREEN , bg_color );
    // init_pair(3, COLOR_PINK ,  bg_color );
    // init_pair(4,  COLOR_BLACK , bg_color );
    // init_pair(5, bg_color , bg_color );

    wclear(menu_pic_win);
    init_pair(1, COLOR_GREEN, bg_color );
    init_pair(2,  COLOR_GREEN , bg_color );
    init_pair(3, COLOR_GREEN , bg_color );
    init_pair(4, COLOR_RED ,  bg_color );
    init_pair(5,  COLOR_BLACK , bg_color );
    init_pair(6, bg_color , bg_color );
    chtype dark_green = '%' | A_NORMAL | COLOR_PAIR(1);
    chtype light_green_1 = '(' | A_NORMAL | COLOR_PAIR(2);
    chtype light_green_2 = '#' | A_NORMAL| COLOR_PAIR(3);
    chtype pink = '*' | A_NORMAL | COLOR_PAIR(4);
    chtype black = '&' | A_NORMAL | COLOR_PAIR(5);
    chtype background = ' ' | A_NORMAL | COLOR_PAIR(6);


    // start drawing every pixel in the menu_pic into the menu_pic_window
    for (short i = 0; i < menu_pic_y; i++){
        for (short j = 0; j < menu_pic_x; j++){

            wmove(menu_pic_win, i, j);

            switch(menu_pic[i * menu_pic_x + j]){
                case('%'):
                waddch(menu_pic_win, dark_green);
                break;
                
                case('('):
                waddch(menu_pic_win, light_green_1);
                break;

                case('#'):
                waddch(menu_pic_win, light_green_2);
                break;

                case('*'):
                waddch(menu_pic_win, pink);
                break;

                case('&'):
                waddch(menu_pic_win, black);
                break;

                default:
                waddch(menu_pic_win, background);
                break;
            }

            // for debugging (commented)
            // mvwprintw(menu_pic_win,20,45,"%d", init_color(COLOR_PINK, 999, 713, 756));
            // mvwprintw(menu_pic_win,20,50,"%d", can_change_color());

        }
    }

    // adding characters with unique features separately at the end
    wattron(menu_pic_win, A_BOLD | A_BLINK);
    mvwaddstr(menu_pic_win, 2, 55, "S N A K E");
    mvwaddstr(menu_pic_win, 3, 58, "G A M E");
    wattroff(menu_pic_win, A_BOLD | A_BLINK);

    wrefresh(menu_pic_win);
}

/* 
render_option function

what it does:
initialize the option window + 
update the player's current choice on the option window

inputs: a WINDOW pointer for option window

outputs: none
*/

void render_option(const char& choice, WINDOW*& option_win){

    // initialization
    werase(option_win);
    box(option_win, 0, 0);
    const char* options[option_number] = {"NEW GAME", "LOAD", "SCORES","EXIT"};

    // adding strings at the designated position,
    // highlighting the option when currently chosen
    for (char i = 0; i < option_number; i++){

        if (choice == i){
            wattron(option_win, A_STANDOUT);
            mvwaddstr(option_win, (i+1) * 5, 1, options[i]);
            wattroff(option_win, A_STANDOUT);
        }
        else{
            mvwaddstr(option_win, (i+1) * 5, 1, options[i]);
        }
    }
    wrefresh(option_win);
}

/* 
closing_start_menu function

what it does:
delete and close the start menu

inputs: two WINDOW pointer for menu picture and option window

outputs: none
*/
void closing_start_menu(WINDOW*& menu_pic_win, WINDOW*& option_win){
    // closing start menu 
    werase(menu_pic_win);
    werase(option_win);
    wrefresh(menu_pic_win);
    wrefresh(option_win);
    delwin(menu_pic_win);
    delwin(option_win);
}