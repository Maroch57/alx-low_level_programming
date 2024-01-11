#include "lists.h"

/**
 *free_dlistint - a double linked list is freed.
 *@head: a ptr to head.
 *
 *Return: NULL.
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *new;

	while (head)
	{
		new = head->next;
		free(head);
		head = new;
	}


}
