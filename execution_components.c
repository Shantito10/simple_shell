#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * shell_execute - function for shell execution
 * @argv: argument vector
 * Return: no return
 */
int shell_execute(char **argv)
{
	if (argv[0] == NULL)
	{
		return (0);
	}

	execute_command(argv);

	return (0);
}

/**
 * execute_command - fuction for command execution
 * @argv: argument vector
 *
 * Return: return nothing
 */
void execute_command(char **argv)
{
	pid_t child_pid;
	int status;
	char *path;
	char *command = argv[0];

	path = _which(command);

	if (path)
	{
		argv[0] = path;

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("./hsh");
		}
		else if (child_pid == 0)
		{
			/* Child process */
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./hsh");
			}
		}
		else
		{
			wait(&status);
		}
		free(path);
	}
	else
	{
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, argv[0], (_strlen(argv[0]) + 1));
		write(STDERR_FILENO, ": not found\n", 13);
	}
}
