#include <iostream>
#include <SDL2/SDL.h>
#include <sstream>
#include "Window.h"
#include "GameDriver.h"
#include "Timer.h"

using namespace std;

int main() {
    Window* game = Window::getInstance();
    SDL_Event e;
    GameDriver* gameDriver = new GameDriver();
    Timer fpsTimer;
    Timer capTimer;
    int countedFrames=0;
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
                gameDriver->spawn();
            }


        }
        float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );

        //Set text to be rendered

        //cout << game->getScreenTicks()  << "\n";
        if (fpsTimer.getTicks() >10) {
            cout << avgFPS << "\n";
        }


        gameDriver->notify();
        game->update();
        ++countedFrames;
        //If frame finished early
        int frameTicks = capTimer.getTicks();
        if( frameTicks < game->getScreenTicks() )
        {
            //Wait remaining time
            SDL_Delay( game->getScreenTicks() - frameTicks );
        }
        //cout<< capTimer.getTicks()<<endl;
        //cout<<fpsTimer.getTicks()<<"\n";
        if (fpsTimer.getTicks() >1000.f){
            fpsTimer.start();
            countedFrames=0;
        }

    }
    delete gameDriver;
    delete game;
    return 0;
}