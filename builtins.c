#include "simple_shell.h"

/**
*builtin_exit - exits the shell program
*
* Return: Nothing
*/
int builtin_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
*builtin_env - prints the environment variables
*
* Return: 0 on success
*
*/

int builtin_env(void)
{
	char **env_var;

	for (env_var = environ; *env_var != NULL; env_var++)
	{
		write(STDOUT_FILENO, *env_var, strlen(*env_var));
		write(STDOUT_FILENO, "\n", 1);
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}

/**
 * handle_builtin - handles the builtin commands
 * @user_input: the command inputted
 *
 * Return: (Success) Pointer to the corresponding builtin function
 * ------- (Failure) -1
*/
int handle_builtin(char *user_input)
{
	int i;
	const char * const builtins[] = {"exit", "env", NULL};

	int (* const builtin_funcs[])(void) = {&builtin_exit, &builtin_env, NULL};

	for (i = 0; builtins[i] != NULL; ++i)
	{
		if (strcmp(user_input, builtins[i]) == 0)
		{
			return ((*builtin_funcs[i])());
		}
	}
	return (-1);
}

/**
*is_built_in_command - checks if the user_input is a built_in command
*@user_input: the command entered by user
* Return: 1 if input is builtin command, 0 if not
*/

int is_built_in_command(char *user_input)
{
	int num_built_in_commands;
	int i;
	const char * const builtins[3] = {"exit", "env", NULL};

	num_built_in_commands = 3;
	for (i = 0; i < num_built_in_commands - 1; i++)
	{
		if (strcmp(user_input, builtins[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}
