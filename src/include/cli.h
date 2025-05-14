#ifndef NIV_CLI_H
#define NIV_CLI_H

#include <stdbool.h>
#include <stddef.h>

// CLI command handling functions
void handle_long_flag(char** args);
void handle_short_flag(char** args);
void handle_cmd(char** args);

// Additional CLI utility functions
void print_help(char* program_name);
void print_version(void);

// Command array getters
const char** get_cmds(void);
size_t get_num_cmds(void);
const char** get_cmds_desc(void);

// Forward declarations to ensure compiler knows about these functions
extern void handle_cmd(char** args);

#endif // NIV_CLI_H
