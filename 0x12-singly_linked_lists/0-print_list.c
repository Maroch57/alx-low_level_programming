#include "list.h"

/**
 * print_list - prints everything in a singly linked list.
 *
 * @h: assigned head of list
 * Return: the number of nodes in the list.
 */

size_t print_list(const list_t *h);
{
	int g;

	if (h == NULL)
		return (0);
	for (g =1; h->next != NULL; g++)
	{
		if (h->str == NULL)
		{
			printf("[%u] %s\n", h->len, "(nil)");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}
		h = h->next
	}
	printf("[%u] %s\n" h->next, "(nil)");
	return (g);
}
