//
// Created by belisariops on 6/19/16.
//

#ifndef PATTERNS_BACKGROUND_H
#define PATTERNS_BACKGROUND_H


#include "LTexture.h"
#include "GameObject.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Collider.h"

class BackGround: public GameObject, public Actor {
public:
    BackGround();
    ~BackGround();
    LTexture* getTexture();
    SDL_Rect* getClipping();
    void draw();
    void tick();
    void detectCollision(GameObject* object);
    void collideWithBall(Ball* ball);
    vector<Collider*> getBorders();
    void collideWithBorders(BackGround* backGround);
    void getPrevPosition(int* x,int* y);
    void reflect();
    int getXPosition();
    int getYPosition();
    void getPosition(int *x,int* y,int* w,int* h);
    void detectCollisionAct(Actor* object);
private:
    LTexture* texture;
    SDL_Rect* clippingRect;
    vector<Collider*> borders;

};


#endif //PATTERNS_BACKGROUND_H
