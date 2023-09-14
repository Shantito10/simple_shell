#include "main.h"
#include <stddef.h>
#include <stdio.h>

char *shell_read_line(void)
{
	char *line = NULL;
	size_t line_buffer_size = 0;

	if (getline(&line, &line_buffer_size, stdin) == -1)
	{
		return (NULL);
	}

	return (line);
}
