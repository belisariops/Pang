//
// Created by belisariops on 23-03-16.
//

#include <iostream>

#include "Segment.h"
#include "math.h"

using namespace std;

Segment ::Segment(Point* a, Point* b) {
    this->a = new Point(a->getX(),a->getY());
    this->b = new Point(b->getX(),b->getY());
}

Segment ::~Segment() {
    delete this->a;
    delete this->b;
}


double Segment :: length() {
    return pow(pow(this->a->getX() - this->b->getX(), 2) + pow(this->a->getY() - this->b->getY(), 2), 0.5);

}

double Segment ::area2(Point* c) {
    return (this->a->getX() * this->b->getY()) - (this->a->getY() * this->b->getX()) + (this->a->getY() * c->getX()) - (this->a->getX() * c->getY()) + (this->b->getX() * c->getY()) - (c->getX() * this->b->getY());
}

bool Segment :: left(Point* c){
    return area2(c)>0;
}

bool Segment :: leftOn(Point* c){
    return area2(c)>=0;
}

bool Segment :: colineal(Point* c){
    return area2(c)==0;
}

bool Segment ::areIntersectedProperly(Segment* seg) {
    if (colineal(seg->a) || colineal(seg->b) || seg->colineal(this->a) || seg->colineal(this->b))
        return false;
    else
        return (left(seg->a)^left(seg->b)) && (seg->left(this->a)^seg->left(this->b));

}

bool Segment ::isInBetween(Point* c) {
    if(!(colineal(c)))
        return false;
    if(this->a->getX() != this->b->getX())
        return ((this->a->getX() <= c->getX()) &&(c->getX() <= this->b->getX()) ) || ((this->a->getX() >= c->getX()) && (c->getX() >= this->b->getX()));
    else
        return ((this->a->getY() <= c->getY()) &&(c->getY() <= this->b->getY()) ) || ((this->a->getY() >= c->getY()) && (c->getY() >= this->b->getY()));
}

bool Segment ::areIntersected(Segment* seg) {
    if(this->areIntersectedProperly(seg))
        return true;
    if (this->isInBetween(seg->a) || this->isInBetween(seg->b) || seg->isInBetween(this->a) || seg->isInBetween(this->b) )
        return true;
    return false;
}

Point* Segment::getA() {
    return this->a;
}

Point* Segment ::getB() {
    return this->b;
}