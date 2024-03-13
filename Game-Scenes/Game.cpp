#include "Game.h"
#include <SFML/Graphics.hpp>
#include "scene.hpp"
#include "../Elements/spriteObject.hpp"
#include "../Elements/Button.h"
#include "../Characters/PlayerC.h"
#include "../Characters/EnemyC.h"
#include "../Elements/Animations.h"

void Game::Start() {

    sf::Font font;
    if (!font.loadFromFile("fonds/SuperPlants.ttf")) {
        std::cout << "couldn't load font\n";
    }

    sf::Font textF;
    if (!textF.loadFromFile("fonds/Text.otf")) {
        std::cout << "couldn't load font\n";
    }

    window = new sf::RenderWindow;
    window->create(sf::VideoMode(1280, 720), "name"); // change size to the correct one later

    //all the elements from main menu
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

    scoreDisplay = new ScoreDisplay("scoreDisplay", font, 30);
    scoreDisplay->setPosition(sf::Vector2f(20, 20));
    scene1.addGameObject(*scoreDisplay);

    //loading screen
    Scene scene2("scene02");

    Animations animation1("move dino", "Images/move.png", 24, 24, 1, 0);
    animation1.setPosition(sf::Vector2f(290, 200));
    animation1.setScale(sf::Vector2f(10.0f, 10.0f));
    scene2.addGameObject(animation1);

    Animations animation2("move dino", "Images/crack.png", 24, 24, 1, 0);
    animation2.setPosition(sf::Vector2f(500, 200));
    animation2.setScale(sf::Vector2f(10.0f, 10.0f));
    scene2.addGameObject(animation2);

    Animations animation3("move dino", "Images/hatch.png", 24, 24, 1, 0);
    animation3.setPosition(sf::Vector2f(700, 200));
    animation3.setScale(sf::Vector2f(10.0f, 10.0f));
    scene2.addGameObject(animation3);

    //all the elements from battle scene
    PlayerC player("player", "Images/loki.png", 6, 6, 6, 6, font, 14, 10);
    printf_s("player stats :\nAttack: %d\nDefence: %d\nDex: %d\nHealth: %d\n",
             player.getStats("Attack"), player.getStats("Defense"), player.getStats("Dex"), player.getHealth());
    player.HealCharacter(50);
    player.setPosition(sf::Vector2f(250.0f, 200.0f));
    player.setScale(sf::Vector2f(10.0f, 10.0f));

    EnemyC enemy("enemy", "images/cole.png", 2, 2, 2, 2, font, 14, 0);
    printf_s("enemy stats :\nAttack: %d\nDefence: %d\nDex: %d\nHealth: %d\n",
             enemy.getStats("Attack"), enemy.getStats("Defense"), enemy.getStats("Dex"), enemy.getHealth());
    enemy.HealCharacter(50);
    enemy.setPosition(sf::Vector2f(800.0f, 200.0f));
    enemy.setScale(sf::Vector2f(10.0f, 10.0f));

    //enemy images
    enemy.addFileName("images/cole.png");
    enemy.addFileName("images/doux.png");
    enemy.addFileName("images/kuro.png");
    enemy.addFileName("images/mort.png");
    enemy.addFileName("images/olaf.png");
    enemy.addFileName("images/sena.png");

    Button quit2("Quit!", "fonds/SuperPlants.ttf", 40, 2, *this);
    quit2.setPosition(sf::Vector2f(1140.0f, 30.0f));

    Button menu("Menu", "fonds/SuperPlants.ttf", 40, 1, *this);
    menu.setPosition(sf::Vector2f(30.0f, 30.0f));

    Button attack("Attack", "fonds/SuperPlants.ttf", 40, 4, *this);
    attack.setPosition(sf::Vector2f(30.0f, 500.0f));

    Button heal("heal", "fonds/SuperPlants.ttf", 40, 5, *this);
    heal.setPosition(sf::Vector2f(30.0f, 550.0f));

    Button textArea("", "fonds/Text.otf", 20, 351, *this);
    textArea.setPosition(sf::Vector2f(350, 550));

    battle = new Battle("battle", player, enemy, textArea);
    battle->addGameObject(textArea);
    battle->addGameObject(player);
    battle->addGameObject(enemy);
    battle->addGameObject(quit2);
    battle->addGameObject(menu);
    battle->addGameObject(attack);
    battle->addGameObject(heal);


    sceneHandler = new SceneHandler();
    sceneHandler->addScene(scene1);
    sceneHandler->addScene(scene2);
    sceneHandler->addScene(*battle);


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

        timer.setTimeout([&]() {
            sceneHandler->stackScene("battle");
        }, 3000);

        counter++;
    } else {
        sceneHandler->stackScene("scene01");
        counter--;
    }
}

void Game::EraseData() const {

    scoreDisplay->EraseData();
}

void Game::attack() const {

    battle->attack();

}

void Game::heal() const {
    battle->heal();
}