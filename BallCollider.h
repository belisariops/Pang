//
// Created by belisariops on 7/2/16.
//

#ifndef PATTERNS_BALLCOLLIDER_H
#define PATTERNS_BALLCOLLIDER_H


#include "Collider.h"

class BallCollider : public Collider {
public:
    BallCollider(vector<Segment*> segments);
    void collide(Ball *ball);

};


#endif //PATTERNS_BALLCOLLIDER_H
