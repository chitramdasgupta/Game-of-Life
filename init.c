#include <SDL2/SDL.h>
#include "constants.h"
#include <stdlib.h>

SDL_Window * initialize_window(const char * window_name) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Window * window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        fprintf(stderr, "SDL_CreateWindow error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    return window;
}

SDL_Renderer * initialize_renderer(SDL_Window * window) {
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateRenderer error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    return renderer;
}

void exit_SDL(SDL_Window * window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
