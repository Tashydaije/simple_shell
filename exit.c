#include "shell.h"

/**
 * exitShell - Handle the "exit" command, optionally specifying an exit code
 * @arg: Array of words entered in shell, including "exit" and exit code if any
 *
 * Description: This function parses the exit code (if provided) and perfoms
 * the "exit" logic. also deallocates memory associated with the argument array
 */

void exitShell(char **arg)
{
	int exit_code = 0;

	if (arg[1])
	{
		exit_code = _atoi(arg[1]);
		if (exit_code < 0)
		{
			exit_code = 2;
		}
	}

	free_args2(arg);
	printf("[Disconnected...]\n");
	exit(exit_code);
}

/**
 * free_args2 - Deallocates memmory from an array of strings
 * @arg: pointer to an array of strings
 *
 * Description: This function de-allocates memory from the array of strings
 * and sets 'arg' pointer to NULL.
 */

void free_args2(char **arg)
{
	int i;

	if (arg == NULL)
		return;

	i = 0;
	while (arg[i] != NULL)
		free(arg[i++]);

	free(arg);
	*arg = NULL;
}

