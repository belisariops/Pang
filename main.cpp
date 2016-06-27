#include <iostream>
#include <SDL2/SDL.h>
#include "Window.h"
#include "GameDriver.h"

using namespace std;

int main() {
    Window* game = Window::getInstance();
    SDL_Event e;
    GameDriver* gameDriver = new GameDriver();

    while (!game->getQuitState()){
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                game->setQuitState(true);
            }
        }
        gameDriver->notify();
        game->update();

    }
    delete gameDriver;
    delete game;
    return 0;
}