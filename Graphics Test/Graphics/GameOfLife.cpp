#include "GameOfLife.h"

void GameOfLife::fillBoard(vector<vector<unsigned char>>& board) {
    for (vector<unsigned char>& row : board) {
        for (unsigned char& col : row) {
            col = rand() % 2;
        }
    }
}

GameOfLife::GameOfLife(int window_width, int window_height, SDL_Window* win) {
    setWindowSize(window_height, window_height);
    setWindow(win);
    setRenderer(SDL_GetRenderer(window));
    fillScreen(50, 50, 50);
    present();

    board = vector<vector<unsigned char>>(10, vector<unsigned char>(10, 0));
    fps = 1;
    SDL_RenderSetScale(SDL_GetRenderer(window), 10, 10);
    fillBoard(board);
}

GameOfLife::GameOfLife(int window_width, int window_height, SDL_Window* win, int board_rows, int board_cols) {
    setWindowSize(window_height, window_height);
    setWindow(win);
    setRenderer(SDL_GetRenderer(window));
    fillScreen(50, 50, 50);
    present();

    board = vector<vector<unsigned char>>(board_rows, vector<unsigned char>(board_cols, 0));
    fps = 1;
    SDL_RenderSetScale(SDL_GetRenderer(window), 10, 10);
    fillBoard(board);
}

void GameOfLife::update() {
    // TODO: Fix problem of cells not dying when they have too many neighbours.

    vector<vector<unsigned char>> board_copy = board;

    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[row].size(); col++) {
            int neighbor_sum = 0;

            for (int sub_row = row - 1; sub_row <= row + 1; sub_row++) {
                for (int sub_col = col - 1; sub_col <= col + 1; sub_col++) {
                    if (0 > sub_row || sub_row >= board.size()) continue;
                    if (0 > sub_col || sub_col >= board[sub_row].size()) continue;
                    if (sub_row == row || sub_col == col) continue;

                    neighbor_sum += board[sub_row][sub_col];
                }
            }

            if (neighbor_sum == 3) board_copy[row][col] = 1;
            else if (neighbor_sum != 2) board_copy[row][col] = 0;
        }
    }

    board = board_copy;

    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board[row].size(); col++) {
            if (board[row][col] == 1) drawPoint(col * 2, row * 2, 255, 255, 255);
            else drawPoint(col * 2, row * 2, 0, 0, 0);
        }
    }

    present();
}
