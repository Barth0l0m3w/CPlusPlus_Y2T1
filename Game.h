
#ifndef WEEK6_GAME_H
#define WEEK6_GAME_H

#include "sceneHandler.hpp"


class Game {

private:

    bool fightScene = false;

public:

    SceneHandler *sceneHandler{};
    sf::RenderWindow *window{};

    void Start();
    void SwitchScene();
    void attack();

private:

    int counter = 0;

};


#endif //WEEK6_GAME_H
