#include "main.h"
#include <stddef.h>

int _strlen(char *str)
{
	int length = 0;

	if (str)
	{
		while (*(str + length) != '\0')
		{
			length++;
		}
	}

	return (length);
}

char *_strcpy(char *dest, char *src)
{
	int idx = 0;
	char *copy = dest;

	if (dest && src)
	{
		while (*(src + idx) != '\0')
		{
			*(dest + idx) = *(src + idx);
			idx++;
		}

		*(dest + idx) = '\0';

		return (copy);
	}
	else
	{
		return (NULL);
	}
}

char *_strdup(char *str)
{
	if (str)
	{
		size_t str_bytes = _strlen(str) + 1;
		char *duplicate = (char *)malloc(sizeof(char) * str_bytes);

		if (!duplicate)
		{
			return (NULL);
		}

		_strcpy(duplicate, str);
		return (duplicate);
	}
	else
	{
		return (NULL);
	}
}

int _strcmp(char *s1, char *s2)
{
	int index = 0;
	int cmp;

	while (*(s1 + index) != '\0' || *(s2 + index) != '\0')
	{
		cmp = (*(s1 + index) - *(s2 + index));

		if (cmp == 0)
		{
			index++;
		}
		else
		{
			break;
		}
	}

	return (cmp);
}

char *_strcat(char *dest, char *src)
{
	int dest_len = _strlen(dest);
	int source_index = 0;

	while (*(src + source_index) != '\0')
	{
		*(dest + (dest_len + source_index)) = *(src + source_index);
		source_index++;
	}
	*(dest + (dest_len + source_index)) = '\0';

	return (dest);
}
