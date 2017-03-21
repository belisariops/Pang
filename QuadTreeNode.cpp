//
// Created by belisariops on 8/27/16.
//

#include <stdlib.h>
#include <malloc.h>
#include <iostream>
#include "QuadTreeNode.h"
#include "Window.h"
#include <algorithm>

#define NULL nullptr

QuadTreeNode ::QuadTreeNode(long topLeftX, long topLeftY, long width, long height): topLeftX(topLeftX), topLeftY(topLeftY), width(width), height(height), subNodes(NULL){
    top = new Segment(new Point((int)(topLeftX+width),(int)topLeftY),new Point((int)topLeftX,(int)topLeftY));
    bottom = new Segment(new Point((int)topLeftX,(int)(topLeftY+height)),new Point((int)(topLeftX+width),(int)(topLeftY+height)));
    left = new Segment(new Point((int)topLeftX,(int)topLeftY),new Point((int)topLeftX,(int)(topLeftY+height)));
    right = new Segment(new Point((int)(topLeftX+width),(int)(topLeftY+height)),new Point((int)(topLeftX+width),(int)topLeftY));

}

QuadTreeNode ::~QuadTreeNode() {
    for (auto object: objects)
        delete object;
    objects.clear();
    for (int i=0; i<4;i++)
        free(subNodes[i]);

}

long QuadTreeNode ::subDivide() {
    long result = 1;
    if (subNodes == NULL) {
        long w = width/2;
        long h = height/2;
        subNodes = (QuadTreeNode**)malloc(4 * sizeof(QuadTreeNode*));
        subNodes[0] = new QuadTreeNode(topLeftX,topLeftY,w,h);
        subNodes[1] = new QuadTreeNode(topLeftX+w,topLeftY,w,h);
        subNodes[2] = new QuadTreeNode(topLeftX,topLeftY+h,w,h);
        subNodes[3] = new QuadTreeNode(topLeftX+w,topLeftY+h,w,h);

    }
    else {
        for (int i =0; i<4 ; i++) {
            result = subNodes[i]->subDivide();
        }
    }
    return result;
}

void QuadTreeNode ::draw() {
    Window* window = Window :: getInstance();
    if (subNodes == NULL) {
        SDL_RenderDrawLine(Window::getInstance()->getRenderer(),topLeftX,topLeftY,topLeftX+width,topLeftY);
        SDL_RenderDrawLine(Window::getInstance()->getRenderer(),topLeftX,topLeftY,topLeftX,topLeftY+height);
        SDL_RenderDrawLine(Window::getInstance()->getRenderer(),topLeftX+width,topLeftY,topLeftX+width,topLeftY+height);
        SDL_RenderDrawLine(Window::getInstance()->getRenderer(),topLeftX,topLeftY+height,topLeftX+width,topLeftY +height);
    }
    else {
        for (int i = 0; i<4 ; i++){
            subNodes[i]->draw();
        }
    }
}

void QuadTreeNode::addObject(Actor *object) {
    if (subNodes == NULL) {
        for (auto actor:objects){
            if (actor == object) {
                return;
            }
        }
        objects.push_back(object);
    }

    else {
        int objX;
        int objY;
        int w;
        int h;
        object->getPosition(&objX,&objY,&w,&h);
        long tlx;
        long tly;
        long lw;
        long lh;
        for (int i=0;i<4;i++) {
            subNodes[i]->getSize(&tlx,&tly,&lw,&lh);

            if (tly > objY || tly+lh <objY || tlx > objX+w || tlx+lw <objX ) {
                //el objeto no se encuentre en el nodo
                continue;
            }
            else {
                //Agregamos recursivamente al sub-nodo i
                subNodes[i]->addObject(object);

            }



        }

    }

}

long QuadTreeNode::getSize(long *llx, long *lly, long *width, long *height) {
    *llx = this->topLeftX;
    *lly = this->topLeftY;
    *width = this->width;
    *height = this->height;
    return 1;
}

void QuadTreeNode::getSegments(Segment **t, Segment **b, Segment **l, Segment **r) {
    *t = this->top;
    *b = this->bottom;
    *l = this->left;
    *r = this->right;
}

void QuadTreeNode ::detectCollisions() {
    if (subNodes == NULL) {
            if (objects.size()==1)
                return;
            vector<Actor *> aux = objects;
            for (auto object : objects) {
                aux.erase(aux.begin());
                for (auto auxiliar: aux) {
                    object->detectCollisionAct(auxiliar);

                }



        }

    }

    else {
        for (int i=0;i<4;i++) {
            subNodes[i]->detectCollisions();
        }
    }
}

void QuadTreeNode::tick(vector<Actor*> actors) {
    this->deleteVector();
    for (auto object: actors) {
        this->updateActor(object);
        object->tick();
        SDL_SetRenderDrawColor(Window::getInstance()->getRenderer(), 0, 255, 0, 255);

    }
    this->detectCollisions();
}

void QuadTreeNode ::removeActor(Actor *actor) {
    if (subNodes == NULL) {
        //objects.erase(std::remove(objects.begin(), objects.end(), actor), objects.end());
        for (int k=0; k<objects.size();k++) {
            if (objects[k] == actor)
                objects.erase(objects.begin()+k);

        }
    }
    else {
        int objX;
        int objY;
        int w;
        int h;
        actor->getPosition(&objX,&objY,&w,&h);
        actor->getPrevPosition(&objX,&objY);
        long tlx;
        long tly;
        long lw;
        long lh;
        for (int i=0;i<4;i++) {
            subNodes[i]->getSize(&tlx,&tly,&lw,&lh);

            if (tlx < objY || tlx+lh >objY || tlx > objX+w || tlx+lw <objX ) {
                //el objeto no se encuentre en el nodo
                continue;
            }
            else {
                //Agregamos recursivamente al sub-nodo i
                subNodes[i]->removeActor(actor);

            }



        }

    }

}

void QuadTreeNode::deleteVector() {
    if (subNodes != NULL) {
        for (int i =0;i<4;i++) {
            subNodes[i]->deleteVector();
        }
    }
    objects.clear();
}

void QuadTreeNode::updateActor(Actor *actor) {
    //this->deleteVector();
    if (subNodes !=NULL) {
        //Se remueve con la posicion previa

        //Se agrega con su posicion actual
        for (int j = 0; j < 4; j++) {
            subNodes[j]->addObject(actor);
        }

    }



}

