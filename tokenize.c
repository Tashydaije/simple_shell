#include "shell.h"

int token_len(char *str, char *delim);
int tokens_count(char *str, char *delim);

/**
 * token_len - finds lenght of 1st token in a string
 *             before 1st occurence of the delimiter.
 * @str: the string to be searched
 * @delim: the delimiter character
 *
 * Return: length of the token
 */

int token_len(char *str, char *delim)
{
	int i = 0;
	int len = 0;

	while (*(str + i) && *(str + i) != *delim)
	{
		len++;
		i++;
	}

	return (len);
}

/**
 * tokens_count - counts the number of tokens in a string
 * @str: the string to be searched
 * @delim: the delimiter character
 *
 * Return: No. of tokens(words) in the string
 */

int tokens_count(char *str, char *delim)
{
	int i;
	int tokens = 0;
	int len = 0;

	for (i = 0; *(str + i); i++)
		len++;

	for (i = 0; i < len; i++)
	{
		if (*(str + i) != *delim)
		{
			tokens++;
			i += token_len(str + i, delim);
		}
	}

	return (tokens);
}

/**
 * _strtok - tokenizes a string
 * @str: the string to tokenize
 * @delim: the delimiter
 *
 * Return: the pointer to an array of tokenized words
 */

char **_strtok(char *str, char *delim)
{
	char **ptr;
	int tokens, t, characters, c;
	int i = 0;

	tokens = tokens_count(str, delim);
	if (tokens == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * tokens + 2);
	if (!ptr)
		return (NULL);

	for (t = 0; t < tokens; t++)
	{
		while (str[i] == *delim)
			i++;

		characters = token_len(str + i, delim);

		ptr[t] = malloc(sizeof(char) * (characters + 1));
		if (!ptr[t])
		{
			for (i -= 1; i >= 0; i++)
				free(ptr[i]);
			free(ptr);
			return (NULL);
		}

		for (c = 0; c < characters; c++)
		{
			ptr[t][c] = str[i];
			i++;
		}

		ptr[t][c] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
