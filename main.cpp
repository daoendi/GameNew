#include"GameLoop.h"
int main(int argc, char** argv)
{
	bool again = false;
	while(!again)
	{
		double first;
		double last = 0;
		bool start = false;
		GameLoop* g = new GameLoop();
		g->Initalize();
		bool gameinit = true;
		while (gameinit)
		{

			if (!g->checkgameover())
			{
				if (!start)
				{
					g->RenderMenu();
					g->MenuEvent(start);
				}
				if (start) {
					g->Render();
					g->Event();
					if (g->pause() % 2 == 0) {
						g->Update();
					}
					g->Check();
				}
			}
			else
			{
				g->RenderOver();
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




