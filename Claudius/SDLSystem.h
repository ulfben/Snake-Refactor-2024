#pragma once
#include <SDL.h>
#include <stdexcept>
struct SDLSystem{
    SDLSystem(){
        auto result = SDL_Init(SDL_INIT_EVERYTHING);
        if(result != 0){
            throw std::runtime_error(SDL_GetError());
        }
    }
    ~SDLSystem() noexcept {
        SDL_Quit();
    }
};