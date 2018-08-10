#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <string>
#include <vector>

class Application{
    private:
        sf::RenderWindow* window;
        Player* playerOne;
        Player* playerTwo;

        std::vector<Player*> players;
    public:
        Application(std::string title, int width, int height);

        void run();
        void update();
        void draw(std::vector<Player*> players);
};

#endif
