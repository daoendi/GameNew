#include "Sound.h"

Music::Music()
{
	music = NULL;
	sound = NULL;
	check = false;
}

Music::~Music()
{
	if (music != NULL)
	{
		Mix_FreeMusic(music);
		music = NULL;
	}
	if (sound != NULL)
	{
		Mix_FreeChunk(sound);
		sound = NULL;
	}
}

bool Music::loadMusic(const char* path)
{
	music = Mix_LoadMUS(path);
	if (music == NULL)
	{
		std::cout << "Load Error";
		return false;
	}

	return true;
}

bool Music::loadSound(const char* path)
{
	sound = Mix_LoadWAV(path);
	if (sound == NULL)
	{
		return false;
	}

	return true;
}

void Music::playMusic(int loop)
{
	if (music) Mix_PlayMusic(music,loop);
	check = true;
}

void Music::playSound(int loop)
{
	SDL_Delay(10);

	if (sound) Mix_PlayChannel(loop, sound,0);
		check = true;
}

void Music::stopMusic()
{
	if (music) Mix_HaltMusic();
}

void Music::pauseMusic()
{
	if (music) Mix_PausedMusic();
}

