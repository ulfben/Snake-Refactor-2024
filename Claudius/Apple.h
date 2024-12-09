#pragma once
#include "Renderer.h"
#include "Apple.h"
#include "SDLUtils.h"
#include "Color.h"
#include "Vector2.h"
constexpr auto APPLE_SIZE = 10;
struct Apple{
    Vector2 pos{(rand() % 125) * 10.0f,
                (rand() % 70) * 10.0f};

    void render(const Renderer& r) const noexcept{                
        r.draw({(int)pos.x, (int)pos.y, APPLE_SIZE, APPLE_SIZE}, Color::RED);
    }        
};