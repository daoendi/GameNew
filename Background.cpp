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
	accelerator++;
	if (distance1 <= -750)
	{
		distance1 = 750;
	}
	else
	{
		distance1 -= (2 + accelerator / 2000);
		setSrc(0, 0, 112, 800);
		setDest(distance1, 420, 112, 800);
	}
}

void Background::GroundUpdate2()
{
	accelerator++;
	if (distance2 <= -750)
	{
		distance2 = 750;
	}
	else
	{
		distance2 -= (2 + accelerator / 2000);
		setSrc(0, 0, 112, 800);
		setDest(distance2, 420, 112, 800);
	}
}
void Background::BackUpdate1() {
	accelerator++;
	if (distance3 <= -800)
	{
		distance3 = 800;
	}
	else
	{
		distance3 -= (1 + accelerator / 2000);
		setSrc(0, 0, 520, 800);
		setDest(distance3, 0, 520, 800);
	}
}
void Background::BackUpdate2() {
	accelerator++;
	if (distance4 <= -800)
	{
		distance4 = 800;
	}
	else
	{
		distance4 -= (1 + accelerator / 2000);
		setSrc(0, 0, 520, 800);
		setDest(distance4, 0, 520, 800);
	}
}
