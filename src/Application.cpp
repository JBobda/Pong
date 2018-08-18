#include "Application.h"

#include <iostream>

//Constructor of the Application, creates the instantiates the window, and creates the players
Application::Application(std::string title, unsigned int width, unsigned int height, float updates)
    :window({width, height}, title)
    ,playerOne(20, 100, Position::LEFT)
    ,playerTwo(20, 100, Position::RIGHT)
    ,ball(20,20)
    ,score(playerOne, playerTwo), UPS(updates){

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
    //Setup for the Game loop, fixing the updates per second to 60
    sf::Clock timer;
    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f/UPS);
    int updates = 0;
    int frames = 0;
    
    sf::Time timing = timer.restart();
    clock.restart();

    //Main game loop that controls the game
    while(window.isOpen()){
        //Polls for Events
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();  
        }
        
        //Updates every 1/60 of a second
        while(accumulator >= ups){
            accumulator -= ups;
            update();
            updates++;
        }

        //Rendering to the window
        window.clear();
        draw();
        frames++;
        window.display();
        
        //Counts the Frames and Updates per second
        if((timer.getElapsedTime() - timing).asSeconds() >= 1){
            timing += sf::seconds(1);
            std::cout << "UPS: " << updates << " | FPS: " << frames << "\n";
            updates = 0;
            frames = 0;
        }

        accumulator += clock.restart();
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

    //Updates the Score
    score.update(ball);

}

//This function draws objects to the screen
void Application::draw(){
    for(int i = 0; i < gameObjects.size(); i++){
        gameObjects[i]->draw(window);
    }
    
    //Displays the Score
    score.display();
}

