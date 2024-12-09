#pragma once
static constexpr std::string_view GAME_TITLE = "Snake";
static constexpr auto TICK_RATE = 15; // ticks per second
static constexpr auto FRAME_DELAY = 1000 / TICK_RATE;
static constexpr auto COLUMNS = 80;
static constexpr auto ROWS = 45;
static constexpr auto CELL_SIZE = 20;
static constexpr uint8_t ALPHA_OPAQUE = 255;
static constexpr uint8_t ALPHA_TRANSPARENT = 0;
static constexpr SDL_Color BLACK{0,0,0,ALPHA_OPAQUE};
static constexpr SDL_Color GREEN{0,255,0,ALPHA_OPAQUE};
static constexpr SDL_Color RED{255,0,0,ALPHA_OPAQUE};
static constexpr auto WINDOW_WIDTH = CELL_SIZE * COLUMNS;
static constexpr auto WINDOW_HEIGHT = CELL_SIZE * ROWS;
static constexpr auto CENTER_X = (COLUMNS / 2);
static constexpr auto CENTER_Y = (ROWS / 2);
static constexpr auto SPEED = 1; //"cells per tick"
static constexpr auto starting_x = CENTER_X;
static constexpr auto starting_y = CENTER_Y;