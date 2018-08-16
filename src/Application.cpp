#include "Application.h"
#include <iostream>

//Constructor of the Application, creates the instantiates the window, and creates the players
Application::Application(std::string title, unsigned int width, unsigned int height)
    :window({width, height}, title)
    ,playerOne(20, 100, Position::LEFT)
    ,playerTwo(20, 100, Position::RIGHT)
    ,ball(20,20)
    ,score(playerOne, playerTwo){

    //Centers the window
    window.setPosition(
            sf::Vector2i(
                sf::VideoMode::getDesktopMode().width/2 - window.getSize().x/2
                ,sf::VideoMode::getDesktopMode().height/2 - window.getSize().y/2));


    gameObjects.push_back(&playerOne);
    gameObjects.push_back(&playerTwo);
    gameObjects.push_back(&ball);
    
}

//The main game loop of the program when this function exits, the program ends
void Application::run(){
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();  
        }
        update();
        window.clear();
        draw();
        window.display();
    }
}

//This function updates all of the positions of the game using input
void Application::update(){
    inputHandler.input();

    //Checks to see if there are any collisions with Player One
    if(ball.getBall().getGlobalBounds().intersects(playerOne.getPaddle().getGlobalBounds())){ 
            ball.setCollision(true);      
    }
    //Checks to see if there are any collisions with Player Two
    if(ball.getBall().getGlobalBounds().intersects(playerTwo.getPaddle().getGlobalBounds())){
            ball.setCollision(true);      
    }


    for(int i = 0; i < gameObjects.size(); i++){
        gameObjects[i]->update(inputHandler);
    }
    score.keepScore(ball);

}

//This function draws objects to the screen
void Application::draw(){
    for(int i = 0; i < gameObjects.size(); i++){
        gameObjects[i]->draw(window);
    }
}

