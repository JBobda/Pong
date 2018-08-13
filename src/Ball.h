#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Ball : public GameObject{
    private:
        sf::RectangleShape* ball;
        int width;
        int height;
        float xPos;
        float yPos;
        float xVelocity;
        float yVelocity;
    public:
        Ball(int width, int height);
        ~Ball();
        void update(InputHandler& inputHandler) override;
        void draw(sf::RenderWindow& window) override;
        bool inBounds(float start, float max, float add, float min);
        

};


#endif //BALL_H