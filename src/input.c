#include "include/input.h"
#include "include/defs.h"

SDL_Event poll_events(void)
{
    SDL_Event event;
    SDL_PollEvent(&event);
    return event;
}

bool is_key_down(uint32_t key)
{
    SDL_Event event = poll_events();

    if (event.type == SDL_KEYDOWN)
    {
        return event.key.keysym.sym == (SDL_Keycode)key;
    }

    return false;
}

void handle_exit_events(App *app)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            app->running = false;
        }
    }
}
