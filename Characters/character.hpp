#pragma once

#include <string>
#include "character.hpp"
#include "../Elements/spriteObject.hpp"
#include <map>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Character: public SpriteObject {

protected:

    std::map<std::string, int> stats = {
            {"Attack",  0},
            {"Defense", 0},
            {"Health",  0},
            {"Dex",  0}
    };

    int currentHealth;
    int level = 1;

    void clearStarts();

private:

    sf::Font font;
    sf::Text healthText;
    std::string spriteFile;


public:

    Character(std::string identifier, std::string spriteFile, int health,
              int attack, int defense, int dex, sf::Font &font, unsigned int fontSize);

    ~Character();


    std::string takeDamage(int damageAmmount, bool isEnemy = false);

    virtual void die();

    int getHealth() const;

    const int getStats(std::string key);

    std::string HealCharacter(int amount);

    std::string RandomlyIncreaseStat(int amount);
};


