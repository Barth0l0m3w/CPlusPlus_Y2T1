#include "Game.h"
#include <SFML/Graphics.hpp>
#include "scene.hpp"
#include "../Elements/spriteObject.hpp"
#include "../Elements/sceneHandler.hpp"
#include "../Elements/gameObject.hpp"
#include "../Elements/Button.h"
#include "../Elements/HighScore.h"

void Game::Start() {

    /*    enum class StateMachine{
        sceneSwitching,
        closeApp,
        deleteData,
        attack,
        heal,
    };*/

    window = new sf::RenderWindow;
    window->create(sf::VideoMode(1280, 720), "name"); // change size to the correct one later

    Scene scene1("scene01");

    Character character("Dude", "images/head.png", 10, 2, 2);
    SpriteObject characterAvatar("soldierSprite", character.getSpriteFile());
    characterAvatar.setPosition(sf::Vector2f(135.0f, 90.0f));
    characterAvatar.setScale(sf::Vector2f(2.5f, 2.5f));
    scene1.addGameObject(characterAvatar);

    Button test("click me", "fonds/SuperPlants.ttf", 1, *this);
    test.setPosition(sf::Vector2f(50.0f, 50.0f));
    scene1.addGameObject(test);


    Scene scene2("scene02");

    sceneHandler = new SceneHandler();
    sceneHandler->addScene(scene1);
    sceneHandler->addScene(scene2);


    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear();
        sceneHandler->update();
        sceneHandler->render(*window);
        window->display();
    }
}

void Game::SwitchScene() {

    if (counter == 0) {
        sceneHandler->stackScene("scene02");
        counter++;
        fightScene = true;
    } else {
        sceneHandler->popScene();
        counter--;
    }
}

void Game::attack() {

   /* if (fightScene) {
        switch (turn) {


        }
    }*/
}