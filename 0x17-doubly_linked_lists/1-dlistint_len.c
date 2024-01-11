#include "lists.h"

/**
 *dlistint_len - ensures length of the list is printed.
 *@h: pointer to list in subject.
 *
 *Return: total number of elements.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t length = 0;

	if (!h)
		return (0);

	while (h)
	{
		length++;
		h = h->next;
	}

	return (length);
}
