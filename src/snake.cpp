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
    // mvwprintw(stdscr, 0, 0, "Preparing for new game ...");   // for debug
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

bool Snake::Move(){
    
    nodelay(curwin,1);
    
    if ( snake.size() <= snakeLen ) storeSnake();          // storing position of snake tail
    
    int choice = (mvCount==1 ? KEY_RIGHT : wgetch(curwin)); // default run direction: right


    keyChoiceProcess(previous, choice);
    // *******
    // mvwprintw(stdscr, 0, 0, "count: %d choice: %d SnkLen: %d VecLen: %lu  ", mvCount, choice, snakeLen, snake.size());   // for debug
    // wrefresh(stdscr);
    // *******

    moveChoice(curwin, yPos, xPos, sBody, snake, choice, exitFlag);

    if ( mvCount >= snakeLen && snake.size()%snakeLen == 0 ) cutSnake(curwin, snake);     // cut the snake tail
    previous = choice;
    mvCount++;

    flushinp();                                 // flush all the input buffers (for continuous input control)

    if ( !isValidMove() )    // check if the input move will lose the game
        return false;
    else    
        return true;
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
key choice processing method

what it does:
normalize the choice input to direction keys
reponse to user key input
    1. spacebar pause
    2. same direction

input: previous key input, current key input

output: none
*/

void Snake::keyChoiceProcess(int previous, int &choice) {

    if (choice == 'w') choice = KEY_UP;                                  // map "wasd" to direction keys
    if (choice == 's') choice = KEY_DOWN;
    if (choice == 'a') choice = KEY_LEFT;
    if (choice == 'd') choice = KEY_RIGHT;

    if ( choice == KEY_KEYBOARD_SPACE ) {
        pause_menu(exitFlag);
        showBody(curwin, snake, sBody); // refresh the snake body once
    }                   // pasue state turns true (menu bar will pop out)
    
    if ( choice == previous ) choice = -1;
    if ( isSame_MvDirection(choice) ) choice = previous;                // continue the same path if no input (-1)

}

/*
check same moving direction method

what it does:
check if choice will make the snake move as the previous direction
input protection

input: none

output: none
*/

bool Snake::isSame_MvDirection(int choice){
    if ( choice == -1 || previous == oppoKey(choice)
            || ( choice != KEY_UP && choice != KEY_DOWN
            && choice != KEY_LEFT && choice != KEY_RIGHT ) )
        return true;
    else
        return false;
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

bool Snake::isValidMove(){
    std::vector<int> currentLoc;
    currentLoc.push_back(xPos);
    currentLoc.push_back(yPos);
    if ( std::find(snake.begin(), snake.end()-1, currentLoc) != snake.end()-1
            || yPos<1 || yPos > yMax-2
            || xPos<1 || xPos > xMax-3 
            || exitFlag )
        return false; //move is invalid
    return true;
}
