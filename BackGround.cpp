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

void BackGround::setState(State* state) {

}

void BackGround:: tick() {
    draw();
}

void BackGround ::setPosition(int x, int y) {
    //do nothing
}

bool BackGround ::detectCollision(GameObject *object) {
    return object->collideWithBorders(this);
}


bool BackGround ::collideWithBall(Ball *ball) {
    for (auto border: borders){
        for (auto line : ball->getState()->getCollider()){
            if (border->isColliding(line)){
                border->collide(ball);
                return true;
            }
        }
    }
    return false;
}

void BackGround ::reflect() {
    return;
}

bool BackGround::collideWithBorders(BackGround *backGround) {
    return false;
}

vector<Collider*> BackGround ::getBorders() {
    return this->borders;
}