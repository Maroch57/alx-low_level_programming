#include "lists.h"

/**
 * listint_len - function prints total elements in the list.
 * @h: head pointer.
 *
 * Return: total number of elements in the listint_t list.
 *
 */
size_t listint_len(const listint_t *h)
{
	size_t tot_numb = 0;

	while (h != NULL)
	{
		h = h->next;
		tot_numb++;
	}
	return (tot_numb);
}

