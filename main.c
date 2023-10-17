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
 * process_cmd - handles processing of commands
 * @command: command from user
 * @argv: NULL terminated list of the prog arguments
 * @env: NULL terminated list of the process' environment variables
 *
 * Return: void
 */

void process_command(char *command,char **argv, char **env)
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
 * main - runs a simple UNIX command line interpreter
 * @argc: Number of arguments passed to the program
 * @argv: An array of pointers to the arguments.
 * @env: NULL terminated list of the process' environment variables
 *
 * Return: 0 if successful, non-zero if not.
 */

int main(UN_ATTR int argc, char **argv, char **env)
{
	last_exit_status = 0;
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

	return (EXIT_SUCCESS);

}
