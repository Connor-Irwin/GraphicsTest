#include "Menu.h"

void Menu::writeTextToScreen(std::string text, int x, int y, int w, int h) {
	SDL_Rect srcrect{ 0, 0, 19, 30 },
			 dstrect{ x, y, w, h };

	for (int i = 0; i < text.size(); i++) {
		srcrect.x = 19 * (text[i] - ' ');

		dstrect.x = w * i + x;
		dstrect.y = y;

		SDL_BlitSurface(font_image, &srcrect, window_surface, &dstrect);
	}
}

Menu::Menu(int window_width, int window_height, SDL_Window *win) {
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
	writeTextToScreen("Press a key to play a demo.", 10, 10);
	writeTextToScreen("Esc: This menu", 10, 45);
	writeTextToScreen("1:   Gaussian bump", 10, 80);
	writeTextToScreen("2:   Crawling ant", 10, 115);

	SDL_UpdateWindowSurface(window);
}