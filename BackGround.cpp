//
// Created by belisariops on 6/19/16.
//

#include "BackGround.h"
#include "Ball.h"
#include "Window.h"
#include "GroundCollider.h"
#include "State.h"
#include "WallCollider.h"

BackGround ::BackGround() {
    texture = new LTexture();
    clippingRect = new SDL_Rect();
    this->texture->loadFromFile("Sprites/Backgrounds.png",Window::getInstance()->getRenderer());
    clippingRect->x=8;
    clippingRect->y=8;
    clippingRect->w=385;
    clippingRect->h=208;
    Collider* ceiling = new GroundCollider(new Segment(new Point(13,14),new Point(625,14)));
    Collider* leftWall = new WallCollider(new Segment(new Point(13,14),new Point(13,409)));
    Collider* rightWall = new WallCollider(new Segment(new Point(625,14),new Point(625,409)));
    Collider* ground = new GroundCollider(new Segment(new Point(13,409),new Point(625,409)));
    this->borders.push_back(ceiling);
    this->borders.push_back(leftWall);
    this->borders.push_back(rightWall);
    this->borders.push_back(ground);

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
    for (auto border : borders)
        border->draw();

}

SDL_Rect* BackGround ::getClipping() {
this->clippingRect;
}

void BackGround:: tick() {
    draw();
}



void BackGround ::getPrevPosition(int *x, int *y) {
    *x = 13;
    *y = 14;
}


void BackGround ::detectCollision(GameObject*object) {
    object->collideWithBorders(this);
}


void BackGround ::collideWithBall(Ball *ball) {
    for (auto border: borders){
        if (border->isColliding(ball->getState()->getCollider())){
            border->collide(ball);
            return;
        }
    }
}


vector<Collider*> BackGround ::getBorders() {
    return this->borders;
}

void BackGround :: collideWithBorders(BackGround* backGround){

}

void BackGround::reflect() {

}

int BackGround::getXPosition() {
    return -1;
}

int BackGround::getYPosition() {
    return -1;
}

void BackGround::getPosition(int *x, int *y, int *w, int *h) {
    *x=13;
    *y=14;
    *w=612;
    *h=395;

}

void BackGround::detectCollisionAct(Actor *object) {
    object->collideWithBorders(this);
}