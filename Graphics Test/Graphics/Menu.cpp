#include "Menu.h"

Menu::Menu(int window_width, int window_height, SDL_Window* win) {
	setWindowSize(window_height, window_height);
	setWindow(win);
	setRenderer(SDL_GetRenderer(window));
	fillScreen();
}

void Menu::update() {
	//SDLTest_DrawString(renderer, 10, 10, "Esc:	This menu");
	//SDLTest_DrawString(renderer, 10, 20, "1:	Gaussian Bump");
	//SDLTest_DrawString(renderer, 10, 30, "2:	Crawling Ants");
	
	SDL_Surface* window_surface = SDL_GetWindowSurface(window);
	SDL_Surface* image = SDL_LoadBMP("/Users/conno/source/repos/Graphics Test/Graphics Test/24pt (19x30).bmp");
	SDL_BlitSurface(image, NULL, window_surface, NULL);
	SDL_UpdateWindowSurface(window);
}