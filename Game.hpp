#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>
#include<iostream>

using namespace std;

class Game
{
private:
	bool isRunning;
	int screenWidth, screenLength;
	int playerSpeed = 5;
	int bulletSpeed = 20;
	int enemySpeed = 2;
	int actEnemy = 0;
	int bulletFlag, powerFlag, enemyFlag,animationFlag;
	Uint32 frameStart;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* backgroundTex;

public:
	Game(int w, int l);
	~Game();

	void init(const char* title, int x_coord, int y_coord, int width, int height, bool fullscreen);
	void events();
	void update();
	void render();
	void clean();
	bool running();

	static SDL_Event event;
};
