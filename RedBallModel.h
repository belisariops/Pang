//
// Created by belisariops on 6/14/16.
//

#ifndef PATTERNS_LARGEBALLMODEL_H
#define PATTERNS_LARGEBALLMODEL_H

#include "Model.h"
#include "LTexture.h"

class RedBallModel : public Model{
public:
    RedBallModel();
    ~RedBallModel();
    LTexture* getTexture();
    SDL_Rect* getClipping();
    void draw();
private:
    LTexture* texture;
    SDL_Rect* clippingRect;

};


#endif //PATTERNS_LARGEBALLMODEL_H
