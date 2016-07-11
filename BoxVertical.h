//
// Created by belisariops on 7/7/16.
//

#ifndef PATTERNS_BOXVERTICAL_H
#define PATTERNS_BOXVERTICAL_H


#include "Collider.h"

class BoxVertical : public Collider {
public:
    BoxVertical(Segment* segment);
    void collide(Ball* ball);
private:
    Point* direction;
};


#endif //PATTERNS_BOXVERTICAL_H
