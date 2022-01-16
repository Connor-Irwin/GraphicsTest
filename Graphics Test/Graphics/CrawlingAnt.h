#pragma once

#include "Graphics.h"

class CrawlingAnt : public Graphics {
private:
	int x, y;

public:
	CrawlingAnt(int window_width, int window_height, SDL_Renderer* rend);
	void update();
};