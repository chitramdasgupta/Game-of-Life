#ifndef RENDER_H_
#define RENDER_H_

#include <SDL2/SDL.h>

void delay(int milliseconds);

void render_grid(SDL_Renderer * renderer);

void render_cells(SDL_Renderer * renderer, int ** world);

#endif
