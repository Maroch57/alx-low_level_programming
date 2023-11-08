#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - this is a function searches for an int
 * @array: it points to array of integers
 * @size: number of elements that an array holds
 * @cmp: pointer to func that return int and argument int
 * Return: index of first element cmp func return 0,
 * -1 for no match or negative size
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int x;

	if (array && cmp)
	{
		for (x = 0; x < size; x++)
		{
		if (cmp(array[x]) != 0)
			return (x);
		}
	}
	return (-1);
}
