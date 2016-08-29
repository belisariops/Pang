//
// Created by belisariops on 6/13/16.
//

#include "State.h"
#include "Window.h"


State ::State() {
}

State ::~State() {

}

void State::tick() {
    this->xPrev=xPosition;
    this->yPrev = yPosition;
    double t = ((double)Window::getInstance()->getScreenTicks())/1000;
    this->xPosition += (velocity->getXSpeed()) * t;
    this->velocity->setYVelocity(this->velocity->getYSpeed() - 200*t);
    this->yPosition +=  -velocity->getYSpeed()*t  +0.5*(400)*t*t;

}

void State ::setPosition(int x, int y) {
    this->xPosition = x;
    this->yPosition = y;
}

Collider* State::getCollider() {
    return this->collider;
}

void State ::setSpeed(double x, double y) {
    this->velocity->setSpeed(x,y);

}

double State ::getXSpeed() {
    return velocity->getXSpeed();
}

double State ::getYSpeed() {
    return velocity->getYSpeed();
}

Velocity2D* State ::getVelocity() {
    return this->velocity;
}

void State ::setVelocity(double a) {
    this->velocity->setYVelocity(a);

}

void State::getPrevPosition(int *x, int *y) {
    *x = xPrev;
    *y = yPrev;
}

void State::getPosition(int *x, int *y,int *w,int* h) {
    *x = xPosition;
    *y = yPosition;
    *w = width;
    *h = height;
}