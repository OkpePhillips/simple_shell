#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/* defining macros */
#define MAX_USER_INPUT_LENGTH 1024
#define MAX_ARGUMENTS 10
#define MAX_ERROR_LENGTH 256


/* global environment variable */
extern char **environ;

/* functions declaration */

void get_input(char *user_input);
void handle_signal(int identifier);
int _isspace(int c);
char *find_path(char *user_input);
int is_built_in_command(char *user_input);
int builtin_env(void);
int builtin_exit(void);
int handle_builtin(char *user_input);

#endif
