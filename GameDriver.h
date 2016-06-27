//
// Created by belisariops on 6/19/16.
//

#ifndef PATTERNS_GAMEDRIVER_H
#define PATTERNS_GAMEDRIVER_H

#include "GameObject.h"
#include <vector>

using namespace std;

class GameDriver {
public:
    GameDriver();
    ~GameDriver();
    void notify();
private:
    vector<GameObject*> gameObjects;

};


#endif //PATTERNS_GAMEDRIVER_H
