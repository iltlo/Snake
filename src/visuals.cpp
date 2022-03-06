#include "visuals.hpp"

void drawBorder(WINDOW * curwin){
    box(curwin, 35, 61);
    wrefresh(stdscr);
    wrefresh(curwin);
}

void showHead(WINDOW * curwin, int yPos, int xPos, std::string sHead){              // shows the head of the snake
    mvwaddstr(curwin, yPos, xPos, sHead.c_str());
    wrefresh(stdscr);
    wrefresh(curwin);
}

void keyChoice(WINDOW * curwin, int &yPos, int &xPos, std::string &sBody, int choice, int pause){
    if (pause == 1){
        while (true) {
            // menu function ...
            // menu function ... 
            // menu function ... 
            break;
        }
    }

    switch(choice){
    case KEY_UP:
        mvwaddstr(curwin, yPos, xPos, sBody.c_str());
        yPos--;
        break;
    case KEY_DOWN:
        mvwaddstr(curwin, yPos, xPos, sBody.c_str());
        yPos++;
        break;
    case KEY_LEFT:
        mvwaddstr(curwin, yPos, xPos, sBody.c_str());
        xPos=xPos-2;
        break;
    case KEY_RIGHT:
        mvwaddstr(curwin, yPos, xPos, sBody.c_str());
        xPos=xPos+2;
        break;
    default:
        break;
    }
}

void cutSnake(WINDOW * curwin, std::vector< std::vector<int> > &snake){
    mvwaddstr(curwin, snake[0][1], snake[0][0], "  ");
    snake.erase(snake.begin());                                                    //first element in snake vec: tail of snake
}

void showHead(WINDOW * curwin, int &yPos, int &xPos, std::string &sHead){          // shows the head of the snake
    mvwaddstr(curwin, yPos, xPos, sHead.c_str());
}