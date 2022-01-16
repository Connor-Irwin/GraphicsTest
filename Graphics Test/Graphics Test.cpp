// Graphics Test.cpp : Defines the entry point for the application.
//

#include "Graphics Test.h"
#include <SDL.h>
#include <math.h>
#include "Graphics/index.h"

using namespace std;

int main(int argc, char* argv[]) {
    int width = 100;	                                    // Width Height of SDL window
    int height = width;									    // Height of window
    const int FPS = 24;										// Program FPS


    // Initializes the timer, audio, video, joystick, haptic, gamecontroller and events subsystems
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 0;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

    if (!window) {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    // Create a renderer
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC; // SDL_RENDERER_SOFTWARE
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, render_flags);

    if (!renderer) {
        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }

    // Initialize a graphics object
    Graphics* graphics = new CrawlingAnt(width, height, renderer);

    // Main loop
    SDL_Event event;
    bool running = true;
    bool paused = false;

    while (running) {
        // Process events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT: {
                running = false;
                printf("Exiting (do not close window)...\n");
                break;
            }
            
            case SDL_WINDOWEVENT_MAXIMIZED: {
                SDL_MaximizeWindow(window);
                break;
            }

            case SDL_WINDOWEVENT_RESTORED: {
                SDL_RestoreWindow(window);
                break;
            }

            case SDL_WINDOWEVENT_RESIZED: {
                SDL_GetWindowSize(window, &width, &height);
                cout << "Resize: " << width << ", " << height;
                break;
            }

            case SDL_KEYDOWN: {
                switch (event.key.keysym.sym) {
                case 27: { // Esc
                    // Display the menu
                    graphics = new Menu(width, height, renderer);
                    paused = true;
                    break;
                }

                case 49: { // 1
                    // Draw gaussian bumps of increasing size
                    graphics = new GaussianBump(width, height, renderer);
                    break;
                }

                case 50: { // 2
                    // Draw a virtual ant that leaves a trail on the screen
                    graphics = new CrawlingAnt(width, height, renderer);
                    break;
                }

                /*
                case 51: { // 3
                    break;
                }

                case 52: { // 4
                    break;
                }

                case 53: { // 5
                    break;
                }

                case 54: { // 6
                    break;
                }

                case 55: { // 7
                    break;
                }

                case 56: { // 8
                    break;
                }

                case 57: { // 9
                    break;
                }

                case 48: { // 0
                    break;
                }
                */

                // a is 97, b is 98, ...

                case 112: { // p
                    // Toggle if the demos are paused or unpaused
                    paused = !paused;
                    break;
                }

                default: {
                    // Print out unmapped keystokes
                    cout << "Sym: " << event.key.keysym.sym << endl;
                }
                }
            }

            default: {
                break;
            }
            }
        }

        // Only update if unpaused
        if (!paused) {
            graphics->update();
        }

        //Draw to window and loop
        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / FPS);
    }

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}