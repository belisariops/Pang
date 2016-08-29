//
// Created by belisariops on 6/13/16.
//

#ifndef PATTERNS_BALL_H
#define PATTERNS_BALL_H



#include "GameObject.h"
#include "Actor.h"

class Model;
class Ball;
class State;

class Ball : public GameObject, public Actor {
public:
    Ball(Model* model);
    ~Ball();
    void tick();
    void setState(State* state);
    void draw();
    void setPosition(int xPosition,int yPosition);
    void detectCollision(GameObject* object);
    void collideWithBall(Ball* ball);
    void collideWithBorders(BackGround* backGround);
    void reflect();
    State* getState();
    void hitGround();
    void hitWall();
    int getXPosition();
    int getYPosition();
    double getDistance(Actor* other);
    void getPosition(int* x,int* y,int* w,int* h);
    void getPrevPosition(int* x,int* y);
    void detectCollisionAct(Actor* actor);

protected:
    State* state;
    int xPosition;
    int yPosition;
    int xPrev;
    int yPrev;
    void switchVelocity(Ball *ball);

};


#endif //PATTERNS_BALL_H
