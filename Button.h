#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "gameObject.hpp"
#include "character.hpp"
#include "Game.h"


class Button : public GameObject {
private:
    sf::Text buttonText;
    sf::Sprite buttonSprite;
    sf::Texture texture;
    sf::Font font;

    int buttonID;

    Game &game;

public:

    Button(const std::string &text, const std::string &font, int buttonID, Game &game);

    void update() override;

    bool contains();

    void setPosition(sf::Vector2f position);

    void onClick();

    void render(sf::RenderWindow &window) override;

};

