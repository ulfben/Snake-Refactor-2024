#pragma once
#include <string_view>
#include <stdexcept>
#include <memory>
#include "SDLUtils.h"
#include "SDL.h"
class Window{
    using WindowPtr = std::unique_ptr<SDL_Window, SDL_Deleter>;   
    WindowPtr ptr;
public:
    Window(std::string_view title, unsigned width, unsigned height, SDL_WindowFlags flags = SDL_WindowFlags::SDL_WINDOW_RESIZABLE){
        ptr.reset(SDL_CreateWindow(title.data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags));
        if(ptr == nullptr){
            throw std::runtime_error(SDL_GetError());
        }
    }  
    void setWindowSize(unsigned width, unsigned height) const noexcept{
        SDL_SetWindowSize(get(), width, height);
    }
    void setTitle(std::string_view t) const noexcept{
        SDL_SetWindowTitle(get(), t.data());
    }
    void setPosition(unsigned x, unsigned y) const noexcept{
        SDL_SetWindowPosition(get(), x, y);
    }
    SDL_Window* get() const noexcept{ return ptr.get(); }
};