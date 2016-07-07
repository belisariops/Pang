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
    vector<Collider*> colliders1 = this->getState()->getCollider();
    vector<Collider*> colliders2 = ball->getState()->getCollider();
    for (auto col1 :colliders1){
        for (auto col2 : colliders2){
            if (col1->isColliding(col2)){
                col1->collide(ball);
                col2->collide(this);
                printf("aaaa\n");
                return true;
            }
        }
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
    this->state->setSpeed(state->getXSpeed(),-state->getYSpeed());
}

void Ball ::hitWall() {
    this->state->setSpeed(-state->getXSpeed(),state->getYSpeed());
}