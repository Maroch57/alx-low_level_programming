#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - function that deletes the head node of a listint_t list.
 * and returns the head node’s data (n).
 *
 * @head: head of a double pointer list.
 *
 * Return: void.
 */
int pop_listint(listint_t **head)
{
	listint_t *begin;
		int n;

	if (head == NULL || *head == NULL)
		return (0);
	begin = *head;
	*head = begin->next;
	n = begin->n;
	free(begin);
	return (n);
}
