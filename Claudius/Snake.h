#pragma once
#include <vector>
#include <algorithm>
#include "Vector2.h"
#include "Color.h"
#include "SDL.h"
#include "SDLUtils.h"
constexpr int TILE_SIZE = 10; //TODO: apple_size, speed, tile_size, should all be the same. 
constexpr float SPEED = 10.0f;
constexpr float starting_x = 300.0f;
constexpr float starting_y = 300.0f;
constexpr Vector2 LEFT  = {-SPEED, 0};
constexpr Vector2 RIGHT = {SPEED, 0};
constexpr Vector2 UP    = {0, -SPEED};
constexpr Vector2 DOWN  = {0, SPEED};
constexpr Vector2 STILL = {0, 0};

class Snake{
    std::vector<Vector2> parts = {1, {starting_x, starting_y}};
    Vector2 heading = STILL;      

    Vector2& head() noexcept{ return *parts.begin(); }
    const Vector2& head() const noexcept{ return *parts.begin(); }
    Vector2 position() const noexcept{ return parts.front(); }
    bool hasTail() const noexcept{ return parts.size() > 1; }

public:
    void input(SDL_Keycode key) noexcept{
        if(key == SDLK_LEFT && heading != RIGHT){
            heading = LEFT;
        } else if(key == SDLK_RIGHT && heading != LEFT){
            heading = RIGHT;
        } else if(key == SDLK_UP && heading != DOWN){
            heading = UP;
        } else if(key == SDLK_DOWN && heading != UP){
            heading = DOWN;
        }
    }
    void update() noexcept{
        std::shift_right(parts.begin(), parts.end(), 1);
        head() += heading;
    }
    void render(const Renderer& r) const noexcept{
        for(auto part : parts){
            SDL_Rect sdlr = {static_cast<int>(part.x), static_cast<int>(part.y),
                 TILE_SIZE,
                 TILE_SIZE};
            r.draw(sdlr, Color::GREEN);
        }
    }
    void grow() noexcept{
        try{
            parts.emplace_back(position());
        } catch(...){
          /*swallowing exception. The game can keep running, the snake won't grow.*/
        }
    }
    bool isCollidingWith(Vector2 pos) const noexcept{                
        return std::ranges::any_of(parts,
            [pos](const auto& piece) constexpr { return piece == pos; });
    }
    bool isSelfColliding() const noexcept{
         return hasTail() && std::any_of(parts.begin()+1, parts.end(),
            [pos = head()](const auto& piece) constexpr { return piece == pos; });
    }
    bool isInside(SDL_Rect bounds) const noexcept{
        bounds.h -= TILE_SIZE;
        bounds.w -= TILE_SIZE;
        return head().x > bounds.x && head().x < bounds.w &&
            head().y > bounds.y && head().y < bounds.h;
    }  
};