#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "GameObject.h"

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
        void setCollision(bool collision) { collided = collision; }
        bool hasCollided(){ return collided;}
        sf::RectangleShape getBall() {return ball;}
        

};


#endif //BALL_H