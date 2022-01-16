#include "Graphics.h"

Graphics::Graphics() {
    setWindowSize(0, 0);
    setRenderer(nullptr);

    fillScreen();
}

Graphics::Graphics(int window_width, int window_height, SDL_Renderer* rend) {
    setWindowSize(window_height, window_height);
    setRenderer(rend);
    fillScreen();
}

void Graphics::setWindowSize(int window_width, int window_height) {
    width = window_width;
    height = window_height;
}

void Graphics::getWindowSizeRef(int& window_width, int& window_height) {
    window_width = width;
    window_height = height;
}

void Graphics::setRenderer(SDL_Renderer* rend) {
    renderer = rend;
}

void Graphics::present() {
    SDL_RenderPresent(renderer);
}

void Graphics::setColor(Uint8 r, Uint8 g, Uint8 b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
}

void Graphics::fillScreen(Uint8 r, Uint8 g, Uint8 b) {
    setColor(r, g, b);
    SDL_RenderClear(renderer);
    present();
}

void Graphics::drawPoint(int x, int y) {
    SDL_RenderDrawPoint(renderer, x, y);
}

void Graphics::drawPoint(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
    setColor(r, g, b);
    SDL_RenderDrawPoint(renderer, x, y);
}
