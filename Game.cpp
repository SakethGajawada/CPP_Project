#include"Game.hpp"
#include"TextureManager.hpp"
#include"GameObject.hpp"
#include"Enemy1.hpp"
#include<bits/stdc++.h>


int i=5;
// SDL_Texture* playertex;
// SDL_Rect src_rect;
// SDL_Rect dst_rect;
//TextureManager texmanager;
GameObject* player=nullptr;
GameObject* enemy=nullptr;
SDL_Renderer* Game::renderer=nullptr;

Game::Game()
{}
Game::~Game()
{}
void Game::init(const char *title,int xpos,int ypos,bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags=SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        std:: cout << "Subsystems Initialised!..."<<std:: endl;
        window=SDL_CreateWindow(title,xpos,ypos,SCREEN_HEIGHT,SCREEN_WIDTH,flags);
        if(window)
        {
            std:: cout << "Window created!"<<std::endl;
        }
        renderer=SDL_CreateRenderer(window,-1,0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            std:: cout << "Renderer created!"<<std::endl;
        }
        isRunning=true;
    }
    else
    {
        isRunning=false;
    }

    // SDL_Surface* tmpSurface=IMG_Load("/home/karanjitsaha/Desktop/cpp_project/download.jpg");
    // playertex=SDL_CreateTextureFromSurface(renderer,tmpSurface);
    // SDL_FreeSurface(tmpSurface);
    // playertex=TextureManager::LoadTexture("/home/karanjitsaha/Desktop/cpp_project/iron.png",renderer);
    player=new GameObject("/home/karanjitsaha/Desktop/cpp_project/iron.png",0,0);
    std::cout<<"fbfjfvnd"<<std::endl;
    enemy=new Enemy1("/home/karanjitsaha/Desktop/cpp_project/iron.png",720,64);
}
void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning=false;
        break; 
    
    default:
        break;
    }
}
void Game::update()
{
    // count++;
    // //dst_rect.h=64,dst_rect.w=64,dst_rect.x=pow(count,1);
    // //dst_rect.h=window_height,dst_rect.w=window_width;
    // std::cout << count << std::endl;
    player->Update(&i);
    enemy->Update();
}
void Game::render()
{
    SDL_RenderClear(renderer);
    player->Render();
    enemy->Render();
    // SDL_RenderCopy(renderer,playertex,nullptr,&dst_rect);
    SDL_RenderPresent(renderer);//yaha pe add krenge stuff jo render krna hai

}
void Game:: clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Game Cleaned"<<std::endl;
}