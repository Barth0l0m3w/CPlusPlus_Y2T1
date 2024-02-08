#include "character.hpp"
#include <stdlib.h>
#include <algorithm>

Character::Character(std::string identifier, std::string spriteFile, int health,
                     int attack, int defense, int dex, sf::Font &font, unsigned int fontSize) : SpriteObject(identifier,
                                                                                                             spriteFile) {

    this->stats["Attack"] = attack;
    this->stats["Defense"] = defense;
    this->stats["Health"] = health;
    this->stats["Dex"] = dex;
    this->currentHealth = health;

    this->healthText = sf::Text();
    this->healthText.setFont(font);
    this->healthText.setFillColor(sf::Color::White);

}

Character::~Character() {

}

void Character::clearStarts() {
    auto mapIterator = stats.begin();
    while (mapIterator != stats.end()) {
        mapIterator->second = 4;
        mapIterator++;
    }
    currentHealth = stats["Health"];
}

std::string Character::HealCharacter(int amount) {
    if (currentHealth + amount <= stats["Health"]) {
        currentHealth += amount;
    } else {
        currentHealth = stats["Health"];
    }
    return "\n You healed yourself\n";
}

std::string Character::takeDamage(int damageAmmount, bool isEnemy) {
    std::string feedback;
    int totalDamage = damageAmmount - stats["Defense"];

    if (totalDamage <= 0) {
        return isEnemy ? "you attacked \nThem enemy took no damage\n "
                         "(your attack: " + std::to_string(damageAmmount) +
                         " enemy defence: " + std::to_string(stats["Defense"]) +
                         ")\n" : "the enemy attacked\n you took no damage\n";
    }
    this->currentHealth -= totalDamage;
    feedback += isEnemy ? "the enemy took " + std::to_string(totalDamage) + " damage\n"
                        : "you took" + std::to_string(totalDamage) + " damage\n";

    if (currentHealth <= 0) {
        die();
        feedback += isEnemy ? "and died\n a new dinosour has taken the stage\n"
                            : "and died\n";
    }
    return feedback;
}

std::string Character::RandomlyIncreaseStat(int amount) {
    std::string feedback;
    for (int i = 0; i < amount; i++) {
        int outcome = rand() % stats.size();
        auto mapIterator = stats.begin();
        for (size_t j = 0; j < outcome; j++) {
            mapIterator++;
        }
        if (mapIterator->first != "Health") {
            mapIterator->second++;
            feedback += mapIterator->first + "stat increased by one. for a total of: " +
                        std::to_string(mapIterator->second) + "\n";
        } else {
            amount++;
        }
    }
    return feedback;
}


void Character::die() {
    //empty because the children will have a different approach
}

int Character::getHealth() const {
    return currentHealth;
}

const int Character::getStats(std::string key) {
    if (stats.find(key) == stats.end()) {
        return -1;
    } else {
        return this->stats[key];
    }
}

void Character::render(sf::RenderWindow &window) {
    SpriteObject::render(window);
    sf::Vector2f pos = getPosition();
    healthText.setPosition(sf::Vector2f(pos.x, pos.y - 50));
    healthText.setString("lvl: " + std::to_string(level) + "\n"+
                         "Health: " + std::to_string(currentHealth) +
                         "/" + std::to_string(stats["Health"]));
    window.draw(healthText);

}







