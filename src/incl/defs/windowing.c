/*
 * Niv -- a dead simple (and lightweight) game engine for C.
 * ---------------------------------------------------------
 * 
 * Copyright (C) 2025  Mario Rosell
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * 
 * ---------------------------------------------------------
 */

#include "../windowing.h"
#include "../logger.h"
#include "../../defs.h"

#include <stdint.h>

static inline uint32_t getMiddleX (void)
  {
    SDL_DisplayMode dm;
    SDL_GetCurrentDisplayMode (0, &dm);
    return (dm.w - 800) / 2;
  }

static inline uint32_t getMiddleY (void)
  {
    SDL_DisplayMode dm;
    SDL_GetCurrentDisplayMode (0, &dm);
    return (dm.h - 600) / 2;
  }

void Application__new (struct Application * app, const char * title)
  {
    app->WinTitle = title;
    app->WinSize.x = 800;
    app->WinSize.y = 600;
    app->WinPos.x = getMiddleX ();
    app->WinPos.y = getMiddleY ();
    LOG_DEBUG("Window position: %d, %d", app->WinPos.x, app->WinPos.y);
  }

bool niv_init_window (struct Application * app)
  {
    if (SDL_Init (NIV_FLAGS) < 0)
      {
        LOG_ERROR ("Failed to initialize SDL: “%s”", SDL_GetError ());
        return false;
      }
    
    app->SdlWin = SDL_CreateWindow ( app->WinTitle, app->WinPos.x, app->WinPos.y,
                                     app->WinSize.x, app->WinSize.y, SDL_WINDOW_SHOWN );

    return true;

  }
