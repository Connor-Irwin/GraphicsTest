#pragma once

#include "Graphics.h"

class GameOfLife : public Graphics {
private:
    vector<vector<unsigned char>> board;
    void fillBoard(vector<vector<unsigned char>>& board);

public:
    GameOfLife(int window_width, int window_height, SDL_Window* win);
    GameOfLife(int window_width, int window_height, SDL_Window* win, int board_rows, int board_cols);
    void update();
};