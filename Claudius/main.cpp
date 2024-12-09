#include "Game.h"
#include <iostream>
#include <stdexcept>
#include <print>
#undef main
static constexpr std::string_view title = "Snake";
static constexpr unsigned width = 1250;
static constexpr unsigned height = 700;    
int main(){      
    try{
        Game game(width, height, title);
        game.run();
    } catch(const std::runtime_error& e){
        std::println(std::cerr, "{}", e.what());
    } catch(...){
        std::println(std::cerr, "{}", "Unknown error!");        
    }
    return 0;
}