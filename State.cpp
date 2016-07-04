//
// Created by belisariops on 6/13/16.
//

#include "State.h"


State ::State() {

}

State ::~State() {

}

void State::tick() {
    this->xPosition += xSpeed;
    this->yPosition += ySpeed;
}

void State ::setPosition(int x, int y) {
    this->xPosition = x;
    this->yPosition = y;
}

Collider* State::getCollider() {
    return this->collider;
}

void State ::setSpeed(double x, double y) {
    this->xSpeed = x;
    this->ySpeed = y;
}

double State ::getXSpeed() {
    return this->xSpeed;
}

double State ::getYSpeed() {
    return this->ySpeed;
}