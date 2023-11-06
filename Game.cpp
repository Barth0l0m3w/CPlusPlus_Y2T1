#include "Game.h"
#include <SFML/Graphics.hpp>
#include "scene.hpp"
#include "spriteObject.hpp"
#include "sceneHandler.hpp"
#include "gameObject.hpp"
#include "Button.h"

void Game::Start() {

    window = new sf::RenderWindow;
    window->create(sf::VideoMode(400, 400), "name"); // change size to the correct one later

    Scene scene1("scene01");

    SpriteObject sprite1("soldierSprite", "Images/head.png");
    sprite1.setPosition(sf::Vector2f(70.0f, 70.0f));
    sprite1.setScale(sf::Vector2f(5.0f, 5.0f));
    scene1.addGameObject(sprite1);

    Button test("click me", "fonds/SuperPlants.ttf", 1, *this);
    test.setPosition(sf::Vector2f(40.0f, 20.0f));
    scene1.addGameObject(test);

    Scene scene2("scene02");

    SpriteObject sprite2("soldierSprite", "Images/head_hurt.png");
    sprite2.setPosition(sf::Vector2f(70.0f, 70.0f));
    sprite2.setScale(sf::Vector2f(5.0f, 5.0f));
    scene2.addGameObject(sprite2);

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
    } else {
        sceneHandler->popScene();
        counter--;
    }
}