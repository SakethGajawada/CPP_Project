#pragma once
#include"GameObject.hpp"

class Player : public GameObject
{
    public:
    Player(SDL_Renderer* renderer,int vel);
    ~Player();
    void set_y_trajetory(){ypos=0;}
    void set_x_trajetory(){xpos=0;}
    
};