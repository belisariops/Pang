//
// Created by belisariops on 7/2/16.
//

#ifndef PATTERNS_WALLCOLLIDER_H
#define PATTERNS_WALLCOLLIDER_H

#include "Collider.h"
#include "Ball.h"

class WallCollider : public Collider {
public:
    WallCollider(Segment* segment);
    void collide(Ball* object);
};


#endif //PATTERNS_WALLCOLLIDER_H
