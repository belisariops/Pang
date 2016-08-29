//
// Created by belisariops on 7/2/16.
//

#include "BallCollider.h"

BallCollider::BallCollider(vector<Segment*> segments) {
    this->segments = segments;
    a =segments[0]->getA();
    b = segments[1]->getB();
    c =segments[2]->getB();
    d = segments[2]->getA();
}

void BallCollider::collide(Ball *ball) {
    ball->reflect();
}