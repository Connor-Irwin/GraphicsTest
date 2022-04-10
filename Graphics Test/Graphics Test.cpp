#include "Graphics Test.h"
#include <SDL.h>
#include <vector>
#include "Graphics/index.h"

using namespace std;

int main(int argc, char *argv[]) {
    int width = 300; // Width Height of SDL window
    int height = width; // Height of window

    // Initializes the timer, audio, video, joystick, haptic, game controller and events subsystems
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return -1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow(__FILE__, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

    if (!window) {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Create a renderer
    Uint32 render_flags = SDL_RENDERER_ACCELERATED; // SDL_RENDERER_SOFTWARE
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, render_flags);
    
    if (!renderer) {
        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Set blend mode
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Initialize a graphics object vector
    vector<Graphics*> graphics{ new Menu(width, height, window) };
    
    // Main loop
    SDL_Event event;
    bool running = true;
    bool paused = false;

    while (running) {
        // Process events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT: {
                // Stop when the window close button is pressed
                running = false;
                printf("Exiting (do not close window)...\n");
                break;
            }
            
            case SDL_WINDOWEVENT: {
                // If the window is resized, update the graphics object's window size

                //for (Graphics* graphic : graphics) {
                //    graphic->setWindowSize(width, height);
                //    graphic->update();
                //}

                SDL_GetWindowSize(window, &width, &height);
                graphics[0]->setWindowSize(width, height);
                graphics[0]->update();

                break;
            }

            case SDL_KEYDOWN: {
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE: {
                    // Display the menu
                    graphics.clear();
                    graphics.push_back(new Menu(width, height, window));
                    break;
                }

                case SDLK_1: {
                    // Draw Gaussian bumps of increasing size
                    graphics.clear();
                    graphics.push_back(new GaussianBump(width, height, window));
                    break;
                }

                case SDLK_2: {
                    // Draw a virtual ant that leaves a trail on the screen
                    graphics.clear();
                    graphics.push_back(new CrawlingAnt(width, height, window, 255, 255, 0, 178));
                    //graphics.push_back(new CrawlingAnt(width, height, window, 255, 0, 0, 178));
                    break;
                }

                case SDLK_3: {
                    // Display a game of Conway's Game of Life
                    graphics.clear();
                    graphics.push_back(new GameOfLife(width, height, window, 10, 10));
                    break;
                }

                case SDLK_4: {
                    // Display an interactive ray tracer maze
                    graphics.clear();
                    graphics.push_back(new RayTracerMaze(width, height, window));
                    break;
                }

                case SDLK_7: {
                    // Set blend mode
                    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_MUL);
                    break;
                }

                case SDLK_8: {
                    // Set blend mode
                    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_MOD);
                    break;
                }

                case SDLK_9: {
                    // Set blend mode
                    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD);
                    break;
                }

                case SDLK_0: {
                    // Set blend mode
                    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
                    break;
                }

                case SDLK_p: { // p
                    // Toggle if the demos are paused or unpaused
                    paused = !paused;
                    break;
                }

                default: {
                    // Pass key press to graphics object
                    graphics[0]->keyPress(event.key.keysym.sym);
                    break;
                }
                }
            }
            }
        }

        // Only update if unpaused
        if (!paused) {
            for (Graphics *graphic : graphics) {
                graphic->update();
            }
        }

        SDL_Delay(1000 / graphics[0]->getFPS());
    }

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}