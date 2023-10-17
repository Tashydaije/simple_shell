#include "shell.h"

/**
 * process_cmd - handles processing of commands
 * @command: command from user
 * @argv: NULL terminated list of the prog arguments
 * @env: NULL terminated list of the process' environment variables
 *
 * Return: void
 */

void process_command(char *command, char **env)
{
	char **args = NULL;
	char *progPath = NULL;
	char *env_string = print_env();

	if (!command || command[0] == '\0')
	{
		free(command);
		return;
	}

	args = _strtok(command, " ");
	if (args != NULL)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			exitShell(args);
		}
		else if (strcmp(args[0], "env") == 0)
		{
			if (env_string != NULL)
			{
				printf("%s", env_string);
				free(env_string);
			}
		}
		else
		{
			progPath = get_location(args);

			if (progPath == NULL)
			{
				free_args2(args);
				return;
			}
			update_cmd(args, 0, progPath);
			execute_cmd(args, env);
		}
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
		process_command(input, env);
	}

	return (EXIT_SUCCESS);

}
