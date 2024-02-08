#ifndef WEEK6_BATTLE_H
#define WEEK6_BATTLE_H

#include "scene.hpp"


class Character;

class PlayerC;

class EnemyC;

class Button;

class HighScore;

class Battle : public Scene {

private:
    bool gameOver;
    Button &text;
    PlayerC &player;
    EnemyC &enemy;
    HighScore &highScore;
    std::string feedback;

    void printFeedback();

public:

    Battle(std::string identifier, PlayerC &p, EnemyC &e, Button &t);

    ~Battle();

    void update() override;

    void attack();

    void heal();

    void nothing();
};


#endif //WEEK6_BATTLE_H
