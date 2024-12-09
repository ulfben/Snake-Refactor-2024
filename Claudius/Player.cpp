#include "Player.h"
#include <cmath>
#include "SDLUtils.h"

void Player::Update(){
    x_array_difference[0] = trans.x - parts[0].trans.x;
    y_array_difference[0] = trans.y - parts[0].trans.y;

    for(int i = 1; i < (player_size - 1); i++){
        x_array_difference[i] = parts[i].trans.x - parts[i + 1].trans.x;
        y_array_difference[i] = parts[i].trans.y - parts[i + 1].trans.y;
    }

    if(moving_left == true){
        trans += {-movement_speed, 0};
        parts[0].trans += {x_array_difference[0], y_array_difference[0]};

        for(int i = 1; i < player_size; i++){
            parts[i].trans += Vector2(x_array_difference[i - 1], y_array_difference[i - 1]);
        }
    } else if(moving_right == true){
        trans += Vector2(movement_speed, 0);
        parts[0].trans += Vector2(x_array_difference[0], y_array_difference[0]);

        for(int i = 1; i < player_size; i++){
            parts[i].trans += Vector2(x_array_difference[i - 1], y_array_difference[i - 1]);
        }
    } else if(moving_up == true){
        trans += Vector2(0, -movement_speed);
        parts[0].trans += Vector2(x_array_difference[0], y_array_difference[0]);

        for(int i = 1; i < player_size; i++){
            parts[i].trans += Vector2(x_array_difference[i - 1], y_array_difference[i - 1]);
        }
    } else if(moving_down == true){
        trans += Vector2(0, movement_speed);
        parts[0].trans += Vector2(x_array_difference[0], y_array_difference[0]);

        for(int i = 1; i < player_size; i++){
            parts[i].trans += Vector2(x_array_difference[i - 1], y_array_difference[i - 1]);
        }
    }
}

void Player::OnKeyDown(SDL_Keycode key){
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

void Player::ResetPlayer(){
    player_score = 0;
    moving_right = false;
    moving_left = false;
    moving_up = false;
    moving_down = false;
    trans = {starting_x, starting_y};
}