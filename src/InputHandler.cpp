#include "InputHandler.h"
#include <iostream>

InputHandler::InputHandler(){
    //Player One Controls
        bool wTyped = false;
        bool aTyped = false;
        bool sTyped = false;
        bool dTyped = false;
        
    //Player Two Controls
        bool upTyped = false;
        bool leftTyped = false;
        bool downTyped = false;
        bool rightTyped = false;
}

void InputHandler::input(){
    //Player One Controls
    //Up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        wTyped = true;
    }else{
        wTyped = false;
    }
    //Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        aTyped = true;
    }else{
        aTyped = false;
    }
    //Down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        sTyped = true;
    }else{
        sTyped = false;
    }
    //Right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        dTyped = true;
    }else{
        dTyped = false;
    }

    /////////////////////////////////////////////////////////////////


    //Player Two Controls
    //Up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
        upTyped = true;
    }else{
        upTyped = false;
    }
    //Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
        rightTyped = true;
    }else{
        rightTyped = false;
    }
    //Down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
        downTyped = true;
    }else{
        downTyped = false;
    }
    //Right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        leftTyped = true;
    }else{
        leftTyped = false;
    }

}