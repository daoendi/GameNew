#include"GameLoop.h"
#include "TextManager.h"
GameLoop* g = new GameLoop();

int main(int argc, char** argv)
{
	SDL_Event event;
	int init2 = 0;
	bool over = false;
	double first;
	double last = 0;
	bool start = false;
	bool pause = false;
	bool again = false;
	bool exitgame = false;
	g->Intialize();

	while (g->getGameState())
	{

		//again = g->start();
		init2 = g->pause();
		over = g->checkgameover();
		g->Event();
		//g->Update();


		if (!over)
		{
			if (!start)
			{
				g->RenderMenu();
			}
			if (start) {
				g->Render();
				if (init2 % 2 == 0) {
					g->Update();
				}
				g->Check();
			}
		}
		else
		{
			g->RenderOver();
			g->Event();
		}
		first = SDL_GetTicks();
		if (first - last < 16.7)
		{
			SDL_Delay(16.7 - (first - last));
		}
		last = first;
		if (!start)
		{
			SDL_PollEvent(&event);
			if (event.button.button == SDL_BUTTON_LEFT) {
				if (event.button.x < 600 and event.button.x > 320 and event.button.y > 220 and event.button.y < 340)
				{
					start = true;
				}
				if (event.button.x < 600 and event.button.x > 320 and event.button.y > 365 and event.button.y < 485)
				{
					exit(0);
				}
			}

		}

		
	}
		g->Clear();
	return 0;
}