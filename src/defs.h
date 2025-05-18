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

#include <SDL2/SDL.h>

#include <stdint.h>

#ifndef NIV_DEFS
#define NIV_DEFS

    #define NIV_VERSION_STRING "0.0.1 (devel)"
    #define NIV_VERSION_MAJOR  0
    #define NIV_VERSION_MINOR  0
    #define NIV_VERSION_PATCH  1
    #define NIV_VERSION_EXTRA  "devel"

    /*** EXIT CODES ***/

    #define EXIT_SUCCESS 0
    #define EXIT_UNKNOWN_ERROR -1

    /*** WINDOWING ***/

    #define NIV_FLAGS SDL_INIT_EVERYTHING

    #define EXIT_ERROR_SDL_INIT 2

    /*** STRUCTS ***/

    /**
     * A 2D vector (a.k.a. point)
     * 
     * Vectors are useful for representing positions, sizes, etc.
     * 
     * == Has ==
     * 
     * Position:
     * 
     * - `float x` -- The x position
     * - `float y` -- The y position
     */
    struct Vector2D
    {
        float x;
        float y;
    };

    /**
     * A Niv program.
     * 
     * This `struct` holds metadata about a Niv program.
     * 
     * == Has ==
     * 
     * SDL stuff:
     * 
     * - `SDL_Window * SdlWin` -- The SDL window
     * - `SDL_Renderer * SdlRenderer` -- The SDL renderer
     * - `uint32_t SDL_Flags` -- The SDL flags
     * 
     * Window data:
     * 
     * - `char * WinTitle` -- The window title
     * - `SDL_Surface * WinIcon` -- The window icon (generated via `gen_icon()`)
     * - `Vector2D WinSize` -- The window size
     * - `Vector2D WinPos` -- The window position
     * 
     */
    struct Application
    {
        /// The SDL window
        SDL_Window *   SdlWin;
        /// The SDL renderer
        SDL_Renderer * Renderer;
        /// The SDL flags
        uint32_t       SDL_Flags; 

        /// The window title
        char * WinTitle;
        /// The window icon surface (required by SDL2)
        SDL_Surface * WinIcon;

        /// The window size
        struct Vector2D WinSize;
        /// The window position
        struct Vector2D WinPos;
    };

    /// Initializes the application
    void Application__new(struct Application * app, const char * title);

#endif // NIV_DEFS
