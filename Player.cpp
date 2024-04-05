#include "Player.h"
#include<iostream>

void Player::Render(SDL_Renderer* ren)
{
	SDL_Rect screen = getSrc();
	SDL_Rect destination = getDest();
	SDL_RenderCopy(ren, getTexture(), &screen, &destination);
}

void Player::Update()
{
	gravity = gravity + 1;
	setSrc(0, 0, 60, 80);
	setDest(0, gravity, 60, 80);
}