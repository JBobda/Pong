#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Ball : public GameObject{
    private:
        bool collided;
        int width;
        int height;
        float xPos;
        float yPos;
        float xVelocity;
        float yVelocity;
    public:
        sf::RectangleShape* ball;
    public:
        Ball(int width, int height);
        ~Ball();
        //Overriden methods from the Game Object class
        void update(InputHandler& inputHandler) override;
        void draw(sf::RenderWindow& window) override;

        //Ball Specific Methods
        bool inBounds(float start, float max, float add, float min);
        void setCollision(bool collision) { collided = collision; }
        bool hasCollided(){ return collided;}
        

};


#endif //BALL_H