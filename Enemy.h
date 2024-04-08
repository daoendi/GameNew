#pragma once
#include "Object.h"

class Enemy: public Object
{
private:
	int distance1 = 800;
	int distance2 = 1200;
	int distance3 = 1600;
public:
	void EnemyUpdate1();
	void EnemyUpdate2();
	void EnemyUpdate3();
	void Render(SDL_Renderer* ren);
	void EnemyRender(SDL_Renderer* ren);
}; 