#include "SDLSystem.h"
#include "Game.h"
#include "Window.h"
#include "Renderer.h"
#include <stdexcept>
#undef main

int main(){
    constexpr std::string_view title = "Snake";
    constexpr unsigned width = 1250;
    constexpr unsigned height = 700;   
    SDLSystem init{};
    Window w{title, width, height};
    Renderer r(w);
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
        game.Render(r.get());                        
        SDL_Delay(1000 / 20); //<- "Framerate".
    }

    SDL_DestroyRenderer(r.get());
    return 0;
}
