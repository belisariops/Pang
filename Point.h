//
// Created by belisariops on 6/20/16.
//

#ifndef PATTERNS_POINT_H
#define PATTERNS_POINT_H

class Point {
public:
    Point(int x,int y);
    ~Point();
    int getX();
    int getY();
private:
    int x;
    int y;
};


#endif //PATTERNS_POINT_H
