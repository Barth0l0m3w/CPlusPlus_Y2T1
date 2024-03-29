#pragma once

#include "gameObject.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class SpriteObject : public GameObject {
protected:
    void SetNewSprite(std::string fileName);

private:
    std::string spriteFile;
    sf::Sprite sprite;
    sf::Texture texture;
public:
    SpriteObject(std::string identifier, std::string spriteFile);

    SpriteObject(const SpriteObject &other);

    ~SpriteObject();

    void update() override;

    void render(sf::RenderWindow &window) override;

    void setPosition(sf::Vector2f position);

    void setScale(sf::Vector2f scale);

    std::string getSpriteFile() const;

    sf::Vector2f getPosition();
};



