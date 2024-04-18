#include"GameLoop.h"
#include "TextManager.h"
//GameLoop* g = new GameLoop();

int main(int argc, char** argv)
{
	
	bool again = false;
	while(!again)
	{
		SDL_Event event;
		SDL_Event event1;
		int pause = 0;
		bool over = false;
		double first;
		double last = 0;
		bool start = false;
		
		GameLoop* g = new GameLoop();
		g->Intialize();
		bool gameinit = g->getGameState();
		while (gameinit)
		{
			int x = 0;
			int y = 0;
			pause = g->pause();
			over = g->checkgameover();
			g->Event();
			if (!over)
			{
				if (!start)
				{
					g->RenderMenu();
				}
				if (start) {
					g->Render();

					if (pause % 2 == 0) {
						g->Update();
					}
					g->Check();
				}
			}
			else
			{
				g->RenderOver();
				start = false;
				SDL_PollEvent(&event1);
				x = 0;
				y = 0;
				if (event1.button.button == SDL_BUTTON_LEFT)
				{
					x = event1.button.x;
					y = event1.button.y;
					if (x < 380 and x > 100 and y > 280 and y < 400)
					{
						
						gameinit = false;
						event1.button.button = NULL;
						
					}
					else if (x < 720 and x > 440 and y > 280 and y < 400)
					{
						exit(0);
					}
				}
			}
			first = SDL_GetTicks();
			if (first - last < 16.7)
			{
				SDL_Delay(16.7 - (first - last));
			}
			last = first;
			if (!start )
			{
				SDL_PollEvent(&event);
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					x = event.button.x;
					y = event.button.y;
					if (x < 600 and x > 320 and y > 220 and y < 340)
					{
						start = true;
						event.button.button = NULL;
					}
					else if (x < 600 and x > 320 and y > 365 and y < 485)
					{
						exit(0);
					}
				}

			}

		}
		g->Clear();
	}
	return 0;
}




