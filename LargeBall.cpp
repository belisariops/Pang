//
// Created by belisariops on 6/13/16.
//

#include "LargeBall.h"
#include "Window.h"
#include <vector>
#include "BallCollider.h"
#include "GroundCollider.h"
#include "WallCollider.h"
#include "BoxHorizontal.h"
#include "BoxVertical.h"

LargeBall :: LargeBall (Model* model) {
    this->model = model;
    xPosition = 100;
    yPosition = 100;
    this->width = 100;
    this->height= 100;
    ballViewport.x=0;
    ballViewport.y=0;
    ballViewport.w=100;
    ballViewport.h=100;
    this->velocity = new Velocity2D(-50,0);
    this->dim = 50;
    }

LargeBall ::~LargeBall() {
    delete model;
}
void LargeBall::draw() {
    Window* window = Window::getInstance();
    SDL_Renderer* render= window->getRenderer();
    this->model->getTexture()->render(xPosition,yPosition,model->getClipping(),ballViewport,render);
    Segment* top = new Segment( new Point(xPosition,yPosition),new Point(xPosition+100,yPosition));
    Segment* left =new Segment( new Point(xPosition,yPosition),new Point(xPosition,yPosition+100));
    Segment* right  = new Segment( new Point(xPosition+100,yPosition),new Point(xPosition+100,yPosition+100));
    Segment* bottom =new Segment( new Point(xPosition,yPosition+100),new Point(xPosition+100,yPosition+100));
    vector<Segment*> segments;
    segments.push_back(top);
    segments.push_back(left);
    segments.push_back(right);
    segments.push_back(bottom);
    this->collider = new BallCollider(segments);
    this->collider->draw();
}

void LargeBall::hitGround() {
    this->setVelocity(360);
}