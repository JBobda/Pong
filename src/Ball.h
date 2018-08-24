#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "GameObject.h"
#include "Player.h"

class Ball : public GameObject{
    private:
        sf::RectangleShape ball;
        bool collided;
        float width;
        float height;
        float xPos;
        float yPos;
        float xVelocity;
        float yVelocity;
    public:
        Ball(float width, float height);
        ~Ball();

        //Overriden methods from the Game Object class
        void update(InputHandler& inputHandler) override;
        void draw(sf::RenderWindow& window) override;

        //Ball Specific Methods
        bool inBounds(float start, float max, float add, float min);
        bool hasCollided(){ return collided;}

        void setCollision(bool collision) { collided = collision; }
        void setPosition(float xPos, float yPos){ this->xPos = xPos; this->yPos = yPos;}
        void setVelocity(float xVel, float yVel){xVelocity = xVel; yVelocity = yVel;}

        sf::Vector2i generateDirection();
        sf::Vector2f getPosition() {return sf::Vector2f{xPos, yPos}; }
        sf::Vector2f getVelocity() { return sf::Vector2f{xVelocity, yVelocity}; }
        
        sf::RectangleShape getBall() {return ball;}
        

};


#endif //BALL_H