#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer of first node in the linked list.
 *
 * @index: node index.
 * Return: nth node of list.
 *
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int t;

	if (head == NULL)
		return (NULL);
	for (t = 0; t < index; t++)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}
	return (head);
}

