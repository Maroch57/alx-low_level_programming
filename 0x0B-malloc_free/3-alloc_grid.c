#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - prints a grid sized width x height
 * populated with 0
 * @width: 1st array subscript
 * @height: 2nd array subscript
 * Return: pointer or NULL
 */
int **alloc_grid(int width, int height) /* 6 columns and 4 rows*/
{
	int i, j;
	int **array;

	if (width < 1 || height < 1)
		return (NULL);

	array = (int **)malloc(sizeof(int *) * height);
	if (array == NULL)
	{
		free(array);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		array[i] = malloc(sizeof(int) * width);
		if (array[i] == NULL)
		{
			for (i = 0; i < height; i++)
			{
				free(array[i]);
			}
			free(array);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
		{
			array[i][j] = 0;
		}

	return (array);
}
