#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: pointer to first node in the list.
 * @idx: index of the node.
 * @n: new node data.
 *
 * Return: the address of the new node.
 *
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int k;
	listint_t *tempp, *new_p;

	if (head == NULL)
		return (NULL);
	if (idx != 0)
	{
		tempp = *head;
		for (k = 0; k < idx - 1 && tempp != NULL; k++)
		{
			tempp = tempp->next;
		}
		if (tempp == NULL)
			return (NULL);
	}
	new_p = malloc(sizeof(listint_t));
	if (new_p == NULL)
		return (NULL);
	new_p->n = n;
	if (idx == 0)
	{
		new_p->next = *head;
		*head = new_p;
		return (new_p);
	}
	new_p->next = tempp->next;
	tempp->next = new_p;
	return (new_p);
}
