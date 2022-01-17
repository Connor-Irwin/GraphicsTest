#include "CrawlingAnt.h"
#include <iostream>

CrawlingAnt::CrawlingAnt(int window_width, int window_height, SDL_Renderer* rend) {
    setWindowSize(window_width, window_height);
    setRenderer(rend);

    x = width / 2;
    y = height / 2;

    x_move = x;
    y_move = y;

    edginess = 10;

	fillScreen();
}

void CrawlingAnt::update() {
    /*
    dist_from_center = (int)distance(x, y, width / 2, height / 2);
    dist_from_right_edge = (int)distance(x, y, width, y);
    dist_from_left_edge = (int)distance(x, y, 0, y);
    dist_from_bottom_edge = (int)distance(x, y, x, height);
    dist_from_top_edge = (int)distance(x, y, x, 0);
    */

    x_move = rand() % width;
    y_move = rand() % height;
    
    if (SDL_abs(x_move - width / 2) < width / 2 / edginess) x_move = rand() % width;
    if (SDL_abs(y_move - height / 2) < height / 2 / edginess) y_move = rand() % height;

    if (x_move > x) x += 2;
    else if (x_move < x) x -= 2;
    
    if (y_move > y) y += 2;
    else if (y_move < y) y -= 2;

    drawPoint(x, y, 255, 178, 0);
    present();
}
