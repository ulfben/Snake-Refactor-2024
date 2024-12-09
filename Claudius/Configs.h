#pragma once
static constexpr std::string_view GAME_TITLE = "Snake";
static constexpr int TICK_RATE = 15; // ticks per second
static constexpr auto FRAME_DELAY = 1000 / TICK_RATE;
static constexpr auto COLUMNS = 125;
static constexpr auto ROWS = 70;
static constexpr auto CELL_SIZE = 10;
static constexpr unsigned WINDOW_WIDTH = CELL_SIZE*COLUMNS;
static constexpr unsigned WINDOW_HEIGHT = CELL_SIZE*ROWS; 
static constexpr unsigned CENTER_X = (COLUMNS/2) * CELL_SIZE;
static constexpr unsigned CENTER_Y = (ROWS/2) * CELL_SIZE;
static constexpr int SPEED = CELL_SIZE;
static constexpr int starting_x = CENTER_X;
static constexpr int starting_y = CENTER_Y;