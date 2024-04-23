#include "Player.h"
#include<iostream>
#include"GameLoop.h"
void Player::Render(SDL_Renderer* ren)
{
	SDL_Rect scra = getSrc();
	SDL_Rect destb = getDest();
	SDL_RenderCopyEx(ren, getTexture(), &scra, &destb, 0, NULL, SDL_FLIP_NONE);
}
void Player::PlayerRender(SDL_Renderer* ren, int a)
{
    SDL_Rect scra = getSrc();
    SDL_Rect destb = getDest();
	if (a % 2 == 0)
	{
		animationTimer++;
		if (animationTimer < 16)
		{
			SDL_RenderCopyEx(ren, getTexture(), &scra, &destb, 0, NULL, SDL_FLIP_NONE);
		}
		else if (animationTimer >= 16 && animationTimer <= 32)
		{
			SDL_RenderCopyEx(ren, Tex1, &scra, &destb, 0, NULL, SDL_FLIP_NONE);
		}
		else if (animationTimer > 32)
		{
			SDL_RenderCopyEx(ren, Tex2, &scra, &destb, 0, NULL, SDL_FLIP_NONE);
		}
		if (animationTimer > 48)
		{
			animationTimer = 0;
		}
	}
	else
	{
		if (animationTimer < 16)
		{
			SDL_RenderCopyEx(ren, getTexture(), &scra, &destb, 0, NULL, SDL_FLIP_NONE);
		}
		else if (animationTimer >= 16 && animationTimer <= 32)
		{
			SDL_RenderCopyEx(ren, Tex1, &scra, &destb, 0, NULL, SDL_FLIP_NONE);
		}
		else if (animationTimer > 32)
		{
			SDL_RenderCopyEx(ren, Tex2, &scra, &destb, 0, NULL, SDL_FLIP_NONE);
		}
		if (animationTimer > 48)
		{
			animationTimer = 0;
		}
	}
}

void Player::Gravity()
{

	if (JumpState())
	{
		SpeedUp = SpeedUp + gravity;
		Ypos = Ypos  + SpeedUp;
		setDest(25, Ypos, 72, 72);
		if (SpeedUp > 0)
		{
			inJump = false;
			SpeedUp = -12;
		}
		
	}
	else
	{
		
		if (Ypos < 358)
		{

			SpeedDown = SpeedDown + gravity;
			Ypos = Ypos + SpeedDown;
		}
		else
		{
			Ypos = 358;
			SpeedDown = 0;
		}
		setDest(25, Ypos, 72, 72);
	}

}

void Player::Jump()
{

		if (jumpTimer - lastJump > 920)
		{
			inJump = true;
			lastJump = jumpTimer;
		}
		else
		{
			Gravity();
		}
}

void Player::GetJumpTime()
{
	jumpTimer = SDL_GetTicks();
}

bool Player::JumpState()
{
	return inJump;
}

void Player::CreateTexture1(const char* address, SDL_Renderer* ren)
{
	Tex1 = TextureManager::Texture(address, ren);
}

void Player::CreateTexture2(const char* address, SDL_Renderer* ren)
{
	Tex2 = TextureManager::Texture(address, ren);
}
