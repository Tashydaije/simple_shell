#include "shell.h"

/**
 * execute_extern_cmd - executes the command
 * @args: null-terminate array of strings containing cmd and its args
 * @env: a pointer to an array of strings of env variables
 *
 * Return: 1.
 */

int execute_extern_cmd(char **args, char **env)
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
		set_last_exit_status(status);
	}

	return (-1);
}

/**
 * execute_builtin - searches if the given command is built-in
 * @command: command given by user
 * @args: null-terminate array of strings containing command and its arguments
 * @path: pointer to the path of the environment
 * @argv: NULL terminated list of the shell's arguments
 *
 * Return: 1 success, 0 otherwise
 */

int execute_builtin(char *command,
char **args, char *path, char **argv)
{
	char *cmd = args[0];

	if (cmd == NULL)
		return (0);
	if (_strcmp(cmd, "exit") == 0)
	{
		free(path);
		free(command);
		handle_exit(args, argv);
		return (1);
	}
	if (_strcmp(cmd, "env") == 0)
	{
		free(path);
		handle_env();
		return (1);
	}
	if (_strcmp(cmd, "cd") == 0)
	{
		free(path);
		handle_cd(args);
		return (1);
	}

	return (0);
}

/**
 * execute_cmd - execute command
 * @args: null-terminate array of strings containing command and its arguments
 * @env: a pointer to an array of strings of environment variables
 *
 * Return: 1 success, O otherwise
 */

int execute_cmd(char **args, char **env)
{
	if (execute_extern_cmd(args, env))
		return (1);
	return (0);
}
