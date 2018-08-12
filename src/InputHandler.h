#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SFML/Graphics.hpp>

class InputHandler{
    public:
    //Player One Controls
        bool wTyped;
        bool aTyped;
        bool sTyped;
        bool dTyped;

    //Player Two Controls
        bool upTyped;
        bool leftTyped;
        bool downTyped;
        bool rightTyped;
    public:
        InputHandler();
        void input();

};

#endif //INPUT_HANDLER_H