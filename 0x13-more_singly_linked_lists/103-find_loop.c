#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: points to the first element in the list.
 *
 * Return: address of the node where the loop starts.
 *
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *findp = head;
	listint_t *execptr = head;

	if (!head)
		return (NULL);
	while (findp && execptr && execptr->next)
	{
		execptr = execptr->next->next;
		findp = findp->next;
		if (execptr == findp)
		{
			findp = head;
			while (findp != execptr)
			{
				findp = findp->next;
				execptr = execptr->next;
			}
			return (execptr);
		}
	}
	return (NULL);
}
