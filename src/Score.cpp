#include "Score.h"
#include <iostream>

Score::Score(Player& playerOne, Player& playerTwo){
    players.push_back(&playerOne);
    players.push_back(&playerTwo);
}

void Score::keepScore(Ball& ball){
    if(!(ball.inBounds(ball.getPosition().x, 1000 - ball.getBall().getSize().x, ball.getVelocity().x, 0))){
        if(ball.getPosition().x > 500) players[0]->addPoint();
        if(ball.getPosition().x < 500) players[1]->addPoint();
        std::cout << "Player One Score: " << players[0]->getPoints() << " ";
        std::cout << "Player Two Score: " << players[1]->getPoints() << "\n";


        ball.setPosition((1000/2) - (ball.getBall().getSize().x/2)
            ,((1000*9/16)/2) - (ball.getBall().getSize().y/2));
    }
}