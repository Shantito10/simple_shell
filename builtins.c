#include "main.h"
#include <stdio.h>
#include <unistd.h>

int shell_exit(char **argv)
{
	(void)argv;

	return (-1);
}

int shell_env(char **argv)
{
	int i = 0;
	(void)argv;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], (_strlen(environ[i]) + 1));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (0);
}
