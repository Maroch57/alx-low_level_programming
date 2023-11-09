#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_numbers - prints num
 * @separator: pointer param
 * @n: param
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list userlist;
	unsigned int i;

	va_start(userlist, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(userlist, int));
	if (separator && i < n - 1)
		printf("%s", separator);
	}

	printf("\n");
	va_end(userlist);
}
