//
// Created by belisariops on 6/18/16.
//

#include "SmallBall.h"
#include "Window.h"
#include "BallCollider.h"

SmallBall :: SmallBall (Model* model) {
    this->model = model;
    xPosition = 300;
    yPosition = 135;
    vector<Segment*> segments;
    segments.push_back(new Segment( new Point(xPosition,yPosition),new Point(xPosition+25,yPosition)));
    segments.push_back(new Segment( new Point(xPosition,yPosition),new Point(xPosition,yPosition+25)));
    segments.push_back(new Segment( new Point(xPosition+25,yPosition),new Point(xPosition+25,yPosition+25)));
    segments.push_back(new Segment( new Point(xPosition,yPosition+25),new Point(xPosition+25,yPosition+25)));
    this->collider = new BallCollider(segments);
}

SmallBall ::~SmallBall() {
    free(model);

}
void SmallBall::draw() {
    SDL_Rect ballViewport;
    ballViewport.x=0;
    ballViewport.y=0;
    ballViewport.w=25;
    ballViewport.h=25;
    Window* window = Window::getInstance();
    SDL_Renderer* render= window->getRenderer();
    this->model->getTexture()->render(300,135,model->getClipping(),ballViewport,render);
    collider->draw();
}