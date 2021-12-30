#include"Enemy3.hpp"

Enemy3::Enemy3(const char* texturesheet, SDL_Renderer* ren, int x, int y, int vel) :Enemy::Enemy(texturesheet, ren, x, y, vel) {};


void Enemy3::movement()
{
	if (SDL_GetTicks() % 1000 <= 28 && SDL_GetTicks() % 500 >= 15)
	{
		this->set_ypos(100 + rand() % 400);
	}
	if (movingUp == 0 && this->get_ypos() <= 450)
	{
		this->MoveObj(-enemyspeed, enemyUpSpeed);
	}
	else if (movingUp == 0 && this->get_ypos() > 450)
	{
		movingUp = 1;
	}
	else if (movingUp == 1 && this->get_ypos() >= 50)
	{
		this->MoveObj(-enemyspeed, -enemyUpSpeed);
	}

	else if (movingUp == 1 && this->get_ypos() < 50)
	{
		movingUp = 0;
	}
}

void Enemy3::animation()
{
	if (SDL_GetTicks() % 500 <= 28 && SDL_GetTicks() % 500 >= 15)
	{
		if (animationFlag == 0)
		{
			this->animate("enemy3.png", renderer);
			animationFlag = 1;
		}
		else
		{
			this->animate("enemy3_2.png", renderer);
			animationFlag = 0;
		}
	}
}