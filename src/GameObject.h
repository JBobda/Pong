#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

#include "InputHandler.h"

class GameObject{
    public:
    GameObject(){}
    virtual ~GameObject(){}
    void virtual update(InputHandler& inputHandler) = 0;
    void virtual draw(sf::RenderWindow& window) = 0;
};

#endif //GAME_OBJECT_H