//
// Created by belisariops on 23-03-16.
//


#ifndef POINT_SEGMENT_H
#define POINT_SEGMENT_H

#include <iostream>

#include "Point.h"

using namespace std;

class Segment {
public:
    Segment(Point* a, Point* b);
    ~Segment();
    double length();
    bool left(Point* c);
    bool leftOn(Point* c);
    bool colineal(Point* c);
    double area2(Point* c);
    bool areIntersected(Segment* seg);
    Point* getA();
    Point* getB();
private:
    Point* a;
    Point* b;
    bool areIntersectedProperly(Segment* seg);
    bool isInBetween(Point* c);
};


#endif //POINT_SEGMENT_H
