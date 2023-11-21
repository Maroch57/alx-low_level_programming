#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - frees a listint_t list.
 * @head: head of the list.
 *
 * Return: NULL if unsuccessful.
 *
 */
void free_listint(listint_t *head)
{
	listint_t *nxt;

	while (head != NULL)
	{
		nxt = head->next;
		free(head);
			head = nxt;
	}
}
