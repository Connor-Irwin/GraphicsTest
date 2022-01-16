#include "CrawlingAnt.h"
#include <iostream>

CrawlingAnt::CrawlingAnt(int window_width, int window_height, SDL_Renderer* rend) {
    setWindowSize(window_height, window_height);
    setRenderer(rend);

    getWindowSizeRef(x, y);
    x /= 2;
    y /= 2;

	fillScreen();
}

void CrawlingAnt::update() {
    int rand_int = rand() % 5;

    switch (rand_int) {
    case 1: { // Right
        x++;
        drawPoint(x, y, 255, 178, 0);
        x++;
        drawPoint(x, y, 255, 178, 0);

        break;
    }

    case 2: { // Left
        x--;
        drawPoint(x, y, 255, 178, 0);
        x--;
        drawPoint(x, y, 255, 178, 0);

        break;
    }

    case 3: { // Down
        y--;
        drawPoint(x, y, 255, 178, 0);
        y--;
        drawPoint(x, y, 255, 178, 0);

        break;
    }

    case 4: { // Up
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
