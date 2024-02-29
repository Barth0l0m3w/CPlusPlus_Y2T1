#ifndef WEEK6_SCOREDISPLAY_H
#define WEEK6_SCOREDISPLAY_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "gameObject.hpp"
#include "HighScore.h"
#include "SceneHandler.hpp"

class HighScore;

class ScoreDisplay : public GameObject {

private:

    sf::Text scoreText;
    sf::Font font;
    HighScore& highScore;
    std::vector<int> highScores;

public:

    ScoreDisplay(std::string identifier, sf::Font &font, unsigned int fontSize);

    ~ScoreDisplay();

    void update() override;

    void setPosition(sf::Vector2f position);

    void EraseData();

    void render(sf::RenderWindow &window) override;

    void UpdateScore();
};


#endif //WEEK6_SCOREDISPLAY_H
