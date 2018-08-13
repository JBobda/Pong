#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "InputHandler.h"
#include "GameObject.h"

enum Position{
    RIGHT,
    LEFT
};

class Player : public GameObject{
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
        ~Player();
        void update(InputHandler& inputHandler) override;
        void draw(sf::RenderWindow& window) override;

        
};

#endif //PLAYER_H