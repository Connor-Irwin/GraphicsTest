#pragma once

#include "Graphics.h"

class CrawlingAnt : public Graphics {
private:
	int x, y;

    int dist_from_center,
        dist_from_east_edge,
        dist_from_west_edge,
        dist_from_south_edge,
        dist_from_north_edge;

    //int x_move, // The x coordinate to move towards.
    //    y_move; // The y coordinate to move towards.

    Uint8 r, g, b, a;   // Color of the ant.
    int direction;      // The direction the ant will move next (0 for no movement, 1 for right, 2 for left, 3 for down, 4 for up).
    double edginess;    // How close to the edge the ant will get.

public:
    CrawlingAnt(int window_width, int window_height, SDL_Window *win);
	CrawlingAnt(int window_width, int window_height, SDL_Window *win,
                Uint8 r = 255, Uint8 g = 178, Uint8 b = 0, Uint8 a = 255);
	void update();
};