#pragma once

#include <string>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>   // for istringstream
#include <iomanip>   // for setw()
#include <chrono>    // for time_t
#include <ctime>     // for getting current time
#include <algorithm> // fo sort()
#include <ncurses.h>

#define leaderboard_win_y 10
#define leaderboard_win_x 40

// save and load class
class SaveAndLoad {
    public:
        SaveAndLoad(std::string state_file, std::string score_file);
        
        bool is_empty(std::ifstream &File) { return File.peek() == std::ifstream::traits_type::eof(); }

        void saveScore(int score);

        void saveState(int mvCount, int previous, int yApple, int xApple, bool appleEaten, int snakeLen, std::vector< std::vector<int> > snake);
        
        void delState();

        std::string get_state_file() { return state_file; }
        
    private:
        std::string state_file;
        std::string score_file;
        void sortLogScore();
};

void show_leaderboard(WINDOW*&);