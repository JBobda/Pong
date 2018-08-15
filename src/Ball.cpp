#include "Ball.h"
#include <iostream>

Ball::Ball(int width, int height){
    this->width = width;
    this->height = height;
    ball = new sf::RectangleShape(sf::Vector2f(width, height));
    collided = false;
    xPos = (1000/2) - (width/2);
    yPos = ((1000*9/16)/2) - (height/2);
    ball->setPosition(sf::Vector2f(xPos, yPos));

    xVelocity = 0.15f;
    yVelocity = 0.15f;
}

Ball::~Ball(){
    delete ball;
}

void Ball::update(InputHandler& inputHandler){
    
    if(hasCollided() && inBounds(xPos, 1000 - width, xVelocity, 0)){    
        //Handles the acceleration of the ball in the x direction   
        if(xVelocity < 0) xVelocity -= 0.01f;    
        else xVelocity += 0.01f;
        //Handles the bouncing of the ball in the x direction
        xVelocity *= -1;
        setCollision(false);
        
    }else {
        xVelocity *= 1;
    }
    xPos = xPos + xVelocity;


    if(inBounds(yPos, 1000*9/16-height, yVelocity, 0)) yVelocity *= 1;
    else{
        //Handles the acceleration of the ball in the y direction
        if(yVelocity < 0) yVelocity -= 0.01f;
        else yVelocity += 0.01f; 
        //Handles the bouncing of the ball in the y direction
        yVelocity *= -1;
    }
    yPos = yPos + yVelocity;

    ball->setPosition(sf::Vector2f(xPos, yPos));
}

void Ball::draw(sf::RenderWindow& window){
    window.draw(*ball);
}

bool Ball::inBounds(float start, float max, float add, float min){
    if(start + add > max) return false;
    if(start + add < min) return false;

    return true;
}

