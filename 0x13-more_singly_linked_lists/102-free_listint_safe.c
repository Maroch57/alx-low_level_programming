#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @h: pointer to first node in a list.
 *
 * Return: no. of elements in the linked list that is freed.
 *
 */
size_t free_listint_safe(listint_t **h)
{
	size_t lngth = 0;
	int subt;
	listint_t *n_ptr;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		subt = *h - (*h)->next;
		if (subt > 0)
		{
			n_ptr = (*h)->next;
			free(*h);
			*h = n_ptr;
			lngth++;
		}
		else
		{
			free(*h);
			*h = NULL;
			lngth++;
			break;
		}
	}
	*h = NULL;
	return (lngth);
}
