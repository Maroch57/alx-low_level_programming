#include "lists.h"

/**
 * insert_dnodeint_at_index - it ensures a new node is inserted.
 * @h: it is a pointer to a pointer.
 * @idx: index of the list where a new node will be added in the list.
 * @n:the element to be added in the list.
 *
 * Return: address of new node, else NULL.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *tmp = *h;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (idx == 0)
	{
		if (*h != NULL)
			(*h)->prev = new_node;
		new_node->next = *h;
		*h = new_node;
	}

	while (i < idx - 1)
	{
		if (tmp == NULL)
			return (NULL);
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL)
		return (NULL);
	new_node->next = tmp->next;
	new_node->prev = tmp;
	if (tmp->next == new_node)
		tmp->next->prev = new_node;
	tmp->next = new_node;
	return (new_node);
}


