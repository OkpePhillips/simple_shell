#include "simple_shell.h"

/**
 *get_input - function to read user input on the command line
 *@user_input: Command entered by the user
 *
 * Return: Nothing.
 */

void get_input(char *user_input)
{
	ssize_t input_read;
	int i;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 3);
	}
	i = 0;

	while (1)
	{
		char c;

		input_read = read(STDIN_FILENO, &c, 1);
		if (input_read == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if (input_read == 0)
		{
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			user_input[i] = '\0';
			break;
		}
		else
		{
			user_input[i] = c;
			i++;
		}
	}
}
