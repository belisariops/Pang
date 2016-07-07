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
    GameObject* backGround = new BackGround();
    gameObjects.push_back(backGround);
    RedBallModel* model = new RedBallModel();
    GameObject* ball1 = new Ball(model);
    gameObjects.push_back(ball1);
    GameObject* ball2 = new Ball(model);
    ball2->setPosition(400,100);
    //ball2->setState(new MediumBall(model));
    gameObjects.push_back(ball2);
   /* GameObject* ball3 = new Ball(model);
    ball3->setState(new SmallBall(model));
    gameObjects.push_back(ball3);*/
    SDL_SetRenderDrawColor(game->getRenderer(), 0, 255, 0, 255);
}

GameDriver::~GameDriver() {
    for (auto object: gameObjects)
        delete object;

    gameObjects.clear();
}

void GameDriver::notify() {
    for (auto object: gameObjects){
        object->tick();
    }
    //Por implementar

    vector<GameObject*> aux = gameObjects;
    while (!aux.empty()){
        GameObject* auxObject = aux.back();
        aux.pop_back();

        for (auto object1:aux){
                if (auxObject->detectCollision(object1)){

                }
        }


    }


}