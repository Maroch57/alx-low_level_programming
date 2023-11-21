#include "lists.h"
#include <stdlib.h>

/**
 * sum_listint - returns sum of all data (n) of a listint_t linked list.
 * @head: pointer to first node in a list.
 *
 * Return: sum of data in the list.
 *
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}

