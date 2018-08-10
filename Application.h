#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <string>

class Application{
    private:
        sf::RenderWindow* window;
    public:
        Application(std::string title, int width, int height);

        void run();
        void update();
        void draw(sf::RectangleShape rect);
};

#endif
