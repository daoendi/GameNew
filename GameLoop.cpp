#include"GameLoop.h"

GameLoop::GameLoop()
{
	window = NULL;
	renderer = NULL;
	GameState = false;
	p.setSrc(0, 0, 72, 72);
	p.setDest(25, HEIGHT / 2, 72, 72);
	ground1.setSrc(0, 0, 112,800);
	ground1.setDest(0, 420, 112, 800);
	ground2.setSrc(0, 0, 112, 800);
	ground2.setDest(336, 420, 112, 800);
}

bool GameLoop::getGameState()
{
	return GameState;
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
			}
			else
			{
				p.Gravity();
			}
		}
	}
	else
	{
		p.Gravity();
	}
}

void GameLoop::Update()
{
	ground1.GroundUpdate1();
	ground2.GroundUpdate2();
	mod1.EnemyUpdate1();
	mod2.EnemyUpdate2();
	mod3.EnemyUpdate3();
}

void GameLoop::Render()
{
	SDL_RenderClear(renderer);
	b.Render(renderer);
	b1.Render(renderer);
	b3.Render(renderer);
	ground1.GroundRender(renderer);
	ground2.GroundRender(renderer);
	mod1.EnemyRender(renderer);
	mod2.EnemyRender(renderer);
	mod3.EnemyRender(renderer);
	p.Render(renderer);
	SDL_RenderPresent(renderer);
}

void GameLoop::Clear()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
