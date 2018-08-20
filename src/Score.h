#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>

#include "Player.h"
#include "Ball.h"

class Score{
    private:
        sf::Text score;
        sf::Font font;
        std::stringstream sstream;
        std::vector<Player*> players;
        uint playerOneScore;
        uint playerTwoScore;
    public:
        Score(Player& playerOne, Player& playerTwo);
        void update(Ball& ball);
        void display(sf::RenderWindow& window);

};

#endif //SCORE_H