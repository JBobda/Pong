#include "Application.h"

const int WIDTH = 1000; //Width of the window
const int HEIGHT = WIDTH * 9 / 16; //Height of the window
const float UPS = 60; //Updates per second

int main(){
    Application pong("Pong - The game", WIDTH, HEIGHT, UPS);
    pong.run();
}