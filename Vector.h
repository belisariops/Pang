//
// Created by belisariops on 6/25/16.
//

#ifndef PATTERNS_VECTOR_H
#define PATTERNS_VECTOR_H

#include "Point.h"

class Vector {
public:
    Vector(Point* p);
    Vector();
    ~Vector();
    double norm();
    Vector* *operator+(Vector* vec);
    double operator*(Vector* vec);
    Vector* operator^(Vector* vec);

protected:
    Point* point;
};

#endif //PATTERNS_VECTOR_H
