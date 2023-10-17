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
	dir_l *new_node = NULL;

	if (dir == NULL)
	{
		fprintf(stderr, "Cannot create an empty node\n");
		return (NULL);
	}
	node = malloc(sizeof(dir_l));
	if (new_node == NULL)
	{
		perror("malloc");
		return (NULL):
	}
	new_node->dir = _strdup(dir);
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
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

void free_list(dir_l **head)
{
	dir_l *curr_ptr = NULL;
	dir_l *next_ptr = NULL;

	if (!head || !(*head))
		return;

	curr_ptr = *head;
	next_ptr = (*head)->next;
	while (next_ptr != NULL)
	{
		free(curr_ptr->dir);
		free(curr_ptr);
		curr_ptr = next_ptr;
		next_ptr = next_ptr->next;
	}
	free(curr_ptr->dir);
	free(curr_ptr);
	*head = NULL;
}
