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
        int mvCount=1, previous;                //totol move count, previous move

        int get_yPos() { return yPos; }
        int get_xPos() { return xPos; }
        std::string get_sHead() { return sHead; }
        std::string get_sBody() { return sBody;}
        int get_speed() { return snakeSpeed; }

        // class Apple {
        //     public:
        //         void genApple(WINDOW * win);
        //         void storeApple(int y, int x);
        //         std::vector< std::vector<int> > applePos;
                
        // };

    private:
        std::vector< std::vector<int> > snake;  // xy, storage of snake position
        int xPos, yPos, xMax, yMax;             // Pos: head of the snake Max: game window size

        int yApple, xApple;

        int snakeLen = 2;
        std::string sHead = "00";               // head char of the snake
        std::string sBody ="[]";                // body char of the snake

        int COUNTDOWN=10;                       // count down before the snake will die, should be based on initial po <-> wall distance
        int snakeSpeed=330;                     // usleep(snakeSpeed*1000)
        int appleState = 1;                     // 1: apple eaten
        int pause = 0;                          // default false

        WINDOW * curwin;

};
