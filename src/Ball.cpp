#include "Ball.h"
#include <iostream>

Ball::Ball(float width, float height)
    :ball({width, height}){

    this->width = width;
    this->height = height;
    collided = false;
    xPos = (1000/2) - (width/2);
    yPos = ((1000*9/16)/2) - (height/2);
    ball.setPosition(sf::Vector2f(xPos, yPos));

    xVelocity = 2.f;
    yVelocity = 2.f;
}

Ball::~Ball(){}

void Ball::update(InputHandler& inputHandler){
    //TODO
    
    if(hasCollided()){    
        //Handles the acceleration of the ball in the x direction   
        if(xVelocity < 0) xVelocity -= 0.35f;    
        else xVelocity += 0.35f;
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
        if(yVelocity < 0) yVelocity -= 0.35f;
        else yVelocity += 0.35f; 
        //Handles the bouncing of the ball in the y direction
        yVelocity *= -1;
    }
    yPos = yPos + yVelocity;

    ball.setPosition(sf::Vector2f(xPos, yPos));
}

void Ball::draw(sf::RenderWindow& window){
    window.draw(ball);
}

bool Ball::inBounds(float start, float max, float add, float min){
    if(start + add > max) return false;
    if(start + add < min) return false;

    return true;
}

