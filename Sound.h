#pragma once
#include<SDL_mixer.h>
#include <iostream>

class Music
{
private:
	Mix_Chunk* sound;
	Mix_Music* music;
	bool check;
public: 
	Music();
	~Music();
	bool loadMusic(const char* path);
	bool loadSound(const char* path);
	void playMusic(int loop = -1);
	void playSound(int loop = -1);
	void stopMusic();
	void pauseMusic();
	bool inPlay();
	void reset();
	void checkMusic();

};