#include "snake.hpp"
#include "visuals.hpp"

/*
default class constructor

what it does:
declare an object to the Snake class

input: current window

output: loading game message
*/

Snake::Snake(WINDOW * win){       // Snake class constructor
    curwin = win;
    getmaxyx(curwin, yMax, xMax);
    yPos = yMax/2-1;
    xPos = xMax/2-1;
    mvwprintw(stdscr, 0, 0, "Preparing for new game ...");   // for debug
    keypad(curwin, true);
    curs_set(0);
}

/*
move method

what it does:
main function loop of the game
response to user key input

input: user key input, and the member attribute

output: none
*/

int Snake::Move(){
    
    nodelay(curwin,1);
    
    if ( snake.size() <= snakeLen ) storeSnake();          // storing position of snake tail
    
    int choice = (mvCount==1 ? KEY_RIGHT : wgetch(curwin)); // default run direction: right
    if (choice == previous) choice = -1;

    // *******
    mvwprintw(stdscr, 0, 0, "count: %d choice: %d SnkLen: %d VecLen: %lu  ", mvCount, choice, snakeLen, snake.size());   // for debug
    wrefresh(stdscr);
    // *******
    if ( choice == ' ' ) pause = 1;               // pasue state turns true (menu bar will pop out)

    if ( choice == -1 || previous == oppoKey(choice) || pause == 1 ) choice = previous;    // continue the same path if no input (-1)

    keyChoice(curwin, yPos, xPos, sBody, choice, pause); 
    pause = 0;

    if (mvCount>=snakeLen && snake.size()%snakeLen==0) cutSnake(curwin, snake);     // cut the snake tail
    previous = choice;
    mvCount++;

    if (!checkValid() && mvCount>COUNTDOWN){    // check if the input move will lose the game
        choice = 'q';
    }

    flushinp();                                 // flush all the input buffers (for continuous input control)

    return choice;
}

/*
store snake method

what it does:
stores every coordinate of the snake to vector container
updates snake size attribute

input: current position of snake: xPos yPos

output: none
*/

void Snake::storeSnake(){
    snake.push_back( std::vector<int>() );
    int snakeSize = snake.size();
    snake[snakeSize==0 ? 0 : snakeSize-1].push_back(xPos);
    snake[snakeSize==0 ? 0 : snakeSize-1].push_back(yPos);
}

/*
check valid move method

what it does:
check if the the move will end the game
    1. Snake hit itself, or
    2. Snake hit the wall
return false if move is invalid, true if valid

input: snake head position, snake body coordinate, window size

output: none
*/

int Snake::checkValid(){
    std::vector<int> currentLoc;
    currentLoc.push_back(xPos);
    currentLoc.push_back(yPos);
    if ( std::find(snake.begin(), snake.end()-1, currentLoc) != snake.end()-1
        || yPos<1 || yPos > yMax-2 ||
        xPos<1 || xPos > xMax-3 )
        return 0; //false
    return 1;
}