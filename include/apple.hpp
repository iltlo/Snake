#pragma once

#include <ncurses.h>
#include <array>

std::array<int, 2> genApple(WINDOW * win);

void checkApple();