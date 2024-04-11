#include"GameLoop.h"
#include "TextManager.h"
GameLoop* g = new GameLoop();

int main(int argc, char** argv)
{
	int init1 = 0;
	int init2 = 0;
	double first;
	double last = 0;
	g->Intialize();
	while (g->getGameState())
	{
		init1 = g->start();
		init2 = g->pause();
		g->Event();
		//g->Update();
		
		first = SDL_GetTicks();
		if (first - last < 16.7)
		{
			SDL_Delay(16.7 - (first - last));
		}
		last = first;
		if (init1 % 2 == 0)
		{
			g->RenderMenu();
		}
		if ((init1 % 2 == 1)) {
			g->Render();
			if(init2 % 2 == 0){
			g->Update();
			}
			g->Check();
		}

	}
	g->Clear();
	return 0;
}