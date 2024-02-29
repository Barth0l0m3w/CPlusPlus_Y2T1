#ifndef WEEK6_ANIMATIONS_H
#define WEEK6_ANIMATIONS_H

#include "gameObject.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Animations : public GameObject {
private:

    std::string spriteFile;
    sf::Texture texture;
    sf::Sprite sprite;
    int f = 0;

    int width;
    int height;
    int rows;
    int collums;

public:
    Animations(std::string identifier, std::string spriteFile, int width, int height, int rows, int collums);

    Animations(const Animations &other);

    ~Animations();

    void update() override;

    void render(sf::RenderWindow &window) override;

    void setPosition(sf::Vector2f position);

    void setScale(sf::Vector2f scale);

};


#endif //WEEK6_ANIMATIONS_H
