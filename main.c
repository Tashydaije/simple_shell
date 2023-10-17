#include "shell.h"

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

	if (strcmp(args[0], "exit") == 0)
	{
		exitShell(args);
	}
}

/**
 * main - runs a simple UNIX command line interpreter
 * @argc: Number of arguments passed to the program
 * @argv: An array of pointers to the arguments.
 * @env: NULL terminated list of the process' environment variables
 *
 * Return: 0 if successful, non-zero if not.
 */

int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	char *input;

	while (1 && argv[0])
	{
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
