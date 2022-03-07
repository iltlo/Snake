#pragma once
#include <string>
#include <ncurses.h>

#define term_y 24
#define term_x 80
#define s_new_game 0
#define s_option 1
#define s_exit_game 2
#define menu_pic_y term_y
#define menu_pic_x 70
#define option_win_y term_y
#define option_win_x term_x - menu_pic_x
#define option_number 3

#define bg_color COLOR_BLUE
// #define COLOR_LIGHT_GREEN 2
// #define COLOR_DARK_GREEN 2
// #define COLOR_PINK 1

// #define HIGHLIGHTS_COLOR_PAIR 13
#define KEY_KEYBOARD_ENTER 10
#define KEY_R 114

char start_menu(WINDOW*&, WINDOW*&);
void render_menu_pic(WINDOW*&);
void render_option(const char&, WINDOW*&);

extern const std::string menu_pic;