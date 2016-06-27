//
// Created by belisariops on 6/13/16.
//

#include "MediumBall.h"
#include "Window.h"

MediumBall :: MediumBall (Model* model) {
    this->model = model;
    xPosition = 500;
    yPosition = 120;
    ballViewport.x=0;
    ballViewport.y=0;
    ballViewport.w=60;
    ballViewport.h=60;
    //this->xSpeed =-0.02;


}

MediumBall ::~MediumBall() {
    free(model);
}
void MediumBall::draw() {
    Window* window = Window::getInstance();
    SDL_Renderer* render= window->getRenderer();
    this->model->getTexture()->render(xPosition,yPosition,model->getClipping(),ballViewport,render);

    vector<Segment*> segments;
    segments.push_back(new Segment( new Point(xPosition,yPosition),new Point(xPosition+60,yPosition)));
    segments.push_back(new Segment( new Point(xPosition,yPosition),new Point(xPosition,yPosition+60)));
    segments.push_back(new Segment( new Point(xPosition+60,yPosition),new Point(xPosition+60,yPosition+60)));
    segments.push_back(new Segment( new Point(xPosition,yPosition+60),new Point(xPosition+60,yPosition+60)));
    this->collider = new Collider(segments);
    collider->draw();
}
