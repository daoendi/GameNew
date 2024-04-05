#pragma once
#include "Object.h"

class Player :public Object
{
private:
    int gravity = 1;
    //SDL_Rect screen = getSrc();
    //SDL_Rect destination = getDest();
public:
    void Update();
    void Render(SDL_Renderer* ren);
};

