#ifndef NIV_WINDOWING_H
#define NIV_WINDOWING_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "defs.h"

#define NIV_WIN_FLAGS (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)

SDL_Window*    create_window(App *app);
SDL_Renderer*  create_renderer(App *app, int flags);

void destroy_window(SDL_Window* window);
void destroy_renderer(SDL_Renderer* renderer);

void cleanup(App *app);

#endif // NIV_WINDOWING_H