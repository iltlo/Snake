#include <ncurses.h>
#include <string>

#include "start_menu.hpp"

char start_menu()
{
    curs_set(0);

    char choice = 0;
    bool n_chosen = true;
    WINDOW* menu_pic_win = newwin(menu_pic_y, menu_pic_x, 0, 0);
    WINDOW* option_win = newwin(option_win_y, option_win_x, 0, menu_pic_x);
    keypad(option_win,true);

    render_menu_pic(menu_pic_win);
    render_option(choice,option_win);

    while(n_chosen)
    {
        switch(wgetch(option_win))
        {
            case(KEY_UP):
                if (choice > 0)
                    choice--;
                break;

            case(KEY_DOWN):
                if (choice < 2)
                    choice++;
                break;
            
            case(KEYBOARD_KEY_ENTER):
                n_chosen = false;
                break;

            default:
                break;
        }
        render_option(choice, option_win);
    }

    werase(menu_pic_win);
    werase(option_win);
    delwin(menu_pic_win);
    delwin(option_win);
    return choice; // to the main loop
}

void render_menu_pic(WINDOW*& menu_pic_win){

    box(menu_pic_win, 0, 0);
    // ( , # = green, % = dark green , & = black , * = red , others = grey (space can be arbitary color)

    std::string menu_pic[24] = {
    R"(                  &&&&&&&&&&&&&&&&&&&&&&&&                            )",
    R"(            &&&&&(((((((((((((((((((((((&&&&&                         )",
    R"(            &&&&&(((((((((((((((((((((((&&&&&                         )",
    R"(            &&&&&((((((((((((((((((((((((((((&&&&&                    )",
    R"(            &&&&&((((((((((((((((((((((((((((&&&&&                    )",
    R"(        &&&&((((((&&&&&(((((((((((((&&&&&((((&&&&&                    )",
    R"(        &&&&((((((&&&&&(((((((((((((&&&&&((((&&&&&                    )",
    R"(        &&&&((((((&&&&&(((((((((((((&&&&&((((####%&&&&                )",
    R"(        &&&&((((((&&&&&(((((((((((((&&&&&((((####%&&&&                )",
    R"(        &&&&(****((((((((((&&((((((((((((****####%&&&&                )",
    R"(        &&&&(****((((((((((((((((((((((((****&&&&%&&&&                )",
    R"(            &&&&&###########################&                         )",
    /*R"(                &&&&&&&&&&&&&&&&&&&&&&&&&&&&&                         )",*/
    R"(                &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                      )",
    R"(        &&&&&&&&&((((((((((&&&&((((((((((####&&&&  &&&                )",
    R"(        &&&&&&&&&((((((((((&&&&((((((((((####&&&&&&##&                )",
    R"(  &&&&&&((((((((((((((&&&&&((((((((((((((####&&&&&####&&&&&           )",
    R"(  &&&&&&((((((((((((((&&&&&((((((((((((((####&&&&&####&&&&&           )",
    R"(&&&&&((((((((((&&&&########################&&&&(((((####&&###&&&&&    )",
    R"(&&&&&#####(((((((((&&&&&&&&&&&&&&&&&&&&&&&&(((((((((####&&&######%&&&)",
    R"(&&&&&#####(((((((((&&&&&&&&&&&&&&&&&&&&&&&&(((((((((####&&&&####%&&&& )",
    R"(&&&&&#####((((((((((((((((((((((((((((((((((((((((((####&&&&####%&&&& )",
    R"(    &&&&&&####&####################################%&&&&&&&&####%&&&& )",
    R"(    &&&&&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&&&&&&&&&##&&&&&& )",
    R"(          &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&        &&&&&&    )"
    };

    // init_color(COLOR_LIGHT_GREEN, 0, 901, 0);
    // init_color(COLOR_DARK_GREEN, 0, 783, 0);
    // init_color(COLOR_PINK, 999, 713, 756);
    // init_pair(0, COLOR_DARK_GREEN, bg_color );
    // init_pair(1,  COLOR_LIGHT_GREEN , bg_color );
    // init_pair(2, COLOR_LIGHT_GREEN , bg_color );
    // init_pair(3, COLOR_PINK ,  bg_color );
    // init_pair(4,  COLOR_BLACK , bg_color );
    // init_pair(5, bg_color , bg_color );
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

    wmove(menu_pic_win, 0, 0);

    for (short i = 0; i < menu_pic_y; i++){
        for (short j = 0; j< menu_pic_x+1; j++){
            switch(menu_pic[i][j]){
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
            // mvwprintw(menu_pic_win,20,45,"%d", init_color(COLOR_PINK, 999, 713, 756));
            // mvwprintw(menu_pic_win,20,50,"%d", can_change_color());
            wmove(menu_pic_win, i,j);

            // wattron(menu_pic_win, COLOR_PAIR(2));
            // wprintw(menu_pic_win, );
            // wattroff(menu_pic_win, COLOR_PAIR(2));
            wrefresh(menu_pic_win);
            refresh();
        }
    }
    wattron(menu_pic_win, A_BOLD | A_BLINK);
    mvwaddstr(menu_pic_win, 2, 55, "S N A K E");
    mvwaddstr(menu_pic_win, 3, 58, "G A M E");
    wattroff(menu_pic_win, A_BOLD | A_BLINK);
    wrefresh(menu_pic_win);
    refresh();
}

void render_option(const char& choice, WINDOW*& option_win){

    box(option_win, 0, 0);
    const char* temp[option_number] = {"NEW GAME\0", "OPTION\0", "EXIT\0"};

    for (char i = 0; i < option_number; i++){

        if (choice == i){
            wattron(option_win, A_STANDOUT);
            mvwaddstr(option_win, (i+1) * 5, 1, temp[i]);
            wattroff(option_win, A_STANDOUT);
        }
        else{
            mvwaddstr(option_win, (i+1) * 5, 1, temp[i]);
        }
    }
    wrefresh(option_win);
    refresh();
}