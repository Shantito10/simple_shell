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
 * _isapath - function entry
 * @str: string
 * Return: 0
 */
int _isapath(char *str)
{
	if (str)
	{
		int idx = 0;

		while (*(str + idx) != '\0')
		{
			if (*(str + idx) == '/')
			{
				return (1);
			}

			idx++;
		}
	}

	return (0);
}

/**
 * _path_join - function entry
 * @path: path
 * @command_name: name of the command
 * Return: 0, if not NULL
 */
char *_path_join(char *path, char *command_name)
{
	char *full_path = NULL;
	size_t full_path_size;
	int last_char_idx;

	if (path && command_name)
	{

		last_char_idx = _strlen(path) - 1;
		full_path_size = _strlen(path) + _strlen(command_name) + 2;

		full_path = malloc(full_path_size);

		if (!full_path)
		{
			return (NULL);
		}

		_strcpy(full_path, path);
		if (path[last_char_idx] != '/')
			_strcat(full_path, "/");
		_strcat(full_path, command_name);

		return (full_path);
	}

	return (NULL);
}
