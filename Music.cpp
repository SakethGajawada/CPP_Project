#include "Music.hpp"

Music::Music()
{
	SDL_Init(SDL_INIT_AUDIO);

	int audio_rate = MIX_DEFAULT_FREQUENCY;
	Uint16 audio_format = AUDIO_S16SYS;
	int audio_channels = 2;
	int audio_buffers = 4096;

	if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0)
	{
		cout << "Couldn't initialise audio:" << Mix_GetError() << endl;
		exit(0);
	}
}

Music::~Music()
{
	Mix_Quit();
}

void Music::playmusic(const char* path,bool playmus)
{
	if (playmus == true)
		Mix_HaltMusic;
	Mix_Music* music = Mix_LoadMUS(path);
	if (music== nullptr)
	{
		cout << Mix_GetError();
	}
	Mix_PlayMusic(music, -1);
}

