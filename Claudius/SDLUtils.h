#pragma once
#include "SDL.h"

static void SetRenderDrawColor(SDL_Renderer* r, SDL_Color c) noexcept{
    SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);
}

