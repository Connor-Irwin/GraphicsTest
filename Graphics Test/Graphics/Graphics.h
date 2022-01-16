#pragma once

#include <SDL.h>

class Graphics {
private:
	static SDL_Renderer* renderer;
	static int width, height;

public:
	Graphics();
	Graphics(int window_width, int window_height, SDL_Renderer* rend);

	void setWindowSize(int window_width, int window_height);
	void getWindowSizeRef(int& window_width, int& window_height);
	void setRenderer(SDL_Renderer* rend);

	void present();
	void setColor(Uint8 r, Uint8 g, Uint8 b);
	void fillScreen(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0);
	void drawPoint(int x, int y);
	void drawPoint(int x, int y, Uint8 r, Uint8 g, Uint8 b);

	virtual void update() = 0;
};