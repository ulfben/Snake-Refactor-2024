#pragma once
#include <memory>
#include <stdexcept>
#include "SDLUtils.h"
#include "Window.h"
struct Renderer{
    using RenderPtr = std::unique_ptr<SDL_Renderer, SDL_Deleter>;
    RenderPtr ptr;
    Renderer(const Window& w){
        ptr.reset(SDL_CreateRenderer(w.get(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED));
        if(!ptr){
            throw std::runtime_error(SDL_GetError());
        }
    }
    SDL_Renderer* get() const noexcept{ return ptr.get(); }
};