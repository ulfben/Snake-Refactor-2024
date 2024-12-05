#pragma once
#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"
#include "SDL.h"

struct Apple
{	
	void Render(SDL_Renderer* r);
	void Initialize(unsigned int width, unsigned int height);

	Rectangle rect;
	Color color;
	Transform trans;

	bool new_apple = false;
};