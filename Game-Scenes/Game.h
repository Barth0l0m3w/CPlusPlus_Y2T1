#ifndef WEEK6_GAME_H
#define WEEK6_GAME_H

#include "../Elements/SceneHandler.hpp"
#include "../Elements/ScoreDisplay.h"
#include "../Game-Scenes/Battle.h"
#include "../library/timercpp.h"

class Game {

private:

    bool fightScene = false;
    int counter = 0;

    Timer timer;

public:

    SceneHandler *sceneHandler{};
    ScoreDisplay *scoreDisplay{};
    Battle *battle{};
    sf::RenderWindow *window{};

    void Start();

    void SwitchScene();

    void EraseData() const;

    void attack() const;

    void heal() const;

};


#endif //WEEK6_GAME_H
