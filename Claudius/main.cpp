#include "SDLSystem.h"
#include "Game.h"
#include <stdexcept>
#undef main




int main(){
    SDLSystem init();

    SDL_Window* window = SDL_CreateWindow("Base", 0, 0, 0, 0, SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
    if(window == nullptr){
        const char* error = SDL_GetError();
        return 0;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        const char* error = SDL_GetError();
        return 0;
    }
    bool running = true; 
    
    int width = 1250;
    int height = 700;    
    Game game(width, height, "Snake");
    
    SDL_SetWindowSize(window, width, height);
    SDL_SetWindowTitle(window, "Snake");
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    float dt = 1.0f / 60.0f;
    while(running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            switch(e.type){
            case SDL_QUIT: running = false; break;
            case SDL_KEYDOWN: game.OnKeyDown(e.key.keysym.sym); break;
            case SDL_KEYUP: game.OnKeyUp(e.key.keysym.sym); break;
            }
        }
        game.Update(dt);
        game.Render(renderer);                        
        SDL_Delay(1000 / 20); //<- "Framerate".
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    //TODO: SDL_ deinit? 

    return 0;
}
