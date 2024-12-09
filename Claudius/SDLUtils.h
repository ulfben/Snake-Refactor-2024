#pragma once
#include "SDL.h"
struct SDL_Deleter {
  void operator()(SDL_Renderer *ptr) const noexcept {
    if (ptr) SDL_DestroyRenderer(ptr);
  }
  void operator()(SDL_Window *ptr) const noexcept {
    if (ptr) SDL_DestroyWindow(ptr);
  }
};

