#include "TextManager.h"


Text::Text()
{
	Tcolor.r = 255;
	Tcolor.g = 255;
	Tcolor.b = 255;
	Ttex = NULL;

}
Text::~Text()
{

}

bool Text::LoadFromRenderText(TTF_Font& font, SDL_Renderer* screen)
{
	SDL_Surface* Tsurf = TTF_RenderText_Solid(&font, val.c_str(), Tcolor);
	if (Tsurf)
	{
		Ttex = SDL_CreateTextureFromSurface(screen, Tsurf);
		Twidth = Tsurf->w;
		Theight = Tsurf->h;

		SDL_FreeSurface(Tsurf);
	}
	return Ttex != NULL;
}
void Text::Free()
{
	if (Ttex != NULL)
	{
		SDL_DestroyTexture(Ttex);
		Ttex = NULL; 
	}
}

void Text::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	Tcolor.r = red;
	Tcolor.g = green;
	Tcolor.b = blue;
}

void Text::SetColor(int type)
{
	if (type == RED_TEXT)
	{
		SDL_Color color = { 255, 0, 0 };
	}
	else if (type == WHITE_TEXT)
	{
		SDL_Color color = { 255, 255, 255 };
	}
	else if (type == BLACK_TEXT)
	{
		SDL_Color color = { 0, 0, 0 };
	}
}

void Text::RenderText(SDL_Renderer* screen, int xp, int yp, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { xp , yp ,Twidth, Theight };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(screen, Ttex, clip, &renderQuad, angle, center, flip);

}


int Text::GetWidth()
{
	return Theight;
}

int Text::GetHeight()
{
	return Theight;
}
void Text::SetText(const std::string& text)
{
	val = text;
}

std::string Text::GetText()
{
	return std::string();
}
