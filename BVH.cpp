//
// Created by belisariops on 7/18/16.
//


#include "BVH.h"
#include <math.h>

BVH ::BVH(Actor*actor) {
    this->actor = actor;
    this->xPosition = actor->getXPosition();
    this->yPosition = actor->getYPosition();
    this->left = 0;
    this->right = 0;
}

BVH ::BVH(BVH* left, BVH* right) {
    this->actor =0;
    this->yPosition = (left->yPosition + right->yPosition)*(0.5);
    this->xPosition = (left->xPosition + right->xPosition)*(0.5);
    this->left = left;
    this->right = right;
}

double BVH ::distance(BVH *other) {
    return sqrt((xPosition - other->xPosition)*(xPosition - other->xPosition)+ (yPosition - other->yPosition)*(yPosition - other->yPosition));
}

void BVH ::setPosition(int x, int y) {
    this->xPosition = x;
    this->yPosition = y;
}

void BVH ::addLeft(BVH *actor) {
    this->left = actor;
}

void BVH ::addRight(BVH *actor) {
    this->right = actor;
}




