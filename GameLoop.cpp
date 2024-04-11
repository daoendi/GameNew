#include"GameLoop.h"
#include <string>

GameLoop::GameLoop()
{
	window = NULL;
	renderer = NULL;
	GameState = false;
	gamestart = 0;
	gamepause = 0;
	p.setSrc(0, 0, 108, 108);
	p.setDest(25, HEIGHT / 2, 108, 108);
	bpause.setSrc(0, 0, 150, 150);
	bpause.setDest(325, 185, 150, 150);
	ground1.setSrc(0, 0, 112,800);
	ground1.setDest(0, 420, 112, 800);
	ground2.setSrc(0, 0, 112, 800);
	ground2.setDest(336, 420, 112, 800);
}
bool GameLoop::getGameState()
{
	return GameState;
}

int GameLoop::pause()
{
	return gamepause;
}

void GameLoop::Intialize()
{
	

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Dino", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			
			std::cout << "Succeeded!" << std::endl;
			GameState = true;
		//	std::string str_time = "Point:";
			//Uint32 time_val = SDL_GetTicks() / 1000;
			//std::string str_val = std::to_string(time_val);
			//time.SetText(str_time);
			bstart.CreateTexture("Image/menu.png", renderer);
			p.CreateTexture("Image/dino1.png", renderer);
			p.CreateTexture1("Image/dino2.png", renderer);
			p.CreateTexture2("Image/dino3.png", renderer);
			b.CreateTexture("Image/background2.png", renderer);
			b1.CreateTexture("Image/texture1.png", renderer);
			b3.CreateTexture("Image/texture3.png", renderer);
			mod1.CreateTexture("Image/enemy1.png", renderer);
			mod2.CreateTexture("Image/enemy2.png", renderer);
			mod3.CreateTexture("Image/enemy3.png", renderer);
			ground1.CreateTexture("Image/base.png", renderer);
			ground2.CreateTexture("Image/base.png", renderer);
			bpause.CreateTexture("Image/pause.png", renderer);
	//		time.LoadFromRenderText(&font_time, renderer);
//time.RenderText(renderer, WIDTH - 200, 15);
		}
		else
		{
			std::cout << "Not created!" << std::endl;
		}
	}
	else
	{
		std::cout << "window not created!" << std::endl;
	}
	//if (TTF_Init() == -1)
	//{
	//	std::cout << "font error!";
	//}
	
}

void GameLoop::Event()
{
	p.GetJumpTime();
	SDL_PollEvent(&event1);
	if (event1.type == SDL_QUIT)
	{
		GameState = false;
	}
	if (event1.type == SDL_KEYDOWN)
	{
		if (event1.key.keysym.sym == SDLK_SPACE)
		{
			if (!p.JumpState())
			{
					p.Jump();
					std::cout << " pes";
					//gamestart = true;
					//gamepause = false;
			}
			else
			{
				p.Gravity();
			}
		}
		if (event1.key.keysym.sym == SDLK_p)
		{
			//gamestart = false;
			gamepause ++;
		}
		if (event1.key.keysym.sym == SDLK_s)
		{
			gamestart ++;
			//gamepause = true;
		}
	}
	else
	{
		p.Gravity();
	}
}
int GameLoop::start()
{
	return gamestart;
}
void GameLoop::Update()
{
	ground1.GroundUpdate1();
	ground2.GroundUpdate2();
	mod1.EnemyUpdate1();
	mod2.EnemyUpdate2();
	mod3.EnemyUpdate3();
}
void GameLoop::RenderMenu()
{
	SDL_RenderClear(renderer);
	bstart.Render(renderer);
	SDL_RenderPresent(renderer);
}
void GameLoop::Render()
{

		
		SDL_RenderClear(renderer);
		b.Render(renderer);
		b1.Render(renderer);
		b3.Render(renderer);
		ground1.GroundRender(renderer);
		ground2.GroundRender(renderer);
		if (gamepause % 2 == 1)
		{
			bpause.GroundRender(renderer);
		}
		p.PlayerRender(renderer, gamepause);
		mod1.EnemyRender(renderer);
		mod2.EnemyRender(renderer);
		mod3.EnemyRender(renderer);
		
		SDL_RenderPresent(renderer);
}

void GameLoop::Clear()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

bool GameLoop::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2) 
{
	int left_a = object1.x;
	int right_a = object1.x + object1.w;
	int top_a = object1.y;
	int bottom_a = object1.y + object1.h;

	int left_b = object2.x;
	int right_b = object2.x + object2.w;
	int top_b = object2.y;
	int bottom_b = object2.y + object2.h;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 1 < size object 2
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}
void GameLoop::Close()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = NULL;
	renderer = NULL;
	IMG_Quit();
	//Mix_Quit();
	//TTF_Quit();
	SDL_Quit();
}
SDL_Rect GameLoop::GetFrameP( Player p)
{
	SDL_Rect rectF = {};
	SDL_Rect scra = p.getDest();
	rectF.x = scra.x;
	rectF.y = scra.y;
	rectF.w = scra.w / 8;
	rectF.h = scra.h;
	return rectF;
	
}
SDL_Rect GameLoop::GetFrameE( Enemy e)
{
	SDL_Rect rectE = {};
	SDL_Rect scra = e.getDest();
	rectE.x = scra.x;
	rectE.y = scra.y;
	rectE.w = scra.w / 8;
	rectE.h = scra.h;
	return rectE;

}
void GameLoop::Check()
{
	GameEnd = false;
	SDL_Rect cplayer = GameLoop::GetFrameP(p);
	SDL_Rect Fenemy1 = GameLoop::GetFrameE(mod1);
	SDL_Rect Fenemy2 = GameLoop::GetFrameE(mod2);
	SDL_Rect Fenemy3 = GameLoop::GetFrameE(mod3);
	if(CheckCollision(cplayer,Fenemy1)|| CheckCollision(cplayer, Fenemy2) || CheckCollision(cplayer, Fenemy3))
	{
		Close();
		exit(0);
	}
}

void GameLoop::RenderPause()
{
	SDL_RenderClear(renderer);
	bpause.GroundRender(renderer);
	SDL_RenderPresent(renderer);
}
