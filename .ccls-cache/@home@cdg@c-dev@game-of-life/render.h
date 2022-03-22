#ifndef RENDER_H_
#define RENDER_H_

#include <SDL2/SDL.h>

struct timespec {
    time_t tv_sec;
    long   tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);

int msleep(long ms);

void render_grid(SDL_Renderer * renderer);

void render_cells(SDL_Renderer * renderer, int ** world);

#endif
