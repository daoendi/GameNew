#include "GameLoop.h"

GameLoop::GameLoop() 
{
	p_object_ = NULL;
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;

}
GameLoop:: ~GameLoop()
{
	Free();
}
bool GameLoop::LoadImage(std::string path, SDL_Renderer* screen)
{
	SDL_Texture* new_tex = NULL;
	SDL_Surface* load_surface = IMG_Load(path.c_str());
	if (load_surface != NULL)
	{
		// xoa back nhan vat
		SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
		new_tex = SDL_CreateTextureFromSurface(screen, load_surface);
		if (new_tex != NULL) 
		{
			rect_.w = load_surface->w;
			rect_.h = load_surface->h;
		}
		SDL_FreeSurface(load_surface);

	}
	p_object_ = new_tex;
	return p_object_ = NULL;
}

void GameLoop::Render(SDL_Renderer* des, const SDL_Rect* clip /* = NULL */)
{
	SDL_Rect renderquad = { rect_.x, rect_.y, rect_.w, rect_.h };
	SDL_RenderCopy(des, p_object_, clip, &renderquad);
}

void GameLoop::Free()
{
	if (p_object_ != NULL)
	{
		SDL_DestroyTexture(p_object_);
		p_object_ = NULL;
		rect_.w = 0;
		rect_.h = 0;
			
	}
}