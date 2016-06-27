//
// Created by belisariops on 6/13/16.
//

#ifndef PATTERNS_LARGEBALL_H
#define PATTERNS_LARGEBALL_H


#include "State.h"
#include "RedBallModel.h"

class LargeBall : public State {
public:
    LargeBall(Model* model);
    ~LargeBall();
    void draw();
private:
    SDL_Rect ballViewport;
    Model* model;

};


#endif //PATTERNS_LARGEBALL_H
