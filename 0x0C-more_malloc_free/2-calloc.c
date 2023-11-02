#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array with malloc
 * @nmemb: number of elements in array
 * @size: size of each element in bytes
 * Return: pointer to malloc or NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	void *pointer;

	if (nmemb == 0 || size == 0)
		return (NULL);

	pointer = malloc(size * nmemb);
	if (pointer == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		((char *)pointer)[i] = 0;

	return (pointer);
}
