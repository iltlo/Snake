#pragma once

#include <ncurses.h>
#include <vector>
#include <string>
#include <random>
#include <array>

void showHead(WINDOW * curwin, int yPos, int xPos, std::string sHead);

void drawBorder(WINDOW * curwin);

int oppoKey(int key);

void keyChoice(WINDOW * curwin, int &yPos, int &xPos, std::string &sBody, int choice, int pause);

void cutSnake(WINDOW * curwin, std::vector< std::vector<int> > &snake);

std::array<int, 2> genApple(WINDOW * win);

