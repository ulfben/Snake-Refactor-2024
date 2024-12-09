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
        : window(title, width, height), renderer(window){}
    void run() noexcept {
        while(isRunning){
            Input();
            Update();
            Render();
            SDL_Delay(SLEEP_TIME);
        }
    }
private: 
    SDLSystem init{};
    Window window;
    Renderer renderer;    
    Snake snake;
    Apple apple;
    bool isRunning = true;

    void Input() noexcept{
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                isRunning = false;
            } else if(e.type == SDL_KEYDOWN){
                const auto key = e.key.keysym.sym;
                snake.OnKeyDown(key);
                isRunning = (key != SDLK_ESCAPE && key != SDLK_q);
            }
        }
    }
    void Update() noexcept {
        snake.Update();                               
        if(snake.isSelfColliding() || 
            !snake.isInside({0, 0, window.width(), window.height()})){
            snake = {};
        }        
        if(snake.isCollidingWith(apple.pos)){            
            apple = {};
            snake.grow();
        }        
    };
    void Render() const noexcept{
        renderer.clear(Color::BLACK);
        snake.Render(renderer.get());
        apple.Render(renderer.get());
        renderer.present();
    }
};