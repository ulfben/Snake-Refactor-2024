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
    SDLSystem init{};
    Window w;
    Renderer r;
    bool running = true;
    Player player;
    Apple apple;
    void Update(){
        player.Update();                               
        if(player.isSelfColliding() || 
            !player.isInside({0, 0, w.width(), w.height()})){
            player.ResetPlayer();
        }

        // Player going out of Y bounds.
        if(player.trans.GetY() > w.height() || player.trans.GetY() < 0){
            player.ResetPlayer();
        }

        // Player collide on apple.
        if(player.trans.GetPosition() == apple.trans.GetPosition()){
            player.player_score++;
            apple.trans.SetPosition((rand() % 125) * 10.0f, (rand() % 70) * 10.0f);
        }
    };
    void Render(){
        r.clear(Color::BLACK);
        player.Render(r.get());
        apple.Render(r.get());
        r.present();
    }
    void Input(){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                running = false;
            } else if(e.type == SDL_KEYDOWN){
                auto key = e.key.keysym.sym;
                player.OnKeyDown(key);
                running = (key != SDLK_ESCAPE && key != SDLK_q);
            }
        }
    }
public:
    Game(int width, int height, std::string_view title)
        : w(title, width, height), r(w){}
    void run(){
        while(running){
            Input();
            Update();
            Render();
            SDL_Delay(SLEEP_TIME);
        }
    }
};