#include "Graphics.h"

void Graphics::setRenderer(SDL_Renderer *rend) {
    renderer = rend;
}

Graphics::Graphics() {
    setWindowSize(0, 0);
    setWindow(nullptr);
    setRenderer(nullptr);
    SDL_RenderSetScale(SDL_GetRenderer(window), 1, 1);
    fillScreen();
    present();
}

Graphics::Graphics(int window_width, int window_height, SDL_Window *win) {
    setWindowSize(window_height, window_height);
    setWindow(win);
    setRenderer(SDL_GetRenderer(window));
    SDL_RenderSetScale(SDL_GetRenderer(window), 1, 1);
    fillScreen();
    present();
}

Graphics::~Graphics() {
    delete window;
    delete renderer;
}

void Graphics::setWindowSize(int w, int h) {
    width = w;
    height = h;
}

void Graphics::setWindow(SDL_Window *win) {
    window = win;
}

int Graphics::getFPS() {
    return fps;
}

void Graphics::present() {
    SDL_RenderPresent(renderer);
}

void Graphics::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Graphics::fillScreen(Uint8 r, Uint8 g, Uint8 b) {
    setColor(r, g, b);
    SDL_RenderClear(renderer);
}

void Graphics::drawPoint(int x, int y) {
    SDL_RenderDrawPoint(renderer, x, y);
}

void Graphics::drawPoint(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    setColor(r, g, b, a);
    SDL_RenderDrawPoint(renderer, x, y);
}

double Graphics::distance(double x0, double y0, double x1, double y1) {
    return SDL_sqrt(SDL_pow(x1 - x0, 2) + SDL_pow(y1 - y0, 2));
}

void Graphics::keyPress(SDL_Keycode key) {}