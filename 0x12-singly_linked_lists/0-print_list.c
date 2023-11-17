#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * print_list - prints everything in a singly linked list.
 *
 * @h: assigned head of list
 * Return: the number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	/* initialize return data type, size_t*/
	size_t bigSize;

	bigSize = 0;
	/*loop around h list*/
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		/*no node to return because the current node was calculated prev.*/

		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
			/*use h->next as the newly incremented value of h, not h++*/
		h = h->next;
		bigSize++;
	}

	return (bigSize);
}
