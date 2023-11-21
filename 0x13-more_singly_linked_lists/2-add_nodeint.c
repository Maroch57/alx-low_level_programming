#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - adds a new node at the beginning of listint_t list.
 * @head: it is the head of double pointer
 * @n: int adds into the list.
 *
 * Return: NULL incase it fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *pointer;

	if (head == NULL)
		return (NULL);
	pointer = malloc(sizeof(listint_t));
	if (pointer == NULL)
		return (NULL);
	pointer->n = n;
	pointer->next = *head;
	*head = pointer;
	return (pointer);
}
