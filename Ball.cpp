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


void Ball ::collideWithBall(Ball *ball) {
    if ( this->state->getCollider()->isColliding(ball->state->getCollider())){
        this->switchVelocity(ball);
    }


}


void Ball ::detectCollision(GameObject *object) {
    object->collideWithBall(this);
}

void Ball ::collideWithBorders(BackGround *backGround) {
   backGround->collideWithBall(this);
}

void Ball :: reflect() {
    this->state->getVelocity()->reflect();
}

State* Ball ::getState() {
    return this->state;
}

void Ball::hitGround() {
    this->state->getVelocity()->reflectY();
    this->state->setVelocity(220);
}

void Ball ::hitWall() {
    this->state->getVelocity()->reflectX();
}

void Ball ::switchVelocity(Ball *ball) {
    int x = ball->getState()->getVelocity()->getXSpeed();
    int y = ball->getState()->getVelocity()->getYSpeed();
    ball->getState()->setSpeed(this->getState()->getXSpeed(),this->getState()->getYSpeed());
    this->getState()->setSpeed(x,y);
}