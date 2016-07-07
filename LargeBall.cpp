//
// Created by belisariops on 6/13/16.
//

#include "LargeBall.h"
#include "Window.h"
#include <vector>
#include "BallCollider.h"
#include "GroundCollider.h"
#include "WallCollider.h"

LargeBall :: LargeBall (Model* model) {
    this->model = model;
    xPosition = 100;
    yPosition = 100;
    ballViewport.x=0;
    ballViewport.y=0;
    ballViewport.w=100;
    ballViewport.h=100;
    this->xSpeed =2;
    this->ySpeed = 1;
    }

LargeBall ::~LargeBall() {
    delete model;
}
void LargeBall::draw() {
    Window* window = Window::getInstance();
    SDL_Renderer* render= window->getRenderer();
    this->model->getTexture()->render(xPosition,yPosition,model->getClipping(),ballViewport,render);
    WallCollider* top = new WallCollider(new Segment( new Point(xPosition,yPosition),new Point(xPosition+100,yPosition)));
    GroundCollider* left =new GroundCollider(new Segment( new Point(xPosition,yPosition),new Point(xPosition,yPosition+100)));
    GroundCollider* right =new GroundCollider(new Segment( new Point(xPosition+100,yPosition),new Point(xPosition+100,yPosition+100)));
    WallCollider* bottom =new WallCollider(new Segment( new Point(xPosition,yPosition+100),new Point(xPosition+100,yPosition+100)));
    vector<Collider*> segments;
    segments.push_back(top);
    segments.push_back(left);
    segments.push_back(right);
    segments.push_back(bottom);
    this->collider = segments;
    for (auto col :collider)
        col->draw();
}