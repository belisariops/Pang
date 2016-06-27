//
// Created by belisariops on 6/15/16.
//

#ifndef PATTERNS_WINDOW_H
#define PATTERNS_WINDOW_H

#include <SDL2/SDL.h>

class Window {
    static Window* window ;
public:
    ~Window();
    bool getQuitState();
    void setQuitState(bool boolean);
    static Window* getInstance();
    SDL_Renderer* getRenderer();
    void update();
private:
    bool quitState;
    int SCREEN_HEIGHT;
    int SCREEN_WIDTH;
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

//The window renderer
    SDL_Renderer* gRenderer;
    Window(int width,int height);
    void init();
};


#endif //PATTERNS_WINDOW_H
