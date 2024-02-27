#include "spriteObject.hpp"

SpriteObject::SpriteObject(std::string identifier, std::string spriteFile) :
        GameObject(identifier), spriteFile(spriteFile) {
    this->texture.loadFromFile(this->spriteFile);
    this->sprite.setTexture(this->texture);
}

SpriteObject::SpriteObject(const SpriteObject &other) :
        GameObject(other.getIdentifier()), spriteFile(other.getSpriteFile()) {
    this->texture.loadFromFile(this->spriteFile);
    this->sprite.setTexture(this->texture);
}

SpriteObject::~SpriteObject() {}

void SpriteObject::update() {

}

void SpriteObject::render(sf::RenderWindow &window) {
    window.draw(this->sprite);
    for (unsigned int i = 0; i < this->children.size(); i++) {
        this->children[i]->render(window);
    }
}

void SpriteObject::setPosition(sf::Vector2f position) {
    sprite.setPosition(position);
}
sf::Vector2f SpriteObject::getPosition() {
    return sprite.getPosition();
}


void SpriteObject::setScale(sf::Vector2f scale) {
    sprite.setScale(scale);
}

void SpriteObject::SetNewSprite(std::string fileName)
{
    sf::Texture t;
    if (t.loadFromFile(fileName)) {
        texture = t;
        sprite.setTexture(texture);
    }
}

std::string SpriteObject::getSpriteFile() const {
    return this->spriteFile;
}