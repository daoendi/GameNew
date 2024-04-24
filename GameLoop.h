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
#include <fstream>
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
	SDL_Window* window = NULL;
	SDL_Event event1;
	SDL_Renderer* renderer=NULL;
	int gamepause;
	bool over = true;
	TTF_Font* fontscore = NULL;
	SDL_Texture* fonttex = NULL;
	SDL_Texture* fonttex2 = NULL;
	SDL_Color black = { 0, 0 , 0, 255 };
	SDL_Color white = { 255, 255, 255 };
	int score,best;
public:
	TTF_Font* loadFont(const char* path, int size);
	SDL_Texture* RenderText(const std::string& text, TTF_Font* font, SDL_Color color,int score);
	void TextRender(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer);
	int pause();
	bool checkgameover();
	GameLoop();
	bool getGameState();
	void Update();
	void Initalize();
	void Event();
	void MenuEvent(bool &start);
	void OverEvent(bool &gameinit);
	void Render();
	void RenderMenu();
	void RenderOver();
	void Clear();   
	SDL_Rect GetFrameP(Player p);
	SDL_Rect GetFrameE(Enemy p);
	void Check();
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
	void Highscore();
	void getHighscore();
	
};