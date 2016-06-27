//
// Created by belisariops on 6/19/16.
//

#include "BackGround.h"
#include "Window.h"


BackGround ::BackGround() {
    texture = new LTexture();
    clippingRect = new SDL_Rect();
    this->texture->loadFromFile("Sprites/Backgrounds.png",Window::getInstance()->getRenderer());
    clippingRect->x=8;
    clippingRect->y=8;
    clippingRect->w=385;
    clippingRect->h=208;
}

BackGround ::~BackGround() {
    texture->free();
    clippingRect =NULL;
}

LTexture* BackGround ::getTexture() {
    this->texture;
}

void BackGround ::draw() {
    SDL_Rect ballViewport;
    ballViewport.x=0;
    ballViewport.y=0;
    ballViewport.w=640;
    ballViewport.h=425;
    Window* window = Window::getInstance();
    SDL_Renderer* render= window->getRenderer();
    this->texture->render(0,0,this->clippingRect,ballViewport,render);
}

SDL_Rect* BackGround ::getClipping() {
this->clippingRect;
}

void BackGround::setState(State* state) {

}

void BackGround:: tick() {
    draw();
}

void BackGround ::setPosition(int x, int y) {
    //do nothing
}

bool BackGround ::detectCollision(GameObject *object) {
    return false;
}

/*
bool BackGround ::collideWithBall(Ball *ball) {
    return false;
}
 */