#include "simple_shell.h"

/**
 * builtin_cd - calls the appropriate cd function
 *@user_input: the input received
 *
 * Return: 0 on success; -1 if failed
 */
int builtin_cd(char *user_input)
{
	char *path;
	int result;

	path = strchr(user_input, ' ');
	if (path == NULL)
	{
		result = change_directory_to_home();
		set_old_working_directory();
	}
	else if (_strcmp(path + 1, "-") == 0)
	{
		result = change_directory_to_previous();
		set_old_working_directory();
	}
	else
	{
		++path;
		result = change_directory_to_path(path);
		set_old_working_directory();
	}
	return (result);
}

/**
 * set_old_working_directory - sets the oldpwd
 *
 * Return: Nothing
 */
void set_old_working_directory(void)
{
	char *pwd;

	pwd = _getenv("PWD");
	if (pwd != NULL)
	{
		setenv("OLDPWD", pwd, 1);
	}
}

/**
 * change_directory_to_path - cd to a specified path
 *@path: the specified directory
 * Return: 0 on success, -1 if failed
 */
int change_directory_to_path(char *path)
{
	if (chdir(path) != 0)
	{
		perror("chdir");
		return (-1);
	}
	return (0);
}

/**
 * change_directory_to_previous - cd to the previous directory
 *
 * Return: 0 on success, -1 if failed.
 */
int change_directory_to_previous(void)
{
	char *oldpwd;

	oldpwd = _getenv("OLDPWD");
	if (oldpwd == NULL)
	{
		return (-1);
	}
	if (chdir(oldpwd) != 0)
	{
		perror("chdir");
		return (-1);
	}
	return (0);
}

/**
 * change_directory_to_home - cd to home
 *
 * Return: 0 on success, -1 if failed.
 */
int change_directory_to_home(void)
{
	if (chdir(_getenv("HOME")) != 0)
	{
		perror("chdir");
		return (-1);
	}
	return (0);
}
