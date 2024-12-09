#pragma once
#include <memory>
#include "SDLUtils.h"
#include "Window.h"
#include "Configs.h"
struct Renderer final {
    using RenderPtr = std::unique_ptr<SDL_Renderer, SDL_Deleter>;
    RenderPtr ptr;
    Renderer(const Window& w){
        ptr.reset(SDL_CreateRenderer(w.get(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED));
        if(!ptr){
            throw SDLInitError();
        }
    }
    SDL_Renderer* get() const noexcept{ return ptr.get(); }
    void setColor(SDL_Color c) const noexcept{
        SDL_SetRenderDrawColor(get(), c.r, c.g, c.b, c.a);
    }
    void drawCell(int x, int y) const noexcept{
        SDL_Rect r = {x*CELL_SIZE, y*CELL_SIZE, CELL_SIZE, CELL_SIZE};
        SDL_RenderFillRect(get(), &r);
    }
    void clear(SDL_Color c) const noexcept{
        setColor(c);
        SDL_RenderClear(get());
    }
    void present() const noexcept{
        SDL_RenderPresent(get());
    }      
};