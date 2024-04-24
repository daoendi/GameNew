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
		g->Initalize();
		bool gameinit = true;
		while (gameinit)
		{
			pause = g->pause();
			over = g->checkgameover();
			g->Event();
			if (!over)
			{
				if (!start)
				{
					g->RenderMenu();
					g->MenuEvent(start);
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
				g->OverEvent(gameinit);
			}
			first = SDL_GetTicks();
			if (first - last < 16.7)
			{
				SDL_Delay(16.7 - (first - last));
			}
			last = first;
		}
		g->Clear();
	}
	return 0;
}




