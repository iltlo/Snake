#include "visuals.hpp"

/*
draw border function

what it does:
draw the border

input: pointer to the specified window (game window)

output: drawn border around the window
*/
void drawBorder(WINDOW *& curwin){

    init_pair( 1, COLOR_BLACK, COLOR_YELLOW);
    chtype fence_lr = '#' | A_BOLD | A_STANDOUT | COLOR_PAIR(1);
    chtype fence_ud = 'X' | A_BOLD | A_STANDOUT | COLOR_PAIR(1);
    chtype fence_corner = 'X' | A_BOLD | A_STANDOUT | COLOR_PAIR(1);

    wborder(curwin, fence_lr, fence_lr,fence_ud,fence_ud,fence_corner,fence_corner,fence_corner,fence_corner);

    wrefresh(stdscr);
    wrefresh(curwin);
}

/*
show head function

what it does:
will show the head of the snake
coloured by using ncurses attribute
overloaded to distringuish between game over or not

input: pointer to the game window, coordinate and appearance of snake head

output: shows snake head (as string)
*/
void showHead(WINDOW * curwin, int yPos, int xPos, std::string sHead){              // shows the head of the snake

    wattron(curwin, COLOR_PAIR(12));

    mvwaddstr(curwin, yPos, xPos, sHead.c_str());

    wattroff(curwin, COLOR_PAIR(12));
    wrefresh(curwin);
}
void showHead(WINDOW * curwin, std::vector< std::vector<int> > &snake, std::string sHead){    // shows the head of the snake after game over

    wattron(curwin, COLOR_PAIR(12));
    int snakeSize = snake.size();
    int xPos = snake[snakeSize-1][0];
    int yPos = snake[snakeSize-1][1];

    mvwaddstr(curwin, yPos, xPos, sHead.c_str());

    wattroff(curwin, COLOR_PAIR(12));
    wrefresh(curwin);
}

/*
show body function

what it does:
will refresh the body of the snake
prevents the snake disappering after calling the pause menu

input: pointer to the game window, coordinate vector and appearance of snake head

output: refreshes the whole snake
*/
void showBody(WINDOW * curwin, std::vector< std::vector<int> > snake, std::string sBody) {
    wattron(curwin, COLOR_PAIR(14));

    for (int i=0; i<snake.size(); i++) { 
        mvwaddstr(curwin, snake[i][1], snake[i][0], sBody.c_str()); // snake is stored in x-y
    }

    wattroff(curwin, COLOR_PAIR(14));
    wrefresh(curwin);
}

/*
opposite key function

what it does:
return the opposite moving key

input: key input

output: mapped opposite keyvalue as return value
*/
int oppoKey(int key){

    if ( key == KEY_UP )
        return KEY_DOWN;
    if ( key == KEY_DOWN )
        return KEY_UP;
    if ( key == KEY_LEFT)
        return KEY_RIGHT;
    if ( key == KEY_RIGHT)
        return KEY_LEFT;
    
    return -1;
}

/*
key choice function

what it does:
response to user key input and refresh the snake body

input: window pointer, coordinate and appearance of snake body, keyboard input

output: snake body
*/
void moveChoice(WINDOW * curwin, std::string &sBody, std::vector< std::vector<int> > &snake, int choice) {
    
    int snakeSize = snake.size();
    int xPos = snake[snakeSize<=1 ? 0 : snakeSize-1][0];
    int yPos = snake[snakeSize<=1 ? 0 : snakeSize-1][1];

    wattron(curwin, COLOR_PAIR(14));

    switch(choice){

        case KEY_UP:
            mvwaddstr(curwin, yPos, xPos, sBody.c_str());

            wattroff(curwin, COLOR_PAIR(14));
            wrefresh(curwin);

            break;

        case KEY_DOWN:
            mvwaddstr(curwin, yPos, xPos, sBody.c_str());

            wattroff(curwin, COLOR_PAIR(14));
            wrefresh(curwin);

            break;

        case KEY_LEFT:
            mvwaddstr(curwin, yPos, xPos, sBody.c_str());

            wattroff(curwin, COLOR_PAIR(14));
            wrefresh(curwin);

            break;

        case KEY_RIGHT:
            mvwaddstr(curwin, yPos, xPos, sBody.c_str());

            wattroff(curwin, COLOR_PAIR(14));
            wrefresh(curwin);

            break;
        
        default:
            break;
    }
}

/*
cut snake function

what it does:
cuts the tail of the snake: first element in snake vector

input: window pointer, snake vector

output: blank space to cover the snake tail
*/
void cutSnake(WINDOW * curwin, std::vector< std::vector<int> > &snake){

    mvwaddstr(curwin, snake[0][1], snake[0][0], "  ");

    snake.erase(snake.begin());                                             // first element in snake vec: tail of snake

}

/*
apple function

what it does:
if snake ate apple,
    1. generate a new apple
    2. increase length and speed
update apple coord and snake length as attribute

input: window pointer, and "player" class object passed by pointer from start_game.cpp

output: none
*/
void apple(Snake &p, WINDOW * curwin) {

    if ( p.get_yPos() == p.get_yApple() && p.get_xPos() == p.get_xApple() ) {
        p.increment_snakeLen();

        p.set_appleState(true);

        return;
    }

    if ( p.get_appleState() == 1 ){

        std::array<int, 2> arr = { genApple(p, curwin, 1) };

        p.set_yApple(arr[0]);
        p.set_xApple(arr[1]);

        p.set_appleState(false);
    }
    else {
        genApple(p, curwin, 0);
    }
    
}

/*
gen apple function

what it does:
generate an apple on the window at a random coord
ensured that the apple position is not covered by the snake

input: window pointer

output: red apple on the screen, array of the apple's int coordinate
*/
std::array<int, 2> genApple(Snake &p, WINDOW * win, bool appleEaten){

    std::string apple = "()";
    int yApple, xApple;
    chtype ch;

    if (appleEaten == true) {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> unif(1, 819);

        do {
            int applePos = unif(generator);
            yApple = applePos/40+1;
            xApple = ( (xApple=(applePos%39)*2-1)==-1 ? 77 : xApple ) ;     //xApple: (applePos%39)*2-1),  == -1 indicates: y-index = 77
            ch = mvwinch(win, yApple, xApple);
        } while ( ch == 3120 || ch == 3675 );                               // 3120: chtype of highlighted sHead[0], 3675: sBody[0]
    }
    else {
        yApple = p.get_yApple();
        xApple = p.get_xApple();
    }

    wattron(win, COLOR_PAIR(11));
    mvwprintw(win, yApple, xApple, "%s", apple.c_str());
    wattroff(win, COLOR_PAIR(11));
    
    wrefresh(stdscr);
    wrefresh(win);

    return {yApple, xApple};
}