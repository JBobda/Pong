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
    playerOne = new Player(20, 100, Position::LEFT);
    playerTwo = new Player(20, 100, Position::RIGHT);
    ball = new Ball(20,20);


    gameObjects.push_back(playerOne);
    gameObjects.push_back(playerTwo);
    gameObjects.push_back(ball);
    
}

Application::~Application(){
    delete window;
    delete inputHandler;
    delete playerOne;
    delete playerTwo;
    delete ball;
}

//The main game loop of the program when this function exits, the program ends
void Application::run(){
    while(window->isOpen()){
        sf::Event event;
        while(window->pollEvent(event)){
            if(event.type == sf::Event::Closed) window->close();  
        }
        update();
        window->clear();
        draw();
        window->display();
    }
}

//This function updates all of the positions of the game using input
void Application::update(){
    inputHandler->input();

    //Checks to see if there are any collisions with Player One
    if(((Ball*)ball)->ball->getGlobalBounds()
        .intersects(((Player*)playerOne)->paddle->getGlobalBounds())){
            
            ((Ball*)ball)->setCollision(true);      
    }
    //Checks to see if there are any collisions with Player Two
    if(((Ball*)ball)->ball->getGlobalBounds()
        .intersects(((Player*)playerTwo)->paddle->getGlobalBounds())){
            
            ((Ball*)ball)->setCollision(true);      
    }


    for(int i = 0; i < gameObjects.size(); i++){
        gameObjects[i]->update(*inputHandler);
    }
}

//This function draws objects to the screen
void Application::draw(){
    for(int i = 0; i < gameObjects.size(); i++){
        gameObjects[i]->draw(*window);
    }
}

