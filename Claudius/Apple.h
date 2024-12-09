#pragma once
#include "Renderer.h"
#include "Cell.h"
#include "Configs.h"
struct Apple final{
    Cell pos{(rand() % COLUMNS),
                (rand() % ROWS)};

    void render(const Renderer& r) const noexcept{    
        r.setColor(RED);
        r.drawCell(pos.x, pos.y);
    }        
};