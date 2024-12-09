#pragma once
#include "SDLSystem.h"
#include "SDLUtils.h"
#include "Apple.h"
#include "Snake.h"
#include "Window.h"
#include "Renderer.h"
#include <string_view>
static constexpr auto SLEEP_TIME = 1000 / 20;
class Game{
public:
    Game(int width, int height, std::string_view title)
        : window(title, width, height), r(window){}
    void run() noexcept {
        while(isRunning){
            input();
            update();
            render();
            SDL_Delay(SLEEP_TIME);
        }
    }
private: 
    SDLSystem init{};
    Window window;
    Renderer r;    
    Snake snake;
    Apple apple;
    bool isRunning = true;

    void input() noexcept{
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                isRunning = false;
            } else if(e.type == SDL_KEYDOWN){
                const auto key = e.key.keysym.sym;
                snake.onKeyDown(key);
                isRunning = (key != SDLK_ESCAPE && key != SDLK_q);
            }
        }
    }
    void update() noexcept {
        snake.update();                               
        if(snake.isSelfColliding() || 
            !snake.isInside({0, 0, window.width(), window.height()})){
            snake.respawn();
        }        
        if(snake.isCollidingWith(apple.pos)){            
            apple = {};
            snake.grow();
        }        
    };
    void render() const noexcept{
        r.clear(Color::BLACK);
        snake.render(r);
        apple.render(r);
        r.present();
    }
};