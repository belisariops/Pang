#include <iostream>
#include <SDL2/SDL.h>
#include "Window.h"
#include "GameDriver.h"

using namespace std;

int main() {
    Window* game = Window::getInstance();
    SDL_Event e;
    GameDriver gameDriver = GameDriver();
    Timer fpsTimer;
    Timer capTimer;
    fpsTimer.start();

    while (!game->getQuitState()){
        capTimer.start();
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                game->setQuitState(true);
            }

            if ( e.type == SDL_KEYDOWN){
                gameDriver.spawn();
            }


        }

        gameDriver.notify();
        game->update();
        //If frame finished early
        int frameTicks = capTimer.getTicks();
        if( frameTicks < game->getScreenTicks() )
        {
            //Wait remaining time
            SDL_Delay( game->getScreenTicks() - frameTicks );
        }

    }
    delete game;
    return 0;
}
