#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player{
    private:
        sf::RectangleShape* paddle;
    public:
        enum Position{
            RIGHT,
            LEFT
        };

        Player(int width, int height, Position position);
        void update();
        void draw(sf::RenderWindow& window);

        
};

#endif 