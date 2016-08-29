//
// Created by belisariops on 6/13/16.
//

#ifndef PATTERNS_STATE_H
#define PATTERNS_STATE_H

#include "Velocity2D.h"

class Collider;

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
    void getPosition(int* x,int* y,int* w,int* h);
    void getPrevPosition(int* x,int* y);

protected:
    double xPosition;
    double yPosition;
    int xPrev;
    int yPrev;
    int width;
    int height;
    Velocity2D* velocity;
    Collider* collider;
    double v;
    int dim;


};


#endif //PATTERNS_STATE_H
