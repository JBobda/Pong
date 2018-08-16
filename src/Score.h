#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"
#include "Ball.h"

class Score{
    private:
        std::vector<Player*> players;
        uint playerOneScore;
        uint playerTwoScore;
        bool scoreUpdated;
    public:
        Score(Player& playerOne, Player& playerTwo);
        void update(Ball& ball);
        void display();

};

#endif //SCORE_H