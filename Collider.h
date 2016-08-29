//
// Created by belisariops on 6/20/16.
//

#ifndef PATTERNS_COLLIDER_H
#define PATTERNS_COLLIDER_H

#include <vector>
#include "Segment.h"
#include "Ball.h"

using namespace std;

class Collider {
public:
    Collider();
    ~Collider();
    void detectCollision(Collider* other);
    void draw();
    bool isColliding(Collider* other);
    virtual void collide(Ball *ball)=0;
    void getPoints(Point** a,Point** b,Point** c,Point** d);
protected:
    vector<Segment*> segments;
    Point* a;
    Point* b;
    Point* c;
    Point* d;



};


#endif //PATTERNS_COLLIDER_H