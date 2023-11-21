#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - fn frees a listint_t list.
 *
 * @head: head of double pointer list.
 *
 * Return: NULL
 *
 */
void free_listint2(listint_t **head)
{
	listint_t *nxt_node;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		nxt_node = (*head)->next;
		free(*head);
		*head = nxt_node;
	}
}
