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
        SaveAndLoad(std::string file_name);
        
        void saveScore(int score);

        void saveSnake(std::vector<std::vector<int>> snake, int score, int speed, int yApple, int xApple, int appleEaten);
        void loadSnake(std::vector<std::vector<int>> &snake, int &score, int &speed, int &yApple, int &xApple, int &appleEaten);
        
    private:
        std::string file_name;
        void sortLogScore();
};
