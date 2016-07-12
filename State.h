//
// Created by belisariops on 6/13/16.
//

#ifndef PATTERNS_STATE_H
#define PATTERNS_STATE_H

#include "Collider.h"
#include "Velocity2D.h"

class State {
public:
    State();
    ~State();
    void tick();
    void setPosition(int x, int y);
    void setSpeed(double x, double y);
    virtual void draw() =0;
    Collider* getCollider();
    double getXSpeed();
    double getYSpeed();
    Velocity2D* getVelocity();
    double getSpeed();
    void setVelocity(double a);
    virtual void hitGround() = 0;

protected:
    double xPosition;
    double yPosition;
    Velocity2D* velocity;
    Collider* collider;
    double v;


};


#endif //PATTERNS_STATE_H
