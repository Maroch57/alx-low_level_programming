#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at index of the list.
 * @head: points to first node in the list.
 * @index: index of node.
 *
 * Return: a ptr to the node index.
 *
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int p;
	listint_t *del_int, *neext;

	if  (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		neext = (*head)->next;
		free(*head);
		*head = del_int;
		return (1);
	}
	del_int = *head;
	for (p = 0; p < index - 1; p++)
	{
		if (del_int->next == NULL)
			return (-1);
		del_int = del_int->next;
	}
	neext = del_int->next;
	del_int->next = neext->next;
	free(neext);
	return (1);
}
