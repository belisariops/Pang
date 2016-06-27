//
// Created by belisariops on 6/19/16.
//

#ifndef PATTERNS_GAMEOBJECT_H
#define PATTERNS_GAMEOBJECT_H


#include "State.h"

class GameObject {
public:
    virtual void tick()=0;
    virtual void draw()=0;
    virtual void setState(State* state)=0;
    virtual void setPosition(int x,int y)=0;
    virtual bool detectCollision(GameObject* object)=0;

};


#endif //PATTERNS_GAMEOBJECT_H