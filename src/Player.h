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
        sf::RectangleShape paddle;
        Position position;
        unsigned int points;
        float width;
        float height;
        float xPos;
        float yPos;
        float xVelocity;
        float yVelocity;
    public:
        Player(float width, float height, Position position);
        ~Player();

        //Overriden Methods from the Game Object abstract class
        void update(InputHandler& inputHandler) override;
        void draw(sf::RenderWindow& window) override;

        //Methods exclusive to the player class
        void addPoint();
        unsigned int getPoints() { return points;}
        sf::RectangleShape getPaddle() {return paddle;}
    

        
};

#endif //PLAYER_H