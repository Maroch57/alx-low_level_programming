#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * create_node - ensures creation of a new node for the sorted hash table.
 * @key: the key string in subject.
 * @value: value associated with the key in subject.
 *
 * Return: ptr to the newly created node else, NULL.
 */
shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);
	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;

	return (node);
}

/**
 * shash_table_create - ensures creation of a sorted hash table.
 * @size: size of the hash table array.
 *
 * Return: ptr to the created hash table, else, NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - responsible for updating/adding an element in the sorted hash table.
 * @ht: hash table in subject.
 * @key: key string in subject.
 * @value: value associated with the key.
 *
 * Return: 1 on success, else 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *temp, *prev;
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = strdup(value);
			return (1);
		}
		node = node->next;
	}

	temp = create_node(key, value);
	if (temp == NULL)
		return (0);

	temp->next = ht->array[index];
	ht->array[index] = temp;

	prev = NULL;
	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) < 0)
	{
		prev = node;
		node = node->snext;
	}

	if (prev == NULL)
	{
		temp->sprev = NULL;
		temp->snext = ht->shead;
		ht->shead = temp;
	}
	else
	{
		temp->sprev = prev;
		temp->snext = prev->snext;
		prev->snext = temp;
	}

	if (temp->snext != NULL)
		temp->snext->sprev = temp;
	else
		ht->stail = temp;

	return (1);
}

/**
 * shash_table_get - fetches a value associated with the key in subject.
 * @ht: hash table in subject.
 * @key: the key to be searched for.
 *
 * Return: value associated with the key, else NULL on failure.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);

		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - responsible for printing the sorted hash table.
 * @ht: the hash table in subject.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->shead;

	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->snext != NULL)
			printf(", ");
		node = node->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - it prints the sorted hash table in reverse order.
 * @ht: the hash table in subject.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->stail;

	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->sprev != NULL)
			printf(", ");
		node = node->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - responsible for deleting the sorted hash table.
 * @ht: the hash table in subject.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			temp = node;
			node = node->next;
			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}

	free(ht->array);
	free(ht);
}

