#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

exec_status_t shell_exit(char **argv)
{
	exec_status_t res = {1, 0};
	if (argv[1])
	{
		res.status = atoi(argv[1]);
		return (res);
	}

	return (res);
}

exec_status_t shell_env(char **argv)
{
	exec_status_t res = {0, 0};
	int i = 0;
	(void)argv;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], (_strlen(environ[i]) + 1));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (res);
}
