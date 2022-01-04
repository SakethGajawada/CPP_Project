#pragma once
#include "Game.hpp"
class Score
{
private:
    SDL_Rect *rect=new SDL_Rect();
    SDL_Texture* texture;
    

public:
    Score();
    void render(int cnt,SDL_Renderer* renderer);
};

