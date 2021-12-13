#pragma once
#include"GameObject.hpp"
#include<bits/stdc++.h>
#include<vector>
struct bullet {
    SDL_Rect dest;
    int direction;
};
class Player:GameObject
{
    public:
    Player(const char* texturesheet,int x,int y);
    void keyboard_handler();
    std::vector<bullet*> get_bullets(){return bullets;}
    private:
    std::vector<bullet*> bullets;
    int speed=5;
    //bool jump=false;
};