//
// Created by belisariops on 7/2/16.
//

#ifndef PATTERNS_GROUNDCOLLIDER_H
#define PATTERNS_GROUNDCOLLIDER_H


#include "Collider.h"
#include "Ball.h"

class GroundCollider : public Collider {
public:
    GroundCollider(Segment* segment);
    void collide(Ball* object);
};


#endif //PATTERNS_GROUNDCOLLIDER_H
