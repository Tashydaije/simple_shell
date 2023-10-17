#include "shell.h"

/**
 * get_path_dir - tokenizes a list of directories into dir_l
 *                liinked list.
 * @head: Pointer to the head node of a dir_l linked list
 * @path: A colon-separated list of directories
 *
 * Return: pointer to initialized linked list
 */

dir_l *get_path_dir(dir_l **head, char *path)
{
	char *token = strtok(path, ":");

	if (*head != NULL)
	{
		fprintf(stderr, "List is not empty...");
		return (NULL);
	}
	while (token != NULL)
	{
		add_node(head, token);
		token = strtok(NULL, ":");
	}
	return (*head);
}

/**
 * isProgPath - checks if path given is the actual path to prog
 * @path: program path given
 *
 * Return: 1 if path is executable, 0 if not or doesn't exist.
 */

int isProgPath(char *path)
{
	if (path && (access(path, X_OK) == 0))
		return (1);
	return (0);
}

/**
 * searchfile - searches for existing file in the dir_l list
 * @head: pointer to the dir_l list
 * @name: name of the file
 *
 * Return: pointer to the file path string,
 *         otherwise NULL if file not found.
 */

char *searchfile(dir_l *head, char *name)
{
	char *file = NULL;
	int file_len = 0, dir_len = 0;
	int name_len = _strlen(name);

	if (head == NULL || name == NULL)
		return (NULL);
	while (head != NULL)
	{
		dir_len = _strlen(head->dir);
		file_len = dir_len + name_len + 2;
		file = malloc(sizeof(*file) * file_len);

		if (!file)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		_memcpy(file, head->dir, dir_len);
		_memcpy(file + dir_len, "/", 1);
		_memcpy(file + dir_len + 1, name, name_len);
		file[file_len - 1] = '\0';

		if (isProgPath(file))
		{
			return (file);
		}
		free(file);
		file = NULL;
		head = head->next;
	}

	return (NULL);
}

/**
 * get_location - looks for a program in the process env
 * @tokens: name of the program (1st token)
 * @command: User command input
 * @argv: NULL termited list of shell's arguments
 *
 * Return: pointer to updated program name(token)
 */

char *get_location(char *command, char **tokens, char *argv[])
{
	char *path = _getenv("PATH");
	char *prog_path = NULL;
	dir_l *head = NULL;

	if (!tokens || !path)
		return (NULL);

	if (execute_builtin(command, tokens, path, argv))
		return (NULL);

	if (isProgPath(tokens[0]))
	{
		free(path);
		return (_strdup(tokens[0]));
	}

	get_path_dir(&head, path);
	prog_path = searchfile(head, tokens[0]);

	if (prog_path == NULL)
	{
		showError(argv[0], tokens[0]);
		free_list(&head);
		free(path);
		return (NULL);
	}
	free_list(&head);
	free(path);
	return (prog_path);
}
