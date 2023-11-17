#include <lists.h>

/**
 * l_word - function executed before main function
 * Return: void data type
 */
void __attribute__((constructor)) l_word()
{
	printf("You're beat! and yet, you must allow,");
	printf("\nI bore my house upon my back!\n");
}
