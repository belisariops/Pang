//
// Created by belisariops on 6/19/16.
//

#ifndef PATTERNS_GAMEDRIVER_H
#define PATTERNS_GAMEDRIVER_H

#include "GameObject.h"
#include "Actor.h"
#include "QuadTreeNode.h"
#include "RedBallModel.h"
#include <vector>

using namespace std;

class GameDriver {
public:
    GameDriver();
    ~GameDriver();
    void notify();
    void spawn();
    int getCount();
private:
    vector<Actor*> gameObjects;
    BackGround* backGround;
    QuadTreeNode* quadTree;
    Model* model;
    int count;
};


#endif //PATTERNS_GAMEDRIVER_H
