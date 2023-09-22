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
	exec_status_t execution_status;
	int exit_status;

	exit_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		line = shell_read_line();

		if (!line)
			break;

		argv = argument_parser(line);

		execution_status = shell_execute(argv);

		exit_status = execution_status.status;

		if (execution_status._isexit)
		{
			free(argv);
			free(line);
			break;
		}

		free(argv);
		free(line);
	}

	exit(exit_status);
}
