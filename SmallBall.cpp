//
// Created by belisariops on 6/18/16.
//

#include "SmallBall.h"
#include "Window.h"
#include "BallCollider.h"
#include "GroundCollider.h"
#include "WallCollider.h"
#include "BoxHorizontal.h"
#include "BoxVertical.h"

SmallBall :: SmallBall (Model* model) {
    this->model = model;
    xPosition = 300;
    yPosition = 135;
    this->velocity = new Velocity2D(100,2);
    this->dim = 13;
}

SmallBall ::~SmallBall() {
    free(model);

}
void SmallBall::draw() {
    SDL_Rect ballViewport;
    ballViewport.x=0;
    ballViewport.y=0;
    this->width = 25;
    this->height = 25;
    ballViewport.w=25;
    ballViewport.h=25;
    Window* window = Window::getInstance();
    SDL_Renderer* render= window->getRenderer();
    this->model->getTexture()->render(xPosition,yPosition,model->getClipping(),ballViewport,render);
    Segment* top = new Segment( new Point(xPosition,yPosition),new Point(xPosition+25,yPosition));
    Segment* left =new Segment( new Point(xPosition,yPosition),new Point(xPosition,yPosition+25));
    Segment* right  = new Segment( new Point(xPosition+25,yPosition),new Point(xPosition+25,yPosition+25));
    Segment* bottom =new Segment( new Point(xPosition,yPosition+25),new Point(xPosition+25,yPosition+25));
    vector<Segment*> segments;
    segments.push_back(top);
    segments.push_back(left);
    segments.push_back(right);
    segments.push_back(bottom);
    this->collider = new BallCollider(segments);
    this->collider->draw();
}

void SmallBall ::hitGround() {
    this->setVelocity(400);
}