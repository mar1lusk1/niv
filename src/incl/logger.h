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

#ifndef NIV_LOGGER
#define NIV_LOGGER

    #include <stdio.h>

    static const char * ANSI_RED =    "\x1b[31m";
    static const char * ANSI_YELLOW = "\x1b[33m";
    static const char * ANSI_GREEN =  "\x1b[32m";
    static const char * ANSI_RESET =  "\x1b[0m";

    #define LOG_ERROR(...)  { \
        fprintf (stderr, ANSI_RED); \
        fprintf (stderr, __VA_ARGS__); \
        fprintf (stderr, ANSI_RESET); \
        fprintf (stderr, "\n"); \
    }

    #define LOG_INFO(...)   { \
        fprintf (stdout, ANSI_GREEN); \
        fprintf (stdout, __VA_ARGS__); \
        fprintf (stdout, ANSI_RESET); \
        fprintf (stdout, "\n"); \
    }

    #define LOG_WARN(...)   { \
        fprintf (stdout, ANSI_YELLOW); \
        fprintf (stdout, __VA_ARGS__); \
        fprintf (stdout, ANSI_RESET); \
        fprintf (stdout, "\n"); \
    }

    #define LOG_DEBUG(...)  { \
        fprintf (stdout, __VA_ARGS__); \
        fprintf (stdout, "\n"); \
    }

#endif