//
// Created by belisariops on 8/27/16.
//

#ifndef PATTERNS_QUADTREENODE_H
#define PATTERNS_QUADTREENODE_H


#include <vector>
#include "GameObject.h"
#include "Segment.h"

class QuadTreeNode {
public:
    QuadTreeNode(long topLeftX, long topLeftY,long width, long height);
    ~QuadTreeNode();
    long subDivide();
    void draw();
    void addObject(Actor* object);
    long getSize(long* llx, long* lly, long* width,long* height);
    void detectCollisions();
    void tick(vector<Actor*> actors);
    void removeActor(Actor* actor);
    void updateActor(Actor* actor);

private:
    long topLeftX;
    long topLeftY;
    long width;
    long height;


    Segment* top;
    Segment* bottom;
    Segment* left;
    Segment* right;

    QuadTreeNode** subNodes;
    std::vector<Actor*> objects;
protected:
    void getSegments(Segment** t,Segment** b,Segment** l,Segment** r);
};


#endif //PATTERNS_QUADTREENODE_H
