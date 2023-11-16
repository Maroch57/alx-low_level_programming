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

size_t print_list(const list_t *h);
{
	int count = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n")
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		count++;
		h = h->next;
	}
	return (count);
}
