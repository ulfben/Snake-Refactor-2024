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
    } catch(const SDLInitError& e){
        std::println(std::cerr, "SDL failed to initialize. Error: {}", e.what());
    } catch(const SDLError& e){
        std::println(std::cerr, "SDL error: {}", e.what());
    } catch(...){
        std::println(std::cerr, "Unrecognized exception. Exiting!");
    }
    return 0;
}