#include <SFML/Graphics.hpp>

#include "scene.hpp"
#include "spriteObject.hpp"
#include "sceneHandler.hpp"
#include "GameObject.hpp"
#include "Button.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML with Scenes!");


    //sf::Font font;
    //font.loadFromFile("fonds/SuperPlants.ttf");


    Scene scene1("scene01");

    SpriteObject sprite1("soldierSprite", "Images/head.png");
    sprite1.setPosition(sf::Vector2f(70.0f, 70.0f));
    sprite1.setScale(sf::Vector2f(5.0f, 5.0f));
    scene1.addGameObject(sprite1);

    Button test("click me", "fonds/SuperPlants.ttf", "Images/head.png");
    scene1.addGameObject(test);

    Scene scene2("scene02");

    SpriteObject sprite2("soldierSprite", "Images/head_hurt.png");
    sprite2.setPosition(sf::Vector2f(70.0f, 70.0f));
    sprite2.setScale(sf::Vector2f(5.0f, 5.0f));
    scene2.addGameObject(sprite2);

    /*SpriteObject sprite3("soldierSprite", "Images/small.png");
    sprite3.setPosition(sf::Vector2f(70.0f, 70.0f));
    sprite3.setScale(sf::Vector2f(1.0f, 1.0f));
    sprite2.AddChildren(sprite3);*/

    SceneHandler handler;
    handler.addScene(scene1);
    handler.addScene(scene2);



    int counter = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased) {
                /*if (event.key.code == sf::Keyboard::R) {
                    sprite2.RemoveChildren(sprite3);
                }*/

                if (event.key.code == sf::Keyboard::A) {
                    /*if (counter == 0) {
                        handler.stackScene("scene02");
                        counter++;
                    } else {
                        handler.popScene();
                        counter--;
                    }*/
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (test.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    test.onClick();
                    if (counter == 0) {
                        handler.stackScene("scene02");
                        counter++;
                    } else {
                        handler.popScene();
                        counter--;
                    }
                }
            }
        }


        window.clear();
        handler.update();
        handler.render(window);
        window.display();
    }

    return 0;
}





