//
// Created by belisariops on 6/15/16.
//

#ifndef PATTERNS_VIEW_H
#define PATTERNS_VIEW_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>

struct SDL_Window;
struct SDL_Renderer;

class View {
public:
    View();
    ~View();
    SDL_Surface* loadImage(std::string &filePath);
    void blitSurface(SDL_Texture* source,SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
    void flip();
    void clear();
    SDL_Renderer* getRenderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<SDL_Surface*> sprites;
};


#endif //PATTERNS_VIEW_H
