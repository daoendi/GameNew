#pragma once
#include "Object.h"

class Player :public Object
{
private:
    double ground = 358;
    double gravity = 0.2;
    double Ypos = 358;
    double accelerator1 = 0;
    double accelerator2 = 0;
    bool inJump = false;
    double jumpHeight = -12;
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