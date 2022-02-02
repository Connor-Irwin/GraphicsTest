#include "GaussianBump.h"

double GaussianBump::bump(double x, double y, double x0, double y0, double sX, double sY) {
    return SDL_exp(-((SDL_pow((x - x0), 2)) / (2 * SDL_pow(sX, 2)) + (SDL_pow((y - y0), 2)) / (2 * SDL_pow(sY, 2))));
}

GaussianBump::GaussianBump(int window_width, int window_height, SDL_Window *win) {
    setWindowSize(window_height, window_height);
    setWindow(win);
    renderer = SDL_GetRenderer(window);

    size = 1;

    fillScreen();
}

void GaussianBump::update() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Uint8 c;

            c = (Uint8)round(255 * bump(x, y, (width - 1) / 2, (height - 1) / 2, size, size));

            drawPoint(x, y, c, c, c);
        }
    }

    present();
    size++;
}
