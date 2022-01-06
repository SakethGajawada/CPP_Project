#include "../include/Score.hpp"
#include "../include/Game.hpp"
#include <SDL2/SDL_ttf.h>
#include<string>


Score::Score()
{
	TTF_Init();
}


void get_text_and_rect(SDL_Renderer* renderer, int x, int y, const char* txt, TTF_Font* font, SDL_Texture* texture, SDL_Rect* rect, int screenno)
{
	SDL_Color txtColor = { 255, 255, 255, 0 };
	SDL_Surface* surf;
	SDL_Color backgroundColor = {0,0,0};

	surf= TTF_RenderText_Shaded(font, txt, txtColor,backgroundColor);
	rect->x = x;
	rect->y = y;
	rect->w = surf->w;
	rect->h = surf->h;
	SDL_FreeSurface(surf);
}



void Score::render(int score_count,SDL_Renderer* renderer,int screenno)
{

	string outputText = "Score: " + to_string(score_count);
	TTF_Font* Usedfont = TTF_OpenFont("../assets/ttf_files/Symtext.ttf", 40);
	if (Usedfont == NULL)
	{
		cout<<stderr<<"error: font not found"<<endl;
		exit(EXIT_FAILURE);
	}

	SDL_Surface* surf;
	SDL_Color txtColor = { 255, 255, 255, 0 };


	SDL_Color backgroundColor = { 56, 178, 215 };

	if(screenno == 1)
		backgroundColor = { 56, 178, 215 };
	
	else
		backgroundColor = {0,0,0};
	

	surf = TTF_RenderText_Shaded(Usedfont, outputText.c_str(),txtColor, backgroundColor);
	if(texture)
	{
		SDL_DestroyTexture(texture);
	}
	texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);	
	rect->x = 0;
	rect->y = 0;
	rect->w = surf->w;
	rect->h = surf->h;
	SDL_RenderCopy(renderer, texture, NULL, rect);

	TTF_CloseFont(Usedfont);
}
