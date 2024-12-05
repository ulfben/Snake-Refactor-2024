#include "SDLSystem.h"
#include "Game.h"
#include "Window.h"
#include <stdexcept>
#undef main

int main(){
    constexpr std::string_view title = "Snake";
    constexpr unsigned width = 1250;
    constexpr unsigned height = 700;   
    SDLSystem init{};
    Window w{title, width, height};
    
    SDL_Renderer* renderer = SDL_CreateRenderer(w.get(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        [[maybe_unused]] const char* error = SDL_GetError();
        return 0;
    }
    bool running = true;        
    Game game(width, height, title);    
    while(running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            switch(e.type){
            case SDL_QUIT: running = false; break;
            case SDL_KEYDOWN: game.OnKeyDown(e.key.keysym.sym); break;            
            }
        }
        game.Update();
        game.Render(renderer);                        
        SDL_Delay(1000 / 20); //<- "Framerate".
    }

    SDL_DestroyRenderer(renderer);
    return 0;
}
