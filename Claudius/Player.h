#pragma once		// #pragma once == Compile this file once.

#include "Transform.h"
#include "Color.h"
#include "Rectangle.h"
#include "SDL.h"
struct Player{
    struct PlayerPart{
        Transform trans;
        Rectangle rect;
    };

    static const int player_size = 50;
    PlayerPart parts[player_size];
    Transform trans;
    Rectangle rect;
    Player();
    void OnKeyDown(SDL_Keycode key);    
    void Render(SDL_Renderer* renderManager) const noexcept;				// A reference or pointer doesn't need to be #include, just a forward declare.
    void Update();
    void ResetPlayer();
    bool isSelfColliding() const noexcept{
        for(int i = 0; i < player_score; i++){
            if(trans.GetPosition() == parts[i].trans.GetPosition()){
                return true;
            }
        }
        return false;
    }
    bool isInside(SDL_Rect bounds) const noexcept{
        return trans.GetX() > bounds.x && trans.GetX() < bounds.w &&
            trans.GetY() > bounds.y && trans.GetY() < bounds.h;
    }
    bool isCollidingWith(Vector2 pos) const noexcept{
        return trans.GetPosition() == pos;
    }

    int size = 10;
    const float movement_speed = 10.0f;
    const float starting_x = 300.0f;
    const float starting_y = 300.0f;

    bool moving_right = false;
    bool moving_left = false;
    bool moving_up = false;
    bool moving_down = false;
    bool new_snake = false;

    float x_array_difference[player_size] = {};
    float y_array_difference[player_size] = {};

    int player_score = 0;
};