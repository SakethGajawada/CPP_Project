#include "Score.hpp"
#include "Game.hpp"
#include <SDL2/SDL_ttf.h>
#include<string>

void get_text_and_rect(SDL_Renderer* renderer, int x, int y, const char* text, TTF_Font* font, SDL_Texture* texture, SDL_Rect* rect)
{

	int text_width;
	int text_height;
	SDL_Surface* surface;
	SDL_Color textColor = { 255, 255, 255, 0 };

	SDL_Color bColor = { 56, 178, 215 };

		//SDL_Color bColor = { 56, 178, 215 };

	surface = TTF_RenderText_Shaded(font, text, textColor, bColor);
	//texture = SDL_CreateTextureFromSurface(renderer, surface);
	text_width = surface->w;
	text_height = surface->h;
	SDL_FreeSurface(surface);
	rect->x = x;
	rect->y = y;
	rect->w = text_width;
	rect->h = text_height;
}

Score::Score()
{
	TTF_Init();
}

void Score::render(int cnt,SDL_Renderer* renderer)
{

	//cout<<"score ka render"<<endl;
	//int time =  / 10;
	std::string tmp = "Score: " + std::to_string(cnt);
	TTF_Font* font1 = TTF_OpenFont("Symtext.ttf", 40);
	if (font1 == NULL)
	{
		fprintf(stderr, "error: font not found\n");
		exit(EXIT_FAILURE);
	}

	//cout<<"line47"<<endl;

	// get_text_and_rect(renderer, 0, 0, tmp.c_str(), font1, texture, &rect);
	int text_width;
	int text_height;
	SDL_Surface* surface;
	SDL_Color textColor = { 255, 255, 255, 0 };

	SDL_Color bColor = { 56, 178, 215 };

	surface = TTF_RenderText_Shaded(font1, tmp.c_str(),textColor, bColor);
	//cout<<"evbvdje"<<endl;
	if(texture){
		SDL_DestroyTexture(texture);
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	//cout<<"cvbjdvn"<<endl;
	text_width = surface->w;
	text_height = surface->h;
	SDL_FreeSurface(surface);	
	rect->x = 0;
	rect->y = 0;
	rect->w = text_width;
	rect->h = text_height;
	SDL_RenderCopy(renderer, texture, NULL, rect);
	//SDL_DestroyTexture(texture);
	TTF_CloseFont(font1);
	//cout<<"score done"<<endl;
}
