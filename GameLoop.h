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
	Background b,b1,b3;
	Background ground1, ground2;
	Background bstart, bpause;
	Background gameover,pausebutton;
	Enemy mod1,mod2,mod3;
	const int HEIGHT = 520;
	const int WIDTH = 800;
	bool GameState;
	bool GameEnd;
	SDL_Window* window;
	SDL_Event event, event1, event2;
	SDL_Renderer* renderer;
	int x_event, y_event;
	//bool gamestart;
	int gamepause;
	bool over = true;
public:
//	bool start();
	int pause();
	bool checkgameover();
	GameLoop();
	bool getGameState();
	void Update();
	void Intialize();
	void Event();
	void Render();
	void RenderMenu();
	//void RenderPause();
	void RenderOver();
	void Clear();       
	void Close();
	SDL_Rect GetFrameP(Player p);
	SDL_Rect GetFrameE(Enemy p);
	void Check();
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
};