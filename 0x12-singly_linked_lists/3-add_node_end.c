#include "lists.h"

/**
 * add_node_end - function that adds new node to end of this list
 * @head: pointer to pointer for new last node
 * @str: the string we shall duplicate
 *
 * Return: address of last new element
 */
list_t *add_node_end(list_t **head, const char *str)
{
	size_t len_var = 0;
	list_t *newptr, *ptrTemp;

	newptr = malloc(sizeof(list_t));

	if (newptr == NULL)
		return (NULL);

	newptr->str = strdup(str);

	while (str[len_var])
		len_var++;

	newptr->len = len_var;
	newptr->next = NULL;
	ptrTemp = *head;

	if (ptrTemp == NULL)
		*head = newptr;

	else
	{
		while (ptrTemp->next != NULL)
		ptrTemp = ptrTemp->next;
		ptrTemp->next = newptr;
	}
	return (*head);
}
