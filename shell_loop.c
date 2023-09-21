#include "main.h"

/**
 * shell_loop - Entry point
 *
 * Return: no return
 */
void shell_loop(void)
{
	char *line = NULL;
	char **argv = NULL;
	int temp_status, exit_status;

	exit_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		line = shell_read_line();

		if (!line)
			break;

		argv = argument_parser(line);

		temp_status = shell_execute(argv);

		if (temp_status == -1)
			break;

		exit_status = temp_status;

		free(argv);
		free(line);
	}

	exit(exit_status);
}
