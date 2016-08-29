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
    /*
    Point* a2;
    Point* b2;
    Point* c2;
    Point* d2;
    other->getPoints(&a2,&b2,&c2,&d2);
     if (a->getX()> d2->getX() || d->getX() < a2->getX() || b->getY() <a2->getY() || b2->getY()<a->getY()){
         return false;
     }
    else
         return true;

*/
    return false;


}

void Collider ::getPoints(Point **a, Point **b, Point **c, Point **d) {
    *a = this->a;
    *b = this->b;
    *c = this->c;
    *d = this->d;
    return;
}