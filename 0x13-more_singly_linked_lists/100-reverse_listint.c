#include "lists.h"
#include <stdlib.h>

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: pointer to first element in alist.
 *
 * Return: ptr to first node of reversed list.
 *
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *list_prv, *list_nxt;

	if (head == NULL || *head == NULL)
		return (NULL);
	if ((*head)->next == NULL)
		return (*head);
	list_prv = NULL;
	while (*head != NULL)
	{
		list_nxt = (*head)->next;
		(*head)->next = list_prv;
		list_prv = *head;
		*head = list_nxt;
	}
	*head = list_prv;
	return (*head);
}
