#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball{
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
        void update();
        void draw(sf::RenderWindow& window);
        bool inBounds(float start, float max, float add, float min);
        

};


#endif //BALL_H