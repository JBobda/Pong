#include "Ball.h"

Ball::Ball(int width, int height){
    this->width = width;
    this->height = height;
    ball = new sf::RectangleShape(sf::Vector2f(width, height));
    xPos = (1000/2) - (width/2);
    yPos = ((1000*9/16)/2) - (height/2);
    ball->setPosition(sf::Vector2f(xPos, yPos));

    xVelocity = 0.15f;
    yVelocity = 0.15f;
}

Ball::~Ball(){

}

void Ball::update(InputHandler& inputHandler){
    if(inBounds(xPos, 1000-width, xVelocity, 0)) xVelocity *= 1;
    else{
        if(xVelocity < 0) xVelocity -= 0.05f;
        else xVelocity += 0.01f;
        xVelocity *= -1;
    }
    xPos = xPos + xVelocity;
    if(inBounds(yPos, 1000*9/16-height, yVelocity, 0)) yVelocity *= 1;
    else{
        if(yVelocity < 0) yVelocity -= 0.05f;
        else yVelocity += 0.01f; 
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

