#pragma once

#include "Graphics.h"

class Menu : public Graphics {
private:
	SDL_Surface* font_image;
	SDL_Surface* window_surface;

public:
	Menu(int window_width, int window_height, SDL_Window* win);
	~Menu();

	void update();
};