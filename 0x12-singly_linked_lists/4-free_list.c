#include "lists.h"

/**
* free_list - frees memory allocated for a list
*
* @head: A pointer to the first node list_t of the list to be freed
* Return: void
*/
void free_list(list_t *head)
{
	list_t *point_new;

	while ((point_new = head) != NULL)
	{
		head = head->next;
		free(point_new->str);
		free(point_new);
	}
}
