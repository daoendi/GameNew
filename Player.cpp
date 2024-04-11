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
		accelerator1 = accelerator1 + 0.035;
		accelerator2 = accelerator2 + 0.035;
		jumpHeight = jumpHeight + gravity;
		Ypos = Ypos + gravity + accelerator1 + accelerator2 + jumpHeight;
		setDest(25, Ypos, 72, 72);
		if (jumpHeight > 0)
		{
			inJump = false;
			jumpHeight = -12;
		}
		
	}
	else
	{

		accelerator1 = accelerator1 + 0.035;
		accelerator2 = accelerator2 + 0.035;
		ground = ground + gravity + accelerator1 + accelerator2;
		setDest(25, Ypos, 72, 72);
		if (Ypos < 358)
		{
			Ypos += 6;

		}
	}

}

void Player::Jump()
{

		if (jumpTimer - lastJump > 900)
		{
			accelerator1 = 0;
			accelerator2 = 0;
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
