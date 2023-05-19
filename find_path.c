#include "simple_shell.h"

/**
 *find_path - gets the full path of the command the user enters
 *@user_input: the input supplied
 *
 *Return: Returns the full path to the command, if success
 * -------- If failed, returns NULL
 */
char *find_path(char *user_input)
{
	char *path;
	char *directory;
	char *command;
	char *result;
	char *trimmedcommand;

	command = strtok(user_input, ";");
	while (command != NULL)
	{
		trimmedcommand = strtrim(command);
		if (access(trimmedcommand, X_OK) == 0)
		{
			result = strdup(trimmedcommand);
			if (result == NULL)
			{
				return (NULL);
			}
			return (result);
		}
		path = getenv("PATH");
		result = malloc(MAX_USER_INPUT_LENGTH);
		if (path == NULL)
			return (NULL);
		directory = strtok(path, ":");
		while (directory != NULL)
		{
			command = strcpy(result, directory);
			command = strcat(command, "/");
			command = strcat(command, trimmedcommand);
			if (access(command, X_OK) == 0)
			{
				return (result);
			}
			directory = strtok(NULL, ":");
			free(result);
			result = malloc (MAX_USER_INPUT_LENGTH);
		}
		free(result);
		command = strtok(NULL, ";");
	}
	return (NULL);
}
