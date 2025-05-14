#ifndef NIV_INPUT_H
#define NIV_INPUT_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "defs.h"

SDL_Event poll_events(void);
bool      is_key_down(uint32_t key);

void handle_exit_events(App *app);

#endif // NIV_INPUT_H
