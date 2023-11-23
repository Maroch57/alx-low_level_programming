#include "main.h"

/**
 * clear_bit - fn sets the value of a bit at a given index to 0.
 * @n: ptr to the bit.
 * @index: The index to set the value.
 *
 * Return: if unsuccessful -1, else 1.
 *
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1 << index);

	return (1);
}
