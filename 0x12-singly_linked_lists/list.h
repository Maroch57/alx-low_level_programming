#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

size_t print_list(const list_t *h);

/**
 * struct list_s - demonsrates a singly linked list.
 * @str: a malloced string
 * len: length of string
 * @next: a pointer to next node.
 */

struct list_s
{
	char *str;

	size_t len
	struct list_s *next
} list_t

#endif
