#include "simple_shell.h"
/**
 * execute_command - calls the appropriate exec function
 * @user_input: the input supplied
 *
 * Return: Nothing.
 */

void execute_command(char *user_input)
{
	char input_copy[MAX_USER_INPUT_LENGTH];
	char *space_pos;
	char *command;

	strcpy(input_copy, user_input);
	command = strtok(input_copy, ";");
	while (command != NULL)
	{
		if (_strlen(command) > 0)
		{
			space_pos = _strchr(command, ' ');
			if (space_pos != NULL)
			{
				execute_command_with_args(command);
			}
			else
			{
				execute_command_without_args(command);
			}
		}
		command = strtok(NULL, ";");
	}
}

/**
 *execute_command_with_args - executes inputs without arguments
 *@command: the input supplied
 *
 * Return: Nothing.
 */

void execute_command_with_args(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		char *args[MAX_ARGUMENTS + 1];
		char *full_path;
		char arg_str[MAX_USER_INPUT_LENGTH];
		int num_args = 0;
		char *token;

		strtok(command, " \n");
		full_path = find_path(command);
		if (full_path == NULL)
		{
			write(STDERR_FILENO, "./hsh: 1: ", 10);
			write(STDERR_FILENO, command, _strlen(command));
			write(STDERR_FILENO, ": not found\n", 13);
			exit(EXIT_FAILURE);
		}
		args[0] = full_path;
		_strcpy(arg_str, command + _strlen(command) + 1);
		token = strtok(arg_str, " \n");
		while (token != NULL && num_args < MAX_ARGUMENTS)
		{
			args[++num_args] = token;
			token = strtok(NULL, " \n");
		}
		args[num_args + 1] = NULL;
		execve(args[0], args, environ);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}

/**
 *execute_command_without_args - executes inputs that have no arguments
 *@command: the input supplied
 *
 * Return: Nothing.
 */

void execute_command_without_args(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[MAX_ARGUMENTS + 1];
		char *full_path;

		full_path = find_path(command);
		if (full_path == NULL)
		{
			write(STDERR_FILENO, "./hsh: 1: ", 10);
			write(STDERR_FILENO, command, _strlen(command));
			write(STDERR_FILENO, ": not found\n", 13);
			exit(EXIT_FAILURE);
		}
		args[0] = full_path;
		args[1] = NULL;
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
