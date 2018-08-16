#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Player.h"
#include "InputHandler.h"
#include "Ball.h"
#include "GameObject.h"
#include "Score.h"

class Application{
    private:
        sf::RenderWindow window;
        InputHandler inputHandler;
        Player playerOne;
        Player playerTwo;
        Ball ball;
        Score score;

        std::vector<GameObject*> gameObjects;
    public:
        Application(std::string title, unsigned int width, unsigned int height);
        void run();
        void update();
        void draw();
};

#endif //APPLICATION_H
