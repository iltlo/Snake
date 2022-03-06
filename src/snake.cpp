#include <algorithm>
#include <iostream>

#include "snake.hpp"
#include "visuals.hpp"
#include "apple.hpp"                              // genApple()

Snake::Snake(WINDOW * win, int y, int x){       // Snake class constructor
    curwin = win; //current window
    getmaxyx(curwin, yMax, xMax);
    yPos = yMax/2-1;
    xPos = xMax/2-1;
    mvwprintw(stdscr, 0, 0, "gamewin xMax: %d yMax: %d", xMax, yMax);
    keypad(curwin, true);
    curs_set(0);
}

int Snake::Move(){
    
    nodelay(curwin,1);
    
    storeSnake();                                  // storing position of snake tail
    
    int choice = (mvCount==0 ? KEY_RIGHT : wgetch(curwin)); // default run direction: right
    if (choice == previous) choice = -1;

    // *******
    mvwprintw(stdscr, 0, 0, "count: %d choice: %d      ", mvCount, choice);   // for debug
    // *******
    if (choice == ' ') pause = 1;               // pasue state turns true (menu bar will pop out)

    if (choice == -1 || pause == 1) choice = previous;    // continue the same path if no input

    keyChoice(curwin, yPos, xPos, sBody, choice, pause); 
    pause = 0;

    if (mvCount>=snakeLen && snake.size()%snakeLen!=0) cutSnake(curwin, snake);     // cut the snake tail
    previous = choice;
    mvCount++;

    if (!checkValid() && mvCount>COUNTDOWN){    // check if the input move will lose the game
        choice = 'q';
    }

    // TODO: only if ate apple, generate a new apple
    if (mvCount%10==0){                          // generate an apple on the map
        genApple(curwin);
    }
    
    // TODO: only if ate apple, increase length
    if (mvCount%10 == 0){                        // increase snake length
        snakeLen++;
    }

    flushinp();                                 // flush all the input buffers (for continuous input control)

    return choice;
}

void Snake::storeSnake(){
    snake.push_back( std::vector<int>() );
    int snakeSize = snake.size();
    snake[snakeSize==0 ? 0 : snakeSize-1].push_back(xPos);
    snake[snakeSize==0 ? 0 : snakeSize-1].push_back(yPos);
}

int Snake::checkValid(){                        // return false if invalid move
    std::vector<int> currentLoc;
    currentLoc.push_back(xPos);
    currentLoc.push_back(yPos);
    if ( std::find(snake.begin(), snake.end()-1, currentLoc) != snake.end()-1
        || yPos<1 || yPos > yMax-2 ||
        xPos<1 || xPos > xMax-3 )               // snake hit itself / hit the wall
        return 0; //false
    return 1;
}