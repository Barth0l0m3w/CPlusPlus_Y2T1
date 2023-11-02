#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "gameObject.hpp"


class Button : public GameObject {
private:
    sf::Text buttonText;
    sf::Sprite buttonSprite;
    sf::Texture texture;
    sf::Font font;

    bool isClicked;

public:
    Button(const std::string &text, const std::string &font/*, const std::string& buttonSprite*/);

    void update() override;

    bool contains(const sf::Vector2f &point);

    void setPosition(sf::Vector2f position);

    void onClick();

    void render(sf::RenderWindow &window) override;

};

