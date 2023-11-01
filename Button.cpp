#include "Button.h"
#include <iostream>

Button::Button(const std::string &text, const sf::Font &font, const std::string &spritePath) : GameObject(text) {

    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(50);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(0,0);

    texture.loadFromFile(spritePath);
    this->buttonSprite.setTexture(texture);
}

void Button::update() {

}

bool Button::contains(const sf::Vector2f &point) {
    return buttonSprite.getGlobalBounds().contains(point);
}

void Button::onClick() {
    std::cout << "clicked \n";
    isClicked = true;
}

void Button::render(sf::RenderWindow &window) {
    window.draw(this->buttonSprite);
    window.draw(this->buttonText);
    for (unsigned int i = 0; i < this->children.size(); i++) {
        this->children[i]->render(window);
    }
}