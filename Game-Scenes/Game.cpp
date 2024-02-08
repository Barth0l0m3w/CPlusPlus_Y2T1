#include "Game.h"
#include <SFML/Graphics.hpp>
#include "scene.hpp"
#include "../Elements/spriteObject.hpp"
#include "../Elements/SceneHandler.hpp"
#include "../Elements/gameObject.hpp"
#include "../Elements/Button.h"
#include "../Elements/HighScore.h"
#include "../Elements/ScoreDisplay.h"
#include "../Game-Scenes/Battle.h"
#include "../Characters/PlayerC.h"
#include "../Characters/EnemyC.h"

void Game::Start() {

    /*    enum class StateMachine{
        sceneSwitching,
        closeApp,
        deleteData,
        attack,
        heal,
    };*/

    sf::Font font;
    if (!font.loadFromFile("fonds/SuperPlants.ttf")) {
        std::cout << "couldn't load font\n";
    }

    window = new sf::RenderWindow;
    window->create(sf::VideoMode(1280, 720), "name"); // change size to the correct one later

    Scene scene1("scene01");

    Button start("Start", "fonds/SuperPlants.ttf", 50, 1, *this);
    start.setPosition(sf::Vector2f(1100.0f, 30.0f));
    scene1.addGameObject(start);

    Button quit("Quit", "fonds/SuperPlants.ttf", 40, 2, *this);
    quit.setPosition(sf::Vector2f(1160.0f, 100.0f));
    scene1.addGameObject(quit);

    Button RemoveData("Erase High-scores", "fonds/SuperPlants.ttf", 30, 3, *this);
    RemoveData.setPosition(sf::Vector2f(950.0f, 650.0f));
    scene1.addGameObject(RemoveData);

    scoreDisplay = new
    ScoreDisplay("scoreDisplay", font, 30);
    scoreDisplay->setPosition(sf::Vector2f(20, 20));
    scene1.addGameObject(*scoreDisplay);

    Scene scene2("scene02");

    PlayerC player("player", "images/head.png", 5, 5, 5, 5,font, 14);
    printf_s("Character 2 Stats:\nAttack: %d\nDefence: %d\nSpeed: %d\nHP: %d\n",
             player.getStats("Attack"), player.getStats("Defence"), player.getStats("Speed"), player.getHealth());
    player.HealCharacter(50);
    player.setPosition(sf::Vector2f(250.0f, 250.0f));
    player.setScale(sf::Vector2f(4.0f, 4.0f));

    EnemyC enemy("enemy", "images/head_hurt.png", 5, 5, 5, 5, font, 14);
    enemy.addFileName("images/head_hurt");
    enemy.HealCharacter(50);
    enemy.setPosition(sf::Vector2f(1000.0f, 250.0f));
    enemy.setScale(sf::Vector2f(-4.0f, 4.0f)); //flip so he looks at him

    Button textArea("text", "fonds/SuperPlants.ttf", 20, 5, *this);
    textArea.setPosition(sf::Vector2f(400, 300));
    scene2.addGameObject(textArea);

    battle = new Battle("battle", player, enemy, textArea);
    battle->addGameObject(textArea);
    battle->addGameObject(player);
    battle->addGameObject(enemy);


    sceneHandler = new
    SceneHandler.addScene(scene1);
    sceneHandler.addScene(scene2);


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

void Game::EraseData(){

    scoreDisplay->EraseData();
}

void Game::attack() {

   /* if (fightScene) {
        switch (turn) {


        }
    }*/
}