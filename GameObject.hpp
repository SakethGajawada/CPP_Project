#pragma once
#include"Game.hpp"

class GameObject
{
    private:
    SDL_Texture* objTexture;
    //SDL_Renderer* renderer;
    public:
    int xpos, ypos;
    SDL_Rect src_rect,dst_rect;
    GameObject(const char* texturesheet,int x,int y);
    ~GameObject();
    void Update();
    void Render();
    void setSrc(int x,int y,int h,int w)
    {
        src_rect.x = x; src_rect.y = y; src_rect.h = h; src_rect.w = w;
    }
    void setDest(int w,int h)
    {
        dst_rect.w = w;
        dst_rect.h=h;
    }
    virtual int set_x_trajectory()=0;
    virtual int set_y_trajectory()=0;
    // void setSpeed(int s)
    // {
    //     speed=s;
    // }
    //virtual void set_trajectory();



} ;