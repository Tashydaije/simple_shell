#include "shell.h"

/**
 * prompt - displays a prompt from user
 *
 * return: void
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
* readline - reads input(command) from user
*
* return: command
*/

char *readline(void)
{
	ssize_t read = -1;
	char *command = NULL;
	size_t cmd_len = 0;

	read = getline(&command, &cmd_len, stdin);

	if (read == EOF)
	{
		free(command);
		return (NULL);
	}
	if (command[read - 1] == '\n')
		command[read - 1] = '\0';


	fflush(stdin);

	return (command);

}

/**
 * update_cmd - Updates a command argument
 * @args: Pointer to the argument array
 * @index: index of the token command
 * @arg: value to update argument
 *
 * Return: void
 */

void update_cmd(char **args, int index, char *arg)
{
	if (!args || !(*args) || !arg || index < 0)
		return;
	free(args[index]);
	args[index] = _strdup(arg);
}
