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
	ssize_t read;
	char *command = NULL;
	size_t cmd_len = 0;

	read = getline(&command, &cmd_len, stdin);

	if (read == -1)
	{
		if (read == EOF)
		{
			free(command);
			return (NULL);
		}
		perror("getline");
		free(command);
		return (NULL);
	}

	if (command[read - 1] == '\n')
		command[read - 1] = '\0';


	fflush(stdin);

	return (command);

}
