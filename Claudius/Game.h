#pragma once
#include "Apple.h"
#include "Player.h"
#include <string_view>
class Game
{
	Player playerOne;
	Apple apple;

public:
	//Teemu Code Begin.

	// float timer; <- can be used in delta time
	// float updateInterval; <- check Game.h

	int width;
	int height;

	Game(int width, int height, std::string_view title);		
	void Update(double dt);
	void Render(SDL_Renderer* r);
	void OnKeyDown(SDL_Keycode key);
	void OnKeyUp(SDL_Keycode key);
};