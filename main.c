#include "shell.h"

static int last_exit_status;

/**
 * set_last_exit_status - Function to set the last exit status
 * @status: status
 *
 * Return: ....
 */

void set_last_exit_status(int status)
{
	last_exit_status = WIFEXITED(status) ? WEXITSTATUS(status) : 1;
}

/**
 * get_last_exit_status - Function to get the last exit status
 *
 * Return: last exit status
 */

int get_last_exit_status(void)
{
	return (last_exit_status);
}

/**
 * process_command - handles processing of commands
 * @command: command from user
 * @argv: NULL terminated list of the prog arguments
 * @env: NULL terminated list of the process' environment variables
 *
 * Return: void
 */

void process_command(char *command, char **argv, char **env)
{
	int num_args = 0;
	char **args = NULL;
	char *progPath = NULL;

	if (!command || command[0] == '\0')
	{
		free(command);
		return;
	}

	args = _strtok(command, &num_args);
	progPath = get_location(command, args, argv);

	if (progPath == NULL)
	{
		free(command);
		free_tokens(args);
		return;
	}
	update_cmd(args, 0, progPath);
	execute_cmd(args, env);

	if (_strcmp(args[0], "exit") == 0)
	{
		cleanup(command, args, progPath);
		exitShell(args);
	}
	cleanup(command, args, progPath);
}

/**
 * shell_lp - handles the main loop in the entry point
 * @argv: NULL terminated list of the application arguments
 * @env: NULL terminated list of the process' environment variables
 *
 * Return: void
 */

void shell_lp(char *argv[], char **env)
{
	char *input;

	while (1 && argv[0])
	{
		signal(SIGINT, handle_sigint);
		prompt();
		input = readline();

		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		process_command(input, argv, env);
	}
}

/**
 * main - Entry of shell application
 * @argc: Number of arguments passed to the program
 * @argv: NULL terminated list of the application arguments
 * @env: NULL terminated list of the process' environment variables
 *
 * Return: 0 if successful, non-zero if error
 */

int main(UN_ATTR int argc, char **argv, char **env)
{
	char *input;

	last_exit_status = 0;

	if (!isatty(STDIN_FILENO))
	{
		input = readline();

		if (input && _strcmp(input, "exit") != 0)
		{
			process_command(input, argv, env);
		}
	}
	else
		shell_lp(argv, env);

	return (EXIT_SUCCESS);
}
