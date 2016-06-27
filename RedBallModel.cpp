//
// Created by belisariops on 6/14/16.
//

#include "RedBallModel.h"
#include "Window.h"

RedBallModel ::RedBallModel() {
    texture = new LTexture();
    clippingRect = new SDL_Rect();
    this->texture->loadFromFile("Sprites/Balls.png",Window::getInstance()->getRenderer());
    clippingRect->x=1;
    clippingRect->y=6;
    clippingRect->w=49;
    clippingRect->h=40;

}

RedBallModel ::~RedBallModel() {
    texture->free();
    clippingRect =NULL;

}

void RedBallModel::draw() {
    SDL_Rect ballViewport;
    ballViewport.x=0;
    ballViewport.y=0;
    ballViewport.w=100;
    ballViewport.h=100;
    Window* window = Window::getInstance();
    SDL_Renderer* render= window->getRenderer();
    this->texture->render(100,100,this->clippingRect,ballViewport,render);
}

LTexture* RedBallModel::getTexture() {
    return this->texture;
}

SDL_Rect* RedBallModel::getClipping() {
    return this->clippingRect;
}