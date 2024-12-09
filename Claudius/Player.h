#pragma once
#include "Vector2.h"
#include "Color.h"
#include "SDL.h"
#include "SDLUtils.h"
constexpr int size = 10;
constexpr float movement_speed = 10.0f;
constexpr float starting_x = 300.0f;
constexpr float starting_y = 300.0f;
constexpr int player_size = 50;
struct Player{
    struct PlayerPart{
        Vector2 trans;
        SDL_Rect rect;
    };
    PlayerPart parts[player_size];
    Vector2 trans{starting_x, starting_y};
    SDL_Rect rect{0, 0, size, size};
    int player_score = 0;
    Player() noexcept{
        for(int i = 0; i < player_size; i++){
            parts[i].rect = rect;
            parts[i].trans = trans;
        }
    }
    void OnKeyDown(SDL_Keycode key);
    void Render(SDL_Renderer* r) const noexcept{
        SetRenderDrawColor(r, Color::GREEN);
        SDL_Rect sdlr{(int) trans.x,  (int) trans.y, rect.w, rect.h};
        SDL_RenderFillRect(r, &sdlr);
        for(int i = 0; i < player_score; i++){
            sdlr = {static_cast<int>(parts[i].trans.x),
                 static_cast<int>(parts[i].trans.y),
                 rect.w,
                 rect.h};
            SetRenderDrawColor(r, Color::GREEN);
            SDL_RenderFillRect(r, &sdlr);
        }
    }
    void Update();
    void ResetPlayer();
    bool isSelfColliding() const noexcept{
        for(int i = 0; i < player_score; i++){
            if(trans == parts[i].trans){
                return true;
            }
        }
        return false;
    }
    bool isInside(SDL_Rect bounds) const noexcept{
        return trans.x > bounds.x && trans.x < bounds.w &&
            trans.y > bounds.y && trans.y < bounds.h;
    }
    bool isCollidingWith(Vector2 pos) const noexcept{
        return trans == pos;
    }

    bool moving_right = false;
    bool moving_left = false;
    bool moving_up = false;
    bool moving_down = false;
    bool new_snake = false;

    float x_array_difference[player_size] = {};
    float y_array_difference[player_size] = {};
};