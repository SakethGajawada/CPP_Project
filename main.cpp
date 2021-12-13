#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"Game.hpp"
#include"Enemy1.hpp"
#include"Player.hpp"



int main(int argc, char* argv[])
{
    // SDL_Init(SDL_INIT_EVERYTHING);//initialiser
    
    // SDL_Window* window = SDL_CreateWindow("title",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,400,SDL_WINDOWEVENT_SHOWN);//creating window
    
    // SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,0);//creating renderer which renders on screen
    // SDL_SetRenderDrawColor(renderer,0,255,0,255);
    // SDL_RenderClear(renderer);
    // SDL_RenderPresent(renderer);
    // SDL_Delay(3000);
    const int FPS=60;
    const int frameDelay=1000/60; 
    Uint32 frameStart;
    int frameTime;


    Game* game=new Game();
    game->init("The legend of something",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,false);

    while(game->running())
    {
        frameStart=SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();
        frameTime=SDL_GetTicks()-frameStart;
        
        if(frameDelay>frameTime)
            SDL_Delay(frameDelay-frameTime);

    }
    game->clean();
    //Player* p = new Player("/home/karanjitsaha/Desktop/cpp_project/iron.png",720,64);
    //p->Update();
    Enemy1* e=new Enemy1("/home/karanjitsaha/Desktop/cpp_project/iron.png",720,64);
    e->set_y_trajectory();
    
    return 0;
}