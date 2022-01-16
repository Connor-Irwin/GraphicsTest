#pragma once

#include "Graphics.h"

class Menu : public Graphics {
public:
	Menu(int window_width, int window_height, SDL_Renderer* rend);
	void update();
};