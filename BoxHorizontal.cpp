//
// Created by belisariops on 7/7/16.
//

#include "BoxHorizontal.h"

BoxHorizontal ::BoxHorizontal(Segment *segment) {
    this->segments.push_back(segment);
    this->direction = new Point(1,0);
}

void BoxHorizontal ::collide(Ball *object) {
    object->hitWall();
}

