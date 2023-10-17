#include "shell.h"

/**
 * _strlen - counts the length of a string
 * @str: the string
 *
 * Return: the number of bytes coounted
 */

size_t _strlen(const char *str)
{
	size_t len = 0;

	if (str == NULL)
		return (0);

	while (*str != '\0')
	{
		len++;
		str++;
	}

	return (len);
}

/**
 * *_memcpy - copies a specified number of bytes from one string to another.
 * @dest: destination string to copy memory area to.
 * @src: source sring to copy memory area from
 * @n: The number of bytes to copy
 *
 * Return: A pointer to the destination string
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/**
 * _strcmp - compares two strings in lexical order
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 0 if the strings are equal, otherwise the lexical (alphabetical)
 * difference in the order of the strings.
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			continue;
		}
		break;
	}

	return (*s1 - *s2);
}

/**
 * _strcat - - concatenates two strings.
 * @dest: The destination string.
 * @src: the source string
 *
 * Return: A pointer to the destination string
 */

char *_strcat(char *dest, char *src)
{
	size_t dest_len = _strlen(dest);
	size_t src_len = strlen(src);
	size_t i;

	for (i = 0; i < src_len; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _strdup - duplicaates a string
 * @src: the string to dupicate
 *
 * Return: the duplicated string, otherwise return NULL
 */

char *_strdup(char *src)
{
	size_t len = _strlen(src) + 1;
	char *dest = malloc(sizeof(*dest) * len);

	if (src == NULL)
		return (NULL);

	if (dest)
	{
		_memcpy(dest, src, len);
		return (dest);
	}

	free(dest);
	return (NULL);
}
