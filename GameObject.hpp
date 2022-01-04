#pragma once
#include"Game.hpp"

class GameObject
{
    protected:
    SDL_Texture* objTexture;
    int xpos,ypos;
    SDL_Rect* src_rect=new SDL_Rect();
    SDL_Rect* dst_rect=new SDL_Rect();
    int vel;
    SDL_Renderer* renderer;
    public:
    //constructor -destructor
    GameObject(const char*texturesheet,SDL_Renderer* renderer,int x,int y,int vel);
    ~GameObject();
    
    //main functions
    void Update(int srch,int srcw);
    void Render();
    void setSrc(int x,int y,int h,int w);
    void setDst(int x,int y,int h,int w);
    void MoveObj(int x_vel,int y_vel);
    void animate(const char* texturesheet,SDL_Renderer* ren);

    //getter- setter
    void set_xpos(int x){xpos=x;}
    void set_ypos(int y){ypos=y;}
    int get_xpos(){return xpos;}
    int get_ypos(){return ypos;}
    int get_velocity(){return vel;}
    void set_velocity(int v){vel=v;}
    SDL_Rect* get_dst_rect(){return dst_rect;}
};