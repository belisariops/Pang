//
// Created by belisariops on 6/18/16.
//

#ifndef PATTERNS_MODEL_H
#define PATTERNS_MODEL_H

#endif //PATTERNS_MODEL_H

#include "LTexture.h"
#include <SDL2/SDL.h>

class Model {
public:
    virtual LTexture* getTexture()=0;
    virtual SDL_Rect* getClipping()=0;
    virtual void draw() = 0;
};