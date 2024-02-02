#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include <string>


class GameObject {
private:
    const std::string identifier;


public:
    std::vector <GameObject *> children;
    GameObject(std::string identifier);

    GameObject(const GameObject &other);

    virtual ~GameObject();

public:
    virtual void update() = 0;

    virtual void render(sf::RenderWindow &window) = 0;

    std::string getIdentifier() const;

    void AddChildren(GameObject &child);

    void RemoveChildren(GameObject &child);

};