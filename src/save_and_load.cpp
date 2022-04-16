#include <save_and_load.hpp>

SaveAndLoad::SaveAndLoad(std::string state_file, std::string score_file) {
    this->state_file = state_file;
    this->score_file = score_file;
}

/*
save state method

what it does:
saves the current game state

input: mvCount, previous, yApple, xApple, appleEaten, snakeLen, snake

output: to state.txt
*/

void SaveAndLoad::saveState(int mvCount, int previous, int yApple, int xApple, bool appleEaten, int snakeLen, std::vector< std::vector<int> > snake) {
    std::ofstream fout;
    fout.open(state_file);
    fout << mvCount << " " << previous << " " << yApple << " " << xApple << " " << appleEaten << " " << snakeLen << std::endl;
    for (int i = 0; i < snake.size(); i++) {
        for (int j = 0; j < snake[i].size(); j++) {
            fout << snake[i][j] << " ";
        }
        if ( i != snake.size()-1 ) fout << std::endl;
    }
    fout.close();
}


/*
delete state method

what it does:
delete content from status.txt by truncate-option

input: state.txt

output: none
*/

void SaveAndLoad::delState() {
    std::ofstream fout;
    fout.open(state_file, std::ofstream::out | std::ofstream::trunc);
    fout.close();
}

/*
save score function

what it does:
save the game result to log file

input: none

output: score and date
*/

void SaveAndLoad::saveScore(int newScore){
    std::ofstream fout;
    fout.open(score_file.c_str(), std::ios::app);

    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    fout  << std::setw(5) << newScore << " |";
    fout  << std::setw(29) << std::ctime(&end_time) ;
    fout.close();

    sortLogScore();
}

/*
sorting function

what it does:
sorts the log file by score in descending order

inputs: current log file

outputs: log file sorted by score
*/

void SaveAndLoad::sortLogScore(){
    std::ifstream fin;
    fin.open(score_file.c_str());

    std::vector<std::string> lines;
    std::string line;
    int count = 0;
    while(std::getline(fin, line) ){
        if (count>=2) lines.push_back(line);
        count++;
    }
    fin.close();

    std::sort(lines.begin(), lines.end(), [](std::string a, std::string b){
        return stoi(a.substr(0, 5)) > stoi(b.substr(0, 5));
    });

    std::ofstream fout;
    fout.open(score_file.c_str());
    fout << "      ===  LEADERBOARD  ===\n"
            "SCORE |                        DATE" << std::endl;

    for(auto line : lines){
        fout << line << std::endl;
    }
    fout.close();
}
