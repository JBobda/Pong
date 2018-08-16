#include "Score.h"
#include <iostream>

Score::Score(Player& playerOne, Player& playerTwo){
    players.push_back(&playerOne);
    players.push_back(&playerTwo);

    scoreUpdated = false;
}

void Score::update(Ball& ball){
    if(!(ball.inBounds(ball.getPosition().x, 1000 - ball.getBall().getSize().x, ball.getVelocity().x, 0))){
        if(ball.getPosition().x > 500) players[0]->addPoint();
        if(ball.getPosition().x < 500) players[1]->addPoint();

        playerOneScore = players[0]->getPoints();
        playerTwoScore = players[1]->getPoints();

        ball.setPosition((1000/2) - (ball.getBall().getSize().x/2)
            ,((1000*9/16)/2) - (ball.getBall().getSize().y/2));
        scoreUpdated = true;
    }
}

void Score::display(){
    if(scoreUpdated){
        std::cout << "Player One Score: " << playerOneScore << " ";
        std::cout << "Player Two Score: " << playerTwoScore << "\n";
        scoreUpdated = false;
    }
}