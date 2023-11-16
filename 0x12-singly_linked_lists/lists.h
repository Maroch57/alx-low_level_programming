#ifndef _LISTS_H_
#define _LISTS_H_

/**
 * struct list_s - demonsrates a singly linked list.
 * @str: a malloced string
 * @len: length of string
 * @next: a pointer to next node.
 *
 * Description: structure of singly linked list
 *
 */

typedef struct list_s
{
	char *str;

	unsigned int len;
	struct list_s *next;
} list_t;

size_t print_list(const list_t *h);

#endif
