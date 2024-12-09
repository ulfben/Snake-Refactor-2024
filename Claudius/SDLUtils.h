#pragma once
#include <codeanalysis\warnings.h>
#pragma warning(push)
#pragma warning(disable : ALL_CODE_ANALYSIS_WARNINGS)
#include "SDL.h"
#pragma warning(pop)
#include <stdexcept>
struct SDL_Deleter final{
    void operator()(SDL_Renderer* ptr) const noexcept{
        if(ptr) SDL_DestroyRenderer(ptr);
    }
    void operator()(SDL_Window* ptr) const noexcept{
        if(ptr) SDL_DestroyWindow(ptr);
    }
};

class SDLError : public std::runtime_error{
public:
    [[gsl::suppress(f.6, justification: "As long as it depends on std::runtime_error this ctor can not be marked noexcept. std::runtime_error can throw std::bad_alloc.")]]
    SDLError() : std::runtime_error(SDL_GetError()){};
};

class SDLInitError : public SDLError{};