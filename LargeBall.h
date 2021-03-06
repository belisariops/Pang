//
// Created by belisariops on 6/13/16.
//

#ifndef PATTERNS_LARGEBALL_H
#define PATTERNS_LARGEBALL_H


#include "State.h"
#include "SDL2/SDL.h"
#include "Model.h"

class LargeBall : public State {
public:
    LargeBall(Model* model);
    ~LargeBall();
    void draw();
    void hitGround();
private:
    SDL_Rect ballViewport;
    Model* model;

};


#endif //PATTERNS_LARGEBALL_H
