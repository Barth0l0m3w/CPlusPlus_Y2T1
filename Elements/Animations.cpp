//
// Created by nhoge on 28/02/2024.
//

#include "Animations.h"
#include <chrono>
#include <iostream>


Animations::Animations(std::string identifier, std::string spriteFile) :
        GameObject(identifier), spriteFile(spriteFile) {

    texture.loadFromFile(spriteFile);
    sprite.setTexture(texture);
    sprite.setTextureRect({0, 0, 24, 24});
}

Animations::~Animations() {}

void Animations::update() {

    f++;
    sprite.setTextureRect({(f / 1000 % 4) * 24, 0, 24, 24});

}


void Animations::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

void Animations::setScale(sf::Vector2f scale) {
    sprite.setScale(scale);
}


void Animations::render(sf::RenderWindow &window) {

    window.draw(sprite);
    for (unsigned int i = 0; i < this->children.size(); i++) {
        this->children[i]->render(window);
    }
}