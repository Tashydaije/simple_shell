#include "shell.h"

/**
 * free_tokens - frees the memory allocated for tokens
 * @tokens: tokens to be freed
 *
 * Return: nothing
 */

void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/**
 * free_args - De-allocates memory from an array of strings
 * allocated dynamically.
 * @args: the address of a pointer to an array of strings
 *
 * Description: Using a tripple pointer allos us to fully
 * control the args variable and help us de-allocate memory
 * of the array of strings it points to and also reset the args
 *
 * Return: void
 */

void free_args(char ***args)
{
	int i;
	char **current_arg;

	i = 0;
	if (args == NULL || *args == NULL)
		return;
	current_arg = *args;
	while (current_arg[i] != NULL)
		free(current_arg[i++]);
	free(*args);
	*args = NULL;
}

/**
 * cleanup - Free the dynamically allocated memory for the command,
 * arguments, and prog path.
 * @command: commands to be freed
 * @progPath: path to free
 * args: ...
 *
 * Return: nothing
 */

void cleanup(UN_ATTR char *command,
UN_ATTR char **args,
UN_ATTR char *progPath)
{
	if (command)
		free(command);
	if (args)
		free_args(&args);
	if (progPath)
		free(progPath);
}
