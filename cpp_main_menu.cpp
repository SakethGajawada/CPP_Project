#include "SDL.h"
#include<iostream>
int main(int argc, char* argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("DRAGON_BALL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 748, 421, SDL_WINDOW_SHOWN);
	
	SDL_Surface* screen = SDL_GetWindowSurface(window);
	SDL_Surface *image = SDL_LoadBMP("actual.bmp");
	SDL_BlitSurface(image, NULL, screen, NULL);
	SDL_FreeSurface(image);
	bool isRunning = true;
	SDL_Event ev;
	while (isRunning)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
				isRunning = false;
		}
		SDL_UpdateWindowSurface(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}