#include "shell.h"

/**
* handle_exit - handles the exit built-in
* @args: the command and its arguments
* @argv: NULL terminated list of the shell's arguments
*
* Return: void
*/

void handle_exit(char **args, char **argv)
{
	int exit_code = 0;

	if (args[1])
	{
		exit_code = _atoi(args[1]);
		if (exit_code < 0 && args[1][0] && args[1][0] != '0')
		{
			exit_code = 2;
			write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
			write(STDOUT_FILENO, ": 1: ", 5);
			write(STDOUT_FILENO, args[0], _strlen(args[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDERR_FILENO, "Illegal number: ", 16);
			write(STDERR_FILENO, args[1], _strlen(args[1]));
			write(STDOUT_FILENO, "\n", 1);
		}
		else if (exit_code > 255)
			exit_code = 232;
	}
	else
	{
		exit_code = 2;
	}
	free_tokens(args);
	exit(exit_code);
}

/**
 * handle_env - Prints the process' environment variables
 *
 * Return: void
 */

void handle_env(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * change_directory - changes current working dir to specified dir
 * @dir: Apointer to a string representing the path of the dir to change to
 *
 * Return: 0 on success, -1 on failure
 */

int change_directory(char *dir)
{
	int chdir_ret = 0;
	char *oldpwd = NULL;
	char *pwd = NULL;

	oldpwd = getcwd(NULL, 0);
	chdir_ret = chdir(dir);
	if (chdir_ret == -1)
	{
		write(STDERR_FILENO, "cd: ", 4);
		write(STDERR_FILENO, dir, strlen(dir));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		free(dir);
		free(oldpwd);
		return (-1);
	}

	else
	{
		setenv("OLDPWD", oldpwd, 1);
		pwd = getcwd(NULL, 0);
		setenv("PWD", pwd, 1);
		free(oldpwd);
		free(pwd);
		free(dir);
	}

	return (0);
}

/**
 * handle_cd_minus - handles the built-in command cd- which chnges
 * the current working directory to the previous directory
 *
 * Return: ....
 */

int handle_cd_minus(void)
{
	char *dir = _getenv("OLDPWD");

	if (!dir)
	{
		write(STDERR_FILENO, "cd: OLDPWD enviroment variable not set\n", 40);
		return (-1);
	}

	write(STDOUT_FILENO, dir, _strlen(dir));
	write(STDOUT_FILENO, "\n", 1);

	return (change_directory(dir));
}

/**
 * handle_cd - handle the change directory built-in
 * @args: the command and its arguments
 *
 * Return: 0 success, -1 on failure
 */

int handle_cd(char **args)
{
	char *dir, buffer[1024];
	char *s;

	s = getcwd(buffer, 1024);

	if (!s)
	{
		write(STDERR_FILENO, "cd: Failed to get current working directory\n", 45);
		return (-1);
	}

	if (!args[1])
	{
		dir = _getenv("HOME");

		if (!dir)
		{
			write(STDERR_FILENO, "cd: HOME environment variable not set\n", 38);
			return (-1);
		}

		return (change_directory(dir));
	}

	else if (_strcmp(args[1], "-") == 0)
	{
		return (handle_cd_minus());
	}

	else
	{
		return (change_directory(_strdup(args[1])));
	}
}
