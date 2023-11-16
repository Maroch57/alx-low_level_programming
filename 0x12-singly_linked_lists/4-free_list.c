#include <stdlib.h>
#include "lists.h"

/**
* free_list - frees memory allocated for a list
*
* @head: A pointer to the first node list_t of the list to be freed
*/
void free_list(list_t *head)
{
   if (head)
   {
       free_list(head->next);
       if (head->str)
       free(head->str);
       free(head);
   }
}

