#include "simple_shell.h"

/**
 * handle_signal - handle the process interrept signal
 * @identifier: the signal identifier
 *
 * Return: void
 */
void handle_signal(int identifier)
{
	if (identifier == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 4);
	}
}

/**
 * _isspace - checks for space characters
 * @c: the input to be checked
 *
 * Return: 1 if the character is a space, or 0 if not
 */
int _isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' ||
		c == '\f' || c == '\v');
}

/**
 * remove_whitespace - removes leading and trailing white spaces from input
 * @user_input: user input to be trimmed
 *
 * Return: the user input without leading and trailing white spaces
 */
/*char *remove_whitespace(char *user_input)
{
	char *end;

	while (isspace((unsigned char)*user_input))
	{
		user_input++;
	}
	if (*user_input == '\0')
	{
		return (user_input);
	}
	end = user_input + strlen(user_input) - 1;
	while (end > user_input && isspace((unsigned char)*end))
	{
		end--;
	}
	*(end + 1) = '\0';
	return (user_input);
}*/
