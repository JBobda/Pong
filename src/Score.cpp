#include "Score.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <sstream>

Score::Score(Player& playerOne, Player& playerTwo)
    :sstream(){
    players.push_back(&playerOne);
    players.push_back(&playerTwo);
    playerOneScore = players[0]->getPoints();
    playerTwoScore = players[1]->getPoints();
    winnerExists = false;

    //Creates Font for the score
    if(!font.loadFromFile("res/block.ttf")){
        std::cerr << "There was an error loading the font" << std::endl;
        std::exit(1);
    }


    //Sets up the score
    sstream << playerOneScore << " | " << playerTwoScore;

    score.setFont(font);
    score.setString(sstream.str().c_str());
    score.setCharacterSize(34);
    score.setPosition({500 - score.getGlobalBounds().width/2, 0});
    score.setColor(sf::Color::White);
}

void Score::update(Ball& ball){
    if(!(ball.inBounds(ball.getPosition().x, 1000 - ball.getBall().getSize().x, ball.getVelocity().x, 0))){
        //Gives point to the player deserving of it
        if(ball.getPosition().x > 500) players[0]->addPoint();
        if(ball.getPosition().x < 500) players[1]->addPoint();

        //Updates the score variables
        playerOneScore = players[0]->getPoints();
        playerTwoScore = players[1]->getPoints();

        //Sets the ball's position back to middle of the window
        ball.setPosition((1000/2) - (ball.getBall().getSize().x/2)
            ,((1000*9/16)/2) - (ball.getBall().getSize().y/2));

        //Sets the ball's velocity back to a normal speed and a new direction
        float newVel = 0;
        if(ball.getVelocity().x < 0) newVel = -2.f;
        else newVel = 2.f;
        ball.setVelocity(-1 * newVel , ball.generateDirection().x * 2.f);

        //Updates the score in the sstream variable
        sstream.str("");
        sstream << playerOneScore << " | " << playerTwoScore;

        if(playerOneScore >= 10){
            sstream.str("");
            sstream << "Player One Wins!";
            winnerExists = true;
            playerOneScore = 0;
            playerTwoScore = 0;
        }else if(playerTwoScore >= 10){
            sstream.str("");
            sstream << "Player Two Wins!";
            winnerExists = true;
            playerOneScore = 0;
            playerTwoScore = 0;
        }
    }
}

void Score::draw(sf::RenderWindow& window){
    score.setString(sstream.str().c_str());
    score.setPosition({500 - score.getGlobalBounds().width/2, 0});
    window.draw(score);
}

void Score::display(){
    if(winnerExists){
        winnerExists = false;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::exit(0);
    }
}