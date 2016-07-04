//
// Created by belisariops on 7/2/16.
//

#include "WallCollider.h"

WallCollider::WallCollider(Segment *segment) {
    this->segments.push_back(segment);
}

void WallCollider ::collide(Ball*object) {
    object->hitWall();
}