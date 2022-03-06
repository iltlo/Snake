#pragma once

#include <ncurses.h>
#include <vector>

void showHead(WINDOW * curwin, int yPos, int xPos, std::string sHead);

void drawBorder(WINDOW * curwin);

void keyChoice(WINDOW * curwin, int &yPos, int &xPos, std::string &sBody, int choice, int pause);

void cutSnake(WINDOW * curwin, std::vector< std::vector<int> > &snake);

