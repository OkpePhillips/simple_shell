#include "simple_shell.h"

/**
*_strlen - Checks the length of the string
*@str: string input
*
* Return: String length
*/

int _strlen(const char *str)
{
	int l = 0;
	int i;

	for (i = 0; str[i] != 0; i++)
	{
		l++;
	}
	return (l);
}

/**
 * _strcpy - makes a copy of a string
 * @source: the string source
 * @dest: the string destination
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
* _strcmp - Compares characters in two strings
*@s1: The first string
*@s2: The second string
*
*Return: number based on comparison
*/

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			break;
		}
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}

/**
 * _strchr - locates a character in a given string
 * @str: the given string
 * @c: the character to be found
 *
 * Return: (Success) a pointer to the first occurence of c
 * ------- (Fail) a null pointer
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		if (*ptr == c)
		{
			return (ptr);
		}
		ptr++;
	}
	return (NULL);
}

/**
 * _strdup - dupicates a given string
 * @str: the given string
 *
 * Return: (Success) a pointer to the duplicated string
 * ------- (Fail) return a null pointer
 */
char *_strdup(char *str)
{
	char *duplicate;

	if (str == NULL)
		return (NULL);
	duplicate = malloc(_strlen(str) + 1);
	if (duplicate == NULL)
		return (NULL);
	_strcpy(duplicate, str);
	return (duplicate);
}
