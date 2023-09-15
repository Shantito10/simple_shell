#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void shell_loop(void)
{
	char *line = NULL;
	char **argv = NULL;
	int i;

	while (1)
	{
		/* TODO: */
		/**
		 * print prompt
		 * Get line
		 * parse line into argument vector
		 */

		/* Print the prompt */
		printf("$ ");

		/* Get the line */
		line = shell_read_line();

		/* Check if line is NULL */
		if (!line)
		{
			/* If so, then an error or EOF was detected */
			perror("EOF detected");
			break;
		}

		argv = argument_parser(line);

		i = 0;
		while (argv[i] != NULL)
		{
			printf("arg %d: %s\n", i, argv[i]);
			i++;
		}

		free(argv);
		free(line);
	}

}
