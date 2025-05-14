#ifndef NIV_DEFS_H
#define NIV_DEFS_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#define NIV_VERSION    "0.1.0"
#define NIV_COPYRIGHT  "Copyright (C) 2025 Mario Rosell"

struct App
{
    SDL_Window    *window;
    SDL_Renderer  *renderer;

    bool           running;

    const char    *title;
    int            width;
    int            height;
};

typedef struct App App;

#endif // NIV_DEFS_H