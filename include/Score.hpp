#pragma once
#include "Game.hpp"
class Score
{
private:
    SDL_Rect *rect=new SDL_Rect();
    SDL_Texture* texture;
    

public:
    Score();
    void render(int cnt,SDL_Renderer* renderer, int screenno);
    void get_text_and_rect(SDL_Renderer* renderer, int x, int y, const char* text, TTF_Font* font, SDL_Texture* texture, SDL_Rect* rect, int screenno);
};

