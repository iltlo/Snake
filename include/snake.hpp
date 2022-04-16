#pragma once

#include <ncurses.h>
#include <algorithm>
#include <vector>
#include <string>

#include "pause_menu.hpp"

#define KEY_KEYBOARD_SPACE 32

class Snake{
    
    public:
        Snake(WINDOW * win);

        bool Move();
        void storeSnake();
        bool isValidMove();
        void keyChoiceProcess(int previous, int &choice);
        bool isSame_MvDirection(int choice);

        int get_score() { return snakeLen-2; }
        int get_yPos() { return yPos; }
        int get_xPos() { return xPos; }
        std::string get_sHead() { return sHead; }
        std::string get_sBody() { return sBody;}
        int get_speed() { return snakeSpeed; }
        int get_appleState() { return appleEaten;};
        int get_yApple() { return yApple; }
        int get_xApple() { return xApple; }

        void set_yApple(int y) { yApple = y; }
        void set_xApple(int x) { xApple = x; }
        void set_appleState(bool n) { appleEaten = n; }
        void increment_snakeLen() { snakeLen++; }

        bool exitFlag = false;

    private:
        std::vector< std::vector<int> > snake;  // xy, storage of snake position
        int xPos, yPos, xMax, yMax;             // Pos: head of the snake Max: game window size

        int yApple, xApple;


        int snakeLen = 2;
        std::string sHead = "00";               // head char of the snake
        std::string sBody = "[]";                // body char of the snake

        int snakeSpeed = 120;                     // usleep(snakeSpeed*1000)
        bool appleEaten = true;
        int mvCount = 1, previous;                //totol move count, previous move

        WINDOW * curwin;

};
