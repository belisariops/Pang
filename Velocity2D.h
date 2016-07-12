//
// Created by belisariops on 7/7/16.
//

#ifndef PATTERNS_VELOCITY2D_H
#define PATTERNS_VELOCITY2D_H


class Velocity2D {
public:
    Velocity2D(double x,double y);
    void reflect();
    void reflectX();
    void reflectY();
    int getXSpeed();
    int getYSpeed();
    void setSpeed(double x, double y);
    void setXVelocity(double  x);
    void setYVelocity(double y);
private:
    double xSpeed;
    double ySpeed;
};


#endif //PATTERNS_VELOCITY2D_H
