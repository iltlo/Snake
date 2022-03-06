#pragma once

#include <ncurses.h>
#include <vector>
#include <string>

class Snake{
    public:
        Snake(WINDOW * win, int y, int x);

        int Move();
        void storeSnake();
        int checkValid();
        int mvCount=0, previous;                //totol move count, previous move

        int get_yPos() {return yPos;}
        int get_xPos() {return xPos;}
        std::string get_sHead() {return sHead;}
        int get_speed() {return snakeSpeed;}

    private:
        std::vector< std::vector<int> > snake;  // xy, storage of snake position
        int xPos, yPos, xMax, yMax;             // Pos: head of the snake Max: game window size
        int snakeLen = 3;
        std::string sHead = "<>";               // head char of the snake
        std::string sBody ="[]";                // body char of the snake
        int COUNTDOWN=10;                       // count down before the snake will die, should be based on initial po <-> wall distance
        int snakeSpeed=500;                     // usleep()
        int appleState = 0;                     // default false
        int pause = 0;                          // default false
        WINDOW * curwin;
};
