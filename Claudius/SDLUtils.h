#pragma once
#include "SDL.h"

inline void SetRenderDrawColor(SDL_Renderer* r, SDL_Color c) noexcept{
    SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);
}

struct SDL_Deleter {
  void operator()(SDL_Renderer *ptr) const noexcept {
    if (ptr) SDL_DestroyRenderer(ptr);
  }
  void operator()(SDL_Window *ptr) const noexcept {
    if (ptr) SDL_DestroyWindow(ptr);
  }
};

