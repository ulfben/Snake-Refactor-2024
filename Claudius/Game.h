#pragma once
#include "SDLSystem.h"
#include "SDLUtils.h"
#include "Apple.h"
#include "Player.h"
#include "Window.h"
#include "Renderer.h"
#include <string_view>
static constexpr auto SLEEP_TIME = 1000 / 20;
class Game{
public:
    Game(int width, int height, std::string_view title)
        : w(title, width, height), r(w){}
    void run() noexcept {
        while(running){
            Input();
            Update();
            Render();
            SDL_Delay(SLEEP_TIME);
        }
    }
private: 
    SDLSystem init{};
    Window w;
    Renderer r;    
    Player player;
    Apple apple;
    bool running = true;

    void Input() noexcept{
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                running = false;
            } else if(e.type == SDL_KEYDOWN){
                const auto key = e.key.keysym.sym;
                player.OnKeyDown(key);
                running = (key != SDLK_ESCAPE && key != SDLK_q);
            }
        }
    }
    void Update() noexcept {
        player.Update();                               
        if(player.isSelfColliding() || 
            !player.isInside({0, 0, w.width(), w.height()})){
            player.ResetPlayer();
        }        
        if(player.isCollidingWith(apple.pos)){            
            apple.pos.x = (rand() % 125) * 10.0f;
            apple.pos.y = (rand() % 70) * 10.0f;
        }        
    };
    void Render() const noexcept{
        r.clear(Color::BLACK);
        player.Render(r.get());
        apple.Render(r.get());
        r.present();
    }
};