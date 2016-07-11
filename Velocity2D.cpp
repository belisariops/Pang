//
// Created by belisariops on 7/7/16.
//

#include "Velocity2D.h"

Velocity2D ::Velocity2D(double x, double y) {
    this->xSpeed = x;
    this->ySpeed = y;
}

void Velocity2D ::setSpeed(double x, double y) {
    this->xSpeed = x;
    this->ySpeed = y;
}

void Velocity2D ::reflect() {
    this->xSpeed = -xSpeed;
    this->ySpeed = -ySpeed;
}

void Velocity2D ::reflectX() {
    this->xSpeed = -xSpeed;
    this->ySpeed = ySpeed;
}

void Velocity2D ::reflectY() {
    this->xSpeed = xSpeed;
    this->ySpeed = -ySpeed;
}

int Velocity2D ::getXSpeed() {
    return this->xSpeed;
}

int Velocity2D ::getYSpeed() {
    return this->ySpeed;
}