#include "shell.h"

/**
 * main - runs a simple UNIX command line interpreter
 * @argc: Number of arguments passed to the program
 * @argv: An array of pointers to the arguments.
 * @env: NULL terminated list of the process' environment variables
 *
 * Return: 0 if successful, non-zero if not.
 */

int main( __attribute__((unused)) int argc, char **argv, char **env)
{
	char *input;
	char **args = NULL;

	while (1 && argv[0])
	{
		prompt();
		input = readline();
		args = _strtok(input, " ");
		execute_cmd(args, env);
	}

	return (EXIT_SUCCESS);

}
