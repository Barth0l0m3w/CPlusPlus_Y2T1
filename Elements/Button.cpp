#include "Button.h"
#include <SFML/Graphics.hpp>
#include "SceneHandler.hpp"
#include <iostream>
#include "windows.h"
#include <thread>


Button::Button(const std::string &text, const std::string &fontPath, unsigned int fontSize, int buttonID, Game &game) :
        GameObject(text), game(game) {

    buttonText.setString(text);
    buttonText.setCharacterSize(50);
    buttonText.setFillColor(sf::Color::White);

    sf::Font font1;
    if (!font.loadFromFile(fontPath)) {
        std::cout << "couldn't load font\n";
    }
    this->buttonText.setFont(font);
    this->buttonText.setCharacterSize(fontSize);

    this->buttonID = buttonID;

}

void Button::update() {

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        if (contains() && !clicked) {
            clicked = true;
            this->onClick();

            //library used for the timer. make a delay and set the boolean to be able to press the button on active again after half a second
            timer.setTimeout([&](){
               clicked = false;
            }, 500);
        }
    }
}

bool Button::contains() {

    const sf::Vector2f point =
            sf::Vector2f(sf::Mouse::getPosition(*game.window));

    return buttonText.getGlobalBounds().contains(point);
}

void Button::setPosition(sf::Vector2f position) {
    buttonText.setPosition(position);
}

void Button::onClick() {


    switch (buttonID) {
        case 1:
            game.SwitchScene();
            break;
        case 2:
            std::cout << "closing application\n";
            game.window->close();
            break;
        case 3:
            game.EraseData();
            break;
        case 4:
            std::cout << "attack\n";
            game.attack();
            //pointer to character and attack function
            break;
        case 5:
            std::cout << "heal\n";
            game.heal();
            //pointer to character and attack function
            break;
        default:
            std::cout << "nothing implemented\n";
            break;
    }
}

void Button::render(sf::RenderWindow &window) {
    window.draw(this->buttonSprite);
    window.draw(this->buttonText);
    for (auto &i: this->children) {
        i->render(window);
    }
}

void Button::setText(std::string newText) {
    buttonText.setString(newText);
}
