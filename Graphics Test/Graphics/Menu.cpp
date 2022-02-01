#include "Menu.h"

Menu::Menu(int window_width, int window_height, SDL_Window* win) {
	setWindowSize(window_height, window_height);
	setWindow(win);
	setRenderer(SDL_GetRenderer(window));
	fillScreen();

	font_image = SDL_LoadBMP("/Users/conno/source/repos/Graphics Test/Graphics Test/24pt (19x30) - Copy.bmp");
	window_surface = SDL_GetWindowSurface(window);
}

Menu::~Menu() {
	delete font_image;
}

void Menu::update() {
	SDL_BlitSurface(font_image, NULL, window_surface, NULL);
	SDL_UpdateWindowSurface(window);
}