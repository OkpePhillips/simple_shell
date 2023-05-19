#include "simple_shell.h"

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
 * strtrim - removes first whitespace
 * @str: the input string
 *
 * Return: trimmed input
 */
char *strtrim(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n')
	{
		str++;
	}
	return (str);
}
