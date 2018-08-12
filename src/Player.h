#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "InputHandler.h"

enum Position{
    RIGHT,
    LEFT
};

class Player{
    private:
        sf::RectangleShape* paddle;
        Position position;
        int width;
        int height;
        float xPos;
        float yPos;
        float xVelocity;
        float yVelocity;
    public:
        Player(int width, int height, Position position);
        void update(InputHandler& inputHandler);
        void draw(sf::RenderWindow& window);

        
};

#endif //PLAYER_H