#include "Game.h"
#include <string_view>
#include <iostream>
#include <stdexcept>
#include "Configs.h"
#undef main
   
int main(){      
    try{
        Game game(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
        game.run();
    } catch(const std::runtime_error& e){
        std::println(std::cerr, "{}", e.what());
    } catch(...){
        std::println(std::cerr, "{}", "Unknown error!");        
    }
    return 0;
}