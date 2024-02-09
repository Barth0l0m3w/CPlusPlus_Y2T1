//
// Created by nhoge on 08/02/2024.
//

#include "PlayerC.h"

PlayerC::PlayerC(std::string identifier, std::string spriteFile, int health, int attack, int defense, int dex, sf::Font &font, unsigned int fontSize, int randomStatIncr) :
        Character(identifier, spriteFile, health, attack, defense, dex, font, fontSize)
{
    this->RandomlyIncreaseStat(randomStatIncr);
}

PlayerC::~PlayerC() {

}

std::string PlayerC::levelUp(int currentScore) {
    std::string feedback;

    if (currentScore != finalScore && currentScore % 3 == 0) {
        level++;
        currentHealth = currentHealth++;
        stats["Health"] = stats["Health"]++;
        feedback += "\nlevel up! (+1 Health)";
        finalScore = currentScore;
    }
    return feedback;

}

void PlayerC::die() {
    isDead = true;
}
