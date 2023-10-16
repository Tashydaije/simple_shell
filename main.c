#include "shell.h"

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
	char **args = NULL;

	while (1 && argv[0])
	{
		prompt();
		input = readline();
		args = _strtok(input, " ");

		if (args != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				exitShell(args);
			}

			else if (strcmp(args[0], "env") == 0)
			{
				char *env_string = print_env();

				if (env_string != NULL)
				{
					printf("%s", env_string);
					free(env_string);
				}
			}
			else
			{
				execute_cmd(args, env);
				free_args2(args);
			}
		}
	}

	return (EXIT_SUCCESS);

}
