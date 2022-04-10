#pragma once

#include <SDL.h>
#include <vector>
#include <iostream>

using namespace std;

class Graphics {
protected:
	SDL_Window* window;
	SDL_Renderer *renderer;
	int width, height;
	vector<char> keysDown;
	
	int fps = 24;

	void setRenderer(SDL_Renderer *rend);

public:
	Graphics();
	Graphics(int window_width, int window_height, SDL_Window *win);
	~Graphics();

	void setWindowSize(int window_width, int window_height);
	void setWindow(SDL_Window *win);
	int getFPS();

	void present();
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
	void fillScreen(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0);
	void drawPoint(int x, int y);
	void drawPoint(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

	double distance(double x0, double y0, double x1, double y1);

	virtual void keyPress(SDL_Keycode key);

	virtual void update() = 0;
};