#include "Button.h"
#include <SFML/Graphics.hpp>
#include "sceneHandler.hpp"
#include <iostream>
#include "Game.h"

Button::Button(const std::string &text, const std::string &fontPath, int buttonID, Game &game) : GameObject(text),
                                                                                                 game(game) {

    buttonText.setString(text);
    buttonText.setCharacterSize(50);
    buttonText.setFillColor(sf::Color::White);

    sf::Font font1;
    if (!font.loadFromFile(fontPath)) {
        std::cout << "couldn't load font\n";
    }
    this->buttonText.setFont(font);

    this->buttonID = buttonID;

}

void Button::update() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (contains()) {
            this->onClick();
        }
    }
}


bool Button::contains() {

    const sf::Vector2f point =
            sf::Vector2f(sf::Mouse::getPosition(*game.window));

    return buttonText.getGlobalBounds().contains(point);
}

void Button::setPosition(sf::Vector2f position) {
    //buttonSprite.setPosition(position);
    buttonText.setPosition(position);
}

void Button::onClick() {
    switch (buttonID) {
        case 1:
            game.SwitchScene();
            break;
        case 2:
            std::cout << "case 2\n";
            break;
        default:
            std::cout << "nothing implemented\n";
            break;
    }
}

void Button::render(sf::RenderWindow &window) {
    window.draw(this->buttonSprite);
    window.draw(this->buttonText);
    for (unsigned int i = 0; i < this->children.size(); i++) {
        this->children[i]->render(window);
    }
}