//
// Created by belisariops on 7/2/16.
//

#include "BallCollider.h"

BallCollider::BallCollider(vector<Segment*> segments) {
    this->segments = segments;
}

void BallCollider::collide(Ball *ball) {
    ball->reflect();
}