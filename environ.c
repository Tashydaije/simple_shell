#include "shell.h"

/**
 * _getenv - searches for the env variable provided
 * @name: the env variable
 *
 * Return: pointer to env variable
 */

char *_getenv(const char *name)
{
	int i;
	int len;
	char *path = NULL;

	len = _strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], len) == 0)
		{
			path = _strdup(environ[i] + len + 1);
			return (path);
		}
		i++;
	}
	return (NULL);
}
