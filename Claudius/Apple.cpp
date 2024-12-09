#pragma once
#include "Apple.h"
#include "SDLUtils.h"
#include "Color.h"

Apple::Apple(){        
    trans.SetPosition(100, 200);    
}

void Apple::Render(SDL_Renderer* r) const noexcept{
    SetRenderDrawColor(r, Color::GREEN);
    SDL_Rect sdlr{(int)trans.position.x, (int)trans.position.y, 10, 10};
    SDL_RenderFillRect(r, &sdlr);  // <- If you want to draw a "filled" rectangle.    
}


