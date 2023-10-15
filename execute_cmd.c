#include "shell.h"

/**
 * execute_cmd - executes the command
 * @args: null-terminate array of strings containing cmd and its args
 * @env: a pointer to an array of strings of env variables
 *
 * Return: 1.
 */

int execute_cmd(char **args, char **env)
{
	pid_t child_pid;
	int status;
	char *command = get_location(args[0]);

	if (command == NULL)
	{
		char msg[100];

		snprintf(msg, sizeof(msg), "%s: command not found\n", args[0]);
		write(STDERR_FILENO, msg, strlen(msg));
		return (-1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (execve(command, args, env) == -1)
		{
			perror(command);
			exit(1);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}

	free(command);
	return (1);

}
