#include "CrawlingAnt.h"
#include <iostream>

CrawlingAnt::CrawlingAnt(int window_width, int window_height, SDL_Window *win) {
    setWindowSize(window_height, window_height);
    setWindow(win);
    renderer = SDL_GetRenderer(window);

    x = window_width / 10;  // Divide by 2 to center it,
    y = window_height / 10; // then by 5 to counteract the render scale.

    edginess = 1;

    r = 255;
    g = 178;
    b = 0;
    a = 255;

    direction = 0;

    SDL_RenderSetScale(SDL_GetRenderer(window), 5, 5);
    fillScreen();
    present();
}

CrawlingAnt::CrawlingAnt(int window_width, int window_height, SDL_Window *win, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    setWindowSize(window_height, window_height);
    setWindow(win);
    renderer = SDL_GetRenderer(window);

    x = window_width / 10;  // Divide by 2 to center it,
    y = window_height / 10; // then by 5 to counteract the render scale.

    edginess = 1;

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;

    direction = 0;

    SDL_RenderSetScale(SDL_GetRenderer(window), 5, 5);
	fillScreen();
    present();
}

void CrawlingAnt::update() {
    direction = rand() % 5;

    switch (direction) {
    case 1: { // East
        if (x < width - 1) {
            x++;
            drawPoint(x, y, r, g, b, a);
            x++;
            drawPoint(x, y, r, g, b, a);
        }

        break;
    }

    case 2: { // West
        if (x > 0) {
            x--;
            drawPoint(x, y, r, g, b, a);
            x--;
            drawPoint(x, y, r, g, b, a);
        }

        break;
    }

    case 3: { // South
        if (y < height - 1) {
            y++;
            drawPoint(x, y, r, g, b, a);
            y++;
            drawPoint(x, y, r, g, b, a);
        }

        break;
    }

    case 4: { // North
        if (y > 0) {
            y--;
            drawPoint(x, y, r, g, b, a);
            y--;
            drawPoint(x, y, r, g, b, a);
        }

        break;
    }
    }

    present();
}
