#include"TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* ren)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	 SDL_CreateTextureFromSurface(ren, tempSurface);
	//SDL_FreeSurface(tempSurface);
	//SDL_DestroyTexture(tex);

	//return tex;
}