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
