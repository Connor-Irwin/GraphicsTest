#pragma once

#include "Graphics.h"
#include <string>

class Menu : public Graphics {
private:
	SDL_Surface *font_image;
	SDL_Surface *window_surface;

	void writeTextToScreen(std::string text, int x, int y, int width = 19, int height = 30);

public:
	Menu(int window_width, int window_height, SDL_Window *win);
	~Menu();

	void update();
};