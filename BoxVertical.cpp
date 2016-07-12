//
// Created by belisariops on 7/7/16.
//

#include "BoxVertical.h"

BoxVertical ::BoxVertical(Segment *segment) {
    this->segments.push_back(segment);
    this->direction = new Point(1,0);
}

void BoxVertical ::collide(Ball *ball) {
    ball->hitGround();
}