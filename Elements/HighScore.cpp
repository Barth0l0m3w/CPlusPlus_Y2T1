#include "HighScore.h"


HighScore::~HighScore() {}

void GetData(std::vector<HighScore>& scores){

    std::ifstream inputFile("typed.cmgt");

    if(inputFile.is_open()){
        while(!inputFile.eof()){

        }
        inputFile.close();
    } else {
        std::cout << "Unable to open file for reading.\n";
    }
}

void UpdateText(const HighScore& newScore, std::vector<HighScore>& scores){
    scores.push_back(newScore);

   std::ofstream outputFile("typed.cmgt");

   outputFile.close();

}