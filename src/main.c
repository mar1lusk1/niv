/*
 * SPDX-License-Identifier: GPL-3.0-or-later
 * 
 * Copyright (C) 2025 Mario Rosell
*/

/*** INCLUDES ***/

#include <SDL2/SDL.h>
#include <SDL2/SDL_shape.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>

#include "include/defs.h"
#include "include/cli.h"
#include "include/windowing.h"
#include "include/input.h"

/*** GLOBAL VARIABLES ***/

struct App app;

/*** DEFINITIONS ***/

#define  NIV_VERSION    "0.1.0"
#define  NIV_COPYRIGHT  "Copyright (C) 2025 Mario Rosell"

#define  NIV_WIN_TITLE  "Niv Game Engine"
#define  NIV_WIN_WIDTH  640
#define  NIV_WIN_HEIGHT 480

#define  NIV_RENDERER_FLAGS (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)

/*** FUNCTIONS ***/

static void init_app(App *app)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    int img_flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(img_flags) & img_flags)) {
        fprintf(stderr, "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    app->title = NIV_WIN_TITLE;
    app->width = NIV_WIN_WIDTH;
    app->height = NIV_WIN_HEIGHT;

    app->window = create_window(app);
    app->renderer = create_renderer(app, NIV_RENDERER_FLAGS);

    app->running = true;
}

/*** MAIN ***/

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        /*** ERROR: No command or flag provided ***/
        print_help(argv[0]);
        return EXIT_FAILURE;
    }

    handle_cmd(argv);

    return EXIT_SUCCESS;
}
