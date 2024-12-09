#pragma once
#include "Apple.h"
#include "SDLUtils.h"
#include "Color.h"
#include "Vector2.h"
struct Apple{
    Vector2 pos{(rand() % 125) * 10.0f,
                (rand() % 70) * 10.0f};

    void Render(SDL_Renderer* r) const noexcept{
        SetRenderDrawColor(r, Color::GREEN);
        SDL_Rect sdlr{(int)pos.x, (int)pos.y, 10, 10};
        SDL_RenderFillRect(r, &sdlr);
    }        
};