#include "Game.h"
#include <stdexcept>
#undef main
static constexpr std::string_view title = "Snake";
static constexpr unsigned width = 1250;
static constexpr unsigned height = 700;    
int main(){      
    Game game(width, height, title);    
    game.run();
    return 0;
}
