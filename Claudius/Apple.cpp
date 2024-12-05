#pragma once

#include <iostream>
#include "Apple.h"

void Apple::Initialize(unsigned int width, unsigned int height){
    color.SetColor(0, 255, 0, 0);
    rect.SetBounds(0, 0, width, height);
    trans.SetPosition(100, 200);    
}

void Apple::Render(SDL_Renderer* r){
    SDL_SetRenderDrawColor(r, color.r, color.g, color.b, color.a);
    rect.x = (int)trans.position.x;
    rect.y = (int)trans.position.y;
    SDL_Rect sdlr{rect.x, rect.y, rect.w, rect.h};
    SDL_RenderFillRect(r, &sdlr);  // <- If you want to draw a "filled" rectangle.    
}


