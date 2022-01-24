#include "Graphics Test.h"
#include <SDL.h>
#include <vector>
#include "Graphics/index.h"

using namespace std;

int main(int argc, char* argv[]) {
    int width = 100;	                                    // Width Height of SDL window
    int height = width;									    // Height of window
    const int FPS = 24;										// Program FPS


    // Initializes the timer, audio, video, joystick, haptic, game controller and events subsystems
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return -1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow(__FILE__, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

    if (!window) {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Create a renderer
    Uint32 render_flags = SDL_RENDERER_ACCELERATED; // SDL_RENDERER_SOFTWARE
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, render_flags);
    
    if (!renderer) {
        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Set blend mode
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Initialize a graphics object
    //Graphics* graphics = new CrawlingAnt(width, height, renderer);
    vector<Graphics*> graphics;
    graphics.push_back(new Menu(width, height, window));
    
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
            
            case 8192: {
                SDL_GetWindowSize(window, &width, &height);
                graphics[0]->setWindowSize(width, height);
                cout << "Size changed: " << width << ", " << height << endl;
                break;
            }

            case SDL_KEYDOWN: {
                switch (event.key.keysym.sym) {
                case 27: { // Esc
                    // Display the menu
                    graphics.clear();
                    graphics.push_back(new Menu(width, height, window));
                    paused = true;
                    break;
                }

                case 49: { // 1
                    // Draw Gaussian bumps of increasing size
                    graphics.clear();
                    graphics.push_back(new GaussianBump(width, height, window));
                    break;
                }

                case 50: { // 2
                    // Draw a virtual ant that leaves a trail on the screen
                    graphics.clear();
                    graphics.push_back(new CrawlingAnt(width, height, window, 255, 255, 0, 178));
                    graphics.push_back(new CrawlingAnt(width, height, window, 255, 0, 0, 178));
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
                */

                case 55: { // 7
                    // Set blend mode
                    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_MUL);

                    break;
                }

                case 56: { // 8
                    // Set blend mode
                    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_MOD);

                    break;
                }

                case 57: { // 9
                    // Set blend mode
                    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD);

                    break;
                }

                case 48: { // 0
                    // Set blend mode
                    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

                    break;
                }

                // a is 97, b is 98, ...

                case 112: { // p
                    // Toggle if the demos are paused or unpaused
                    paused = !paused;
                    break;
                }

                default: {
                    // Print out unmapped keystrokes
                    cout << "Sym: " << event.key.keysym.sym << endl;
                }
                }
            }

            default: {
                cout << "Uncaught event: " << event.type << endl;
                break;
            }
            }
        }

        // Only update if unpaused
        if (!paused) {
            for (Graphics* graph : graphics) {
                graph->update();
            }
        }

        SDL_Delay(1000 / FPS);
    }

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}