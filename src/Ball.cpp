#include "Ball.h"

Ball::Ball(float width, float height)
    :ball({width, height}){

    this->width = width;
    this->height = height;
    collided = false;
    xPos = (1000/2) - (width/2);
    yPos = ((1000*9/16)/2) - (height/2);
    ball.setPosition(sf::Vector2f(xPos, yPos));

    xVelocity = 0.15f;
    yVelocity = 0.15f;
}

Ball::~Ball(){}

void Ball::update(InputHandler& inputHandler){
    /* SCORING SYSTEM
    //TODO
    if(!inBounds(xPos, 1000 - width, xVelocity, 0)){
        if(xPos > 500) 
        if(xPos < 500)
    }
    */
    if(hasCollided()){    
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

