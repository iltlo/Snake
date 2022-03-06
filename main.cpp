#include <ncurses.h>

#include "start_menu.hpp"
#include "new_game.hpp"

int main()
{
    initscr();
    cbreak();
    noecho();
    start_color();

    bool n_exit_game = true;

    while(n_exit_game)
    {
        switch(start_menu())
        {
            case(s_new_game):
            new_game();
            break;

            // case(s_option):
            // option();

            case(s_exit_game):
                n_exit_game = false;
                curs_set(1);
                break;

            default:
                break;
        }
    }
    endwin();
}