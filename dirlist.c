#include "shell.h"

/**
 * add_node - adds new node at the end of a dir_l list
 * @head: pointer to head node's addr
 * @dir: string to add to the node list
 *
 * Return: pointer to created node
 */

dir_l *add_node(dir_l **head, char *dir)
{
	dir_l *new_node =  malloc(sizeof(dir_l));
	dir_l *last;

	if (dir == NULL)
	{
		fprintf(stderr, "Cannot create an empty node\n");
		return (NULL);
	}

	if (!new_node)
		return (NULL);

	new_node->dir = dir;
	new_node->next = NULL;

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
	{
		*head = new_node;
	}
	return (new_node);
}

/**
 * free_list - frees the memory
 * @head: pointer to head node address
 *
 * Return: void
 */

void free_list(dir_l *head)
{
	dir_l *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
