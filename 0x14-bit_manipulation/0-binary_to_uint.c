#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Return: If b is NULL or contains chars not 0 or 1 - 0.
 *         Otherwise - the converted number.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int numb = 0, mult_no = 1;
	int lnth;

	if (!b)
		return (0);

	for (lngth = 0; b[lngth];)
		lngth++;

	for (lngth -= 1; lngth >= 0; lngth--)
	{
		if (b[lngth] != '0' && b[lngth] != '1')
			return (0);

		num += (b[len] - '0') * mult_no;
		mult_no *= 2;
	}

	return (numb);
}
