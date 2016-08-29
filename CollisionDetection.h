//
// Created by belisariops on 7/20/16.
//

#ifndef PATTERNS_COLLISIONDETECTION_H
#define PATTERNS_COLLISIONDETECTION_H


#include "Actor.h"
#include <vector>

class CollisionDetection {
public:
    CollisionDetection(std::vector<Actor*> actors);
    void addActor(Actor* actor);
    void popActor(Actor * actor);
    void tick();
private:
    std::vector<Actor*> actors;

};


#endif //PATTERNS_COLLISIONDETECTION_H
