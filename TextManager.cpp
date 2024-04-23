#include "TextManager.h"

Text::Text()
{
	Textcolor.r = 255;
	Textcolor.g = 255;
	Textcolor.g = 255;
	Texttex = NULL;
}

Text::~Text()
{
}

bool Text::LoadFromFile(std::string path)
{
	return false;
}

bool Text::LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen)
{
	SDL_Surface* textsurface = TTF_RenderText_Solid(font, val.c_str(), Textcolor);
	if (textsurface)
	{
		Texttex = SDL_CreateTextureFromSurface(screen, textsurface);
		Textwidth = textsurface->w;
		Textheight = textsurface->h;
		SDL_FreeSurface(textsurface);
	}
	return Texttex != NULL;
}

void Text::Free()
{
	if (Texttex != NULL)
	{
		SDL_DestroyTexture(Texttex);
		Texttex = NULL;
	}
}

void Text::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	Textcolor.r = red;
	Textcolor.g = green;
	Textcolor.b = blue;
}

void Text::SetColor(int type)
{
	if (type == RED_TEXT)
	{
		SDL_Color color = { 255,0,0 };
		Textcolor = color;
	}
	else if (type == WHITE_TEXT)
	{
		SDL_Color color = { 255,255,255 };
		Textcolor = color;
	}
	else if (type == BLACK_TEXT)
	{
		SDL_Color color = { 0,0,0 };
		Textcolor = color;
	}
}

void Text::RenderText(SDL_Renderer* screen, int xp, int yp, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { xp,yp,Textwidth,Textheight };
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;

	}
	SDL_RenderCopyEx(screen, Texttex, clip, &renderQuad, angle, center, flip);
}

/*int Text::GetWidth()
{
	return Textwidth;
}

int Text::GetHeight()
{
	return Textheight;
}
*/
void Text::SetText(const std::string& text)
{
	val = text;
}

std::string Text::GetText()
{
	return val;
}
