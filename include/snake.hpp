#pragma once

#include <ncurses.h>
#include <algorithm>
#include <vector>
#include <string>

#include "pause_menu.hpp"
#include "save_and_load.hpp"

#define KEY_KEYBOARD_SPACE 32

class Snake{
    
    public:
        Snake(WINDOW * win);
        Snake(WINDOW * win, SaveAndLoad &sl);

        bool Move();
        void storeSnake();
        bool isValidMove();
        void keyChoiceProcess(int previous, int &choice);
        bool isSame_MvDirection(int choice);

        int get_score() { return snakeLen-2; }
        int get_yPos() { return yPos; }
        int get_xPos() { return xPos; }
        int get_mvCount() { return mvCount; }
        int get_previous() { return previous; }
        int get_yApple() { return yApple; }
        int get_xApple() { return xApple; }
        bool get_appleState() { return appleEaten;};
        int get_snakeLen() { return snakeLen; }
        std::vector< std::vector<int> > get_snake() { return snake; }
        
        // std::string get_sHead() { return sHead; }
        std::string get_sBody() { return sBody;}
        int get_speed() { return snakeSpeed; }

        void set_mvCount(int n) { this->mvCount = n; }
        void set_previous(int k) { this->previous = k; }
        void set_yApple(int y) { this->yApple = y; }
        void set_xApple(int x) { this->xApple = x; }
        void set_appleState(bool n) { this->appleEaten = n; }
        void set_snakeLen(int n) { this->snakeLen = n; }
        void increment_snakeLen() { snakeLen++; }

        bool exitFlag = false;

    private:
        std::vector< std::vector<int> > snake;  // xy, storage of snake position
        int xPos = 39, yPos = 10;               // Pos: head of the snake
        
        int mvCount = 1, previous = KEY_RIGHT;  //totol move count, previous move

        int yApple, xApple;
        bool appleEaten = true;

        int snakeLen = 2;

        std::string sHead = "00";               // head char of the snake
        std::string sBody = "[]";               // body char of the snake

        int snakeSpeed = 135;                   // usleep(snakeSpeed*1000)

        WINDOW * curwin;

};
