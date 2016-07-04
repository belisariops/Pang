//
// Created by belisariops on 6/13/16.
//
#include "Ball.h"
#include "LargeBall.h"
#include "BackGround.h"

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


bool Ball ::collideWithBall(Ball *ball) {
    if (this->state->getCollider()->isColliding(ball->state->getCollider())) {
        this->reflect();
        ball->reflect();
        return true;
    }
    return false;
}


bool Ball ::detectCollision(GameObject *object) {
    return object->collideWithBall(this);
}

bool Ball ::collideWithBorders(BackGround *backGround) {
   return backGround->collideWithBall(this);
}

void Ball :: reflect() {
    this->state->setSpeed(-state->getXSpeed(),state->getYSpeed());
}

State* Ball ::getState() {
    return this->state;
}

void Ball::hitGround() {
    printf("golpeando suelo o techo");
    this->state->setSpeed(state->getXSpeed(),-state->getYSpeed());
}

void Ball ::hitWall() {
    this->state->setSpeed(-state->getXSpeed(),state->getYSpeed());
}