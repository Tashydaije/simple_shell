#include "shell.h"

/**
 * print_env - prints the current environment variables and returns
 * them as a string
 *
 * Return: A string containing the environment variables.
 */

char *print_env(void)
{
	char *env_string = NULL;
	int i;
	int env_len = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_len += strlen(environ[i]) + 1;
	}

	env_string = (char *)malloc(env_len + 1);
	if (env_string ==  NULL)
	{
		perror("malloc");
		return (NULL);
	}

	env_string[0] = '\0';
	for (i = 0; environ[i] != NULL; i++)
	{
		strcat(env_string, environ[i]);
		strcat(env_string, "\n");
	}

	return (env_string);

}
