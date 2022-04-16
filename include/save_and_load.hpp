#include <string>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>   // for setw()
#include <chrono>    // for time_t
#include <ctime>     // for getting current time
#include <algorithm> // fo sort()

// save and load class
class SaveAndLoad {
    public:
        SaveAndLoad(std::string state_file, std::string score_file);
        
        void saveScore(int score);

        void saveState(int mvCount, int previous, int yApple, int xApple, bool appleEaten, int snakeLen, std::vector< std::vector<int> > snake);
        
        void delState();

        
    private:
        std::string state_file;
        std::string score_file;
        void sortLogScore();
};
