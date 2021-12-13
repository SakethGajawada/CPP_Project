#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600
class Game
{
    public:
    Game();
    ~Game();
    void init(const char* title,int xpos,int ypos,bool fullscrreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running()
    {return isRunning;}
    static SDL_Renderer* renderer;

    private:
    int count=0;
    bool isRunning;
    SDL_Window* window;
    //SDL_Renderer* renderer;
};