#pragma once
#include <vector>
#include <algorithm>
#include "Cell.h"
#include "Configs.h"
constexpr Cell LEFT  = {-SPEED, 0};
constexpr Cell RIGHT = {SPEED, 0};
constexpr Cell UP    = {0, -SPEED};
constexpr Cell DOWN  = {0, SPEED};
constexpr Cell STILL = {0, 0};
class Snake final{
    std::vector<Cell> parts = {1, {starting_x, starting_y}};
    Cell heading = STILL;      

    Cell& head() noexcept{ return *parts.begin(); }
    const Cell& head() const noexcept{ return *parts.begin(); }
    Cell position() const noexcept{ return parts.front(); }
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
        r.setColor(GREEN);
        for(auto part : parts){            
            r.drawCell(part.x, part.y);
        }
    }
    void grow() noexcept{
        try{
            parts.emplace_back(position());
        } catch(...){
          /*swallowing exception. The game can keep running, the snake won't grow.*/
        }
    }
    bool isCollidingWith(Cell pos) const noexcept{                
        return std::ranges::any_of(parts,
            [pos](const auto& piece) constexpr { return piece == pos; });
    }
    bool isSelfColliding() const noexcept{
         return hasTail() && std::any_of(parts.begin()+1, parts.end(),
            [pos = head()](const auto& piece) constexpr { return piece == pos; });
    }
    bool isInside(SDL_Rect bounds) const noexcept{        
        bounds.x -= 1;
        bounds.y -= 1;
        return head().x > bounds.x && head().x < bounds.w &&
            head().y > bounds.y && head().y < bounds.h;
    }  
};