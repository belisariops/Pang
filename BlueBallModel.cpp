//
// Created by belisariops on 8/29/16.
//

#include "BlueBallModel.h"
#include "Window.h"


BlueBallModel ::BlueBallModel() {
    texture = new LTexture();
    clippingRect = new SDL_Rect();
    this->texture->loadFromFile("Sprites/Balls.png",Window::getInstance()->getRenderer());
    clippingRect->x=1;//1
    clippingRect->y=46;//6
    clippingRect->w=49;//49
    clippingRect->h=40;//40

}

BlueBallModel ::~BlueBallModel() {
    texture->free();
    clippingRect =NULL;

}

void BlueBallModel::draw() {
    SDL_Rect ballViewport;
    ballViewport.x=0;
    ballViewport.y=0;
    ballViewport.w=100;
    ballViewport.h=100;
    Window* window = Window::getInstance();
    SDL_Renderer* render= window->getRenderer();
    this->texture->render(100,100,this->clippingRect,ballViewport,render);
}

LTexture* BlueBallModel::getTexture() {
    return this->texture;
}

SDL_Rect* BlueBallModel::getClipping() {
    return this->clippingRect;
}
