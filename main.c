#include "simple_shell.h"

/**
*main - the entry point to the simple shell program
*
* Return: Always 0 (Success)
*/

int main(void)
{
	signal(SIGINT, handle_signal);
	while (1)
	{
		char user_input[MAX_USER_INPUT_LENGTH];

		get_input(user_input);
		if (is_built_in_command(user_input) == 1)
			handle_builtin(user_input);
		else
			printf("The input %s is not a builtin \n", user_input);
	}
	return (0);
}
