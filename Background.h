#pragma once
#include "Object.h"

class Background :public Object
{
private:

	int distance1 = 0;
	int distance2 = 750;
	int distance3 = 0;
	int distance4 = 800;
	int accelerator = 0;
public:
	void GroundUpdate1();
	void GroundUpdate2();
	void BackUpdate1();
	void BackUpdate2();
	void Render(SDL_Renderer* ren);
	void GroundRender(SDL_Renderer* ren);
};