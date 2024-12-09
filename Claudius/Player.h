#pragma once
#include <vector>
#include <algorithm>
#include "Vector2.h"
#include "Color.h"
#include "SDL.h"
#include "SDLUtils.h"
constexpr int TILE_SIZE = 10;
constexpr float movement_speed = 10.0f;
constexpr float starting_x = 300.0f;
constexpr float starting_y = 300.0f;
constexpr int player_size = 50;
struct Player{
    Vector2 head{starting_x, starting_y};
    std::vector<Vector2> parts =  {head};
    void OnKeyDown(SDL_Keycode key);
    void Render(SDL_Renderer* r) const noexcept{
        SetRenderDrawColor(r, Color::GREEN);
        SDL_Rect sdlr{(int) head.x,  (int) head.y, TILE_SIZE, TILE_SIZE};
        SDL_RenderFillRect(r, &sdlr);
        for(auto part : parts){
            sdlr = {static_cast<int>(part.x),
                 static_cast<int>(part.y),
                 TILE_SIZE,
                 TILE_SIZE};
            SetRenderDrawColor(r, Color::GREEN);
            SDL_RenderFillRect(r, &sdlr);
        }
    }
    void Update();
    void ResetPlayer();
    bool isSelfColliding() const noexcept{           
        return std::any_of(parts.begin(), parts.end(), 
            [head = this->head](auto part) constexpr noexcept { return part == head; });
    }
    bool isInside(SDL_Rect bounds) const noexcept{
        return head.x > bounds.x && head.x < bounds.w &&
            head.y > bounds.y && head.y < bounds.h;
    }
    bool isCollidingWith(Vector2 pos) const noexcept{
        return head == pos;
    }

    bool moving_right = false;
    bool moving_left = false;
    bool moving_up = false;
    bool moving_down = false;
    bool new_snake = false;

    float x_array_difference[player_size] = {};
    float y_array_difference[player_size] = {};
};