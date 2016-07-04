//
// Created by belisariops on 6/20/16.
//

#include "Collider.h"
#include <SDL2/SDL.h>
#include "Window.h"

Collider:: Collider(){

}



Collider ::~Collider() {

}

void Collider ::draw() {

    for (auto seg : segments){
        Point* a = seg->getA();
        Point* b = seg->getB();
        SDL_RenderDrawLine(Window::getInstance()->getRenderer(),a->getX(),a->getY(),b->getX(),b->getY());
    }
}

void Collider ::detectCollision(Collider *other) {

}

bool Collider ::isColliding(Collider *other) {
    for (auto seg1 : segments){
        for(auto seg2 : other->segments){
            if (seg1->areIntersected(seg2))
                return true;
        }

    }
    return false;

}

