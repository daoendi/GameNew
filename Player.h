#pragma once
#include "Object.h"

class Player :public Object
{
private:
    double gravity = 0.3;
    double Ypos = 358;
    bool inJump = false;
    double SpeedUp = -12;
    double SpeedDown = 0; 
    double jumpTimer;
    double lastJump = 0;
    SDL_Texture* Tex1;
    SDL_Texture* Tex2;
    int animationTimer;
public:
    void Gravity();
    void GetJumpTime();
    void Jump();
    bool JumpState();
    void CreateTexture1(const char* address, SDL_Renderer* ren);
    void CreateTexture2(const char* address, SDL_Renderer* ren);
    void Render(SDL_Renderer* ren);
    void PlayerRender(SDL_Renderer* ren, int a);
};