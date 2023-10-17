#include "shell.h"

#define CONTINUE_COMMAND 0
#define EXIT_COMMAND 1

/**
 * exitShell - exit built in command that exits the shell
 * @arg: Array of words of the entered shell
 *
 * Return: nothing
 */

void exitShell(char **arg)
{
	char command[100];
	int i = 1;
	int exit_code = 0;
	char exitMessage[] = "exit\n\n[Disconnected...]\n";
<<<<<<< HEAD

	read(STDIN_FILENO, command, sizeof(command));
	command[_strcspn(command, "\n")] = '\0';

=======

	read(STDIN_FILENO, command, sizeof(command));
	command[_strcspn(command, "\n")] = '\0';

>>>>>>> exit with status code
	if (_strcmp(command, "exit") == 0)
	{
		if (arg[i])
		{
			exit_code = _atoi(arg[i]);
			if (exit_code <= -1)
				exit_code = 2;
		}
<<<<<<< HEAD

=======
>>>>>>> exit with status code
		free_args2(arg);
		write(STDOUT_FILENO, exitMessage, sizeof(exitMessage) - 1);
		exit(get_last_exit_status());
	}
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

