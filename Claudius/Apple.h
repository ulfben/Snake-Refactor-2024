#pragma once
#include "Renderer.h"
#include "Apple.h"
#include "SDLUtils.h"
#include "Cell.h"
#include "Configs.h"
struct Apple{
    Cell pos{(rand() % 125) * CELL_SIZE,
                (rand() % 70) * CELL_SIZE};

    void render(const Renderer& r) const noexcept{    
        r.setColor(RED);
        r.drawCell(pos.x, pos.y);
    }        
};