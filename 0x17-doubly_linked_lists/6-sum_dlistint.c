#include "lists.h"

/**
 * sum_dlistint - it ensures the sum of all the data in a linked list is returned.
 * @head: pointer to the head node of the list.
 *
 * Return: 0 incase the list is empty.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
