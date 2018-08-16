#include "Player.h"

//This is the constructor that creates the players and positions them
Player::Player(float width, float height, Position position)
    :paddle({width, height}){

    this->position = position;
    this->width = width;
    this->height = height;

    points = 0;
    xVelocity = 0.65f;
    yVelocity = 0.65f;

    if(position == Position::LEFT){
        xPos = 0;
        yPos = 250;
        paddle.setPosition(0, 250);
    }else{
        xPos = 1000-width;
        yPos = 250;
        paddle.setPosition(1000-width, 250);
    }
}

Player::~Player(){}

//This Function updates the players position based on input
void Player::update(InputHandler& inputHandler){
    switch(position){
        case LEFT:
            //In the case of Player One Pressing up
            if(inputHandler.wTyped == true && yPos > 0)
                yPos = yPos - yVelocity;

            //In the case of Player One Pressing down
            if(inputHandler.sTyped == true && yPos < (1000*9/16) - height)
                yPos = yPos + yVelocity;

            break;
        case RIGHT:
            //In the case of Player Two Pressing up
            if(inputHandler.upTyped == true && yPos > 0)
                yPos = yPos - yVelocity;

            //In the case of Player Two Pressing Down
            if(inputHandler.downTyped == true && yPos < (1000*9/16) - height)
                yPos = yPos + yVelocity;

            break;
    }

    paddle.setPosition(sf::Vector2f(xPos, yPos));
}

//This function draws the Player to the window that is provided
void Player::draw(sf::RenderWindow& window){
    window.draw(paddle);
}

void Player::addPoint(){
    points++;
}