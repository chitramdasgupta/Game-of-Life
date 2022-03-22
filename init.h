#ifndef INIT_H_
#define INIT_H_

#include<SDL2/SDL.h>

SDL_Window * initialize_window(const char * window_name);

SDL_Renderer * initialize_renderer(SDL_Window * window);

void exit_SDL(SDL_Window * window);

#endif
