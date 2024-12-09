#pragma once
#include "Renderer.h"
#include "Apple.h"
#include "SDLUtils.h"
#include "Color.h"
#include "Vector2.h"
#include "Configs.h"
struct Apple{
    Vector2 pos{(rand() % 125) * CELL_SIZE,
                (rand() % 70) * CELL_SIZE};

    void render(const Renderer& r) const noexcept{                
        r.draw({pos.x, pos.y, CELL_SIZE, CELL_SIZE}, Color::RED);
    }        
};