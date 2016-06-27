//
// Created by belisariops on 6/14/16.
//

#ifndef PATTERNS_LTEXTURE_H
#define PATTERNS_LTEXTURE_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

class LTexture
{
public:
    //Initializes variables
    LTexture();

    //Deallocates memory
    ~LTexture();

    //Loads image at specified path
    bool loadFromFile( std::string path, SDL_Renderer* gRenderer );

    //Deallocates texture
    void free();

    //Renders texture at given point with a clipping, image can be extended
    void render( int x, int y, SDL_Rect* clip ,SDL_Rect scale,SDL_Renderer* gRenderer );

    //Gets image dimensions
    int getWidth();
    int getHeight();

private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;
};


#endif //PATTERNS_LTEXTURE_H
