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
    public:
        Score(Player& playerOne, Player& playerTwo);
        void keepScore(Ball& ball);

};

#endif //SCORE_H