#pragma once

#include <ncurses.h>

#define pause_menu_y 8
#define pause_menu_x 60
#define pause_menu_pos_y 12 - pause_menu_y/2
#define pause_menu_pos_x 40 - pause_menu_x/2
#define pause_menu_option_number 2

#define KEY_KEYBOARD_ENTER 10
#define KEY_R 114

void pause_menu();
void render_pause_menu(char, WINDOW*&);