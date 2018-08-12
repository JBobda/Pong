#include "Application.h"

//Constructor of the Application, creates the instantiates the window, and creates the players
Application::Application(std::string title, int width, int height){
    window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    inputHandler = new InputHandler();
    //Centers the window
    window->setPosition(
            sf::Vector2i(
                sf::VideoMode::getDesktopMode().width/2 - window->getSize().x/2
                ,sf::VideoMode::getDesktopMode().height/2 - window->getSize().y/2));
    playerOne = new Player(20, 100, Player::Position::LEFT);
    playerTwo = new Player(20, 100, Player::Position::RIGHT);

    players.push_back(*playerOne);
    players.push_back(*playerTwo);
}

//The main game loop of the program when this function exits, the program ends
void Application::run(){
    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed) window->close();
            update();
        }

        window->clear();
        draw(players);
        window->display();
    }
}

//This function draws objects to the screen
void Application::draw(std::vector<Player> players){
    for(int i = 0; i < players.size(); i++){
        players[i].draw(*window);
    }
}

//This function updates all of the positions of the game using input
void Application::update(){
    inputHandler->input();
    for(int i = 0; i < players.size(); i++){
        players[i].update();
    }
}