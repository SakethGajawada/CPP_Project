#pragma once
#include"Enemy.hpp"
class Enemy2 : public Enemy
{
private:
    int enemyspeed = 2;
    int enemyUpSpeed = 2;
    int movingUp = 0; //0->moving down, 1->moving up
public:
    Enemy2(const char* texturesheet, SDL_Renderer* ren, int x, int y, int vel);

    void animation();
    void movement();

};
