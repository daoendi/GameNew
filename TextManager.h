#pragma once


#include "GameLoop.h"
#include <SDL_ttf.h>
class Text
{
public:
	Text();
	~Text();
	enum TextColor
	{
		RED_TEXT = 0,
		WHITE_TEXT = 1,
		BLACK_TEXT = 2,
	};
	bool LoadFromRenderText(TTF_Font& font, SDL_Renderer* screen);
	void Free();
	void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	void SetColor(int type);
	void RenderText(SDL_Renderer* screen, int xp, int yp, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	int GetWidth();
	int GetHeight();
	void SetText(const std::string& text);
	std::string GetText();
private:
	std::string val;
	SDL_Color Tcolor;
	SDL_Texture* Ttex;
	int Twidth;
	int Theight;
};
