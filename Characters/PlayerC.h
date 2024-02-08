//
// Created by nhoge on 08/02/2024.
//

#ifndef WEEK6_PLAYERC_H
#define WEEK6_PLAYERC_H

#include "character.hpp"

class PlayerC : public Character {

private:
    int finalScore;

public:
    bool isDead;

    PlayerC(std::string identifier, std::string spriteFile,
            int health, int attack, int defense, int dex, sf::Font &font, unsigned int fontSize);

    ~PlayerC();

    std::string levelUp(int finalScore);

    void die() override;

};


#endif //WEEK6_PLAYERC_H
