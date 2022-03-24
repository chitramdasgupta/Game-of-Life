#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include "constants.h"
#include "logic.h"
#include "init.h"
#include "render.h"

int main(int argc, char *argv[]) {
    SDL_Window * window = initialize_window("Game of Life");
    SDL_Renderer * renderer = initialize_renderer(window);

    int ** world = generate_random_world();
    int ** new_world = generate_random_world();

    SDL_Event e;
    int quit = 0;
    while(!quit) {
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                    quit = 1;
                    break;
                default:
                    {}
            }
        }

        // Update the world state
        update_world_state(world, new_world);

        // Render the grid
        render_grid(renderer);
        // Render the cells
        render_cells(renderer, world);
        SDL_RenderPresent(renderer);

        // delay(500);
        SDL_Delay(500);
    }

    exit_SDL(window);
    return EXIT_SUCCESS;
}
