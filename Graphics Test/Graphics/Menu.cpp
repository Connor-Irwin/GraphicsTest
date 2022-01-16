#include "Menu.h"

Menu::Menu(int window_width, int window_height, SDL_Renderer* rend) {
	setWindowSize(window_height, window_height);
	setRenderer(rend);
	fillScreen();
}

void Menu::update() {
	
}
