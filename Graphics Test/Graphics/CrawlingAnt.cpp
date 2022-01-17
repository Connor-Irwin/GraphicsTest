#include "CrawlingAnt.h"
#include <iostream>

CrawlingAnt::CrawlingAnt(int window_width, int window_height, SDL_Renderer* rend) {
    setWindowSize(window_width, window_height);
    setRenderer(rend);

    x = window_width / 2;
    y = window_height / 2;

    edginess = 1;

	fillScreen();
}

void CrawlingAnt::update() {
    dist_from_center = (int)distance(x, y, width / 2, height / 2);
    dist_from_right_edge = (int)distance(x, y, width, y);
    dist_from_left_edge = (int)distance(x, y, 0, y);
    dist_from_bottom_edge = (int)distance(x, y, x, height);
    dist_from_top_edge = (int)distance(x, y, x, 0);

    direction = rand() % 5;

    int x_move = rand() % width;
    int y_move = rand() % height;

    switch (direction) {
    case 1: { // Right
        if (dist_from_right_edge < dist_from_center / edginess || x > width) direction = rand() % 5;

        x++;
        drawPoint(x, y, 255, 178, 0);
        x++;
        drawPoint(x, y, 255, 178, 0);

        break;
    }

    case 2: { // Left
        if (dist_from_left_edge < dist_from_center / edginess || x < 0) direction = rand() % 5;

        x--;
        drawPoint(x, y, 255, 178, 0);
        x--;
        drawPoint(x, y, 255, 178, 0);

        break;
    }

    case 3: { // Down
        if (dist_from_bottom_edge < dist_from_center / edginess || y > height) direction = rand() % 5;

        y--;
        drawPoint(x, y, 255, 178, 0);
        y--;
        drawPoint(x, y, 255, 178, 0);

        break;
    }

    case 4: { // Up
        if (dist_from_top_edge < dist_from_center / edginess || y < 0) direction = rand() % 5;

        y++;
        drawPoint(x, y, 255, 178, 0);
        y++;
        drawPoint(x, y, 255, 178, 0);

        break;
    }

    default: {
        break;
    }
    }

    present();
}
