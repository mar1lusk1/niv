#include "include/windowing.h"
#include "include/defs.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

SDL_Window *create_window(struct App *app)
{
    app->window = SDL_CreateWindow(app->title, SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, app->width, app->height,
                                NIV_WIN_FLAGS);
    if (!app->window)
    {
        fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    return app->window;
}

SDL_Renderer *create_renderer(struct App *app, int flags)
{
    app->renderer = SDL_CreateRenderer(app->window, -1, flags);
    if (!app->renderer)
    {
        fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    return app->renderer;
}

void destroy_renderer(SDL_Renderer* renderer)
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
}

void destroy_window(SDL_Window* window)
{
    if (window)
    {
        SDL_DestroyWindow(window);
    }
}

void cleanup(struct App *app)
{
    destroy_renderer(app->renderer);
    destroy_window(app->window);
    SDL_Quit();
    IMG_Quit();
}