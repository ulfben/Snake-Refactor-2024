#pragma once
#include "Rectangle.h"
#include "Color.h"
#include "Transform.h"
#include "SDL.h"

struct Apple
{	
		Apple();
	void Render(SDL_Renderer* r);	

	Rectangle rect;	
	Transform trans;

	bool new_apple = false;
};