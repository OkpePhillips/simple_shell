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

/**
 * _getenv - gets the path
 * @pathname: the specified path
 *
 * Return: (Success) a pointer to the value of the env variable
 * ------- (Fail) NULL
 */
char *_getenv(char *pathname)
{
	char **env_cursor, *env_ptr, *name_ptr;

	env_cursor = environ;
	while (*env_cursor)
	{
		env_ptr = *env_cursor;
		name_ptr = pathname;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);
		env_cursor++;
	}
	return (NULL);
}


/**
 * _strcat - concatenates two string in a path form
 * @dest: the string unto which another string will be added
 * @src: the string to be added
 *
 * Return: (Success) pointer to the destination string
 *
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest + strlen(dest);

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}

/**
 * _strncmp - checks if the first n characters of two strings are equal
 * @s1: first string
 * @s2: second string
 * @n: the length of characters
 *
 * Return: 0 if the first n characters of the two strings are equal
 * ------- -1 if str1 is less than str2;
 * ------- 1 if str1 is greater than str2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; ++i)
	{
		if (s1[i] != s2[i])
			return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
		else if (s1[i] == '\0')
			return (0);
	}
	return (0);
}
