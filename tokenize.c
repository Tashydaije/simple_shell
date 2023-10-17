#include "shell.h"

#define DELIMS " \t\r\n"
#define MAX_TOKENS 100

/**
 * _strtok - tokenizes a string
 * @str: the string to tokenize
 * @num_args: counts the number of arguments
 *
 * Return: the pointer to an array of tokenized words
 */

char **_strtok(char *str, int *num_args)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(MAX_TOKENS * sizeof(char *));
	if (tokens == NULL)
	{
		perror("_strtok: failed to allocate memory for tokens");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, DELIMS);
	while (token != NULL)
	{
		if (i >= MAX_TOKENS)
		{
			perror("token limit is 100");
			exit(EXIT_FAILURE);
		}
		if (token[0] == '"' && token[_strlen(token) - 1] == '"')
		{
			token[_strlen(token) - 1] = '\0';
			token++;
		}
		tokens[i] = _strdup(token);

		if (!tokens[i])
		{
			while (i > 0)
				free(tokens[--i]);
			free(tokens);
			return (NULL);
		}
		i++;
		token = strtok(NULL, DELIMS);
	}
	tokens[i] = NULL;
	*num_args = i;

	return (tokens);
}
