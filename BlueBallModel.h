//
// Created by belisariops on 8/29/16.
//

#ifndef PATTERNS_BLUEBALLMODEL_H
#define PATTERNS_BLUEBALLMODEL_H


#include "LTexture.h"
#include "Model.h"

class BlueBallModel : public Model {
public:
    BlueBallModel();
    ~BlueBallModel();
    LTexture* getTexture();
    SDL_Rect* getClipping();
    void draw();
private:
    LTexture* texture;
    SDL_Rect* clippingRect;
};


#endif //PATTERNS_BLUEBALLMODEL_H
