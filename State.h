//
// Created by belisariops on 6/13/16.
//

#ifndef PATTERNS_STATE_H
#define PATTERNS_STATE_H

#include "Collider.h"

class State {
public:
    State();
    ~State();
    void tick();
    void setPosition(int x, int y);
    virtual void draw() =0;
    Collider* getCollider();

protected:
    double xPosition;
    double yPosition;
    double xSpeed;
    double ySpeed;
    Collider* collider;


};


#endif //PATTERNS_STATE_H
