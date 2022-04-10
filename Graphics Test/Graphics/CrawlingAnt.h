#pragma once

#include "Graphics.h"

class CrawlingAnt : public Graphics {
private:
	int x, y;

    Uint8 r, g, b, a;   // Color of the ant.
    int direction;      // The direction the ant will move next (0 for no movement, 1 for right, 2 for left, 3 for down, 4 for up).

    double edginess;    // How close to the edge the ant will get.

public:
    CrawlingAnt(int window_width, int window_height, SDL_Window *win);
	CrawlingAnt(int window_width, int window_height, SDL_Window *win,
                Uint8 r = 255, Uint8 g = 178, Uint8 b = 0, Uint8 a = 255);
	void update();
};