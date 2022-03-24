#include <SDL2/SDL.h>
#include <errno.h>
#include <time.h>
#include "constants.h"
#include "render.h"

void delay(int milliseconds) {
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void render_grid(SDL_Renderer * renderer) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        for(int i=0; i<N; i++) {
            SDL_RenderDrawLine(renderer, i * CELL_WIDTH, 0, i * CELL_WIDTH, SCREEN_HEIGHT);
            SDL_RenderDrawLine(renderer, 0, i * CELL_HEIGHT, SCREEN_WIDTH, i * CELL_HEIGHT);
        }
}

void render_cells(SDL_Renderer * renderer, int ** world) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                    if(world[i][j] == 1) {
                    SDL_Rect rect;
                    rect.y = i * CELL_WIDTH;
                    rect.x = j * CELL_HEIGHT;
                    rect.w = CELL_WIDTH;
                    rect.h = CELL_HEIGHT;
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }
}
