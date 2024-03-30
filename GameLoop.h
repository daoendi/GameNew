#pragma once
#ifndef GAME_LOOP_H_
#define GAME_LOOP_H_

#include "CommonFunction.h"

class GameLoop
{
public:
	GameLoop();
	~GameLoop();
	void SetRect(const int& x, const int& y)
	{
		rect_.x = x;
		rect_.y = y;
	}
	SDL_Rect GetRect() const {
		return rect_;
	}
	SDL_Texture* GetObject() const {
		return p_object_;
	}
	bool LoadImage(std::string path, SDL_Renderer* screen);
	void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
	void Free();
protected:
	SDL_Texture* p_object_;
	SDL_Rect rect_;

};
#endif // !GAME_LOOP_H_
