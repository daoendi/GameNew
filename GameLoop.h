#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"Player.h"
#include"Background.h"
#include"Enemy.h"
#include<stdlib.h>
#include <SDL_ttf.h>
#include "Sound.h"
#include"TextManager.h"
class GameLoop
{
private:
	Music gamemusic,jumpsound,oversound;
	Player p;
	Background b,b1,b2;
	Background ground1, ground2;
	Background bstart, bpause;
	Background gameover,pausebutton;
	Enemy mod1,mod2,mod3;
	const int HEIGHT = 520;
	const int WIDTH = 800;
	bool GameState;
	bool GameEnd;
	SDL_Window* window;
	SDL_Event event1;
	SDL_Renderer* renderer;
	
	int gamepause;
	bool over = true;
	SDL_Color color = { 255, 255, 0, 0 };
public:
	int pause();
	bool checkgameover();
	GameLoop();
	bool getGameState();
	void Update();
	void Intialize();
	void Event();
	void Render();
	void RenderMenu();
	void RenderOver();
	void Clear();       ;
	SDL_Rect GetFrameP(Player p);
	SDL_Rect GetFrameE(Enemy p);
	void Check();
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
};