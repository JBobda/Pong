#include "Application.h"

Application::Application(std::string title, int width, int height){
    window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

void Application::run(){
    while(window->isOpen()){
        sf::Event evnt;
        while(window->pollEvent(evnt)){
            if(evnt.type == sf::Event::Closed) window->close();
        }

        window->clear();
        window->display();
    }
}

void Application::draw(sf::RectangleShape rect){
    window->draw(rect);
}

void Application::update(){

}