#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Player.h"
#include "InputHandler.h"

class Application{
    private:
        sf::RenderWindow* window;
        InputHandler* inputHandler;
        Player* playerOne;
        Player* playerTwo;

        std::vector<Player> players;
    public:
        Application(std::string title, int width, int height);

        void run();
        void update();
        void draw(std::vector<Player> players);
};

#endif //APPLICATION_H
