#pragma once

#include <ncurses.h>
#include <algorithm>
#include <vector>
#include <string>

#define KEY_KEYBOARD_SPACE 32

class Snake{
    
    public:
        Snake(WINDOW * win);

        bool Move();
        void storeSnake();
        bool isValidMove();
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

    private:
        std::vector< std::vector<int> > snake;  // xy, storage of snake position
        int xPos, yPos, xMax, yMax;             // Pos: head of the snake Max: game window size

        int yApple, xApple;


        int snakeLen = 2;
        std::string sHead = "00";               // head char of the snake
        std::string sBody = "[]";                // body char of the snake

        int COUNTDOWN = 10;                       // count down before the snake will die, should be based on initial po <-> wall distance
        int snakeSpeed = 150;                     // usleep(snakeSpeed*1000)
        bool appleEaten = true;
        int pause = false;
        int mvCount = 1, previous;                //totol move count, previous move

        WINDOW * curwin;

};
