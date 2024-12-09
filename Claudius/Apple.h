#pragma once
#include "Apple.h"
#include "SDLUtils.h"
#include "Color.h"
#include "Vector2.h"
struct Apple{
    Vector2 pos{100, 200};
    void Render(SDL_Renderer* r) const noexcept{
        SetRenderDrawColor(r, Color::GREEN);
        SDL_Rect sdlr{(int)pos.x, (int)pos.y, 10, 10};
        SDL_RenderFillRect(r, &sdlr);
    }        
};