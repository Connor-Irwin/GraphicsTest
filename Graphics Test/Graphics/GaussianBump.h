#pragma once

#include "Graphics.h"

class GaussianBump : public Graphics {
private:
	int size;
	double bump(double x, double y, double x0, double y0, double sX, double sY);

public:
	GaussianBump(int window_width, int window_height, SDL_Window *win);
	void update();
};