#include"Enemy1.hpp"
#include<SDL2/SDL.h>

Enemy1::Enemy1(const char*texturesheet,SDL_Renderer* ren,int x,int y,int vel):Enemy::Enemy(texturesheet,ren,x,y,vel){}

void Enemy1::movement()
{
	this->MoveObj(-enemyspeed, 0);
}

void Enemy1::animation()
{
	if (SDL_GetTicks() % 500 <= 28 && SDL_GetTicks() % 500 >= 15)
	{
		if (animationFlag == 0)
		{
			this->animate("enemy_standing2.png", renderer);
			animationFlag = 1;
		}
		else
		{
			this->animate("enemy_standing.png", renderer);
			animationFlag = 0;
		}
	}
}
