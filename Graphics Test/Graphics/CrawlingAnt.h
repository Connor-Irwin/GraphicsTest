#pragma once

#include "Graphics.h"

class CrawlingAnt : public Graphics {
private:
	int x, y;

    /*
    int dist_from_center,
        dist_from_right_edge,
        dist_from_left_edge,
        dist_from_bottom_edge,
        dist_from_top_edge;

    int direction;      // The direction the ant will move next (0 for no movement, 1 for right, 2 for left, 3 for down, 4 for up).
    */

    int x_move, // The x coordinate to move towards.
        y_move; // The y coordinate to move towards.

    double edginess;    // How close to the edge the ant will get.

public:
	CrawlingAnt(int window_width, int window_height, SDL_Renderer* rend);
	void update();
};