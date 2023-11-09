#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings
 * @separator: pointer param
 * @n: param
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list userlist;
	unsigned int i;
	char *str;

	va_start(userlist, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(userlist, char *);

		if (str)
			printf("%s", str);
		else
			printf("(nil)");

		if (i < n - 1)
			if (separator)
				printf("%s", separator);
	}

	printf("\n");
	va_end(userlist);
}

