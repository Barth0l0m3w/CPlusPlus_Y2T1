//
// Created by nhoge on 08/02/2024.
//

#ifndef WEEK6_ENEMYC_H
#define WEEK6_ENEMYC_H

#include "character.hpp"
#include <map>


class EnemyC : public Character {

private:
    std::vector<std::string> imageFiles;
    int ammountDead = 0;

public:

    EnemyC(std::string identifier, std::string spriteFile, int health, int attack, int defense, int dex, sf::Font &font, unsigned int fontSize, int randomStatIncr);

    ~EnemyC();

    void addFileName(std::string fileName);

    std::string onTurn(Character &c);

    void die() override;

    const int getScore();

};


#endif //WEEK6_ENEMYC_H
