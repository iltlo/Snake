#include <save_and_load.hpp>

SaveAndLoad::SaveAndLoad(std::string file_name) {
    this->file_name = file_name;
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
    fout.open(file_name.c_str(), std::ios::app);

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
    fin.open(file_name.c_str());

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
    fout.open(file_name.c_str());
    fout << "      ===  LEADERBOARD  ===\n"
            "SCORE |                        DATE" << std::endl;

    for(auto line : lines){
        fout << line << std::endl;
    }
    fout.close();
}
