#include "Snake.h"
#include <cmath>
#include "SDLUtils.h"

void Snake::Update(){
    

    if(moving_left == true){
        head += {-SPEED, 0};
        parts[0] += {x_array_difference[0], y_array_difference[0]};

        for(int i = 1; i < player_size; i++){
            parts[i] += Vector2(x_array_difference[i - 1], y_array_difference[i - 1]);
        }
    } else if(moving_right == true){
        head += Vector2(SPEED, 0);
        parts[0] += Vector2(x_array_difference[0], y_array_difference[0]);

        for(int i = 1; i < player_size; i++){
            parts[i] += Vector2(x_array_difference[i - 1], y_array_difference[i - 1]);
        }
    } else if(moving_up == true){
        head += Vector2(0, -SPEED);
        parts[0] += Vector2(x_array_difference[0], y_array_difference[0]);

        for(int i = 1; i < player_size; i++){
            parts[i] += Vector2(x_array_difference[i - 1], y_array_difference[i - 1]);
        }
    } else if(moving_down == true){
        head += Vector2(0, SPEED);
        parts[0] += Vector2(x_array_difference[0], y_array_difference[0]);

        for(int i = 1; i < player_size; i++){
            parts[i] += Vector2(x_array_difference[i - 1], y_array_difference[i - 1]);
        }
    }
}

void Snake::OnKeyDown(SDL_Keycode key){
    if(key == SDLK_LEFT){
        moving_left = true;
        moving_right = false;
        moving_up = false;
        moving_down = false;
    } else if(key == SDLK_RIGHT){
        moving_left = false;
        moving_right = true;
        moving_up = false;
        moving_down = false;
    } else if(key == SDLK_UP){
        moving_left = false;
        moving_right = false;
        moving_up = true;
        moving_down = false;
    } else if(key == SDLK_DOWN){
        moving_left = false;
        moving_right = false;
        moving_up = false;
        moving_down = true;
    }
}

void Snake::ResetPlayer(){
    moving_right = false;
    moving_left = false;
    moving_up = false;
    moving_down = false;
    head = {starting_x, starting_y};
}