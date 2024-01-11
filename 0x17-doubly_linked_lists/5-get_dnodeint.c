#include "lists.h"

/**
 * get_dnodeint_at_index - it gets the node.
 * @head: a pointer to the list in subject.
 * @index: index of the node to be returned.
 *
 * Return: address of the node, if it doesn't exist, NULL.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head && i < index)
	{
		head = head->next;
		i++;
	}

	return (head ? head : NULL);
}
