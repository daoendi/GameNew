#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"Player.h"
#include"Background.h"
#include"Enemy.h"
#include<stdlib.h>
#include <SDL_ttf.h>
#include"TextManager.h"
class GameLoop
{
private:
//	TTF_Font* font_time = NULL;
//	Text time;
	Player p;
	Background b,b1,b3;
	Background ground1, ground2;
	Enemy mod1,mod2,mod3;
	const int HEIGHT = 520;
	const int WIDTH = 800;
	bool GameState;
	bool GameEnd;
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
	void Close();
	SDL_Rect GetFrameP(Player p);
	SDL_Rect GetFrameE(Enemy p);
	void Check();
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
};