#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * sum_them_all - adds num
 * @n: param
 * Return: int
 */

int sum_them_all(const unsigned int n, ...)
{
    va_list userlist;
    unsigned int i;
    int sum = 0;

    if (n == 0)
        return (0);

    va_start(userlist, n);

    for (i = 0; i < n; i++)
        sum += va_arg(userlist, int);

    va_end(userlist);

    return (sum);
}
