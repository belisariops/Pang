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
}

void State ::setPosition(int x, int y) {
    this->xPosition = x;
    this->yPosition = y;
}

Collider* State::getCollider() {
    return this->collider;
}