#pragma once

#include <ncurses.h>
#include <vector>
#include <string>
#include <random>
#include <array>

#include "snake.hpp"
#include "pause_menu.hpp"

void showHead(WINDOW * curwin, int yPos, int xPos, std::string sHead);
void showHead(WINDOW * curwin, std::vector< std::vector<int> > &snake, std::string sHead);

void showBody(WINDOW * curwin, std::vector< std::vector<int> > &snake, std::string &sBody);

void drawBorder(WINDOW *& curwin);

int oppoKey(int key);

void moveChoice(WINDOW * curwin, std::string &sBody, std::vector< std::vector<int> > &snake, int choice);

void cutSnake(WINDOW * curwin, std::vector< std::vector<int> > &snake);

void apple(Snake &player, WINDOW * curwin);

std::array<int, 2> genApple(Snake &player, WINDOW * win, bool appleEaten);

