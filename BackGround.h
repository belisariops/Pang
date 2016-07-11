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

class BackGround: public GameObject {
public:
    BackGround();
    ~BackGround();
    LTexture* getTexture();
    SDL_Rect* getClipping();
    void draw();
    void tick();
    void setState(State* state);
    void setPosition(int x,int y);
    void detectCollision(GameObject* object);
    void collideWithBall(Ball* ball);
    void collideWithBorders(BackGround* backGround);
    void reflect();
    vector<Collider*> getBorders();
private:
    LTexture* texture;
    SDL_Rect* clippingRect;
    vector<Collider*> borders;

};


#endif //PATTERNS_BACKGROUND_H
