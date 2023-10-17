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
		exit_code = atoi(args[1]);
		if (exit_code < 0 && args[1][0] && args[1][0] != '0')
		{
			exit_code = 2;
			write(STDOUT_FILENO, argv[0], strlen(argv[0]));
			write(STDOUT_FILENO, ": 1: ", 5);
			write(STDOUT_FILENO, args[0], strlen(args[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDERR_FILENO, "Illegal number: ", 16);
			write(STDERR_FILENO, args[1], strlen(args[1]));
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
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

