#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * shl_realloc - reallocates contents from old block to new block
 * @ptr: pointer
 * @ssize: size of pointer
 * Return: pointer, or NULL
 */
void *shl_realloc(void *ptr, size_t ssize)
{
	void *new_ptr;

	if (ssize == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(ssize);

	if (new_ptr == NULL)
		return (NULL);

	if (ptr != NULL)
	{
		memcpy(new_ptr, ptr, ssize);
		free(ptr);
	}

	return (new_ptr);
}

/**
 * main - function entry
 * Return: 0, if not NULL
 */
int main()
{
	int *arr = malloc(5 * sizeof(int));
	int *new_arr;

	for (int i = 0; i < 5; i++)
	{
		arr[i] = i;
	}

	new_arr = (int *)shl_realloc(arr, 10 * sizeof(int));

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", new_arr[i]);
	}

	free(new_arr);
	return (0);
}
