#include <stdio.h>

/**
 * lmain - function executed before main function
 * Return: void data type
 */
void __attribute__((constuctor)) lmain()
{
	printf("You're beat! and yet, you must allow,");
	printf("nI bore my house upon my back!\n");
}
