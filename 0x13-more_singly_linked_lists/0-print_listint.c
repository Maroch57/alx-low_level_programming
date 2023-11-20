#include "lists.h"
#include <stdio.h>

/**
 * print_listint - ensures all elements on listint_t list are printed.
 * @h: head of link list.
 * Return: total number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t size_node = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		size_node++;
	}
	return (size_node);
}
