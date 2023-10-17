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

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}

	return (1);
}
