//
// Created by belisariops on 6/19/16.
//

#include "GameDriver.h"
#include "Window.h"
#include "BackGround.h"
#include "RedBallModel.h"
#include "Ball.h"
#include "MediumBall.h"
#include "SmallBall.h"
class Model;
#include <SDL2/SDL.h>
#include "Window.h"

GameDriver::GameDriver() {
    Window* game = Window::getInstance();
    backGround = new BackGround();
    quadTree = new QuadTreeNode(0,0,640,425);
    quadTree->subDivide();
    //std::cout << "Divide! \n";
    quadTree->subDivide();
    //quadTree->subDivide();
    //quadTree->subDivide();
    model = new RedBallModel();
    Ball* ball1 = new Ball(model);
    ball1->setState(new SmallBall(model));
    //quadTree->addObject(ball1);
    gameObjects.push_back(ball1);
    Ball* ball2 = new Ball(model);
    ball2->setState(new SmallBall(model));
    //quadTree->addObject(ball2);
    ball2->setPosition(550,100);
    gameObjects.push_back(ball2);
    Ball* ball3 = new Ball(model);
    ball3->setState(new SmallBall(model));
    ball3->setPosition(100,100);
    gameObjects.push_back(ball3);
    count =3;
}

GameDriver::~GameDriver() {
    delete quadTree;
    //for (auto object: gameObjects)
      //delete object;


    gameObjects.clear();
}

void GameDriver::notify() {
    SDL_SetRenderDrawColor(Window::getInstance()->getRenderer(), 0, 255, 0, 255);
    backGround->tick();
    /*for (auto object: gameObjects){
        object->tick();
    }*/
    quadTree->tick(gameObjects);


    //Por implementar

    vector<Actor*> aux = gameObjects;

    //Fuerza bruta
       for (auto object1:aux){
                object1->detectCollision(backGround);
        }
        aux.pop_back();


    SDL_SetRenderDrawColor(Window::getInstance()->getRenderer(), 255, 255, 255, 255);
    quadTree->draw();





}

int GameDriver ::getCount() {
    return count;
}

void GameDriver ::spawn() {
    Ball* ball = new Ball(model);
    ball->setState(new SmallBall(model));
    ball->setPosition(rand()%410+15,rand()%200 +10);
    gameObjects.push_back(ball);
    count++;
}
