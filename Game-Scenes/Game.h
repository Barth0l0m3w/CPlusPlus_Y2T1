
#ifndef WEEK6_GAME_H
#define WEEK6_GAME_H

#include "../Elements/SceneHandler.hpp"
#include "../Elements/ScoreDisplay.h"


class Game {

private:

    bool fightScene = false;

public:

    SceneHandler *sceneHandler{};
    ScoreDisplay *scoreDisplay{};
    sf::RenderWindow *window{};

    void Start();
    void SwitchScene();
    void EraseData();
    void attack();

private:

    int counter = 0;

};


#endif //WEEK6_GAME_H
