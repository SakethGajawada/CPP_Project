#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<SDL2/SDL_ttf.h>
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
	string playerName=" "; //Game will not start unless playerName is changed
	Uint32 frameStart;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* backgroundTex;
	TTF_Font* font;
	SDL_Color text_color;
	string text = "0";
	SDL_Surface* text_surface;
	SDL_Texture* texture = nullptr;
	SDL_Rect Score_rect;
	SDL_Surface* background;
	int screenno=0;//0 =start screen 1 main screen 2 game_over screen

public:
	Game(int w, int l);
	~Game();

	void set_playerName(string nam) { playerName = nam; }
	void init(const char* title, int x_coord, int y_coord, int width, int height, bool fullscreen);
	void events();
	void update();
	void render();
	void clean();
	bool running();

	static SDL_Event event;
};
