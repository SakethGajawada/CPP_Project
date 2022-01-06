#pragma once
#include"GameObject.hpp"

class Enemy : public GameObject
{
protected:
    int animationFlag;
public:
    Enemy(const char* texturesheet, SDL_Renderer* renderer, int x, int y, int vel);
    virtual void animation() = 0;
    virtual void movement() = 0;
};

