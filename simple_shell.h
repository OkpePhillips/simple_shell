#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

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
void execute_command(char *user_input);
void execute_command_with_args(char *command);
void execute_command_without_args(char *command);
void print_error(const char *program_name, const char *user_input,
			const char *error_message);
char *strtrim(char *str);
char *_getenv(char *pathname);
int _strlen(const char *str);
char *_strcpy(char *dest, char *source);
int _strcmp(const char *s1, const char *s2);
char *_strchr(char *str, char c);
char *_strdup(char *str);
char *_strcat(char *dest, const char *src);
int builtin_cd(char *user_input);
void set_old_working_directory(void);
int change_directory_to_path(char *path);
int change_directory_to_previous(void);
int change_directory_to_home(void);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif
