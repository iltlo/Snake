#include "visuals.hpp"

void drawBorder(WINDOW * curwin){
    
    init_pair(15, COLOR_BLACK, COLOR_YELLOW);

    wattron(curwin, 15);

    box(curwin, 35, 61);

    wrefresh(stdscr);
    wrefresh(curwin);
}

void showHead(WINDOW * curwin, int yPos, int xPos, std::string sHead){              // shows the head of the snake

    init_pair(12, COLOR_RED, COLOR_CYAN); // -1: terminal default color
    wattron(curwin, COLOR_PAIR(12));

    mvwaddstr(curwin, yPos, xPos, sHead.c_str());

    wattroff(curwin, COLOR_PAIR(12));
    wrefresh(curwin);
}

void keyChoice(WINDOW * curwin, int &yPos, int &xPos, std::string &sBody, int choice, int pause){
    
    init_pair(14, COLOR_CYAN, COLOR_GREEN);

    wattron(curwin, COLOR_PAIR(14));

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

            wattroff(curwin, COLOR_PAIR(14));
            wrefresh(curwin);

            yPos--;
            break;

        case KEY_DOWN:

            mvwaddstr(curwin, yPos, xPos, sBody.c_str());

            wattroff(curwin, COLOR_PAIR(14));
            wrefresh(curwin);

            yPos++;
            break;

        case KEY_LEFT:

            mvwaddstr(curwin, yPos, xPos, sBody.c_str());

            wattroff(curwin, COLOR_PAIR(14));
            wrefresh(curwin);

            xPos=xPos-2;
            break;

        case KEY_RIGHT:
            mvwaddstr(curwin, yPos, xPos, sBody.c_str());

            wattroff(curwin, COLOR_PAIR(14));
            wrefresh(curwin);

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