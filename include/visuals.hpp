#pragma once

#include <ncurses.h>
#include <vector>
#include <string>
#include <random>
#include <array>

#include "snake.hpp"

void showHead(WINDOW * curwin, int yPos, int xPos, std::string sHead);

void drawBorder(WINDOW * curwin);

int oppoKey(int key);

void keyChoice(WINDOW * curwin, int &yPos, int &xPos, std::string &sBody, int choice, int pause);

void cutSnake(WINDOW * curwin, std::vector< std::vector<int> > &snake);

void apple(Snake &player, WINDOW * curwin);

std::array<int, 2> genApple(Snake &player, WINDOW * win, int appleState);

