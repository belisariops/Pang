//
// Created by belisariops on 6/13/16.
//

#include "MediumBall.h"
#include "Window.h"
#include "BallCollider.h"
#include "WallCollider.h"
#include "GroundCollider.h"
#include "BoxHorizontal.h"
#include "BoxVertical.h"

MediumBall :: MediumBall (Model* model) {
    this->model = model;
    xPosition = 500;
    yPosition = 100;
    this->width = 60;
    this->height = 60;
    ballViewport.x=0;
    ballViewport.y=0;
    ballViewport.w=60;
    ballViewport.h=60;
    this->velocity = new Velocity2D(30,2);
    this->dim = 30;


}

MediumBall ::~MediumBall() {
    free(model);
}
void MediumBall::draw() {
    Window* window = Window::getInstance();
    SDL_Renderer* render= window->getRenderer();
    this->model->getTexture()->render(xPosition,yPosition,model->getClipping(),ballViewport,render);

    Segment* top = new Segment( new Point(xPosition,yPosition),new Point(xPosition+60,yPosition));
    Segment* left =new Segment( new Point(xPosition,yPosition),new Point(xPosition,yPosition+60));
    Segment* right  = new Segment( new Point(xPosition+60,yPosition),new Point(xPosition+60,yPosition+60));
    Segment* bottom =new Segment( new Point(xPosition,yPosition+60),new Point(xPosition+60,yPosition+60));
    vector<Segment*> segments;
    segments.push_back(top);
    segments.push_back(left);
    segments.push_back(right);
    segments.push_back(bottom);
    this->collider = new BallCollider(segments);
    this->collider->draw();
}

void MediumBall ::hitGround() {
    this->setVelocity(320);
}