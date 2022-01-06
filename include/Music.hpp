#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include<iostream>
using namespace std;

class Music
{
public:

	Music();
	~Music();
	void playmusic(const char*, bool);
};
