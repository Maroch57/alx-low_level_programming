#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: head of the double pointer.
 * @n: adds to the list.
 *
 * Return: NULL incase it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *ptr_new;
	listint_t *ptr_tmp;

	if (head == NULL)
		return (NULL);
	ptr_new = malloc(sizeof(listint_t));
	if (ptr_new == NULL)
		return (NULL);
	ptr_new->n = n;
	ptr_new->next = NULL;
	if (*head == NULL)
	{
		*head = ptr_new;
		return (ptr_new);
	}
	ptr_tmp = *head;
	while (ptr_tmp->next != NULL)
	{
		ptr_tmp = ptr_tmp->next;
	}

	ptr_tmp = ptr_tmp->next = ptr_new;
		return (ptr_new);
}
