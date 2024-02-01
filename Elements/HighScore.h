
#ifndef WEEK6_HIGHSCORE_H
#define WEEK6_HIGHSCORE_H

#include "gameObject.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>


class HighScore { ;

private:

public:

    ~HighScore();

    void UpdateText();
    void DeleteData();
    void Default();
    void GetData();
    void render(sf::RenderWindow &window);

};


#endif //WEEK6_HIGHSCORE_H
