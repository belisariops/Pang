//
// Created by belisariops on 6/19/16.
//

#ifndef PATTERNS_GAMEOBJECT_H
#define PATTERNS_GAMEOBJECT_H


#include "Actor.h"

class State;
class BackGround;

class Ball;

class GameObject {
public:
    virtual void tick()=0;
    virtual void draw()=0;
    virtual void collideWithBall(Ball* ball)=0;
    virtual void detectCollision(GameObject* object)=0;
    virtual void collideWithBorders(BackGround* backGround)=0;
    //virtual long getPosition(int* xPos, int* yPos)=0;
    //virtual long getPrevPosition(int* xPos,int* yPos)=0;
};


#endif //PATTERNS_GAMEOBJECT_H