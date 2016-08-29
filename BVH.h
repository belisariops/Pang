//
// Created by belisariops on 7/18/16.
//

#ifndef PATTERNS_BVH_H
#define PATTERNS_BVH_H


#include <vector>
#include "Actor.h"


class BVH {
public:
    BVH(BVH* left,BVH* right);
    BVH(Actor* actor);
    void addLeft(BVH* actor);
    void addRight(BVH* actor);
    double distance(BVH* other);
    void setPosition(int x, int y);
private:
    Actor* actor;
    BVH* left;
    BVH* right;
protected:
    int xPosition;
    int yPosition;


};


#endif //PATTERNS_BVH_H
