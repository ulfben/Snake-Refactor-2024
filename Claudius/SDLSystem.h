#pragma once
#include "SDLUtils.h"
struct SDLSystem final{
    SDLSystem(){
        auto result = SDL_Init(SDL_INIT_EVERYTHING);
        if(result != 0){
            throw SDLInitError();
        }
    }
    ~SDLSystem() noexcept {
        SDL_Quit();
    }
};