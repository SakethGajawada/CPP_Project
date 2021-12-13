#pragma once
#include"GameObject.hpp"
class Enemy: public GameObject
{
    protected:
    int speed=5,x=736,y;
    // SDL_Texture* objTexture;
    public:
    // int xpos, ypos;
    // SDL_Rect src_rect,dst_rect;
    //virtual int set_y_trajectory()=0;
    int set_x_trajectory();
    Enemy(const char* texturesheet,int x,int y);
    //~Enemy();
};