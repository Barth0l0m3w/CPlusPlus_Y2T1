#include "Battle.h"
#include "../Elements/Button.h"
#include "../Characters/PlayerC.h"
#include "../Characters/EnemyC.h"

#include "../Elements/ScoreDisplay.h"


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

        feedback = "You have died, GAME OVER. \nThe score you got is " +
                   std::to_string(newScore);

        if (scores.size() > 0) {
            feedback += "\nHighscore: " + std::to_string(scores[0]);
        } else {
            feedback += "\nThere has been no new highscore set";
        }

        if (scores.size() <= 0) {
            scores.push_back(newScore);
            feedback += "Yay, you made the scoreboard";

        } else {
            for (size_t i = 0; i < scores.size(); ++i) {
                if (newScore > scores[i]) {
                    auto pos = scores.begin();
                    scores.insert(pos, newScore);
                    feedback += "\nYay, you made the scoreboard";
                    break;
                } else if (scores.size() < 5) {
                    scores.push_back(newScore);
                    break;
                }
            }
        }

        feedback += "\nGo away now. Nothing here for you to see";

        highScore.UpdateText(scores);
        highScore.getHighScore();

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

    //dex player > enemy == player turn first
    if (player.getStats("Dex") > enemy.getStats("Dex")) {
        feedback += player.HealCharacter(2);
        feedback += enemy.onTurn(player);
    } else {
        feedback += enemy.onTurn(player);
        feedback += player.HealCharacter(2);
    }
    printFeedback();
}
/*
void Battle::nothing() {
    if (gameOver) {
        return;
    }
    feedback = "";
    feedback += "You snooze, you feel a little refreshed\n";
    feedback += enemy.onTurn(player);
    printFeedback();
}*/
