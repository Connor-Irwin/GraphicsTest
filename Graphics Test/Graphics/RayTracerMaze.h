#pragma once

#include "Graphics.h"

#include <iostream>

class RayTracerMaze : public Graphics {
private:
	int row, col;
	double direction; // The direction that the "camera" is facing in radians
	vector<vector<bool> > maze;

public:
	RayTracerMaze(int window_width, int window_height, SDL_Window* win);
	void keyPress(SDL_Keycode key);
	void update();
};