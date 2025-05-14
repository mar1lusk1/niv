#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/defs.h"
#include "include/cli.h"

#define  FORMAT_COLOR_RED     "\x1b[31m"
#define  FORMAT_COLOR_GRAY    "\x1b[38;5;246m"
#define  FORMAT_COLOR_GREEN   "\x1b[32m"
#define  FORMAT_COLOR_BLUE    "\x1b[34m"
#define  FORMAT_COLOR_MAGENTA "\x1b[35m"
#define  FORMAT_COLOR_CYAN    "\x1b[36m"
#define  FORMAT_COLOR_YELLOW  "\x1b[33m"
#define  FORMAT_COLOR_RESET   "\x1b[0m"

static const char* CMDS[] = {"new", "run", "help", "version"};
#define NUM_CMDS (sizeof(CMDS) / sizeof(CMDS[0]))

static const char* CMDS_DESC[] = {"Create a new project", "Run a project", "Show help", "Show version"};

// Ensure the arrays are defined for the entire translation unit
const char** get_cmds(void) { return CMDS; }
size_t get_num_cmds(void) { return NUM_CMDS; }
const char** get_cmds_desc(void) { return CMDS_DESC; }

void print_help(char* program_name)
{
    const char** cmds = get_cmds();
    const char** cmds_desc = get_cmds_desc();
    size_t num_cmds = get_num_cmds();

    fprintf(stderr, FORMAT_COLOR_RED "Usage: " FORMAT_COLOR_RESET FORMAT_COLOR_GRAY "%s" FORMAT_COLOR_RESET " [<command> | <flag>]\n\n", program_name);
    
    fprintf(stderr, FORMAT_COLOR_GREEN "[?] %s: " FORMAT_COLOR_RESET "Available commands:\n\n", "Help");
        
    for (size_t i = 0; i < num_cmds; i++) {
        fprintf(stderr, FORMAT_COLOR_GRAY "-%s %s%s -- %s%s\n",
                FORMAT_COLOR_RESET, cmds[i], FORMAT_COLOR_GRAY,
                FORMAT_COLOR_RESET, cmds_desc[i]);
    }

    fprintf(stderr, "\n");
}

void print_version(void)
{
    printf(FORMAT_COLOR_CYAN "Version:" FORMAT_COLOR_RESET " %s\n"
           FORMAT_COLOR_GREEN "%s" FORMAT_COLOR_RESET "\n", NIV_VERSION, NIV_COPYRIGHT);
}

void handle_long_flag(char** args)
{
    if (strcmp(args[1], "--new") == 0)
    {
        /* TODO: Create new project */
        printf("Creating new project (long flag)...\n");
    }
    else if (strcmp(args[1], "--run") == 0)
    {
        /* TODO: Run project */
        printf("Running project (long flag)...\n");
    }
    else if (strcmp(args[1], "--help") == 0)
    {
        /* Show help */
        printf(FORMAT_COLOR_CYAN "Niv Game Engine" FORMAT_COLOR_RESET " v%s\n\n", NIV_VERSION);
        printf(FORMAT_COLOR_GREEN "Usage:" FORMAT_COLOR_RESET " %s [command/flag]\n\n", args[0]);
        printf(FORMAT_COLOR_MAGENTA "Commands:" FORMAT_COLOR_RESET "\n");
        for (size_t i = 0; i < NUM_CMDS; i++) {
            printf(FORMAT_COLOR_BLUE "  %s" FORMAT_COLOR_RESET " -- %s\n", CMDS[i], CMDS_DESC[i]);
        }
    }
    else if (strcmp(args[1], "--version") == 0)
    {
        /* Show version */
        print_version();
    }
}

void handle_short_flag(char** args)
{
    if (strcmp(args[1], "-n") == 0)
    {
        /* TODO: Create new project */
        printf("Creating new project (short flag)...\n");
    }
    else if (strcmp(args[1], "-r") == 0)
    {
        /* TODO: Run project */
        printf("Running project (short flag)...\n");
    }
    else if (strcmp(args[1], "-h") == 0)
    {
        /* Show help */
        printf(FORMAT_COLOR_CYAN "Niv Game Engine" FORMAT_COLOR_RESET " v%s\n\n", NIV_VERSION);
        printf(FORMAT_COLOR_GREEN "Usage:" FORMAT_COLOR_RESET " %s [command/flag]\n\n", args[0]);
        printf(FORMAT_COLOR_MAGENTA "Commands:" FORMAT_COLOR_RESET "\n");
        for (size_t i = 0; i < NUM_CMDS; i++) {
            printf(FORMAT_COLOR_BLUE "  %s" FORMAT_COLOR_RESET " -- %s\n", CMDS[i], CMDS_DESC[i]);
        }
    }
    else if (strcmp(args[1], "-v") == 0)
    {
        /* Show version */
        print_version();
    }
}

void handle_cmd(char** args)
{
    if (strlen(args[1]) > 2 && args[1][0] == '-' && args[1][1] == '-')
    {
        handle_long_flag(args);
    }
    else if (strlen(args[1]) == 2 && args[1][0] == '-')
    {
        handle_short_flag(args);
    }
    else 
    {
        // Check for full command names
        if (strcmp(args[1], "new") == 0 || strcmp(args[1], "-n") == 0 || strcmp(args[1], "--new") == 0)
        {
            /* TODO: Create new project */
            printf("Creating new project...\n");
        }
        else if (strcmp(args[1], "run") == 0 || strcmp(args[1], "-r") == 0 || strcmp(args[1], "--run") == 0)
        {
            /* TODO: Run project */
            printf("Running project...\n");
        }
        else if (strcmp(args[1], "help") == 0 || strcmp(args[1], "-h") == 0 || strcmp(args[1], "--help") == 0)
        {
            /* Show help */
            printf(FORMAT_COLOR_CYAN "Niv Game Engine" FORMAT_COLOR_RESET " v%s\n\n", NIV_VERSION);
            printf(FORMAT_COLOR_GREEN "Usage:" FORMAT_COLOR_RESET " %s [command/flag]\n\n", args[0]);
            const char** cmds = get_cmds();
            const char** cmds_desc = get_cmds_desc();
            size_t num_cmds = get_num_cmds();

            printf(FORMAT_COLOR_MAGENTA "Commands:" FORMAT_COLOR_RESET "\n");
            for (size_t i = 0; i < num_cmds; i++) {
                printf(FORMAT_COLOR_BLUE "  %s" FORMAT_COLOR_RESET " -- %s\n", cmds[i], cmds_desc[i]);
            }
        }
        else if (strcmp(args[1], "version") == 0 || strcmp(args[1], "-v") == 0 || strcmp(args[1], "--version") == 0)
        {
            /* Show version */
            printf(FORMAT_COLOR_CYAN "Version:" FORMAT_COLOR_RESET " %s\n" 
                   FORMAT_COLOR_GREEN "%s" FORMAT_COLOR_RESET "\n", NIV_VERSION, NIV_COPYRIGHT);
        }
        else
        {
            fprintf(stderr, FORMAT_COLOR_RED "Error: Unknown command or flag '%s'\n" FORMAT_COLOR_RESET, args[1]);
            exit(EXIT_FAILURE);
        }
    }
}
