#include "ScoreDisplay.h"
#include "HighScore.h"

ScoreDisplay::ScoreDisplay(std::string identifier, sf::Font &font, unsigned int fontSize)
        : GameObject(identifier), highScore(highScore) {

    highScores = highScore.getHighScore();

    scoreText.setFillColor(sf::Color::White);

    this->scoreText = sf::Text();
    this->scoreText.setCharacterSize(fontSize);
    this->scoreText.setFont(font);
    this->scoreText.setCharacterSize(fontSize);

    std::string highScoreString = "Leaderboard:\n";
    for (size_t i = 0; i < highScores.size(); i++) {
        highScoreString += std::to_string(i + 1) + ". " + std::to_string(highScores[i]) + "\n";
    }
    scoreText.setString(highScoreString);

}

ScoreDisplay::~ScoreDisplay() {

}

void ScoreDisplay::update() {

}

void ScoreDisplay::setPosition(sf::Vector2f position) {
    scoreText.setPosition(position);
}

void ScoreDisplay::EraseData() {

    HighScore::DeleteData();
    scoreText.setString("Leaderboard:\n");
}

void ScoreDisplay::render(sf::RenderWindow &window) {
    window.draw(scoreText);
    for (unsigned int i = 0; i < this->children.size(); i++) {
        this->children[i]->render(window);
    }
}


