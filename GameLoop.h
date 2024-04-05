#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"Player.h"
#include"Background.h"
#include"Enemy.h"
class GameLoop
{
private:
	Player p;
	Background b,b1,b3;
	Background ground1, ground2;
	Enemy mod1,mod2,mod3;
	const int HEIGHT = 520;
	const int WIDTH = 800;
	bool GameState;
	SDL_Window* window;
	SDL_Event event1, event2;
	SDL_Renderer* renderer;
public:
	GameLoop();
	bool getGameState();
	void Update();
	void Intialize();
	void Event();
	void Render();
	void Clear();
};