#include "Enemy.h"
#include "Object.h"


void Enemy::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}
void Enemy::EnemyRender(SDL_Renderer* ren)
{
	SDL_Rect scre = getSrc();
	SDL_Rect deste = getDest();
	SDL_Texture* texe = getTexture();
	SDL_RenderCopy(ren, texe, &scre, &deste);
}
void Enemy::EnemyUpdate1()
{
	accelerator++;
	if (distance1 <= -400)
	{
		distance1 = 800;
	}
	else
	{
		distance1 -= (2 + accelerator / 2000) ;
		setSrc(0, 0,108,108);
		setDest(distance1, 328, 108, 108);
	}
}
void Enemy::EnemyUpdate2()
{
	accelerator++;
	if (distance2 <= -400)
	{
		distance2 = 800;
	}
	else
	{
		distance2 -= (2 + accelerator / 2000);
		setSrc(0, 0, 108, 108);
		setDest(distance2, 328, 108, 108);
	}
}
void Enemy::EnemyUpdate3()
{
	accelerator++;
	if (distance3 <= -400)
	{
		distance3 = 800;
	}
	else
	{
		distance3 -= (2 + accelerator / 2000);
		setSrc(0, 0, 108, 108);
		setDest(distance3, 328, 108, 108);
	}
}


