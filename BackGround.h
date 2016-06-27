//
// Created by belisariops on 6/19/16.
//

#ifndef PATTERNS_BACKGROUND_H
#define PATTERNS_BACKGROUND_H


#include "LTexture.h"
#include "GameObject.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
    bool detectCollision(GameObject* object);
    //bool collideWithBall(Ball* ball);
private:
    LTexture* texture;
    SDL_Rect* clippingRect;
};


#endif //PATTERNS_BACKGROUND_H
