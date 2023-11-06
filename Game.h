
#ifndef WEEK6_GAME_H
#define WEEK6_GAME_H

#include "sceneHandler.hpp"


class Game {

public:

    SceneHandler *sceneHandler;
    sf::RenderWindow *window;

    void Start();
    void SwitchScene();

private:

    int counter = 0;

};


#endif //WEEK6_GAME_H
