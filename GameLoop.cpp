#include"GameLoop.h"
#include <string>


GameLoop::GameLoop()
{
	window = NULL;
	renderer = NULL;
	GameState = false;
	gamepause = 0;
	p.setSrc(0, 0, 108, 108);
	p.setDest(25, HEIGHT / 2, 108, 108);
	pausebutton.setSrc(0, 0, 50, 50);
	pausebutton.setDest(750, 0, 50, 50);
	bpause.setSrc(0, 0, 150, 150);
	bpause.setDest(325, 185, 150, 150);
	b1.setSrc(0, 0, 520, 800);
	b1.setDest(0, 520, 520, 800);
	b2.setSrc(0, 0, 520, 800);
	b2.setDest(336, 520, 112, 800);
	ground1.setSrc(0, 0, 112,800);
	ground1.setDest(0, 420, 112, 800);
	ground2.setSrc(0, 0, 112, 800);
	ground2.setDest(336, 420, 112, 800);
	gameover.setSrc(0, 0, 520, 800);
	gameover.setDest(0, 0, 520, 800);
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
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			Mix_GetError();
	}

	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			GameState = true;
			gamemusic.loadMusic("Sound/bkgr_audio.wav");
			jumpsound.loadSound("Sound/jump_sound.wav");
			oversound.loadSound("Sound/lose_sound.wav"); 
			bstart.CreateTexture("Image/menu.png", renderer);
			p.CreateTexture("Image/dino1.png", renderer);
			gameover.CreateTexture("Image/gameover.png", renderer);
			p.CreateTexture1("Image/dino2.png", renderer);
			p.CreateTexture2("Image/dino3.png", renderer);
			b.CreateTexture("Image/background.png", renderer);
			b1.CreateTexture("Image/texture1.png", renderer);
			b2.CreateTexture("Image/texture1.png", renderer);
			mod1.CreateTexture("Image/enemy1.png", renderer);
			mod2.CreateTexture("Image/enemy2.png", renderer);
			mod3.CreateTexture("Image/enemy3.png", renderer);
			ground1.CreateTexture("Image/base.png", renderer);
			ground2.CreateTexture("Image/base.png", renderer);
			bpause.CreateTexture("Image/pause.png", renderer);
			pausebutton.CreateTexture("Image/pause2.png", renderer);
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
	gamemusic.playMusic();
}

void GameLoop::Event()
{
	p.GetJumpTime();
	SDL_PollEvent(&event1);
	
	if (gamepause % 2 == 1)
	{
		if (event1.button.button == SDL_BUTTON_LEFT)
		{
			gamepause++;
			event1.button.button = NULL;
		}
	}
	else
	{
		if (event1.button.button == SDL_BUTTON_LEFT)
		{
			if (event1.button.x > 600 and event1.button.x < 800 and event1.button.y > 0 and event1.button.y < 150)
			{
				gamepause++;
				event1.button.button = NULL;
			}
		}
	}
	if (event1.type == SDL_QUIT)
	{
		exit(0);
	}
	if (event1.type == SDL_KEYDOWN)
	{
		if (event1.key.keysym.sym == SDLK_SPACE)
		{
			if (gamepause % 2 == 1)
			{
					gamepause++;
			}
			if (!p.JumpState())
			{
					p.Jump();
					std::cout << " pes";
					jumpsound.playSound();
			}
			else
			{
				p.Gravity();
			}
		}
		if (event1.key.keysym.sym == SDLK_p)
		{
			gamepause ++;
		}
		
	}
	else
	{
		p.Gravity();
	}
}
void GameLoop::Update()
{
	b1.BackUpdate1();
	b2.BackUpdate2();
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
		b1.GroundRender(renderer);
		b2.GroundRender(renderer);
		ground1.GroundRender(renderer);
		ground2.GroundRender(renderer);
		if (gamepause % 2 == 1)
		{
			bpause.GroundRender(renderer);
		}
		else
		{
			pausebutton.GroundRender(renderer);
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
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
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
		GameEnd = true;
	}
}
bool GameLoop::checkgameover()
{
	return GameEnd;
}
void GameLoop::RenderOver()
{if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			Mix_GetError();
	}
	gamemusic.stopMusic();
	if (over)
	{
		oversound.playSound();
		over = NULL;
	}
	SDL_RenderClear(renderer);
	gameover.GroundRender(renderer);
	SDL_RenderPresent(renderer);
}
