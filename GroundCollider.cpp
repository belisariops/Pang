//
// Created by belisariops on 7/2/16.
//

#include "GroundCollider.h"

GroundCollider::GroundCollider(Segment *segment) {
    this->segments.push_back(segment);
}

void GroundCollider ::collide(Ball*object) {
    printf("aaaa");
    object->hitGround();
}