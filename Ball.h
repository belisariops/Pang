//
// Created by belisariops on 6/13/16.
//

#ifndef PATTERNS_BALL_H
#define PATTERNS_BALL_H

#include "State.h"
#include "RedBallModel.h"
#include "GameObject.h"

class Ball : public GameObject {
public:
    Ball(Model* model);
    ~Ball();
    void tick();
    void setState(State* state);
    void draw();
    void setPosition(int xPosition,int yPosition);
    bool detectCollision(GameObject* object);
    //bool collideWithBall(Ball* ball);
protected:
    State* state;
    int xPosition;
    int yPosition;

};


#endif //PATTERNS_BALL_H
