#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void shell_loop(void)
{
	char *line = NULL;
	char **argv = NULL;

	while (1)
	{
		/* TODO: */
		/**
		 * print prompt
		 * Get line
		 * parse line into argument vector
		 */

		/* Print the prompt */
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}

		/* Get the line */
		line = shell_read_line();

		/* Check if line is NULL */
		if (!line)
		{
			/* If so, then an error or EOF was detected */
			break;
		}

		/* store tokens in argument vector */
		argv = argument_parser(line);

		/* pass argument vector to execute the program */
		shell_execute(argv);

		free(argv);
		free(line);
	}
}
