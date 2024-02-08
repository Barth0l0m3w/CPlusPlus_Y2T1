#include "Battle.h"
#include "../Elements/Button.h"
#include "../Characters/PlayerC.h"
#include "../Characters/EnemyC.h"
#include "../Characters/character.hpp"
#include "../Elements/HighScore.h"


Battle::Battle(std::string identifier, PlayerC &p, EnemyC &e, Button &t)
        : Scene(identifier), player(p), enemy(e), text(t), highScore(highScore) {

}

Battle::~Battle() {

}

void Battle::printFeedback() {
    text.setText(feedback);
}

void Battle::update() {
    Scene::update();

    if (gameOver) {
        return;
    }

    if (player.isDead) {
        gameOver = true;

        std::vector<int> scores = highScore.getHighScore();
        int newScore = enemy.getScore();

        feedback = "you have died\n Game over. the score you got is " +
                   std::to_string(newScore);

        if (scores.size() > 0) {
            feedback += "highscore: " + std::to_string(scores[0]);
        } else {
            feedback += "there has been no new highscore set";
        }

        feedback += "you can now go back to main menu or quit";

        if (scores.size() <= 0) {
            scores.push_back(newScore);
            feedback += "yay, you made the scoreboard";

        } else {
            for (size_t i = 0; i < scores.size(); ++i) {
                if (newScore > scores[i]) {
                    auto pos = scores.begin();
                    scores.insert(pos, newScore);
                    feedback += "yay, you made the scoreboard";
                    break;
                }
            }
        }

        highScore.UpdateText(scores);
        printFeedback();
    }
}

void Battle::attack() {
    if (gameOver) {
        return;
    }

    feedback = "";

    if (player.getStats("Dex") > enemy.getStats("Dex")) {
        feedback += enemy.takeDamage(player.getStats("Attack"), true);
        feedback += enemy.onTurn(player);

    } else {
        feedback += enemy.onTurn(player);
        feedback += enemy.takeDamage(player.getStats("Attack"), true);
    }

    feedback += player.levelUp(enemy.getScore());
    printFeedback();

}

void Battle::heal() {
    if (gameOver) {

        return;
    }
    feedback = "";
    if (player.getStats("Dex") > enemy.getStats("Dex")) {
        feedback += player.HealCharacter(2);
        feedback += enemy.onTurn(player);
    } else {
        feedback += enemy.onTurn(player);
        feedback += player.HealCharacter(2);
    }
    printFeedback();
}

void Battle::nothing() {
    if (gameOver) {
        return;
    }
    feedback = "";
    feedback += "You snooze, you feel a little refreshed\n";
    feedback += enemy.onTurn(player);
    printFeedback();
}
