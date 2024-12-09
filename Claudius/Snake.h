#pragma once
#include <vector>
#include <algorithm>
#include "Vector2.h"
#include "Color.h"
#include "SDL.h"
#include "SDLUtils.h"
constexpr int TILE_SIZE = 10;
constexpr float SPEED = 10.0f;
constexpr float starting_x = 300.0f;
constexpr float starting_y = 300.0f;
constexpr Vector2 LEFT = {-SPEED, 0};
constexpr Vector2 RIGHT = {SPEED, 0};
constexpr Vector2 UP = {0, -SPEED};
constexpr Vector2 DOWN = {0, SPEED};
constexpr Vector2 NONE = {0, 0};

struct Snake{
    Vector2 head{starting_x, starting_y};
    std::vector<Vector2> parts = {head};
    Vector2 velocity = NONE;
    void OnKeyDown(SDL_Keycode key) noexcept{
        if(key == SDLK_LEFT){
            velocity = LEFT;
        } else if(key == SDLK_RIGHT){
            velocity = RIGHT;
        } else if(key == SDLK_UP){
            velocity = UP;
        } else if(key == SDLK_DOWN){
            velocity = DOWN;
        }
    }
    void Update() noexcept{
        head += velocity;
    }
    void Render(SDL_Renderer* r) const noexcept{
        SetRenderDrawColor(r, Color::GREEN);
        for(auto part : parts){
            SDL_Rect sdlr = {static_cast<int>(part.x),
                 static_cast<int>(part.y),
                 TILE_SIZE,
                 TILE_SIZE};
            SetRenderDrawColor(r, Color::GREEN);
            SDL_RenderFillRect(r, &sdlr);
        }
    }
    void grow() noexcept{
        try{
            parts.emplace_back(head);
        } catch(...){
          /*swallowing exception. The game can keep running, the snake won't grow.*/
        }
    }
    bool isSelfColliding() const noexcept{
        return std::any_of(parts.begin(), parts.end(),
            [head = this->head](auto part) constexpr noexcept{ return part == head; });
    }
    bool isInside(SDL_Rect bounds) const noexcept{
        bounds.h -= TILE_SIZE;
        bounds.w -= TILE_SIZE;
        return head.x > bounds.x && head.x < bounds.w &&
            head.y > bounds.y && head.y < bounds.h;
    }
    bool isCollidingWith(Vector2 pos) const noexcept{
        return head == pos;
    }
};