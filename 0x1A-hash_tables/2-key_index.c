#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * key_index - ensures the index of a key is given.
 * @key: the key to get index.
 * @size: the size of hash table.
 *
 * Return: the key index.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;
	unsigned long int index;

	hash_value = hash_djb2(key);

	index = hash_value % size;

	return (index);
}

