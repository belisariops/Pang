//
// Created by belisariops on 6/13/16.
//

#include "State.h"
#include "Window.h"


State ::State() {
    this->v = 0;
}

State ::~State() {

}

void State::tick() {
    double t = ((double)Window::getInstance()->getScreenTicks())/1000;
    this->xPosition += (velocity->getXSpeed()) * t;
    this->v = v -100*t;
    this->yPosition +=  -v*t  +0.5*(100)*t*t;

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
    this->v = a;
}