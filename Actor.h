//
// Created by belisariops on 7/18/16.
//

#ifndef PATTERNS_ACTOR_H
#define PATTERNS_ACTOR_H


class GameObject;

class Ball;

class State;
class BackGround;

class Actor  {
public:
    virtual void reflect()=0;
    virtual void collideWithBorders(BackGround* backGround)=0;
    virtual void collideWithBall(Ball* ball)=0;
    virtual void tick()=0;
    virtual int getXPosition()=0;
    virtual int getYPosition()=0;
    virtual void getPosition(int *x,int* y,int* w,int* h)=0;
    virtual void getPrevPosition(int* x ,int* y)=0;
    virtual void detectCollisionAct(Actor* object)=0;
    virtual void detectCollision(GameObject* object)=0;
};


#endif //PATTERNS_ACTOR_H
