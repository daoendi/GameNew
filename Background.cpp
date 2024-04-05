#include "Background.h"

void Background::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

void Background::GroundRender(SDL_Renderer* ren)
{
    SDL_Rect scrb = getSrc();
    SDL_Rect destb = getDest();
    SDL_Texture* texb = getTexture();
	SDL_RenderCopy(ren, texb , &scrb, &destb);
}

void Background::GroundUpdate1(){

	if (distance1 <= -800)
	{
		distance1 = 800;
	}
	else
	{
		distance1--;
		setSrc(0, 0, 112, 800);
		setDest(distance1, 420, 112, 800);
	}
}

void Background::GroundUpdate2()
{
	if (distance2 <= -800)
	{
		distance2 = 800;
	}
	else
	{
		distance2--;
		setSrc(0, 0, 112, 800);
		setDest(distance2, 420, 112, 800);
	}
}
