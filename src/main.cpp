#include "Application.h"

const int WIDTH = 1000;
const int HEIGHT = WIDTH * 9 / 16;

int main(){
    Application pong("Pong - The game", WIDTH, HEIGHT);
    pong.run();
}