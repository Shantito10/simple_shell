#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * shell_exit - function shell entry
 * @argv: argument vector
 * Return: 0
 */
exec_status_t shell_exit(char **argv)
{
	exec_status_t res = {1, 0};
	int temp;

	if (argv[1])
	{
		temp = atoi(argv[1]);
		if (temp > 0 && temp < 256)
		{
			res.status = temp;
		}
		else if (temp > 255)
		{
			res.status = temp % 256;
		}
		else
		{
			write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
			write(STDERR_FILENO, argv[1], _strlen(argv[1]));
			write(STDERR_FILENO, "\n", 1);

			res.status = 2;
		}
	}

	return (res);
}

/**
 * shell_env - function shell entry
 * @argv: argument vector
 * Return: 0
 */
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
