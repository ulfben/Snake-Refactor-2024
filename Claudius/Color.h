#pragma once
#include "SDL.h"
namespace Color{
    static constexpr uint8_t ALPHA_OPAQUE = 255;
    static constexpr uint8_t ALPHA_TRANSPARENT = 0;
    static constexpr SDL_Color BLACK{0,0,0,ALPHA_OPAQUE};
    static constexpr SDL_Color GREEN{0,255,0,ALPHA_OPAQUE};
    static constexpr SDL_Color RED{255,0,0,ALPHA_OPAQUE};
};