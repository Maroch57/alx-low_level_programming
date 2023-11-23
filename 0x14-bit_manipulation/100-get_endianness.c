#include "main.h"

/**
 * get_endianness - fn checks the endianness.
 *
 * Return: incase of big-endian - 0, if little-endian - 1.
 */
int get_endianness(void)
{
	int numbr = 1;
	char *endian_gt = (char *)&numbr;

	if (*endian_gt == 1)
		return (1);

	return (0);
}
