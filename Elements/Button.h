#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "gameObject.hpp"
#include "../Characters/character.hpp"
#include "../Game-Scenes/Game.h"
#include "HighScore.h"
#include "ScoreDisplay.h"
#include "../library/timercpp.h"

class Button : public GameObject {
private:
    sf::Text buttonText;
    sf::Sprite buttonSprite;
    sf::Texture texture;
    sf::Font font;

    int buttonID;
    bool clicked = false;
    Timer timer;

    Game &game;

public:

    Button(const std::string &text, const std::string &font,unsigned int fontSize,  int buttonID, Game &game);

    void update() override;

    bool contains();

    void setPosition(sf::Vector2f position);

    void setText(std::string newText);

    void onClick();

    void render(sf::RenderWindow &window) override;

};

