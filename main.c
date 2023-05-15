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
	}
	return (0);
}
