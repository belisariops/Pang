//
// Created by belisariops on 6/18/16.
//

#ifndef PATTERNS_SMALLBALL_H
#define PATTERNS_SMALLBALL_H


#include "RedBallModel.h"
#include "State.h"

class SmallBall : public State {
public:
    SmallBall(Model* model);
    ~SmallBall();
    void draw();
    void hitGround();
private:
    Model* model;

};


#endif //PATTERNS_SMALLBALL_H
