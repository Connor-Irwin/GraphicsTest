#include "CrawlingAnt.h"
#include <iostream>

CrawlingAnt::CrawlingAnt(int window_width, int window_height, SDL_Window* win) {
    setWindowSize(window_height, window_height);
    setWindow(win);
    renderer = SDL_GetRenderer(window);

    x = window_width / 2;
    y = window_height / 2;

    edginess = 1;

    r = 255;
    g = 178;
    b = 0;
    a = 255;

    fillScreen();
}

CrawlingAnt::CrawlingAnt(int window_width, int window_height, SDL_Window* win, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    setWindowSize(window_height, window_height);
    setWindow(win);
    renderer = SDL_GetRenderer(window);

    x = window_width / 2;
    y = window_height / 2;

    edginess = 1;

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;

	fillScreen();
}

void CrawlingAnt::update() {
    dist_from_center = (int)distance(x, y, width / 2, height / 2);
    dist_from_east_edge = (int)distance(x, y, width, y);
    dist_from_west_edge = (int)distance(x, y, 0, y);
    dist_from_south_edge = (int)distance(x, y, x, height);
    dist_from_north_edge = (int)distance(x, y, x, 0);

    direction = rand() % 5;

    switch (direction) {
    case 1: { // East
        if (dist_from_east_edge < dist_from_center / edginess || x > width) direction = rand() % 5;

        if (x < width - 1) {
            x++;
            drawPoint(x, y, r, g, b, a);
            x++;
            drawPoint(x, y, r, g, b, a);
        }

        break;
    }

    case 2: { // West
        if (dist_from_west_edge < dist_from_center / edginess || x < 0) direction = rand() % 5;

        if (x > 0) {
            x--;
            drawPoint(x, y, r, g, b, a);
            x--;
            drawPoint(x, y, r, g, b, a);
        }

        break;
    }

    case 3: { // South
        if (dist_from_south_edge < dist_from_center / edginess || y > height) direction = rand() % 5;

        if (y < height - 1) {
            y++;
            drawPoint(x, y, r, g, b, a);
            y++;
            drawPoint(x, y, r, g, b, a);
        }

        break;
    }

    case 4: { // North
        if (dist_from_north_edge < dist_from_center / edginess || y < 0) direction = rand() % 5;

        if (y > 0) {
            y--;
            drawPoint(x, y, r, g, b, a);
            y--;
            drawPoint(x, y, r, g, b, a);
        }

        break;
    }

    default: {
        break;
    }
    }

    present();
}
