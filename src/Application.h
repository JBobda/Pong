#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Player.h"
#include "InputHandler.h"
#include "Ball.h"
#include "GameObject.h"

class Application{
    private:
        sf::RenderWindow* window;
        InputHandler* inputHandler;
        GameObject* playerOne;
        GameObject* playerTwo;
        GameObject* ball;

        std::vector<GameObject*> gameObjects;
    public:
        Application(std::string title, int width, int height);

        void run();
        void update();
        void draw();
};

#endif //APPLICATION_H
