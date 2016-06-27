//
// Created by belisariops on 6/13/16.
//

#ifndef PATTERNS_MEDIUMBALL_H
#define PATTERNS_MEDIUMBALL_H

#include "RedBallModel.h"
#include "State.h"

class MediumBall : public State {
public:
    MediumBall(Model* model);
    ~MediumBall();
    void draw();
private:
    SDL_Rect ballViewport;
    Model* model;

};


#endif //PATTERNS_MEDIUMBALL_H
