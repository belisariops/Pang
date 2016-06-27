//
// Created by belisariops on 6/15/16.
//

#include "View.h"
#include <SDL2/SDL_image.h>

View :: View() {
    SDL_CreateWindowAndRenderer(640,480,0,&this->window,&this->renderer);
    SDL_SetWindowTitle(this->window,"Demo");
}

View :: ~View() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
}

SDL_Surface* View ::loadImage(std::string &filePath) {
    this->sprites.push_back(IMG_Load(filePath.c_str()));
}

