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
