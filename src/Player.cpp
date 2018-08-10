#include "Player.h"

//This is the constructor that creates the players and positions them
Player::Player(int width, int height, Position position){
    paddle = new sf::RectangleShape(sf::Vector2f(width, height));

    if(position == Position::LEFT){
        paddle->setPosition(0, 250);
    }else{
        paddle->setPosition(1000-width, 250);
    }
}

//This function draws the Player to the window that is provided
void Player::draw(sf::RenderWindow& window){
    window.draw(*paddle);
}

//This Function updates the players position based on input
void Player::update(){

}