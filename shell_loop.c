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

		if (execution_status.status)
			exit_status = execution_status.status;

		if (execution_status._isexit == 1)
		{
			free(argv);
			free(line);
			if (execution_status._isexit == 2)
				free_environ(environ);
			break;
		}

		free(argv);
		free(line);
		if (execution_status._isexit == 2)
			free_environ(environ);
	}

	exit(exit_status);
}
