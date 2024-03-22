//
// Created by nhoge on 08/02/2024.
//

#include "EnemyC.h"
#include "../Elements/spriteObject.hpp"

EnemyC::EnemyC(std::string identifier, std::string spriteFile, int health, int attack, int defense, int dex,
               sf::Font &font, unsigned int fontSize, int randomStatIncr)
        : Character(identifier, spriteFile, health, attack, defense, dex, font, fontSize) {
    this->RandomlyIncreaseStat(randomStatIncr);

}

EnemyC::~EnemyC() {

}

void EnemyC::addFileName(std::string fileName) {

    imageFiles.push_back(fileName);
}

std::string EnemyC::onTurn(Character &c) {
    std::string feedback;
    int beautysleep = rand() % 100;
    if (beautysleep > 50) {
        return ("the enemy decided this was a good time to do nothing\n");
    }

    //am i doing any damage?
    if (this->getStats("Attack") - c.getStats("Defense") > 0) {
        feedback += c.takeDamage(this->getStats("Attack"));
        return feedback;
    } else {
        //feedback += "the enemy " + this->RandomlyIncreaseStat(1);
        //todo: find a easy way to make sure the enemy doesnt get overpowered.
        //without the function the enemy is too weak
        //now the enemy increases its stats but the player cant so they will be forever losing.
    }

    return feedback;
}

void EnemyC::die() {
    ammountDead++;

    clearStarts();

    if (ammountDead % 2 == 0) {
        level++;
    }

    stats["Health"] += level;
    currentHealth += level;

    int r = rand() % imageFiles.size();
    SetNewSprite(imageFiles[r]);

    //make it more difficult
    RandomlyIncreaseStat(2);

    printf_s("enemy stats :\nAttack: %d\nDefence: %d\nDex: %d\nHealth: %d\n",
             getStats("Attack"), getStats("Defense"), getStats("Dex"), getHealth());

}

const int EnemyC::getScore() {
    return ammountDead;
}