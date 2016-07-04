//
// Created by belisariops on 6/13/16.
//

#include "LargeBall.h"
#include "Window.h"
#include <vector>
#include "BallCollider.h"

LargeBall :: LargeBall (Model* model) {
    this->model = model;
    xPosition = 100;
    yPosition = 100;
    ballViewport.x=0;
    ballViewport.y=0;
    ballViewport.w=100;
    ballViewport.h=100;
    this->xSpeed =0.02;
    this->ySpeed = 0.015;
    }

LargeBall ::~LargeBall() {
    delete model;
}
void LargeBall::draw() {
    Window* window = Window::getInstance();
    SDL_Renderer* render= window->getRenderer();
    this->model->getTexture()->render(xPosition,yPosition,model->getClipping(),ballViewport,render);
    vector<Segment*> segments;
    segments.push_back(new Segment( new Point(xPosition,yPosition),new Point(xPosition+100,yPosition)));
    segments.push_back(new Segment( new Point(xPosition,yPosition),new Point(xPosition,yPosition+100)));
    segments.push_back(new Segment( new Point(xPosition+100,yPosition),new Point(xPosition+100,yPosition+100)));
    segments.push_back(new Segment( new Point(xPosition,yPosition+100),new Point(xPosition+100,yPosition+100)));

    this->collider = new BallCollider(segments);
    this->collider->draw();
}