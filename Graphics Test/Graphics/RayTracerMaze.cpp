#include "RayTracerMaze.h"

RayTracerMaze::RayTracerMaze(int window_width, int window_height, SDL_Window* win) {
    setWindowSize(window_height, window_height);
    setWindow(win);
    renderer = SDL_GetRenderer(window);

    row = 1;
    col = 1;

    direction = 0; // 0 radians is left

    maze = {{1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 0, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0, 0, 0, 1},
            {1, 0, 1, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1}};

    fillScreen();
    present();
}

void RayTracerMaze::keyPress(SDL_Keycode key) {
    switch (key) {
    case SDLK_LEFT: {
        if (col > 0 && !maze[row][col - 1.0] && direction == 0) col--;
        else direction = 0;
        break;
    }

    case SDLK_DOWN: {
        if (row < (maze.size() - 1) && !maze[row + 1.0][col] && direction == (M_PI / 2)) row++;
        else direction = M_PI / 2;
        break;
    }

    case SDLK_RIGHT: {
        if (col < (maze[row].size() - 1) && !maze[row][col + 1.0] && direction == M_PI) col++;
        else direction = M_PI;
        break;
    }

    case SDLK_UP: {
        if (row > 0 && !maze[row - 1.0][col] && direction == (3 * M_PI / 2)) row--;
        else direction = 3 * M_PI / 2;
        break;
    }
    }
}

void RayTracerMaze::update() {
    fillScreen();

    cout << "(" << col << ", " << row << ") " << direction << endl;

    SDL_RenderSetScale(renderer, 11, 11);
    for (int r = 0; r < maze.size(); r++) {
        for (int c = 0; c < maze[r].size(); c++) {
            if (maze[r][c]) setColor(255, 255, 255);
            else if (r == row && c == col) setColor(255, 0, 0);
            else setColor(0, 0, 0);
            SDL_RenderDrawPoint(renderer, c, r);
        }
    }
    
    SDL_RenderSetScale(renderer, 1, 1);

    double r = row;
    while (0 <= r && r < maze.size()) {
        double c = 1 / SDL_tan(direction) * (r - row) + col;
        
        if (!(0 <= c && c < maze[round(r)].size())) c = 0;

        if (r < maze.size() && c < maze[round(r)].size() && maze[round(r)][round(c)] == 1) {
            setColor(0, 255, 255);
            SDL_RenderDrawLine(renderer, round(col * 11 + 5), round(row * 11 + 5), round(c * 11 + 5), round(r * 11 + 5));
            break;
        }

        // l d r u

        //if (direction == 0) c--;
        if (0 <= direction && direction <= (M_PI / 2)) r++;
        //else if (direction == M_PI) c++;
        else if (M_PI <= direction && direction <= (3 * M_PI / 2)) r--;
    }

    present();
}