//
// Created by belisariops on 6/13/16.
//
#include "Ball.h"
#include "LargeBall.h"

Ball::Ball(Model* model) {
    state = new LargeBall(model);
    xPosition = 100;
    yPosition = 100;
}

Ball::~Ball() {
    delete state;
}

void Ball ::tick() {
    //Do something
    state->tick();
    //Then draw
    draw();
}

void Ball ::setState(State* state) {
    this->state = state;
}

void Ball ::draw() {
    state->draw();
}

void Ball ::setPosition(int xPosition, int yPosition) {
    state->setPosition(xPosition,yPosition);
}

/*
bool Ball ::collideWithBall(Ball *ball) {
    return false;
}
 */

bool Ball ::detectCollision(GameObject *object) {
    //return object->collideWithBall(this);
    return false;
}