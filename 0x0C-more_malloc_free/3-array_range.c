#include "main.h"
#include <stdlib.h>

/**
 * array_range - prints an array of integers.
 * from min to max value
 * @min: lower bound value.
 * @max: upper bound value.
 * Return: an array of int or NULL
 */
int *array_range(int min, int max)
{
	int i, arraysize, *pointer;

	if (max < min)
		return (NULL);

	arraysize = max - min + 1;

	pointer = malloc(sizeof(*pointer) * arraysize);
	if (pointer == NULL)
		return (NULL);

	for (i = min; i <= max; i++)
	{
		pointer[i - min] = i;
	}
	return (pointer);
}
