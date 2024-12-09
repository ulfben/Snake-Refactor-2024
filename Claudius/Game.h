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
    Player playerOne;
    Apple apple;
    void Update(){
        playerOne.Update();               

        // Player going out of X bounds.
        if(playerOne.isSelfColliding() || playerOne.trans.GetX() > w.width() || playerOne.trans.GetX() < 0){
            playerOne.ResetPlayer();
        }

        // Player going out of Y bounds.
        if(playerOne.trans.GetY() > w.height() || playerOne.trans.GetY() < 0){
            playerOne.ResetPlayer();
        }

        // Player collide on apple.
        if(playerOne.trans.GetPosition() == apple.trans.GetPosition()){
            playerOne.player_score++;
            apple.trans.SetPosition((rand() % 125) * 10.0f, (rand() % 70) * 10.0f);
        }
    };
    void Render(){
        r.clear(Color::BLACK);
        playerOne.Render(r.get());
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
                playerOne.OnKeyDown(key);
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