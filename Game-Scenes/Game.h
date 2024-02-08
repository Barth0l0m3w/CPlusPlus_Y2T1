
#ifndef WEEK6_GAME_H
#define WEEK6_GAME_H

#include "../Elements/SceneHandler.hpp"
#include "../Elements/ScoreDisplay.h"
#include "../Game-Scenes/Battle.h"


class Game {

private:

    bool fightScene = false;

public:

    SceneHandler& sceneHandler;

    Battle *battle{};
    ScoreDisplay *scoreDisplay{};
    sf::RenderWindow *window{};

    void Start();
    void SwitchScene();
    void EraseData();
    void attack();

private:

    int counter = 0;

    void SwitchScene(SceneHandler &sceneHandler);
};


#endif //WEEK6_GAME_H
