#pragma once
#include <memory>
#include <stdexcept>
#include "SDLUtils.h"
#include "Window.h"
#include "Configs.h"
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
    void setColor(SDL_Color c) const noexcept{
        SDL_SetRenderDrawColor(get(), c.r, c.g, c.b, c.a);
    }
    void clear(SDL_Color c) const noexcept{
        setColor(c);
        SDL_RenderClear(get());
    }
    void present() const noexcept{
        SDL_RenderPresent(get());
    }   
    void drawCell(int x, int y) const noexcept{
        SDL_Rect r = {x, y, CELL_SIZE, CELL_SIZE};
        SDL_RenderFillRect(get(), &r);
    }
};