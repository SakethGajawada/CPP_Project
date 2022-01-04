#pragma once
#include"Enemy.hpp"
class Enemy1 : public Enemy
{
private:
    int enemyspeed = 2;
public:
    Enemy1(const char* texturesheet, SDL_Renderer* ren, int x, int y, int vel);
    void animation();
    void movement();
};