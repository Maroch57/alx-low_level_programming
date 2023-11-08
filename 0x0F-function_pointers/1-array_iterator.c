#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - function executes given func as parameter on array elements
 * @array: an array of elements
 * @size: the size of arr
 * @action: function of pointer
 * Author: KawiraSharon
 * Return: void meaning nothing is returned
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int x;

	if (!array || !action)
	return;

	for (x = 0; x < size; x++)

		action(array[x]);
}
