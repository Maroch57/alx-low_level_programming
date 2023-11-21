#include "lists.h"

/**
 *  _r - reallocates memory.
 * @list: the old list to be added.
 * @size: size of new list - it is always one more than the old list.
 * @new: new node to be added in the list.
 *
 * Return: a ptr to new list.
 *
 */
const listint_t **_r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **lst_new;
	size_t h;

	lst_new = malloc(size * sizeof(listint_t *));
	if (lst_new == NULL)
	{
		free(list);
		exit(98);
	}
	for (h = 0; h < size - 1; h++)
		lst_new[h] = list[h];
	lst_new[h] = new;
	free(list);
	return (lst_new);
}


/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the first node in a list.
 *
 * Return: total number of nodes in the list.
 *
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t q, tot_numb = 0;
	const listint_t **lst = NULL;

	while (head != NULL)
	{
		for (q = 0; q < tot_numb; q++)
		{
			if (head == lst[q])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(lst);
				return (tot_numb);
			}
		}
		tot_numb++;
		lst = _r(lst, tot_numb, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(lst);
	return (tot_numb);
}
