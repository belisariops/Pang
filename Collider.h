//
// Created by belisariops on 6/20/16.
//

#ifndef PATTERNS_COLLIDER_H
#define PATTERNS_COLLIDER_H

#include <vector>
#include "Segment.h"

using namespace std;

class Collider {
public:
    Collider(vector<Segment*> segments);
    ~Collider();
    void detectCollision(Collider* other);
    void draw();
    bool isColliding(Collider* other);
protected:
    vector<Segment*> segments;


};


#endif //PATTERNS_COLLIDER_H