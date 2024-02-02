#include "HighScore.h"

std::vector<int> HighScore::getHighScore() {

    std::vector<int> scores;
    std::ifstream inputFile("typed.cmgt");
    std::string line;
    int index = 0;

    while (std::getline(inputFile, line)) {

        scores.push_back(std::stoi(line));
    }
    std::sort(scores.begin(), scores.end(), std::greater<int>());
    return scores;
}

void HighScore::UpdateText(std::vector<int> newHighScore) {
    std::ofstream inputFile("typed.cmgt");
    if (newHighScore.size() > 5) {
        newHighScore.resize(5);
    }
    for (int i = 0; i < newHighScore.size(); ++i) {
        inputFile << std::to_string(newHighScore[i]) + "\n";
    }
}

void HighScore:: DeleteData(){
    std::ofstream file;
    file.open("typed.cmgt", std::ofstream::out | std::ofstream::trunc); //todo: wtf is happening here
    file.close();
}