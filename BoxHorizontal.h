//
// Created by belisariops on 7/7/16.
//

#ifndef PATTERNS_BOXHORIZONTAL_H
#define PATTERNS_BOXHORIZONTAL_H


#include "Collider.h"

class BoxHorizontal : public Collider {
public:
    BoxHorizontal(Segment* segment);
    void collide(Ball* object);
private:
    Point* direction;
};


#endif //PATTERNS_BOXHORIZONTAL_H
