#include "Player.h"
#include <cmath>
#include "SDLUtils.h"

Player::Player(){    
    rect.SetBounds(0, 0, size, size);
    trans.SetPosition(starting_x, starting_y);
    player_score = 0;

    for(int i = 0; i < player_size; i++){        
        parts[i].rect.SetBounds(0, 0, size, size);
        parts[i].trans.SetPosition(trans.GetX(), trans.GetY());
    }
}

void Player::Render(SDL_Renderer* r){
    SetRenderDrawColor(r, Color::GREEN);    
    SDL_Rect sdlr{ (int)trans.position.x,  (int)trans.position.y, rect.w, rect.h};
    SDL_RenderFillRect(r, &sdlr); 
    for(int i = 0; i < player_score; i++){                
        sdlr = {static_cast<int>(parts[i].trans.position.x),
             static_cast<int>(parts[i].trans.position.y),
             rect.w,
             rect.h};    
        SetRenderDrawColor(r, Color::GREEN);    
        SDL_RenderFillRect(r, &sdlr);
    }
}

void Player::Update(){
    x_array_difference[0] = trans.GetX() - parts[0].trans.GetX();
    y_array_difference[0] = trans.GetY() - parts[0].trans.GetY();

    for(int i = 1; i < (player_size - 1); i++){
        x_array_difference[i] = parts[i].trans.GetX() - parts[i + 1].trans.GetX();
        y_array_difference[i] = parts[i].trans.GetY() - parts[i + 1].trans.GetY();
    }

    if(moving_left == true){
        trans.ChangePosition(-movement_speed, 0);
        parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

        for(int i = 1; i < player_size; i++){
            parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
        }
    } else if(moving_right == true){
        trans.ChangePosition(movement_speed, 0);
        parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

        for(int i = 1; i < player_size; i++){
            parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
        }
    } else if(moving_up == true){
        trans.ChangePosition(0, -movement_speed);
        parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

        for(int i = 1; i < player_size; i++){
            parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
        }
    } else if(moving_down == true){
        trans.ChangePosition(0, movement_speed);
        parts[0].trans.ChangePosition(x_array_difference[0], y_array_difference[0]);

        for(int i = 1; i < player_size; i++){
            parts[i].trans.ChangePosition(x_array_difference[i - 1], y_array_difference[i - 1]);
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

    trans.SetPosition(starting_x, starting_y);
}