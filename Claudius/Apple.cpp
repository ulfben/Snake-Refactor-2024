#pragma once
#include "Apple.h"
#include "SDLUtils.h"
#include "Color.h"

Apple::Apple(){    
    rect.SetBounds(0, 0, 10, 10);
    trans.SetPosition(100, 200);    
}

void Apple::Render(SDL_Renderer* r){
    SetRenderDrawColor(r, Color::GREEN);
    rect.x = (int)trans.position.x;
    rect.y = (int)trans.position.y;
    SDL_Rect sdlr{rect.x, rect.y, rect.w, rect.h};
    SDL_RenderFillRect(r, &sdlr);  // <- If you want to draw a "filled" rectangle.    
}


